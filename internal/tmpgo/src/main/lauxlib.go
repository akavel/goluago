package main

/*
** $Id: ldebug.h,v 2.3.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions from Debug Interface module
** See Copyright Notice in lua.h
 */
/*
** $Id: ldo.h,v 2.7.1.1 2007/12/27 13:02:25 roberto Exp $
** Stack and Call structure of Lua
** See Copyright Notice in lua.h
 */
/*
** $Id: lgc.h,v 2.15.1.1 2007/12/27 13:02:25 roberto Exp $
** Garbage Collector
** See Copyright Notice in lua.h
 */
/*
** $Id: llex.h,v 1.58.1.1 2007/12/27 13:02:25 roberto Exp $
** Lexical Analyzer
** See Copyright Notice in lua.h
 */
/*
** $Id: lmem.h,v 1.31.1.1 2007/12/27 13:02:25 roberto Exp $
** Interface to Memory Manager
** See Copyright Notice in lua.h
 */
/*
** $Id: lobject.h,v 2.20.1.2 2008/08/06 13:29:48 roberto Exp $
** Type definitions for Lua objects
** See Copyright Notice in lua.h
 */
/*
** $Id: lopcodes.h,v 1.125.1.1 2007/12/27 13:02:25 roberto Exp $
** Opcodes for Lua virtual machine
** See Copyright Notice in lua.h
 */
/*
** $Id: lparser.h,v 1.57.1.1 2007/12/27 13:02:25 roberto Exp $
** Lua Parser
** See Copyright Notice in lua.h
 */
/*
** $Id: ltable.h,v 2.10.1.1 2007/12/27 13:02:25 roberto Exp $
** Lua tables (hash)
** See Copyright Notice in lua.h
 */
/*
** $Id: lua.h,v 1.218.1.5 2008/08/06 13:30:12 roberto Exp $
** Lua - An Extensible Extension Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
 */
/*
** $Id: lauxlib.h,v 1.88.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions for building Lua libraries
** See Copyright Notice in lua.h
 */
/*
** $Id: lualib.h,v 1.36.1.1 2007/12/27 13:02:25 roberto Exp $
** Lua standard libraries
** See Copyright Notice in lua.h
 */
/*
** $Id: lua.h,v 1.218.1.5 2008/08/06 13:30:12 roberto Exp $
** Lua - An Extensible Extension Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
 */
/*
** $Id: lapi.h,v 2.2.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions from Lua API
** See Copyright Notice in lua.h
 */
/*
** $Id: lcode.h,v 1.48.1.1 2007/12/27 13:02:25 roberto Exp $
** Code generator for Lua
** See Copyright Notice in lua.h
 */
/*
** $Id: ldebug.h,v 2.3.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions from Debug Interface module
** See Copyright Notice in lua.h
 */
/*
** $Id: ldo.h,v 2.7.1.1 2007/12/27 13:02:25 roberto Exp $
** Stack and Call structure of Lua
** See Copyright Notice in lua.h
 */
/*
** $Id: lfunc.h,v 2.4.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions to manipulate prototypes and closures
** See Copyright Notice in lua.h
 */
/*
** $Id: lobject.h,v 2.20.1.2 2008/08/06 13:29:48 roberto Exp $
** Type definitions for Lua objects
** See Copyright Notice in lua.h
 */
/*
** $Id: lopcodes.h,v 1.125.1.1 2007/12/27 13:02:25 roberto Exp $
** Opcodes for Lua virtual machine
** See Copyright Notice in lua.h
 */
/*
** $Id: lstate.h,v 2.24.1.2 2008/01/03 15:20:39 roberto Exp $
** Global State
** See Copyright Notice in lua.h
 */
/*
** $Id: lstring.h,v 1.43.1.1 2007/12/27 13:02:25 roberto Exp $
** String table (keep all strings handled by Lua)
** See Copyright Notice in lua.h
 */
