################################################################################
# File:		makefile
#
# Purpose:	Makefile for the Open-RJ project, for the Visual C++ v7.1
#           compiler, on Win32
#
# Created:	15th Feburary 2005
# Updated:	3rd March 2005
#
################################################################################


################################################################################
# Environment check
#

!ifndef STLSOFT_INCLUDE
!error STLSOFT_INCLUDE must be defined
!endif # STLSOFT_INCLUDE

!ifndef CH_EXTERN
!error CH_EXTERN must be defined
!endif # CH_EXTERN

!ifndef PYTHON_ROOT
!error PYTHON_ROOT must be defined
!endif # PYTHON_ROOT

################################################################################
# Symbols

# Identification

COMP_TAG			=	vc71
PROJ_TAG			=	openrj

CC					=	cl
CPPC				=	cl
CPPDNC				=	cl -clr
CSC					=	csc
AR					=	lib
LD					=	link
RM					=	del /f

# Directories

PROJ_BASE_DIR		=	..\..
PROJ_LIB_DIR		=	$(PROJ_BASE_DIR)\lib
PROJ_OBJ_DIR		=	.
PROJ_BIN_DIR		=	$(PROJ_BASE_DIR)\bin
PROJ_SRC_DIR		=	$(PROJ_BASE_DIR)\src
PROJ_INCLUDE_DIR	=	$(PROJ_BASE_DIR)\include
PROJ_MAPPINGS_DIR	=	$(PROJ_BASE_DIR)\mappings
PROJ_TEST_DIR		=	$(PROJ_BASE_DIR)\test

# Includes

INCLUDES_LEADER		=	

PROJ_INCLUDE		=	-I$(PROJ_INCLUDE_DIR)

COMMON_INCLUDES		=	

CC_INCLUDES = \
 $(INCLUDES_LEADER) \
 $(PROJ_INCLUDE) \
 $(COMMON_INCLUDES) \
 \

CPPC_INCLUDES = \
 $(INCLUDES_LEADER) \
 $(PROJ_INCLUDE) \
 $(COMMON_INCLUDES) \
 -I"$(STLSOFT_INCLUDE)" \
 -I"$(STLSOFT_INCLUDE)\inprogress" \
 \

CPPDNC_INCLUDES = \
 $(INCLUDES_LEADER) \
 $(PROJ_INCLUDE) \
 $(COMMON_INCLUDES) \
 -I"$(STLSOFT_INCLUDE)" \
 -I"$(STLSOFT_INCLUDE)\inprogress" \
 \

# Lib

LIBS_LEADER			=	

COMMON_LIB			=	

# #defines

COMMON_DEFS			=	-DWIN32

CC_DEFS				=	$(COMMON_DEFS)

CPPC_DEFS			=	$(COMMON_DEFS)

CPPDNC_DEFS			=	$(COMMON_DEFS)

# Flags

CC_F_NOLOGO				=	-nologo
CC_F_COMPILE_ONLY		=	-c
CC_F_WARNING_MAX		=	-W4
CC_F_WARNING_ERR		=	-WX

CPPC_F_NOLOGO		=	-nologo
CPPC_F_COMPILE_ONLY	=	-c
CPPC_F_WARNING_MAX	=	-W4
CPPC_F_WARNING_ERR	=	-WX
CPPC_F_EXCEPTIONS	=	-EHsc
CPPC_F_RTTI			=	-GR

CPPDNC_F_NOLOGO			=	-nologo
CPPDNC_F_COMPILE_ONLY	=	-c
CPPDNC_F_WARNING_MAX	=	-W4
CPPDNC_F_WARNING_ERR	=	-WX
CPPDNC_F_EXCEPTIONS		=	-EHsc
CPPDNC_F_RTTI			=	-GR

CSC_F_NOLOGO			=	-nologo
CSC_F_COMPILE_ONLY		=	
CSC_F_WARNING_MAX		=	-warn:4
CSC_F_WARNING_ERR		=	-warnaserror

CC_TOOL_FLAGS		=	

CC_FLAGS = \
 $(CC_TOOL_FLAGS) \
 $(CC_F_NOLOGO) \
 $(CC_F_COMPILE_ONLY) \
 $(CC_F_WARNING_MAX) \
 $(CC_F_WARNING_ERR)

CPPC_TOOL_FLAGS		=	

CPPC_FLAGS = \
 $(CPPC_TOOL_FLAGS) \
 $(CPPC_F_NOLOGO) \
 $(CPPC_F_COMPILE_ONLY) \
 $(CPPC_F_WARNING_MAX) \
 $(CPPC_F_WARNING_ERR) \
 $(CPPC_F_EXCEPTIONS) \
 $(CPPC_F_RTTI)

CPPDNC_TOOL_FLAGS		=	

CPPDNC_FLAGS = \
 $(CPPDNC_TOOL_FLAGS) \
 $(CPPDNC_F_NOLOGO) \
 $(CPPDNC_F_COMPILE_ONLY) \
 $(CPPDNC_F_WARNING_MAX) \
 $(CPPDNC_F_WARNING_ERR) \
 $(CPPDNC_F_EXCEPTIONS) \
 $(CPPDNC_F_RTTI)

CSC_TOOL_FLAGS		=	

CSC_FLAGS = \
 $(CSC_TOOL_FLAGS) \
 $(CSC_F_NOLOGO) \
 $(CSC_F_COMPILE_ONLY) \
 $(CSC_F_WARNING_MAX) \
 $(CSC_F_WARNING_ERR) \

# Arguments (= flags + defines + includes)

CC_ARGS_MT_DEBUG				=	-MTd -D_DEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_DLL_DEBUG				=	-MDd -D_DEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_DLL_RELEASE				=	-MD -DNDEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_MT_RELEASE				=	-MT -DNDEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_ST_DEBUG				=	-MLd -D_DEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_ST_RELEASE				=	-ML -DNDEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)

