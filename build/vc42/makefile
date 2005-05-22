################################################################################
# File:		makefile
#
# Purpose:	Makefile for the Open-RJ project, for the Visual C++ v4.2
#           compiler, on Win32
#
# Created:	15th Feburary 2005
# Updated:	26th March 2005
#
################################################################################


################################################################################
# Environment check
#


################################################################################
# Symbols

# Identification

COMP_TAG			=	vc42
PROJ_TAG			=	openrj

CC					=	cl
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

# Lib

LIBS_LEADER			=	

COMMON_LIB			=	

# #defines

COMMON_DEFS			=	-DWIN32

CC_DEFS				=	$(COMMON_DEFS)

# Flags

CC_F_NOLOGO				=	-nologo
CC_F_COMPILE_ONLY		=	-c
CC_F_WARNING_MAX		=	-W4
CC_F_WARNING_ERR		=	-WX

CC_TOOL_FLAGS		=	

CC_FLAGS = \
 $(CC_TOOL_FLAGS) \
 $(CC_F_NOLOGO) \
 $(CC_F_COMPILE_ONLY) \
 $(CC_F_WARNING_MAX) \
 $(CC_F_WARNING_ERR)

# Arguments (= flags + defines + includes)

CC_ARGS_MT_DEBUG				=	-MTd -D_DEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_DLL_DEBUG				=	-MDd -D_DEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_DLL_RELEASE				=	-MD -DNDEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_MT_RELEASE				=	-MT -DNDEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_ST_DEBUG				=	-MLd -D_DEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_ST_RELEASE				=	-ML -DNDEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)

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



# test programs
TARGET_TEST_C_MT_DEBUG		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.C.$(COMP_TAG).mt.debug.exe
TARGET_TEST_C_DLL_DEBUG		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.C.$(COMP_TAG).dll.debug.exe
TARGET_TEST_C_DLL_RELEASE		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.C.$(COMP_TAG).dll.exe
TARGET_TEST_C_MT_RELEASE		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.C.$(COMP_TAG).mt.exe
TARGET_TEST_C_ST_DEBUG		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.C.$(COMP_TAG).debug.exe
TARGET_TEST_C_ST_RELEASE		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.C.$(COMP_TAG).exe

TARGETS = \
 $(TARGET_LIB_MT_DEBUG) \
 $(TARGET_LIB_DLL_DEBUG) \
 $(TARGET_LIB_DLL_RELEASE) \
 $(TARGET_LIB_MT_RELEASE) \
 $(TARGET_LIB_ST_DEBUG) \
 $(TARGET_LIB_ST_RELEASE) \
 $(TARGET_TEST_C_MT_DEBUG) \
 $(TARGET_TEST_C_DLL_DEBUG) \
 $(TARGET_TEST_C_DLL_RELEASE) \
 $(TARGET_TEST_C_MT_RELEASE) \
 $(TARGET_TEST_C_ST_DEBUG) \
 $(TARGET_TEST_C_ST_RELEASE) \
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


# for test programs

OBJ_C_MT_DEBUG					=	.\C.mt.debug.obj
OBJ_C_DLL_DEBUG					=	.\C.dll.debug.obj
OBJ_C_DLL_RELEASE					=	.\C.dll.obj
OBJ_C_MT_RELEASE					=	.\C.mt.obj
OBJ_C_ST_DEBUG					=	.\C.debug.obj
OBJ_C_ST_RELEASE					=	.\C.obj

TEST_OBJS = \
 $(OBJ_C_MT_DEBUG) \
 $(OBJ_C_DLL_DEBUG) \
 $(OBJ_C_DLL_RELEASE) \
 $(OBJ_C_MT_RELEASE) \
 $(OBJ_C_ST_DEBUG) \
 $(OBJ_C_ST_RELEASE) \
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
	@-$(RM) $(TARGET_TEST_C_MT_DEBUG)
	@-$(RM) $(TARGET_TEST_C_DLL_DEBUG)
	@-$(RM) $(TARGET_TEST_C_DLL_RELEASE)
	@-$(RM) $(TARGET_TEST_C_MT_RELEASE)
	@-$(RM) $(TARGET_TEST_C_ST_DEBUG)
	@-$(RM) $(TARGET_TEST_C_ST_RELEASE)
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

test_:
	$(TARGET_TEST_C_MT_DEBUG) --unittest
	$(TARGET_TEST_C_DLL_DEBUG) --unittest
	$(TARGET_TEST_C_DLL_RELEASE) --unittest
	$(TARGET_TEST_C_MT_RELEASE) --unittest
	$(TARGET_TEST_C_ST_DEBUG) --unittest
	$(TARGET_TEST_C_ST_RELEASE) --unittest

test:	target test_



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



################################################################################
