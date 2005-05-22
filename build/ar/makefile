################################################################################
# File:		makefile
#
# Purpose:	Makefile for the Open-RJ project, for the Arturius C/C++ Compiler Multiplexer
#           compiler, on Win32
#
# Created:	15th Feburary 2005
# Updated:	26th March 2005
#
################################################################################


################################################################################
# Symbols

# Identification

COMP_TAG			=	ar
PROJ_TAG			=	openrj

CC					=	arcc.debug
CPPC				=	arcc.debug
AR					=	lib
LD					=	arld
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

# Lib

LIBS_LEADER			=	

COMMON_LIB			=	

# #defines

COMMON_DEFS			=	-DWIN32

CC_DEFS				=	$(COMMON_DEFS)

CPPC_DEFS			=	$(COMMON_DEFS)

# Flags

CC_F_NOLOGO				=	
CC_F_COMPILE_ONLY		=	-c
CC_F_WARNING_MAX		=	--warning-level=maximum
CC_F_WARNING_ERR		=	--warnings-as-errors=on

CPPC_F_NOLOGO		=	
CPPC_F_COMPILE_ONLY	=	-c
CPPC_F_WARNING_MAX	=	--warning-level=maximum
CPPC_F_WARNING_ERR	=	--warnings-as-errors=on
CPPC_F_EXCEPTIONS	=	--exception-handling=on
CPPC_F_RTTI			=	

CC_TOOL_FLAGS		=	--compilers=bc56,dmb-stlport,gcc34,icl8,vc6,vc71,ow12 --active-compiler=vc/6 --announce-tool-commands

CC_FLAGS = \
 $(CC_TOOL_FLAGS) \
 $(CC_F_NOLOGO) \
 $(CC_F_COMPILE_ONLY) \
 $(CC_F_WARNING_MAX) \
 $(CC_F_WARNING_ERR)

CPPC_TOOL_FLAGS		=	--compilers=bc56,dmb-stlport,gcc34,icl8,vc6,vc71 --active-compiler=vc/6 --announce-tool-commands

CPPC_FLAGS = \
 $(CPPC_TOOL_FLAGS) \
 $(CPPC_F_NOLOGO) \
 $(CPPC_F_COMPILE_ONLY) \
 $(CPPC_F_WARNING_MAX) \
 $(CPPC_F_WARNING_ERR) \
 $(CPPC_F_EXCEPTIONS) \
 $(CPPC_F_RTTI)

# Arguments (= flags + defines + includes)

CC_ARGS_DEBUG				=	-D_DEBUG -UNDEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_RELEASE				=	-DNDEBUG -U_DEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)

CPPC_ARGS_DEBUG			=	-D_DEBUG -UNDEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)
CPPC_ARGS_RELEASE			=	-DNDEBUG -U_DEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)

AR_ARGS				=	

LD_ARGS				=	 $(COMMON_LIB)

################################################################################
# Targets

# libs
TARGET_LIB_DEBUG			=	$(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).debug.lib
TARGET_LIB_RELEASE			=	$(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).release.lib



# test programs
TARGET_TEST_C_DEBUG		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.C.$(COMP_TAG).debug.exe
TARGET_TEST_CPP_DEBUG		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.Cpp.$(COMP_TAG).debug.exe
TARGET_TEST_STL_DEBUG		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.STL.$(COMP_TAG).debug.exe
TARGET_TEST_C_RELEASE		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.C.$(COMP_TAG).release.exe
TARGET_TEST_CPP_RELEASE		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.Cpp.$(COMP_TAG).release.exe
TARGET_TEST_STL_RELEASE		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.STL.$(COMP_TAG).release.exe

TARGETS = \
 $(TARGET_LIB_DEBUG) \
 $(TARGET_LIB_RELEASE) \
 $(TARGET_TEST_C_DEBUG) \
 $(TARGET_TEST_C_RELEASE) \
 $(TARGET_TEST_CPP_DEBUG) \
 $(TARGET_TEST_CPP_RELEASE) \
 $(TARGET_TEST_STL_DEBUG) \
 $(TARGET_TEST_STL_RELEASE) \
 \