CPPC_ARGS_MT_DEBUG			=	-MTd -D_DEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)
CPPC_ARGS_DLL_DEBUG			=	-MDd -D_DEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)
CPPC_ARGS_DLL_RELEASE			=	-MD -DNDEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)
CPPC_ARGS_MT_RELEASE			=	-MT -DNDEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)
CPPC_ARGS_ST_DEBUG			=	-MLd -D_DEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)
CPPC_ARGS_ST_RELEASE			=	-ML -DNDEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)

CPPDNC_ARGS			=	 -MT $(CPPDNC_FLAGS) $(CPPDNC_DEFS) $(CPPDNC_INCLUDES)

CSC_ARGS			=	 $(CSC_FLAGS) $(CSC_DEFS) $(CSC_INCLUDES)

AR_ARGS				=	-nologo

LD_ARGS				=	-nologo $(COMMON_LIB)

################################################################################
# Targets

# libs
TARGET_LIB_MT_DEBUG			=	$(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).mt.debug.lib
TARGET_LIB_DLL_DEBUG			=	$(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).dll.debug.lib
TARGET_LIB_DLL_RELEASE			=	$(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).dll.lib
TARGET_LIB_MT_RELEASE			=	$(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).mt.lib
TARGET_LIB_ST_DEBUG			=	$(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).debug.lib
TARGET_LIB_ST_RELEASE			=	$(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).lib

TARGET_LIB_CPPDN		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).net.dll


# test programs
TARGET_TEST_C_MT_DEBUG		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.C.$(COMP_TAG).mt.debug.exe
TARGET_TEST_CPP_MT_DEBUG		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.Cpp.$(COMP_TAG).mt.debug.exe
TARGET_TEST_STL_MT_DEBUG		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.STL.$(COMP_TAG).mt.debug.exe
TARGET_TEST_C_DLL_DEBUG		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.C.$(COMP_TAG).dll.debug.exe
TARGET_TEST_CPP_DLL_DEBUG		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.Cpp.$(COMP_TAG).dll.debug.exe
TARGET_TEST_STL_DLL_DEBUG		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.STL.$(COMP_TAG).dll.debug.exe
TARGET_TEST_C_DLL_RELEASE		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.C.$(COMP_TAG).dll.exe
TARGET_TEST_CPP_DLL_RELEASE		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.Cpp.$(COMP_TAG).dll.exe
TARGET_TEST_STL_DLL_RELEASE		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.STL.$(COMP_TAG).dll.exe
TARGET_TEST_C_MT_RELEASE		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.C.$(COMP_TAG).mt.exe
TARGET_TEST_CPP_MT_RELEASE		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.Cpp.$(COMP_TAG).mt.exe
TARGET_TEST_STL_MT_RELEASE		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.STL.$(COMP_TAG).mt.exe
TARGET_TEST_C_ST_DEBUG		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.C.$(COMP_TAG).debug.exe
TARGET_TEST_CPP_ST_DEBUG		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.Cpp.$(COMP_TAG).debug.exe
TARGET_TEST_STL_ST_DEBUG		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.STL.$(COMP_TAG).debug.exe
TARGET_TEST_C_ST_RELEASE		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.C.$(COMP_TAG).exe
TARGET_TEST_CPP_ST_RELEASE		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.Cpp.$(COMP_TAG).exe
TARGET_TEST_STL_ST_RELEASE		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.STL.$(COMP_TAG).exe

TARGET_TEST_CPPDN		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.NET.exe

TARGETS = \
 $(TARGET_LIB_MT_DEBUG) \
 $(TARGET_LIB_DLL_DEBUG) \
 $(TARGET_LIB_DLL_RELEASE) \
 $(TARGET_LIB_MT_RELEASE) \
 $(TARGET_LIB_ST_DEBUG) \
 $(TARGET_LIB_ST_RELEASE) \
 $(TARGET_LIB_CPPDN) \
 $(TARGET_TEST_C_MT_DEBUG) \
 $(TARGET_TEST_C_DLL_DEBUG) \
 $(TARGET_TEST_C_DLL_RELEASE) \
 $(TARGET_TEST_C_MT_RELEASE) \
 $(TARGET_TEST_C_ST_DEBUG) \
 $(TARGET_TEST_C_ST_RELEASE) \
 $(TARGET_TEST_CPP_MT_DEBUG) \
 $(TARGET_TEST_CPP_DLL_DEBUG) \
 $(TARGET_TEST_CPP_DLL_RELEASE) \
 $(TARGET_TEST_CPP_MT_RELEASE) \
 $(TARGET_TEST_CPP_ST_DEBUG) \
 $(TARGET_TEST_CPP_ST_RELEASE) \
 $(TARGET_TEST_STL_MT_DEBUG) \
 $(TARGET_TEST_STL_DLL_DEBUG) \
 $(TARGET_TEST_STL_DLL_RELEASE) \
 $(TARGET_TEST_STL_MT_RELEASE) \
 $(TARGET_TEST_STL_ST_DEBUG) \
 $(TARGET_TEST_STL_ST_RELEASE) \
 $(TARGET_TEST_CPPDN) \
 \

# objects

# for libs

OBJ_PROJ_orjapi__MT_DEBUG = $(PROJ_OBJ_DIR)\orjapi.mt.debug.obj
OBJ_PROJ_orjmem__MT_DEBUG = $(PROJ_OBJ_DIR)\orjmem.mt.debug.obj
OBJ_PROJ_orjstr__MT_DEBUG = $(PROJ_OBJ_DIR)\orjstr.mt.debug.obj

OBJ_PROJ_MT_DEBUG = \
 $(OBJ_PROJ_orjapi__MT_DEBUG) \
 $(OBJ_PROJ_orjmem__MT_DEBUG) \
 $(OBJ_PROJ_orjstr__MT_DEBUG) \
 \

OBJ_PROJ_orjapi__DLL_DEBUG = $(PROJ_OBJ_DIR)\orjapi.dll.debug.obj
OBJ_PROJ_orjmem__DLL_DEBUG = $(PROJ_OBJ_DIR)\orjmem.dll.debug.obj
OBJ_PROJ_orjstr__DLL_DEBUG = $(PROJ_OBJ_DIR)\orjstr.dll.debug.obj