/*
** $Id: ltable.h,v 2.10.1.1 2007/12/27 13:02:25 roberto Exp $
** Lua tables (hash)
** See Copyright Notice in lua.h
 */
/*
** $Id: ltm.h,v 2.6.1.1 2007/12/27 13:02:25 roberto Exp $
** Tag methods
** See Copyright Notice in lua.h
 */
/*
** $Id: lvm.h,v 2.5.1.1 2007/12/27 13:02:25 roberto Exp $
** Lua virtual machine
** See Copyright Notice in lua.h
 */
/*
** $Id: lua.h,v 1.218.1.5 2008/08/06 13:30:12 roberto Exp $
** Lua - An Extensible Extension Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
 */
/*
** $Id: ldebug.h,v 2.3.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions from Debug Interface module
** See Copyright Notice in lua.h
 */
/*
** $Id: ldo.h,v 2.7.1.1 2007/12/27 13:02:25 roberto Exp $
** Stack and Call structure of Lua
** See Copyright Notice in lua.h
 */
/*
** $Id: lfunc.h,v 2.4.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions to manipulate prototypes and closures
** See Copyright Notice in lua.h
 */
/*
** $Id: lgc.h,v 2.15.1.1 2007/12/27 13:02:25 roberto Exp $
** Garbage Collector
** See Copyright Notice in lua.h
 */
/*
** $Id: lmem.h,v 1.31.1.1 2007/12/27 13:02:25 roberto Exp $
** Interface to Memory Manager
** See Copyright Notice in lua.h
 */
/*
** $Id: lobject.h,v 2.20.1.2 2008/08/06 13:29:48 roberto Exp $
** Type definitions for Lua objects
** See Copyright Notice in lua.h
 */
/*
** $Id: lopcodes.h,v 1.125.1.1 2007/12/27 13:02:25 roberto Exp $
** Opcodes for Lua virtual machine
** See Copyright Notice in lua.h
 */
/*
** $Id: lparser.h,v 1.57.1.1 2007/12/27 13:02:25 roberto Exp $
** Lua Parser
** See Copyright Notice in lua.h
 */
/*
** $Id: lstate.h,v 2.24.1.2 2008/01/03 15:20:39 roberto Exp $
** Global State
** See Copyright Notice in lua.h
 */
/*
** $Id: lstring.h,v 1.43.1.1 2007/12/27 13:02:25 roberto Exp $
** String table (keep all strings handled by Lua)
** See Copyright Notice in lua.h
 */
/*
** $Id: ltable.h,v 2.10.1.1 2007/12/27 13:02:25 roberto Exp $
** Lua tables (hash)
** See Copyright Notice in lua.h
 */
/*
** $Id: ltm.h,v 2.6.1.1 2007/12/27 13:02:25 roberto Exp $
** Tag methods
** See Copyright Notice in lua.h
 */
/*
** $Id: lundump.h,v 1.37.1.1 2007/12/27 13:02:25 roberto Exp $
** load precompiled Lua chunks
** See Copyright Notice in lua.h
 */
/*
** $Id: lvm.h,v 2.5.1.1 2007/12/27 13:02:25 roberto Exp $
** Lua virtual machine
** See Copyright Notice in lua.h
 */
/*
** $Id: lzio.h,v 1.21.1.1 2007/12/27 13:02:25 roberto Exp $
** Buffered streams
** See Copyright Notice in lua.h
 */
/*
** $Id: lua.h,v 1.218.1.5 2008/08/06 13:30:12 roberto Exp $
** Lua - An Extensible Extension Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
 */
/*
** $Id: lobject.h,v 2.20.1.2 2008/08/06 13:29:48 roberto Exp $
** Type definitions for Lua objects
** See Copyright Notice in lua.h
 */
/*
** $Id: lstate.h,v 2.24.1.2 2008/01/03 15:20:39 roberto Exp $
** Global State
** See Copyright Notice in lua.h
 */