# objects

# for libs

OBJ_PROJ_orjapi__DEBUG = $(PROJ_OBJ_DIR)\orjapi.debug.obj
OBJ_PROJ_orjmem__DEBUG = $(PROJ_OBJ_DIR)\orjmem.debug.obj
OBJ_PROJ_orjstr__DEBUG = $(PROJ_OBJ_DIR)\orjstr.debug.obj

OBJ_PROJ_DEBUG = \
 $(OBJ_PROJ_orjapi__DEBUG) \
 $(OBJ_PROJ_orjmem__DEBUG) \
 $(OBJ_PROJ_orjstr__DEBUG) \
 \

OBJ_PROJ_orjapi__RELEASE = $(PROJ_OBJ_DIR)\orjapi.release.obj
OBJ_PROJ_orjmem__RELEASE = $(PROJ_OBJ_DIR)\orjmem.release.obj
OBJ_PROJ_orjstr__RELEASE = $(PROJ_OBJ_DIR)\orjstr.release.obj

OBJ_PROJ_RELEASE = \
 $(OBJ_PROJ_orjapi__RELEASE) \
 $(OBJ_PROJ_orjmem__RELEASE) \
 $(OBJ_PROJ_orjstr__RELEASE) \
 \


LIB_OBJS = \
 $(OBJ_PROJ_DEBUG) \
 $(OBJ_PROJ_RELEASE) \
 \


# for test programs

OBJ_C_DEBUG					=	.\C.debug.obj
OBJ_CPP_DEBUG				=	.\Cpp.debug.obj
OBJ_STL_DEBUG				=	.\STL.debug.obj
OBJ_C_RELEASE					=	.\C.release.obj
OBJ_CPP_RELEASE				=	.\Cpp.release.obj
OBJ_STL_RELEASE				=	.\STL.release.obj

TEST_OBJS = \
 $(OBJ_C_DEBUG) \
 $(OBJ_C_RELEASE) \
 $(OBJ_CPP_DEBUG) \
 $(OBJ_CPP_RELEASE) \
 $(OBJ_STL_DEBUG) \
 $(OBJ_STL_RELEASE) \
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
	@-$(RM) $(TARGET_LIB_DEBUG)
	@-$(RM) $(TARGET_LIB_RELEASE)
	@-$(RM) $(TARGET_TEST_C_DEBUG)
	@-$(RM) $(TARGET_TEST_C_RELEASE)
	@-$(RM) $(TARGET_TEST_CPP_DEBUG)
	@-$(RM) $(TARGET_TEST_CPP_RELEASE)
	@-$(RM) $(TARGET_TEST_STL_DEBUG)
	@-$(RM) $(TARGET_TEST_STL_RELEASE)
	@-$(RM) $(OBJ_PROJ_DEBUG)
	@-$(RM) $(OBJ_PROJ_RELEASE)
	@-$(RM) $(OBJ_C_DEBUG)
	@-$(RM) $(OBJ_C_RELEASE)
	@-$(RM) $(OBJ_CPP_DEBUG)
	@-$(RM) $(OBJ_CPP_RELEASE)
	@-$(RM) $(OBJ_STL_DEBUG)
	@-$(RM) $(OBJ_STL_RELEASE)

test_:
	$(TARGET_TEST_C_DEBUG) --unittest
	$(TARGET_TEST_C_RELEASE) --unittest
	$(TARGET_TEST_CPP_DEBUG) --unittest
	$(TARGET_TEST_CPP_RELEASE) --unittest
	$(TARGET_TEST_STL_DEBUG) --unittest
	$(TARGET_TEST_STL_RELEASE) --unittest

test:	target test_



# build targets

# library