OBJ_PROJ_DLL_DEBUG = \
 $(OBJ_PROJ_orjapi__DLL_DEBUG) \
 $(OBJ_PROJ_orjmem__DLL_DEBUG) \
 $(OBJ_PROJ_orjstr__DLL_DEBUG) \
 \

OBJ_PROJ_orjapi__DLL_RELEASE = $(PROJ_OBJ_DIR)\orjapi.dll.obj
OBJ_PROJ_orjmem__DLL_RELEASE = $(PROJ_OBJ_DIR)\orjmem.dll.obj
OBJ_PROJ_orjstr__DLL_RELEASE = $(PROJ_OBJ_DIR)\orjstr.dll.obj

OBJ_PROJ_DLL_RELEASE = \
 $(OBJ_PROJ_orjapi__DLL_RELEASE) \
 $(OBJ_PROJ_orjmem__DLL_RELEASE) \
 $(OBJ_PROJ_orjstr__DLL_RELEASE) \
 \

OBJ_PROJ_orjapi__MT_RELEASE = $(PROJ_OBJ_DIR)\orjapi.mt.obj
OBJ_PROJ_orjmem__MT_RELEASE = $(PROJ_OBJ_DIR)\orjmem.mt.obj
OBJ_PROJ_orjstr__MT_RELEASE = $(PROJ_OBJ_DIR)\orjstr.mt.obj

OBJ_PROJ_MT_RELEASE = \
 $(OBJ_PROJ_orjapi__MT_RELEASE) \
 $(OBJ_PROJ_orjmem__MT_RELEASE) \
 $(OBJ_PROJ_orjstr__MT_RELEASE) \
 \

OBJ_PROJ_orjapi__ST_DEBUG = $(PROJ_OBJ_DIR)\orjapi.debug.obj
OBJ_PROJ_orjmem__ST_DEBUG = $(PROJ_OBJ_DIR)\orjmem.debug.obj
OBJ_PROJ_orjstr__ST_DEBUG = $(PROJ_OBJ_DIR)\orjstr.debug.obj

OBJ_PROJ_ST_DEBUG = \
 $(OBJ_PROJ_orjapi__ST_DEBUG) \
 $(OBJ_PROJ_orjmem__ST_DEBUG) \
 $(OBJ_PROJ_orjstr__ST_DEBUG) \
 \

OBJ_PROJ_orjapi__ST_RELEASE = $(PROJ_OBJ_DIR)\orjapi.obj
OBJ_PROJ_orjmem__ST_RELEASE = $(PROJ_OBJ_DIR)\orjmem.obj
OBJ_PROJ_orjstr__ST_RELEASE = $(PROJ_OBJ_DIR)\orjstr.obj

OBJ_PROJ_ST_RELEASE = \
 $(OBJ_PROJ_orjapi__ST_RELEASE) \
 $(OBJ_PROJ_orjmem__ST_RELEASE) \
 $(OBJ_PROJ_orjstr__ST_RELEASE) \
 \


LIB_OBJS = \
 $(OBJ_PROJ_MT_DEBUG) \
 $(OBJ_PROJ_DLL_DEBUG) \
 $(OBJ_PROJ_DLL_RELEASE) \
 $(OBJ_PROJ_MT_RELEASE) \
 $(OBJ_PROJ_ST_DEBUG) \
 $(OBJ_PROJ_ST_RELEASE) \
 \

OBJ_CPPDN = \
 .\AssemblyInfo.net.obj \
 .\Database.net.obj \
 .\Field.net.obj \
 .\FileDatabase.net.obj \
 .\MemoryDatabase.net.obj \
 .\OpenRJException.net.obj \
 .\OpenRJUtil.net.obj \
 .\Record.net.obj \
 \


# for test programs

OBJ_C_MT_DEBUG					=	.\C.mt.debug.obj
OBJ_CPP_MT_DEBUG				=	.\Cpp.mt.debug.obj
OBJ_STL_MT_DEBUG				=	.\STL.mt.debug.obj
OBJ_C_DLL_DEBUG					=	.\C.dll.debug.obj
OBJ_CPP_DLL_DEBUG				=	.\Cpp.dll.debug.obj
OBJ_STL_DLL_DEBUG				=	.\STL.dll.debug.obj
OBJ_C_DLL_RELEASE					=	.\C.dll.obj
OBJ_CPP_DLL_RELEASE				=	.\Cpp.dll.obj
OBJ_STL_DLL_RELEASE				=	.\STL.dll.obj
OBJ_C_MT_RELEASE					=	.\C.mt.obj
OBJ_CPP_MT_RELEASE				=	.\Cpp.mt.obj
OBJ_STL_MT_RELEASE				=	.\STL.mt.obj
OBJ_C_ST_DEBUG					=	.\C.debug.obj
OBJ_CPP_ST_DEBUG				=	.\Cpp.debug.obj
OBJ_STL_ST_DEBUG				=	.\STL.debug.obj
OBJ_C_ST_RELEASE					=	.\C.obj
OBJ_CPP_ST_RELEASE				=	.\Cpp.obj
OBJ_STL_ST_RELEASE				=	.\STL.obj

TEST_OBJS = \
 $(OBJ_C_MT_DEBUG) \
 $(OBJ_C_DLL_DEBUG) \
 $(OBJ_C_DLL_RELEASE) \
 $(OBJ_C_MT_RELEASE) \
 $(OBJ_C_ST_DEBUG) \
 $(OBJ_C_ST_RELEASE) \
 $(OBJ_CPP_MT_DEBUG) \
 $(OBJ_CPP_DLL_DEBUG) \
 $(OBJ_CPP_DLL_RELEASE) \
 $(OBJ_CPP_MT_RELEASE) \
 $(OBJ_CPP_ST_DEBUG) \
 $(OBJ_CPP_ST_RELEASE) \
 $(OBJ_STL_MT_DEBUG) \
 $(OBJ_STL_DLL_DEBUG) \
 $(OBJ_STL_DLL_RELEASE) \
 $(OBJ_STL_MT_RELEASE) \
 $(OBJ_STL_ST_DEBUG) \
 $(OBJ_STL_ST_RELEASE) \
 \