/*
** $Id: lundump.h,v 1.37.1.1 2007/12/27 13:02:25 roberto Exp $
** load precompiled Lua chunks
** See Copyright Notice in lua.h
 */
/*
** $Id: lua.h,v 1.218.1.5 2008/08/06 13:30:12 roberto Exp $
** Lua - An Extensible Extension Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
 */
/*
** $Id: lfunc.h,v 2.4.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions to manipulate prototypes and closures
** See Copyright Notice in lua.h
 */
/*
** $Id: lgc.h,v 2.15.1.1 2007/12/27 13:02:25 roberto Exp $
** Garbage Collector
** See Copyright Notice in lua.h
 */
/*
** $Id: lmem.h,v 1.31.1.1 2007/12/27 13:02:25 roberto Exp $
** Interface to Memory Manager
** See Copyright Notice in lua.h
 */
/*
** $Id: lobject.h,v 2.20.1.2 2008/08/06 13:29:48 roberto Exp $
** Type definitions for Lua objects
** See Copyright Notice in lua.h
 */
/*
** $Id: lstate.h,v 2.24.1.2 2008/01/03 15:20:39 roberto Exp $
** Global State
** See Copyright Notice in lua.h
 */
/*
** $Id: lua.h,v 1.218.1.5 2008/08/06 13:30:12 roberto Exp $
** Lua - An Extensible Extension Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
 */
/*
** $Id: ldebug.h,v 2.3.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions from Debug Interface module
** See Copyright Notice in lua.h
 */
/*
** $Id: ldo.h,v 2.7.1.1 2007/12/27 13:02:25 roberto Exp $
** Stack and Call structure of Lua
** See Copyright Notice in lua.h
 */
/*
** $Id: lfunc.h,v 2.4.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions to manipulate prototypes and closures
** See Copyright Notice in lua.h
 */
/*
** $Id: lgc.h,v 2.15.1.1 2007/12/27 13:02:25 roberto Exp $
** Garbage Collector
** See Copyright Notice in lua.h
 */
/*
** $Id: lmem.h,v 1.31.1.1 2007/12/27 13:02:25 roberto Exp $
** Interface to Memory Manager
** See Copyright Notice in lua.h
 */
/*
** $Id: lobject.h,v 2.20.1.2 2008/08/06 13:29:48 roberto Exp $
** Type definitions for Lua objects
** See Copyright Notice in lua.h
 */
/*
** $Id: lstate.h,v 2.24.1.2 2008/01/03 15:20:39 roberto Exp $
** Global State
** See Copyright Notice in lua.h
 */
/*
** $Id: lstring.h,v 1.43.1.1 2007/12/27 13:02:25 roberto Exp $
** String table (keep all strings handled by Lua)
** See Copyright Notice in lua.h
 */
/*
** $Id: ltable.h,v 2.10.1.1 2007/12/27 13:02:25 roberto Exp $
** Lua tables (hash)
** See Copyright Notice in lua.h
 */
/*
** $Id: ltm.h,v 2.6.1.1 2007/12/27 13:02:25 roberto Exp $
** Tag methods
** See Copyright Notice in lua.h
 */
/*
** $Id: lua.h,v 1.218.1.5 2008/08/06 13:30:12 roberto Exp $
** Lua - An Extensible Extension Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
 */
/*
** $Id: lauxlib.h,v 1.88.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions for building Lua libraries
** See Copyright Notice in lua.h
 */
/*
** $Id: lualib.h,v 1.36.1.1 2007/12/27 13:02:25 roberto Exp $
** Lua standard libraries
** See Copyright Notice in lua.h
 */
/*
** $Id: lua.h,v 1.218.1.5 2008/08/06 13:30:12 roberto Exp $
** Lua - An Extensible Extension Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
 */