$(TARGET_LIB_DEBUG): $(OBJ_PROJ_DEBUG) makefile
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) $@ $(OBJ_PROJ_DEBUG)

$(OBJ_PROJ_orjapi__DEBUG): $(PROJ_SRC_DIR)\orjapi.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(PROJ_SRC_DIR)\orjapi.c
$(OBJ_PROJ_orjmem__DEBUG): $(PROJ_SRC_DIR)\orjmem.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(PROJ_SRC_DIR)\orjmem.c
$(OBJ_PROJ_orjstr__DEBUG): $(PROJ_SRC_DIR)\orjstr.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(PROJ_SRC_DIR)\orjstr.c

$(TARGET_LIB_RELEASE): $(OBJ_PROJ_RELEASE) makefile
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) $@ $(OBJ_PROJ_RELEASE)

$(OBJ_PROJ_orjapi__RELEASE): $(PROJ_SRC_DIR)\orjapi.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(PROJ_SRC_DIR)\orjapi.c
$(OBJ_PROJ_orjmem__RELEASE): $(PROJ_SRC_DIR)\orjmem.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(PROJ_SRC_DIR)\orjmem.c
$(OBJ_PROJ_orjstr__RELEASE): $(PROJ_SRC_DIR)\orjstr.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(PROJ_SRC_DIR)\orjstr.c


# C test client

$(TARGET_TEST_C_DEBUG):	$(OBJ_C_DEBUG) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) $@ $(OBJ_C_DEBUG) $(TARGET_LIB_DEBUG)


$(OBJ_C_DEBUG):	$(PROJ_TEST_DIR)\C\C.c $(TEST_C_HEADERS) makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(PROJ_TEST_DIR)\C\C.c

$(TARGET_TEST_C_RELEASE):	$(OBJ_C_RELEASE) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) $@ $(OBJ_C_RELEASE) $(TARGET_LIB_RELEASE)


$(OBJ_C_RELEASE):	$(PROJ_TEST_DIR)\C\C.c $(TEST_C_HEADERS) makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(PROJ_TEST_DIR)\C\C.c



# C++ test client

$(TARGET_TEST_CPP_DEBUG):	$(OBJ_CPP_DEBUG) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) $@ $(OBJ_CPP_DEBUG) $(TARGET_LIB_DEBUG)

$(OBJ_CPP_DEBUG):	$(PROJ_TEST_DIR)\Cpp\Cpp.cpp $(TEST_CPP_HEADERS) $(SRC_PROJ_HPP) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(PROJ_TEST_DIR)\Cpp\Cpp.cpp

$(TARGET_TEST_CPP_RELEASE):	$(OBJ_CPP_RELEASE) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) $@ $(OBJ_CPP_RELEASE) $(TARGET_LIB_RELEASE)

$(OBJ_CPP_RELEASE):	$(PROJ_TEST_DIR)\Cpp\Cpp.cpp $(TEST_CPP_HEADERS) $(SRC_PROJ_HPP) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(PROJ_TEST_DIR)\Cpp\Cpp.cpp



# STL test client

$(TARGET_TEST_STL_DEBUG):	$(OBJ_STL_DEBUG) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) $@ $(OBJ_STL_DEBUG) $(TARGET_LIB_DEBUG)

$(OBJ_STL_DEBUG):	$(PROJ_TEST_DIR)\STL\STL.cpp $(TEST_STL_HEADERS) $(SRC_PROJ_HPP) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(PROJ_TEST_DIR)\STL\STL.cpp

$(TARGET_TEST_STL_RELEASE):	$(OBJ_STL_RELEASE) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) $@ $(OBJ_STL_RELEASE) $(TARGET_LIB_RELEASE)

$(OBJ_STL_RELEASE):	$(PROJ_TEST_DIR)\STL\STL.cpp $(TEST_STL_HEADERS) $(SRC_PROJ_HPP) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(PROJ_TEST_DIR)\STL\STL.cpp



################################################################################