LIB_HEADERS	= \
 $(PROJ_INCLUDE_DIR)\openrj\openrj.h \
 $(PROJ_INCLUDE_DIR)\openrj\openrj_assert.h \
 $(PROJ_INCLUDE_DIR)\openrj\openrj_memory.h \
 \

TEST_C_HEADERS = \
 $(LIB_HEADERS) \
 \

TEST_CPP_HEADERS = \
 $(LIB_HEADERS) \
 $(PROJ_INCLUDE_DIR)\openrj\cpp\openrj.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\cpp\database.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\cpp\field.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\cpp\record.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\cpp\openrjfwd.hpp \
 \

TEST_STL_HEADERS = \
 $(LIB_HEADERS) \
 $(PROJ_INCLUDE_DIR)\openrj\stl\openrj.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\stl\database.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\stl\field.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\stl\record.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\stl\openrjfwd.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\stl\functional.hpp \
 $(PROJ_INCLUDE_DIR)\openrj\stl\utility.hpp \
 \


target:		$(TARGETS)

compile:	$(LIB_OBJS) $(TEST_OBJS)

all: \
 ch \
 c++.net \
 python \
 target \
 \

usage:
	@echo "make [usage | clean | compile | all | test | target] - default is 'all'"

clean:
	@-$(RM) $(TARGET_LIB_MT_DEBUG)
	@-$(RM) $(TARGET_LIB_DLL_DEBUG)
	@-$(RM) $(TARGET_LIB_DLL_RELEASE)
	@-$(RM) $(TARGET_LIB_MT_RELEASE)
	@-$(RM) $(TARGET_LIB_ST_DEBUG)
	@-$(RM) $(TARGET_LIB_ST_RELEASE)
	@-$(RM) $(TARGET_LIB_CPPDN)
	@-$(RM) $(TARGET_TEST_C_MT_DEBUG)
	@-$(RM) $(TARGET_TEST_C_DLL_DEBUG)
	@-$(RM) $(TARGET_TEST_C_DLL_RELEASE)
	@-$(RM) $(TARGET_TEST_C_MT_RELEASE)
	@-$(RM) $(TARGET_TEST_C_ST_DEBUG)
	@-$(RM) $(TARGET_TEST_C_ST_RELEASE)
	@-$(RM) $(TARGET_TEST_CPP_MT_DEBUG)
	@-$(RM) $(TARGET_TEST_CPP_DLL_DEBUG)
	@-$(RM) $(TARGET_TEST_CPP_DLL_RELEASE)
	@-$(RM) $(TARGET_TEST_CPP_MT_RELEASE)
	@-$(RM) $(TARGET_TEST_CPP_ST_DEBUG)
	@-$(RM) $(TARGET_TEST_CPP_ST_RELEASE)
	@-$(RM) $(TARGET_TEST_STL_MT_DEBUG)
	@-$(RM) $(TARGET_TEST_STL_DLL_DEBUG)
	@-$(RM) $(TARGET_TEST_STL_DLL_RELEASE)
	@-$(RM) $(TARGET_TEST_STL_MT_RELEASE)
	@-$(RM) $(TARGET_TEST_STL_ST_DEBUG)
	@-$(RM) $(TARGET_TEST_STL_ST_RELEASE)
	@-$(RM) $(OBJ_PROJ_MT_DEBUG)
	@-$(RM) $(OBJ_PROJ_DLL_DEBUG)
	@-$(RM) $(OBJ_PROJ_DLL_RELEASE)
	@-$(RM) $(OBJ_PROJ_MT_RELEASE)
	@-$(RM) $(OBJ_PROJ_ST_DEBUG)
	@-$(RM) $(OBJ_PROJ_ST_RELEASE)
	@-$(RM) $(OBJ_C_MT_DEBUG)
	@-$(RM) $(OBJ_C_DLL_DEBUG)
	@-$(RM) $(OBJ_C_DLL_RELEASE)
	@-$(RM) $(OBJ_C_MT_RELEASE)
	@-$(RM) $(OBJ_C_ST_DEBUG)
	@-$(RM) $(OBJ_C_ST_RELEASE)
	@-$(RM) $(OBJ_CPP_MT_DEBUG)
	@-$(RM) $(OBJ_CPP_DLL_DEBUG)
	@-$(RM) $(OBJ_CPP_DLL_RELEASE)
	@-$(RM) $(OBJ_CPP_MT_RELEASE)
	@-$(RM) $(OBJ_CPP_ST_DEBUG)
	@-$(RM) $(OBJ_CPP_ST_RELEASE)
	@-$(RM) $(OBJ_STL_MT_DEBUG)
	@-$(RM) $(OBJ_STL_DLL_DEBUG)
	@-$(RM) $(OBJ_STL_DLL_RELEASE)
	@-$(RM) $(OBJ_STL_MT_RELEASE)
	@-$(RM) $(OBJ_STL_ST_DEBUG)
	@-$(RM) $(OBJ_STL_ST_RELEASE)
	@-$(RM) $(TARGET_TEST_CPPDN)
	@-$(RM) $(OBJ_CH)
	@-$(RM) $(TARGET_CH_SHARED_LIB)
	@-$(RM) $(OBJ_PYTHON)
	@-$(RM) $(TARGET_PYTHON_SHARED_LIB)
	@-$(RM) $(TARGET_RUBY_SHARED_LIB)