/*
** $Id: ldo.h,v 2.7.1.1 2007/12/27 13:02:25 roberto Exp $
** Stack and Call structure of Lua
** See Copyright Notice in lua.h
 */
/*
** $Id: llex.h,v 1.58.1.1 2007/12/27 13:02:25 roberto Exp $
** Lexical Analyzer
** See Copyright Notice in lua.h
 */
/*
** $Id: lobject.h,v 2.20.1.2 2008/08/06 13:29:48 roberto Exp $
** Type definitions for Lua objects
** See Copyright Notice in lua.h
 */
/*
** $Id: lparser.h,v 1.57.1.1 2007/12/27 13:02:25 roberto Exp $
** Lua Parser
** See Copyright Notice in lua.h
 */
/*
** $Id: lstate.h,v 2.24.1.2 2008/01/03 15:20:39 roberto Exp $
** Global State
** See Copyright Notice in lua.h
 */
/*
** $Id: lstring.h,v 1.43.1.1 2007/12/27 13:02:25 roberto Exp $
** String table (keep all strings handled by Lua)
** See Copyright Notice in lua.h
 */
/*
** $Id: ltable.h,v 2.10.1.1 2007/12/27 13:02:25 roberto Exp $
** Lua tables (hash)
** See Copyright Notice in lua.h
 */
/*
** $Id: lzio.h,v 1.21.1.1 2007/12/27 13:02:25 roberto Exp $
** Buffered streams
** See Copyright Notice in lua.h
 */
/*
** $Id: lua.h,v 1.218.1.5 2008/08/06 13:30:12 roberto Exp $
** Lua - An Extensible Extension Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
 */
/*
** $Id: lauxlib.h,v 1.88.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions for building Lua libraries
** See Copyright Notice in lua.h
 */
/*
** $Id: lualib.h,v 1.36.1.1 2007/12/27 13:02:25 roberto Exp $
** Lua standard libraries
** See Copyright Notice in lua.h
 */
/*
** $Id: lua.h,v 1.218.1.5 2008/08/06 13:30:12 roberto Exp $
** Lua - An Extensible Extension Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
 */
/*
** $Id: ldebug.h,v 2.3.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions from Debug Interface module
** See Copyright Notice in lua.h
 */
/*
** $Id: ldo.h,v 2.7.1.1 2007/12/27 13:02:25 roberto Exp $
** Stack and Call structure of Lua
** See Copyright Notice in lua.h
 */
/*
** $Id: lmem.h,v 1.31.1.1 2007/12/27 13:02:25 roberto Exp $
** Interface to Memory Manager
** See Copyright Notice in lua.h
 */
/*
** $Id: lobject.h,v 2.20.1.2 2008/08/06 13:29:48 roberto Exp $
** Type definitions for Lua objects
** See Copyright Notice in lua.h
 */
/*
** $Id: lstate.h,v 2.24.1.2 2008/01/03 15:20:39 roberto Exp $
** Global State
** See Copyright Notice in lua.h
 */
/*
** $Id: lua.h,v 1.218.1.5 2008/08/06 13:30:12 roberto Exp $
** Lua - An Extensible Extension Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
 */
/*
** $Id: ldo.h,v 2.7.1.1 2007/12/27 13:02:25 roberto Exp $
** Stack and Call structure of Lua
** See Copyright Notice in lua.h
 */
/*
** $Id: lmem.h,v 1.31.1.1 2007/12/27 13:02:25 roberto Exp $
** Interface to Memory Manager
** See Copyright Notice in lua.h
 */
/*
** $Id: lobject.h,v 2.20.1.2 2008/08/06 13:29:48 roberto Exp $
** Type definitions for Lua objects
** See Copyright Notice in lua.h
 */
/*
** $Id: lstate.h,v 2.24.1.2 2008/01/03 15:20:39 roberto Exp $
** Global State
** See Copyright Notice in lua.h
 */
