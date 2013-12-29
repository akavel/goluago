
/* In your code, include:
#include <stdlib.h>
#include "dumper.inc"
*/

typedef void* (*dumper_lua_Alloc)(void *ud, void *ptr, size_t osize, size_t nsize); 

typedef struct {
	dumper_lua_Alloc wrapped;
	void *ud;
	void (*puts)(const char *);
	void *priv;  /* must be zeroed out initially */
} dumper_Wrap;

typedef struct dumper_NodeT {
	void *data;
	size_t size;
	size_t id;
	struct dumper_NodeT *next;
} dumper_Node;

#define dumper_HEXD(x) ((x)==0 ? '*' : (x)<10 ? '0'+(x) : (x)-10+'a')

static void
dumper_hex(unsigned char *p, int size, int prefixed, void (*puts)(const char *)) {
	char buf[] = "00";
	int i;
	for (i=0; i<size; i++) {
		if (prefixed && (i&0xf)==0) {
			(*puts)("  0x");
			dumper_hex((void*)&i, sizeof(i), 0, puts);
			(*puts)(": ");
		}
		if ((i&0x3)==0 && !(i==0 && prefixed==0))
			(*puts)(" ");
		buf[0] = dumper_HEXD(p[i]>>4);
		buf[1] = dumper_HEXD(p[i]&0xf);
		(*puts)(buf);
		if (prefixed && (i&0xf)==0xf)
			(*puts)("\n");
	}
	if (prefixed && (i&0xf)!=0)
		(*puts)("\n");
}

static void
dumper_dump(dumper_Wrap *root) {
	static size_t dumpcounter = 0;
	dumper_Node *n = (dumper_Node*)root->priv;
	void (*puts)(const char *) = root->puts;

	(*puts)("------ DUMP ID: ");
	dumper_hex((void*)&dumpcounter, sizeof(dumpcounter), 0, puts);
	(*puts)(" ------\n");
	dumpcounter++;

	while (n) {
		(*puts)("NODE ");
		dumper_hex((void*)&n->id, sizeof(n->id), 0, puts);
		(*puts)(" at ");
		dumper_hex((void*)&n->data, sizeof(n->data), 0, puts);
		(*puts)(" size ");
		dumper_hex((void*)&n->size, sizeof(n->size), 0, puts);
		(*puts)(":\n");
		dumper_hex(n->data, n->size, 1, puts);
		n = n->next;
	}
	(*puts)("END\n\n");
}

static void*
dumper_alloc(void *ud, void *ptr, size_t osize, size_t nsize) {
	char pad[4] = {0xDE, 0xAD, 0xBE, 0xEF};
	size_t i;
	size_t maxid = 0;
	dumper_Wrap *root = (dumper_Wrap *)ud;
	dumper_Node **p = (dumper_Node **)&root->priv;
	void (*puts)(const char *) = root->puts;

	(*puts)("alloc ptr=");
	dumper_hex((void*)&ptr, sizeof(ptr), 0, puts);
	(*puts)(" osize=");
	dumper_hex((void*)&osize, sizeof(osize), 0, puts);
	(*puts)(" nsize=");
	dumper_hex((void*)&nsize, sizeof(nsize), 0, puts);
	(*puts)("\n");
	if (nsize && !osize) { /* alloc */
		while (*p) {
			if ((*p)->id > maxid)
				maxid = (*p)->id;
			p = &(*p)->next;
		}
		*p = (dumper_Node *)((*root->wrapped)(root->ud, NULL, 0, sizeof(dumper_Node)));
		if (!*p)
			return NULL;
		(*p)->data = (*root->wrapped)(root->ud, NULL, 0, nsize);
		if (!(*p)->data) {
			(*root->wrapped)(root->ud, *p, sizeof(dumper_Node), 0);
			return NULL;
		}
		(*p)->size = nsize;
		(*p)->id = maxid+1;
		(*p)->next = NULL;
		for (i=0; i<nsize; i++) /* TODO: protection against i overflow? */
			((char*)(*p)->data)[i] = pad[i&0x3];
		dumper_dump(root);
		return (*p)->data;
	}
	if (!osize) /* && !nsize */
		return NULL;
	for (;;) {
		if (!*p)
			return NULL;  /* WE SHOULD PANIC! */
		if ((*p)->data == ptr)
			break;
		p = &(*p)->next;
	}
	if (nsize) { /* realloc */
		void *newdata = (*root->wrapped)(root->ud, (*p)->data, osize, nsize);
		if (!newdata)
			return NULL;
		(*p)->size = nsize;
		(*p)->data = newdata;
		for (i=osize; i<nsize; i++) /* TODO: protection against i overflow? */
			((char*)(*p)->data)[i] = pad[i&0x3];
		dumper_dump(root);
		return newdata;
	} else { /* free */
		dumper_Node *next = (*p)->next;
		(*root->wrapped)(root->ud, (*p)->data, osize, 0);
		(*root->wrapped)(root->ud, *p, sizeof(dumper_Node), 0);
		*p = next;
		dumper_dump(root);
		return NULL;
	}
}