test_:
	$(TARGET_TEST_C_MT_DEBUG) --unittest
	$(TARGET_TEST_C_DLL_DEBUG) --unittest
	$(TARGET_TEST_C_DLL_RELEASE) --unittest
	$(TARGET_TEST_C_MT_RELEASE) --unittest
	$(TARGET_TEST_C_ST_DEBUG) --unittest
	$(TARGET_TEST_C_ST_RELEASE) --unittest
	$(TARGET_TEST_CPP_MT_DEBUG) --unittest
	$(TARGET_TEST_CPP_DLL_DEBUG) --unittest
	$(TARGET_TEST_CPP_DLL_RELEASE) --unittest
	$(TARGET_TEST_CPP_MT_RELEASE) --unittest
	$(TARGET_TEST_CPP_ST_DEBUG) --unittest
	$(TARGET_TEST_CPP_ST_RELEASE) --unittest
	$(TARGET_TEST_STL_MT_DEBUG) --unittest
	$(TARGET_TEST_STL_DLL_DEBUG) --unittest
	$(TARGET_TEST_STL_DLL_RELEASE) --unittest
	$(TARGET_TEST_STL_MT_RELEASE) --unittest
	$(TARGET_TEST_STL_ST_DEBUG) --unittest
	$(TARGET_TEST_STL_ST_RELEASE) --unittest
	$(TARGET_TEST_CPPDN) --unittest

test:	target test_

# Ch parts

PROJ_CH_DIR					=	$(PROJ_MAPPINGS_DIR)\ch

SRC_CH_C					=	$(PROJ_CH_DIR)\libopenrjch.c
OBJ_CH						=	$(PROJ_CH_DIR)\libopenrj.obj
TARGET_CH_SHARED_LIB		=	$(PROJ_CH_DIR)\$(PROJ_TAG).dll

CH_CC						=	$(CC)
CH_AR						=	$(AR)
CH_LD						=	$(LD)

CH_CC_FLAGS					=	$(CC_FLAGS) -MD
CH_CC_DEFS					=	$(CC_DEFS)
CH_CC_INCLUDES				=	$(CC_INCLUDES) -I$(CH_EXTERN)\include
CH_LD_LIB					=	-libpath:$(CH_EXTERN)\lib
CH_CC_ARGS					=	$(CH_CC_FLAGS) $(CH_CC_DEFS) $(CH_CC_INCLUDES)
CH_LD_ARGS					=	$(LD_ARGS) $(CH_LD_LIB) -dll  ch.lib chsdk.lib advapi32.lib


$(OBJ_CH):	$(SRC_CH_C) makefile
	$(CH_CC) $(CH_CC_ARGS) -Fo$@ $(SRC_CH_C)

$(TARGET_CH_SHARED_LIB):	$(OBJ_CH) $(TARGET_LIB_DLL_RELEASE) makefile
	$(CH_LD) $(CH_LD_ARGS) -out:$@ $(OBJ_CH) $(TARGET_LIB_DLL_RELEASE)

ch:	$(TARGET_CH_SHARED_LIB)

ch-test:	ch
	cd $(PROJ_CH_DIR)
	ch $(PROJ_CH_DIR)\test.ch

# Python parts

PROJ_PYTHON_DIR				=	$(PROJ_MAPPINGS_DIR)\python

SRC_PYTHON_C				=	$(PROJ_PYTHON_DIR)\$(PROJ_TAG)_python.c
SRC_PYTHON_DEF				=	$(PROJ_PYTHON_DIR)\$(PROJ_TAG)_python.def
OBJ_PYTHON					=	$(PROJ_PYTHON_DIR)\$(PROJ_TAG)_python.obj
TARGET_PYTHON_SHARED_LIB	=	$(PROJ_PYTHON_DIR)\$(PROJ_TAG).dll

PYTHON_CC					=	$(CC)
PYTHON_AR					=	$(AR)
PYTHON_LD					=	$(LD)

PYTHON_CC_FLAGS				=	$(CC_FLAGS)
PYTHON_CC_DEFS				=	$(CC_DEFS)
PYTHON_CC_INCLUDES			=	$(CC_INCLUDES) -I$(PYTHON_ROOT)\include
PYTHON_LD_LIB				=	-libpath:$(PYTHON_ROOT)\libs
PYTHON_CC_ARGS				=	$(PYTHON_CC_FLAGS) $(PYTHON_CC_DEFS) $(PYTHON_CC_INCLUDES)
PYTHON_LD_ARGS				=	$(LD_ARGS) $(PYTHON_LD_LIB) -dll -def:$(SRC_PYTHON_DEF)


$(OBJ_PYTHON):	$(SRC_PYTHON_C) makefile
	$(PYTHON_CC) $(PYTHON_CC_ARGS) -Fo$@ $(SRC_PYTHON_C)

$(TARGET_PYTHON_SHARED_LIB):	$(OBJ_PYTHON) $(TARGET_LIB_ST_RELEASE) makefile
	$(PYTHON_LD) $(PYTHON_LD_ARGS) -out:$@ $(OBJ_PYTHON) $(TARGET_LIB_ST_RELEASE)

python:	$(TARGET_PYTHON_SHARED_LIB)

python-test:	python
	cd $(PROJ_PYTHON_DIR)
	python $(PROJ_PYTHON_DIR)\test.py

# Ruby parts

TARGET_RUBY_SHARED_LIB	=	$(PROJ_MAPPINGS_DIR)\ruby\$(PROJ_TAG).so

$(TARGET_RUBY_SHARED_LIB):	$(PROJ_MAPPINGS_DIR)\ruby\openrj_ruby.c makefile
	@if not exist .\ruby-cc\NUL mkdir $(RUBY_BIN)
	cd .\ruby-cc
	ruby $(PROJ_MAPPINGS_DIR)\ruby\extconf.rb --with-openrj-dir=$(PROJ_BASE_DIR)
	cd ..
	make -f .\ruby-cc\Makefile
	move $(PROJ_TAG).so $(TARGET_RUBY_SHARED_LIB)

ruby:	$(TARGET_RUBY_SHARED_LIB)

ruby-test:	ruby
	ruby $(PROJ_MAPPINGS_DIR)\ruby\test.rb --unittest



# build targets

# library

$(TARGET_LIB_MT_DEBUG): $(OBJ_PROJ_MT_DEBUG) makefile
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_PROJ_MT_DEBUG)

$(OBJ_PROJ_orjapi__MT_DEBUG): $(PROJ_SRC_DIR)\orjapi.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_MT_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\orjapi.c
$(OBJ_PROJ_orjmem__MT_DEBUG): $(PROJ_SRC_DIR)\orjmem.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_MT_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\orjmem.c
$(OBJ_PROJ_orjstr__MT_DEBUG): $(PROJ_SRC_DIR)\orjstr.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_MT_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\orjstr.c