/*
** $Id: lstring.h,v 1.43.1.1 2007/12/27 13:02:25 roberto Exp $
** String table (keep all strings handled by Lua)
** See Copyright Notice in lua.h
 */
/*
** $Id: lvm.h,v 2.5.1.1 2007/12/27 13:02:25 roberto Exp $
** Lua virtual machine
** See Copyright Notice in lua.h
 */
/*
** $Id: lopcodes.h,v 1.125.1.1 2007/12/27 13:02:25 roberto Exp $
** Opcodes for Lua virtual machine
** See Copyright Notice in lua.h
 */
/*
** $Id: lua.h,v 1.218.1.5 2008/08/06 13:30:12 roberto Exp $
** Lua - An Extensible Extension Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
 */
/*
** $Id: lauxlib.h,v 1.88.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions for building Lua libraries
** See Copyright Notice in lua.h
 */
/*
** $Id: lualib.h,v 1.36.1.1 2007/12/27 13:02:25 roberto Exp $
** Lua standard libraries
** See Copyright Notice in lua.h
 */
/*
** $Id: lua.h,v 1.218.1.5 2008/08/06 13:30:12 roberto Exp $
** Lua - An Extensible Extension Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
 */
/*
** $Id: lcode.h,v 1.48.1.1 2007/12/27 13:02:25 roberto Exp $
** Code generator for Lua
** See Copyright Notice in lua.h
 */
/*
** $Id: ldebug.h,v 2.3.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions from Debug Interface module
** See Copyright Notice in lua.h
 */
/*
** $Id: ldo.h,v 2.7.1.1 2007/12/27 13:02:25 roberto Exp $
** Stack and Call structure of Lua
** See Copyright Notice in lua.h
 */
/*
** $Id: lfunc.h,v 2.4.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions to manipulate prototypes and closures
** See Copyright Notice in lua.h
 */
/*
** $Id: llex.h,v 1.58.1.1 2007/12/27 13:02:25 roberto Exp $
** Lexical Analyzer
** See Copyright Notice in lua.h
 */
/*
** $Id: lmem.h,v 1.31.1.1 2007/12/27 13:02:25 roberto Exp $
** Interface to Memory Manager
** See Copyright Notice in lua.h
 */
/*
** $Id: lobject.h,v 2.20.1.2 2008/08/06 13:29:48 roberto Exp $
** Type definitions for Lua objects
** See Copyright Notice in lua.h
 */
/*
** $Id: lopcodes.h,v 1.125.1.1 2007/12/27 13:02:25 roberto Exp $
** Opcodes for Lua virtual machine
** See Copyright Notice in lua.h
 */
/*
** $Id: lparser.h,v 1.57.1.1 2007/12/27 13:02:25 roberto Exp $
** Lua Parser
** See Copyright Notice in lua.h
 */
/*
** $Id: lstate.h,v 2.24.1.2 2008/01/03 15:20:39 roberto Exp $
** Global State
** See Copyright Notice in lua.h
 */
/*
** $Id: lstring.h,v 1.43.1.1 2007/12/27 13:02:25 roberto Exp $
** String table (keep all strings handled by Lua)
** See Copyright Notice in lua.h
 */
/*
** $Id: ltable.h,v 2.10.1.1 2007/12/27 13:02:25 roberto Exp $
** Lua tables (hash)
** See Copyright Notice in lua.h
 */
/*
** $Id: lua.h,v 1.218.1.5 2008/08/06 13:30:12 roberto Exp $
** Lua - An Extensible Extension Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
 */
/*
** $Id: ldebug.h,v 2.3.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions from Debug Interface module
** See Copyright Notice in lua.h
 */
/*
** $Id: ldo.h,v 2.7.1.1 2007/12/27 13:02:25 roberto Exp $
** Stack and Call structure of Lua
** See Copyright Notice in lua.h
 */
/*
** $Id: lfunc.h,v 2.4.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions to manipulate prototypes and closures
** See Copyright Notice in lua.h
 */
/*
** $Id: lgc.h,v 2.15.1.1 2007/12/27 13:02:25 roberto Exp $
** Garbage Collector
** See Copyright Notice in lua.h
 */
/*
** $Id: llex.h,v 1.58.1.1 2007/12/27 13:02:25 roberto Exp $
** Lexical Analyzer
** See Copyright Notice in lua.h
 */
/*
** $Id: lmem.h,v 1.31.1.1 2007/12/27 13:02:25 roberto Exp $
** Interface to Memory Manager
** See Copyright Notice in lua.h
 */
/*
** $Id: lstate.h,v 2.24.1.2 2008/01/03 15:20:39 roberto Exp $
** Global State
** See Copyright Notice in lua.h
 */
/*
** $Id: lstring.h,v 1.43.1.1 2007/12/27 13:02:25 roberto Exp $
** String table (keep all strings handled by Lua)
** See Copyright Notice in lua.h
 */
/*
** $Id: ltable.h,v 2.10.1.1 2007/12/27 13:02:25 roberto Exp $
** Lua tables (hash)
** See Copyright Notice in lua.h
 */
/*
** $Id: ltm.h,v 2.6.1.1 2007/12/27 13:02:25 roberto Exp $
** Tag methods
** See Copyright Notice in lua.h
 */
/*
** $Id: lua.h,v 1.218.1.5 2008/08/06 13:30:12 roberto Exp $
** Lua - An Extensible Extension Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
 */
/*
** $Id: lmem.h,v 1.31.1.1 2007/12/27 13:02:25 roberto Exp $
** Interface to Memory Manager
** See Copyright Notice in lua.h
 */
/*
** $Id: lobject.h,v 2.20.1.2 2008/08/06 13:29:48 roberto Exp $
** Type definitions for Lua objects
** See Copyright Notice in lua.h
 */
/*
** $Id: lstate.h,v 2.24.1.2 2008/01/03 15:20:39 roberto Exp $
** Global State
** See Copyright Notice in lua.h
 */
/*
** $Id: lstring.h,v 1.43.1.1 2007/12/27 13:02:25 roberto Exp $
** String table (keep all strings handled by Lua)
** See Copyright Notice in lua.h
 */
/*
** $Id: lua.h,v 1.218.1.5 2008/08/06 13:30:12 roberto Exp $
** Lua - An Extensible Extension Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
 */
/*
** $Id: lauxlib.h,v 1.88.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions for building Lua libraries
** See Copyright Notice in lua.h
 */
/*
** $Id: lualib.h,v 1.36.1.1 2007/12/27 13:02:25 roberto Exp $
** Lua standard libraries
** See Copyright Notice in lua.h
 */
/*
** $Id: lua.h,v 1.218.1.5 2008/08/06 13:30:12 roberto Exp $
** Lua - An Extensible Extension Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
 */
/*
** $Id: ldebug.h,v 2.3.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions from Debug Interface module
** See Copyright Notice in lua.h
 */
/*
** $Id: ldo.h,v 2.7.1.1 2007/12/27 13:02:25 roberto Exp $
** Stack and Call structure of Lua
** See Copyright Notice in lua.h
 */
/*
** $Id: lgc.h,v 2.15.1.1 2007/12/27 13:02:25 roberto Exp $
** Garbage Collector
** See Copyright Notice in lua.h
 */
/*
** $Id: lmem.h,v 1.31.1.1 2007/12/27 13:02:25 roberto Exp $
** Interface to Memory Manager
** See Copyright Notice in lua.h
 */
/*
** $Id: lobject.h,v 2.20.1.2 2008/08/06 13:29:48 roberto Exp $
** Type definitions for Lua objects
** See Copyright Notice in lua.h
 */
/*
** $Id: lstate.h,v 2.24.1.2 2008/01/03 15:20:39 roberto Exp $
** Global State
** See Copyright Notice in lua.h
 */