$(TARGET_LIB_DLL_DEBUG): $(OBJ_PROJ_DLL_DEBUG) makefile
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_PROJ_DLL_DEBUG)

$(OBJ_PROJ_orjapi__DLL_DEBUG): $(PROJ_SRC_DIR)\orjapi.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_DLL_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\orjapi.c
$(OBJ_PROJ_orjmem__DLL_DEBUG): $(PROJ_SRC_DIR)\orjmem.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_DLL_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\orjmem.c
$(OBJ_PROJ_orjstr__DLL_DEBUG): $(PROJ_SRC_DIR)\orjstr.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_DLL_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\orjstr.c

$(TARGET_LIB_DLL_RELEASE): $(OBJ_PROJ_DLL_RELEASE) makefile
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_PROJ_DLL_RELEASE)

$(OBJ_PROJ_orjapi__DLL_RELEASE): $(PROJ_SRC_DIR)\orjapi.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_DLL_RELEASE) -Fo$@ $(PROJ_SRC_DIR)\orjapi.c
$(OBJ_PROJ_orjmem__DLL_RELEASE): $(PROJ_SRC_DIR)\orjmem.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_DLL_RELEASE) -Fo$@ $(PROJ_SRC_DIR)\orjmem.c
$(OBJ_PROJ_orjstr__DLL_RELEASE): $(PROJ_SRC_DIR)\orjstr.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_DLL_RELEASE) -Fo$@ $(PROJ_SRC_DIR)\orjstr.c

$(TARGET_LIB_MT_RELEASE): $(OBJ_PROJ_MT_RELEASE) makefile
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_PROJ_MT_RELEASE)

$(OBJ_PROJ_orjapi__MT_RELEASE): $(PROJ_SRC_DIR)\orjapi.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_MT_RELEASE) -Fo$@ $(PROJ_SRC_DIR)\orjapi.c
$(OBJ_PROJ_orjmem__MT_RELEASE): $(PROJ_SRC_DIR)\orjmem.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_MT_RELEASE) -Fo$@ $(PROJ_SRC_DIR)\orjmem.c
$(OBJ_PROJ_orjstr__MT_RELEASE): $(PROJ_SRC_DIR)\orjstr.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_MT_RELEASE) -Fo$@ $(PROJ_SRC_DIR)\orjstr.c

$(TARGET_LIB_ST_DEBUG): $(OBJ_PROJ_ST_DEBUG) makefile
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_PROJ_ST_DEBUG)

$(OBJ_PROJ_orjapi__ST_DEBUG): $(PROJ_SRC_DIR)\orjapi.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_ST_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\orjapi.c
$(OBJ_PROJ_orjmem__ST_DEBUG): $(PROJ_SRC_DIR)\orjmem.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_ST_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\orjmem.c
$(OBJ_PROJ_orjstr__ST_DEBUG): $(PROJ_SRC_DIR)\orjstr.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_ST_DEBUG) -Fo$@ $(PROJ_SRC_DIR)\orjstr.c

$(TARGET_LIB_ST_RELEASE): $(OBJ_PROJ_ST_RELEASE) makefile
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) -out:$@ $(OBJ_PROJ_ST_RELEASE)

$(OBJ_PROJ_orjapi__ST_RELEASE): $(PROJ_SRC_DIR)\orjapi.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_ST_RELEASE) -Fo$@ $(PROJ_SRC_DIR)\orjapi.c
$(OBJ_PROJ_orjmem__ST_RELEASE): $(PROJ_SRC_DIR)\orjmem.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_ST_RELEASE) -Fo$@ $(PROJ_SRC_DIR)\orjmem.c
$(OBJ_PROJ_orjstr__ST_RELEASE): $(PROJ_SRC_DIR)\orjstr.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_ST_RELEASE) -Fo$@ $(PROJ_SRC_DIR)\orjstr.c

$(TARGET_LIB_CPPDN): $(OBJ_CPPDN) $(TARGET_LIB_MT_RELEASE) makefile
	$(LD) -nologo -dll -out:$@ $(OBJ_CPPDN) $(TARGET_LIB_MT_RELEASE) user32.lib kernel32.lib $(TARGET_LIB_DLL) /NOENTRY msvcrt.lib /NODEFAULTLIB:nochkclr.obj /INCLUDE:__DllMainCRTStartup@12

.\AssemblyInfo.net.obj:		$(PROJ_MAPPINGS_DIR)\C++.NET\AssemblyInfo.cpp $(PROJ_MAPPINGS_DIR)\C++.NET\OpenRJ.h makefile
	$(CPPDNC) $(CPPDNC_ARGS) -Fo$@ $(PROJ_MAPPINGS_DIR)\C++.NET\AssemblyInfo.cpp
.\Database.net.obj:			$(PROJ_MAPPINGS_DIR)\C++.NET\Database.cpp $(PROJ_MAPPINGS_DIR)\C++.NET\Database.h $(PROJ_MAPPINGS_DIR)\C++.NET\OpenRJ.h makefile
	$(CPPDNC) $(CPPDNC_ARGS) -Fo$@ $(PROJ_MAPPINGS_DIR)\C++.NET\Database.cpp
.\Field.net.obj:			$(PROJ_MAPPINGS_DIR)\C++.NET\Field.cpp $(PROJ_MAPPINGS_DIR)\C++.NET\Field.h $(PROJ_MAPPINGS_DIR)\C++.NET\OpenRJ.h makefile
	$(CPPDNC) $(CPPDNC_ARGS) -Fo$@ $(PROJ_MAPPINGS_DIR)\C++.NET\Field.cpp
.\FileDatabase.net.obj:			$(PROJ_MAPPINGS_DIR)\C++.NET\FileDatabase.cpp $(PROJ_MAPPINGS_DIR)\C++.NET\FileDatabase.h $(PROJ_MAPPINGS_DIR)\C++.NET\OpenRJ.h makefile
	$(CPPDNC) $(CPPDNC_ARGS) -Fo$@ $(PROJ_MAPPINGS_DIR)\C++.NET\FileDatabase.cpp