/*
** $Id: ltable.h,v 2.10.1.1 2007/12/27 13:02:25 roberto Exp $
** Lua tables (hash)
** See Copyright Notice in lua.h
 */
/*
** $Id: lua.h,v 1.218.1.5 2008/08/06 13:30:12 roberto Exp $
** Lua - An Extensible Extension Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
 */
/*
** $Id: lauxlib.h,v 1.88.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions for building Lua libraries
** See Copyright Notice in lua.h
 */
/*
** $Id: lualib.h,v 1.36.1.1 2007/12/27 13:02:25 roberto Exp $
** Lua standard libraries
** See Copyright Notice in lua.h
 */
/*
** $Id: lua.h,v 1.218.1.5 2008/08/06 13:30:12 roberto Exp $
** Lua - An Extensible Extension Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
 */
/*
** $Id: lobject.h,v 2.20.1.2 2008/08/06 13:29:48 roberto Exp $
** Type definitions for Lua objects
** See Copyright Notice in lua.h
 */
/*
** $Id: lstate.h,v 2.24.1.2 2008/01/03 15:20:39 roberto Exp $
** Global State
** See Copyright Notice in lua.h
 */
/*
** $Id: lstring.h,v 1.43.1.1 2007/12/27 13:02:25 roberto Exp $
** String table (keep all strings handled by Lua)
** See Copyright Notice in lua.h
 */
/*
** $Id: ltable.h,v 2.10.1.1 2007/12/27 13:02:25 roberto Exp $
** Lua tables (hash)
** See Copyright Notice in lua.h
 */
/*
** $Id: ltm.h,v 2.6.1.1 2007/12/27 13:02:25 roberto Exp $
** Tag methods
** See Copyright Notice in lua.h
 */
/*
** $Id: lua.h,v 1.218.1.5 2008/08/06 13:30:12 roberto Exp $
** Lua - An Extensible Extension Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
 */
/*
** $Id: ldebug.h,v 2.3.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions from Debug Interface module
** See Copyright Notice in lua.h
 */
/*
** $Id: ldo.h,v 2.7.1.1 2007/12/27 13:02:25 roberto Exp $
** Stack and Call structure of Lua
** See Copyright Notice in lua.h
 */
/*
** $Id: lfunc.h,v 2.4.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions to manipulate prototypes and closures
** See Copyright Notice in lua.h
 */
/*
** $Id: lmem.h,v 1.31.1.1 2007/12/27 13:02:25 roberto Exp $
** Interface to Memory Manager
** See Copyright Notice in lua.h
 */
/*
** $Id: lobject.h,v 2.20.1.2 2008/08/06 13:29:48 roberto Exp $
** Type definitions for Lua objects
** See Copyright Notice in lua.h
 */
/*
** $Id: lstring.h,v 1.43.1.1 2007/12/27 13:02:25 roberto Exp $
** String table (keep all strings handled by Lua)
** See Copyright Notice in lua.h
 */
/*
** $Id: lundump.h,v 1.37.1.1 2007/12/27 13:02:25 roberto Exp $
** load precompiled Lua chunks
** See Copyright Notice in lua.h
 */
/*
** $Id: lzio.h,v 1.21.1.1 2007/12/27 13:02:25 roberto Exp $
** Buffered streams
** See Copyright Notice in lua.h
 */
/*
** $Id: lua.h,v 1.218.1.5 2008/08/06 13:30:12 roberto Exp $
** Lua - An Extensible Extension Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
 */
/*
** $Id: ldebug.h,v 2.3.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions from Debug Interface module
** See Copyright Notice in lua.h
 */
/*
** $Id: ldo.h,v 2.7.1.1 2007/12/27 13:02:25 roberto Exp $
** Stack and Call structure of Lua
** See Copyright Notice in lua.h
 */
/*
** $Id: lfunc.h,v 2.4.1.1 2007/12/27 13:02:25 roberto Exp $
** Auxiliary functions to manipulate prototypes and closures
** See Copyright Notice in lua.h
 */
/*
** $Id: lgc.h,v 2.15.1.1 2007/12/27 13:02:25 roberto Exp $
** Garbage Collector
** See Copyright Notice in lua.h
 */
/*
** $Id: lobject.h,v 2.20.1.2 2008/08/06 13:29:48 roberto Exp $
** Type definitions for Lua objects
** See Copyright Notice in lua.h
 */
/*
** $Id: lopcodes.h,v 1.125.1.1 2007/12/27 13:02:25 roberto Exp $
** Opcodes for Lua virtual machine
** See Copyright Notice in lua.h
 */
/*
** $Id: lstate.h,v 2.24.1.2 2008/01/03 15:20:39 roberto Exp $
** Global State
** See Copyright Notice in lua.h
 */
/*
** $Id: lstring.h,v 1.43.1.1 2007/12/27 13:02:25 roberto Exp $
** String table (keep all strings handled by Lua)
** See Copyright Notice in lua.h
 */
/*
** $Id: ltable.h,v 2.10.1.1 2007/12/27 13:02:25 roberto Exp $
** Lua tables (hash)
** See Copyright Notice in lua.h
 */
/*
** $Id: ltm.h,v 2.6.1.1 2007/12/27 13:02:25 roberto Exp $
** Tag methods
** See Copyright Notice in lua.h
 */
/*
** $Id: lvm.h,v 2.5.1.1 2007/12/27 13:02:25 roberto Exp $
** Lua virtual machine
** See Copyright Notice in lua.h
 */
/*
** $Id: lua.h,v 1.218.1.5 2008/08/06 13:30:12 roberto Exp $
** Lua - An Extensible Extension Language
** Lua.org, PUC-Rio, Brazil (http://www.lua.org)
** See Copyright Notice at the end of this file
 */
/*
** $Id: llimits.h,v 1.69.1.1 2007/12/27 13:02:25 roberto Exp $
** Limits, basic types, and some other `installation-dependent' definitions
** See Copyright Notice in lua.h
 */
/*
** $Id: lmem.h,v 1.31.1.1 2007/12/27 13:02:25 roberto Exp $
** Interface to Memory Manager
** See Copyright Notice in lua.h
 */
/*
** $Id: lstate.h,v 2.24.1.2 2008/01/03 15:20:39 roberto Exp $
** Global State
** See Copyright Notice in lua.h
 */
/*
** $Id: lzio.h,v 1.21.1.1 2007/12/27 13:02:25 roberto Exp $
** Buffered streams
** See Copyright Notice in lua.h
 */
/*
** $Id: lauxlib.c,v 1.159.1.3 2008/01/21 13:20:51 roberto Exp $
** Auxiliary functions for building Lua libraries
** See Copyright Notice in lua.h
 */
/* This file uses only the official API of Lua.
** Any function declared here could be written as an application function.
 */
/* convert a stack index to positive */
/*
** {======================================================
** Error-report functions
** =======================================================
 */
func luaL_argerror(_L *lua_State, narg int, extramsg string) int {
	var ar lua_Debug
	if lua_getstack(_L, 0, &ar) == 0 {
		return luaL_error(_L, "bad argument #%d (%s)", narg, extramsg)
	}
	lua_getinfo(_L, "n", &ar)
	if ar.namewhat == "method" {
		narg--         /* do not count `self' */
		if narg == 0 { /* error is in the self argument itself? */
			return luaL_error(_L, "calling "+"'"+"%s"+"'"+" on bad self (%s)", ar.name, extramsg)
		}
	}

	if ar.name == "" {
		ar.name = "?"
	}
	return luaL_error(_L, "bad argument #%d to "+"'"+"%s"+"'"+" (%s)", narg, ar.name, extramsg)
}