.\MemoryDatabase.net.obj:			$(PROJ_MAPPINGS_DIR)\C++.NET\MemoryDatabase.cpp $(PROJ_MAPPINGS_DIR)\C++.NET\MemoryDatabase.h $(PROJ_MAPPINGS_DIR)\C++.NET\OpenRJ.h makefile
	$(CPPDNC) $(CPPDNC_ARGS) -Fo$@ $(PROJ_MAPPINGS_DIR)\C++.NET\MemoryDatabase.cpp
.\OpenRJException.net.obj:	$(PROJ_MAPPINGS_DIR)\C++.NET\OpenRJException.cpp $(PROJ_MAPPINGS_DIR)\C++.NET\OpenRJException.h $(PROJ_MAPPINGS_DIR)\C++.NET\OpenRJ.h makefile
	$(CPPDNC) $(CPPDNC_ARGS) -Fo$@ $(PROJ_MAPPINGS_DIR)\C++.NET\OpenRJException.cpp
.\Record.net.obj:			$(PROJ_MAPPINGS_DIR)\C++.NET\Record.cpp $(PROJ_MAPPINGS_DIR)\C++.NET\Record.cpp $(PROJ_MAPPINGS_DIR)\C++.NET\Record.h $(PROJ_MAPPINGS_DIR)\C++.NET\OpenRJ.h makefile
	$(CPPDNC) $(CPPDNC_ARGS) -Fo$@ $(PROJ_MAPPINGS_DIR)\C++.NET\Record.cpp
.\OpenRJUtil.net.obj:	$(PROJ_MAPPINGS_DIR)\C++.NET\OpenRJUtil.cpp $(PROJ_MAPPINGS_DIR)\C++.NET\OpenRJUtil.h $(PROJ_MAPPINGS_DIR)\C++.NET\OpenRJ.h makefile
	$(CPPDNC) $(CPPDNC_ARGS) -Fo$@ $(PROJ_MAPPINGS_DIR)\C++.NET\OpenRJUtil.cpp


# C test client

$(TARGET_TEST_C_MT_DEBUG):	$(OBJ_C_MT_DEBUG) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -out:$@ $(OBJ_C_MT_DEBUG) $(TARGET_LIB_MT_DEBUG)


$(OBJ_C_MT_DEBUG):	$(PROJ_TEST_DIR)\C\C.c $(TEST_C_HEADERS) makefile
	$(CC) $(CC_ARGS_MT_DEBUG) -Fo$@ $(PROJ_TEST_DIR)\C\C.c

$(TARGET_TEST_C_DLL_DEBUG):	$(OBJ_C_DLL_DEBUG) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -out:$@ $(OBJ_C_DLL_DEBUG) $(TARGET_LIB_DLL_DEBUG)


$(OBJ_C_DLL_DEBUG):	$(PROJ_TEST_DIR)\C\C.c $(TEST_C_HEADERS) makefile
	$(CC) $(CC_ARGS_DLL_DEBUG) -Fo$@ $(PROJ_TEST_DIR)\C\C.c

$(TARGET_TEST_C_DLL_RELEASE):	$(OBJ_C_DLL_RELEASE) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -out:$@ $(OBJ_C_DLL_RELEASE) $(TARGET_LIB_DLL_RELEASE)


$(OBJ_C_DLL_RELEASE):	$(PROJ_TEST_DIR)\C\C.c $(TEST_C_HEADERS) makefile
	$(CC) $(CC_ARGS_DLL_RELEASE) -Fo$@ $(PROJ_TEST_DIR)\C\C.c

$(TARGET_TEST_C_MT_RELEASE):	$(OBJ_C_MT_RELEASE) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -out:$@ $(OBJ_C_MT_RELEASE) $(TARGET_LIB_MT_RELEASE)


$(OBJ_C_MT_RELEASE):	$(PROJ_TEST_DIR)\C\C.c $(TEST_C_HEADERS) makefile
	$(CC) $(CC_ARGS_MT_RELEASE) -Fo$@ $(PROJ_TEST_DIR)\C\C.c

$(TARGET_TEST_C_ST_DEBUG):	$(OBJ_C_ST_DEBUG) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -out:$@ $(OBJ_C_ST_DEBUG) $(TARGET_LIB_ST_DEBUG)


$(OBJ_C_ST_DEBUG):	$(PROJ_TEST_DIR)\C\C.c $(TEST_C_HEADERS) makefile
	$(CC) $(CC_ARGS_ST_DEBUG) -Fo$@ $(PROJ_TEST_DIR)\C\C.c

$(TARGET_TEST_C_ST_RELEASE):	$(OBJ_C_ST_RELEASE) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -out:$@ $(OBJ_C_ST_RELEASE) $(TARGET_LIB_ST_RELEASE)


$(OBJ_C_ST_RELEASE):	$(PROJ_TEST_DIR)\C\C.c $(TEST_C_HEADERS) makefile
	$(CC) $(CC_ARGS_ST_RELEASE) -Fo$@ $(PROJ_TEST_DIR)\C\C.c



# C++ test client

$(TARGET_TEST_CPP_MT_DEBUG):	$(OBJ_CPP_MT_DEBUG) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -out:$@ $(OBJ_CPP_MT_DEBUG) $(TARGET_LIB_MT_DEBUG)

$(OBJ_CPP_MT_DEBUG):	$(PROJ_TEST_DIR)\Cpp\Cpp.cpp $(TEST_CPP_HEADERS) $(SRC_PROJ_HPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_DEBUG) -Fo$@ $(PROJ_TEST_DIR)\Cpp\Cpp.cpp

$(TARGET_TEST_CPP_DLL_DEBUG):	$(OBJ_CPP_DLL_DEBUG) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -out:$@ $(OBJ_CPP_DLL_DEBUG) $(TARGET_LIB_DLL_DEBUG)

$(OBJ_CPP_DLL_DEBUG):	$(PROJ_TEST_DIR)\Cpp\Cpp.cpp $(TEST_CPP_HEADERS) $(SRC_PROJ_HPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_DEBUG) -Fo$@ $(PROJ_TEST_DIR)\Cpp\Cpp.cpp

$(TARGET_TEST_CPP_DLL_RELEASE):	$(OBJ_CPP_DLL_RELEASE) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -out:$@ $(OBJ_CPP_DLL_RELEASE) $(TARGET_LIB_DLL_RELEASE)

$(OBJ_CPP_DLL_RELEASE):	$(PROJ_TEST_DIR)\Cpp\Cpp.cpp $(TEST_CPP_HEADERS) $(SRC_PROJ_HPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_RELEASE) -Fo$@ $(PROJ_TEST_DIR)\Cpp\Cpp.cpp

$(TARGET_TEST_CPP_MT_RELEASE):	$(OBJ_CPP_MT_RELEASE) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -out:$@ $(OBJ_CPP_MT_RELEASE) $(TARGET_LIB_MT_RELEASE)

$(OBJ_CPP_MT_RELEASE):	$(PROJ_TEST_DIR)\Cpp\Cpp.cpp $(TEST_CPP_HEADERS) $(SRC_PROJ_HPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_RELEASE) -Fo$@ $(PROJ_TEST_DIR)\Cpp\Cpp.cpp

$(TARGET_TEST_CPP_ST_DEBUG):	$(OBJ_CPP_ST_DEBUG) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -out:$@ $(OBJ_CPP_ST_DEBUG) $(TARGET_LIB_ST_DEBUG)

$(OBJ_CPP_ST_DEBUG):	$(PROJ_TEST_DIR)\Cpp\Cpp.cpp $(TEST_CPP_HEADERS) $(SRC_PROJ_HPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_DEBUG) -Fo$@ $(PROJ_TEST_DIR)\Cpp\Cpp.cpp

$(TARGET_TEST_CPP_ST_RELEASE):	$(OBJ_CPP_ST_RELEASE) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -out:$@ $(OBJ_CPP_ST_RELEASE) $(TARGET_LIB_ST_RELEASE)

$(OBJ_CPP_ST_RELEASE):	$(PROJ_TEST_DIR)\Cpp\Cpp.cpp $(TEST_CPP_HEADERS) $(SRC_PROJ_HPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_RELEASE) -Fo$@ $(PROJ_TEST_DIR)\Cpp\Cpp.cpp



# STL test client

$(TARGET_TEST_STL_MT_DEBUG):	$(OBJ_STL_MT_DEBUG) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -out:$@ $(OBJ_STL_MT_DEBUG) $(TARGET_LIB_MT_DEBUG)

$(OBJ_STL_MT_DEBUG):	$(PROJ_TEST_DIR)\STL\STL.cpp $(TEST_STL_HEADERS) $(SRC_PROJ_HPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_DEBUG) -Fo$@ $(PROJ_TEST_DIR)\STL\STL.cpp

$(TARGET_TEST_STL_DLL_DEBUG):	$(OBJ_STL_DLL_DEBUG) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -out:$@ $(OBJ_STL_DLL_DEBUG) $(TARGET_LIB_DLL_DEBUG)

$(OBJ_STL_DLL_DEBUG):	$(PROJ_TEST_DIR)\STL\STL.cpp $(TEST_STL_HEADERS) $(SRC_PROJ_HPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_DEBUG) -Fo$@ $(PROJ_TEST_DIR)\STL\STL.cpp

$(TARGET_TEST_STL_DLL_RELEASE):	$(OBJ_STL_DLL_RELEASE) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -out:$@ $(OBJ_STL_DLL_RELEASE) $(TARGET_LIB_DLL_RELEASE)

$(OBJ_STL_DLL_RELEASE):	$(PROJ_TEST_DIR)\STL\STL.cpp $(TEST_STL_HEADERS) $(SRC_PROJ_HPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL_RELEASE) -Fo$@ $(PROJ_TEST_DIR)\STL\STL.cpp

$(TARGET_TEST_STL_MT_RELEASE):	$(OBJ_STL_MT_RELEASE) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -out:$@ $(OBJ_STL_MT_RELEASE) $(TARGET_LIB_MT_RELEASE)

$(OBJ_STL_MT_RELEASE):	$(PROJ_TEST_DIR)\STL\STL.cpp $(TEST_STL_HEADERS) $(SRC_PROJ_HPP) makefile
	$(CPPC) $(CPPC_ARGS_MT_RELEASE) -Fo$@ $(PROJ_TEST_DIR)\STL\STL.cpp

$(TARGET_TEST_STL_ST_DEBUG):	$(OBJ_STL_ST_DEBUG) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -out:$@ $(OBJ_STL_ST_DEBUG) $(TARGET_LIB_ST_DEBUG)

$(OBJ_STL_ST_DEBUG):	$(PROJ_TEST_DIR)\STL\STL.cpp $(TEST_STL_HEADERS) $(SRC_PROJ_HPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_DEBUG) -Fo$@ $(PROJ_TEST_DIR)\STL\STL.cpp

$(TARGET_TEST_STL_ST_RELEASE):	$(OBJ_STL_ST_RELEASE) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -out:$@ $(OBJ_STL_ST_RELEASE) $(TARGET_LIB_ST_RELEASE)

$(OBJ_STL_ST_RELEASE):	$(PROJ_TEST_DIR)\STL\STL.cpp $(TEST_STL_HEADERS) $(SRC_PROJ_HPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_RELEASE) -Fo$@ $(PROJ_TEST_DIR)\STL\STL.cpp



# .NET test client

$(TARGET_TEST_CPPDN): $(TARGET_LIB_CPPDN) $(PROJ_TEST_DIR)\dotNET\OpenRJTest.cs makefile
	$(CSC) $(CSC_ARGS) -out:$@ -target:exe -reference:$(TARGET_LIB_CPPDN) $(PROJ_TEST_DIR)\dotNET\OpenRJTest.cs

c++.net:	$(TARGET_TEST_CPPDN)

################################################################################
