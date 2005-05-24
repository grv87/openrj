################################################################################
# File:		makefile
#
# Purpose:	Makefile for the Open-RJ project, for the Borland C/C++ 5.5.1
#           compiler, on Win32
#
# Created:	15th Feburary 2005
# Updated:	25th May 2005
#
################################################################################


################################################################################
# Environment check
#

!ifndef STLSOFT_INCLUDE
!error STLSOFT_INCLUDE must be defined
!endif # STLSOFT_INCLUDE

################################################################################
# Symbols

# Identification

COMP_TAG			=	bc551
PROJ_TAG			=	openrj

CC					=	bcc32
CPPC				=	bcc32
AR					=	tlib
LD					=	bcc32
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

COMMON_INCLUDES		=	-I"$(INCLUDE)"

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

COMMON_LIB			=	$(LIBS_LEADER) -L"$(LIB)"

# #defines

COMMON_DEFS			=	-DWIN32

CC_DEFS				=	$(COMMON_DEFS)

CPPC_DEFS			=	$(COMMON_DEFS)

# Flags

CC_F_NOLOGO				=	-q
CC_F_COMPILE_ONLY		=	-c
CC_F_WARNING_MAX		=	-w
CC_F_WARNING_ERR		=	-w!

CPPC_F_NOLOGO		=	-q
CPPC_F_COMPILE_ONLY	=	-c
CPPC_F_WARNING_MAX	=	-w
CPPC_F_WARNING_ERR	=	-w!
CPPC_F_EXCEPTIONS	=	-x
CPPC_F_RTTI			=	

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

# Arguments (= flags + defines + includes)

CC_ARGS_ST_D				=	-D_DEBUG -UNDEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_ST_R				=	-DNDEBUG -U_DEBUG -O1 $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)

CPPC_ARGS_ST_D			=	-D_DEBUG -UNDEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)
CPPC_ARGS_ST_R			=	-DNDEBUG -U_DEBUG -O1 $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)

AR_ARGS				=	

LD_ARGS				=	-q -l-x $(COMMON_LIB)

################################################################################
# Targets

# libs
TARGET_LIB_ST_D			=	$(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).debug.lib
TARGET_LIB_ST_R			=	$(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).lib



# test programs
TARGET_TEST_C_FULL_ST_D			=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.C_full.$(COMP_TAG).debug.exe
TARGET_TEST_C_SIMPLE_ST_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.C_simple.$(COMP_TAG).debug.exe
TARGET_TEST_CPP_FULL_ST_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.Cpp_full.$(COMP_TAG).debug.exe
TARGET_TEST_CPP_SIMPLE_ST_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.Cpp_simple.$(COMP_TAG).debug.exe
TARGET_TEST_STL_FULL_ST_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.STL_full.$(COMP_TAG).debug.exe
TARGET_TEST_STL_SIMPLE_ST_D		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.STL_simple.$(COMP_TAG).debug.exe
TARGET_TEST_C_FULL_ST_R			=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.C_full.$(COMP_TAG).exe
TARGET_TEST_C_SIMPLE_ST_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.C_simple.$(COMP_TAG).exe
TARGET_TEST_CPP_FULL_ST_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.Cpp_full.$(COMP_TAG).exe
TARGET_TEST_CPP_SIMPLE_ST_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.Cpp_simple.$(COMP_TAG).exe
TARGET_TEST_STL_FULL_ST_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.STL_full.$(COMP_TAG).exe
TARGET_TEST_STL_SIMPLE_ST_R		=	$(PROJ_BIN_DIR)\$(PROJ_TAG).test.STL_simple.$(COMP_TAG).exe

TARGETS = \
 $(TARGET_LIB_ST_D) \
 $(TARGET_LIB_ST_R) \
 $(TARGET_TEST_C_FULL_ST_D) \
 $(TARGET_TEST_C_SIMPLE_ST_D) \
 $(TARGET_TEST_C_FULL_ST_R) \
 $(TARGET_TEST_C_SIMPLE_ST_R) \
 $(TARGET_TEST_CPP_FULL_ST_D) \
 $(TARGET_TEST_CPP_SIMPLE_ST_D) \
 $(TARGET_TEST_CPP_FULL_ST_R) \
 $(TARGET_TEST_CPP_SIMPLE_ST_R) \
 $(TARGET_TEST_STL_FULL_ST_D) \
 $(TARGET_TEST_STL_SIMPLE_ST_D) \
 $(TARGET_TEST_STL_FULL_ST_R) \
 $(TARGET_TEST_STL_SIMPLE_ST_R) \
 \

# objects

# for libs

OBJ_PROJ_orjapi__ST_D = $(PROJ_OBJ_DIR)\orjapi.debug.obj
OBJ_PROJ_orjmem__ST_D = $(PROJ_OBJ_DIR)\orjmem.debug.obj
OBJ_PROJ_orjstr__ST_D = $(PROJ_OBJ_DIR)\orjstr.debug.obj

OBJ_PROJ_ST_D = \
 $(OBJ_PROJ_orjapi__ST_D) \
 $(OBJ_PROJ_orjmem__ST_D) \
 $(OBJ_PROJ_orjstr__ST_D) \
 \

OBJ_PROJ_ST_D_PM = \
 -+$(OBJ_PROJ_orjapi__ST_D) \
 -+$(OBJ_PROJ_orjmem__ST_D) \
 -+$(OBJ_PROJ_orjstr__ST_D) \
 \

OBJ_PROJ_orjapi__ST_R = $(PROJ_OBJ_DIR)\orjapi.obj
OBJ_PROJ_orjmem__ST_R = $(PROJ_OBJ_DIR)\orjmem.obj
OBJ_PROJ_orjstr__ST_R = $(PROJ_OBJ_DIR)\orjstr.obj

OBJ_PROJ_ST_R = \
 $(OBJ_PROJ_orjapi__ST_R) \
 $(OBJ_PROJ_orjmem__ST_R) \
 $(OBJ_PROJ_orjstr__ST_R) \
 \

OBJ_PROJ_ST_R_PM = \
 -+$(OBJ_PROJ_orjapi__ST_R) \
 -+$(OBJ_PROJ_orjmem__ST_R) \
 -+$(OBJ_PROJ_orjstr__ST_R) \
 \


LIB_OBJS = \
 $(OBJ_PROJ_ST_D) \
 $(OBJ_PROJ_ST_R) \
 \


# for test programs

OBJ_C_FULL_ST_D				=	.\C_full.debug.obj
OBJ_C_SIMPLE_ST_D			=	.\C_simple.debug.obj
OBJ_CPP_FULL_ST_D			=	.\Cpp_full.debug.obj
OBJ_CPP_SIMPLE_ST_D			=	.\Cpp_simple.debug.obj
OBJ_STL_FULL_ST_D			=	.\STL_full.debug.obj
OBJ_STL_SIMPLE_ST_D			=	.\STL_simple.debug.obj
OBJ_C_FULL_ST_R				=	.\C_full.obj
OBJ_C_SIMPLE_ST_R			=	.\C_simple.obj
OBJ_CPP_FULL_ST_R			=	.\Cpp_full.obj
OBJ_CPP_SIMPLE_ST_R			=	.\Cpp_simple.obj
OBJ_STL_FULL_ST_R			=	.\STL_full.obj
OBJ_STL_SIMPLE_ST_R			=	.\STL_simple.obj

TEST_OBJS = \
 $(OBJ_C_FULL_ST_D) \
 $(OBJ_C_SIMPLE_ST_D) \
 $(OBJ_C_FULL_ST_R) \
 $(OBJ_C_SIMPLE_ST_R) \
 $(OBJ_CPP_FULL_ST_D) \
 $(OBJ_CPP_SIMPLE_ST_D) \
 $(OBJ_CPP_FULL_ST_R) \
 $(OBJ_CPP_SIMPLE_ST_R) \
 $(OBJ_STL_FULL_ST_D) \
 $(OBJ_STL_SIMPLE_ST_D) \
 $(OBJ_STL_FULL_ST_R) \
 $(OBJ_STL_SIMPLE_ST_R) \
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
	@-$(RM) $(TARGET_LIB_ST_D)
	@-$(RM) $(TARGET_LIB_ST_R)
	@-$(RM) $(TARGET_TEST_C_FULL_ST_D)
	@-$(RM) $(TARGET_TEST_C_SIMPLE_ST_D)
	@-$(RM) $(TARGET_TEST_C_FULL_ST_R)
	@-$(RM) $(TARGET_TEST_C_SIMPLE_ST_R)
	@-$(RM) $(TARGET_TEST_CPP_FULL_ST_D)
	@-$(RM) $(TARGET_TEST_CPP_SIMPLE_ST_D)
	@-$(RM) $(TARGET_TEST_CPP_FULL_ST_R)
	@-$(RM) $(TARGET_TEST_CPP_SIMPLE_ST_R)
	@-$(RM) $(TARGET_TEST_STL_FULL_ST_D)
	@-$(RM) $(TARGET_TEST_STL_SIMPLE_ST_D)
	@-$(RM) $(TARGET_TEST_STL_FULL_ST_R)
	@-$(RM) $(TARGET_TEST_STL_SIMPLE_ST_R)
	@-$(RM) $(OBJ_PROJ_ST_D)
	@-$(RM) $(OBJ_PROJ_ST_R)
	@-$(RM) $(OBJ_C_FULL_ST_D)
	@-$(RM) $(OBJ_C_SIMPLE_ST_D)
	@-$(RM) $(OBJ_C_FULL_ST_R)
	@-$(RM) $(OBJ_C_SIMPLE_ST_R)
	@-$(RM) $(OBJ_CPP_FULL_ST_D)
	@-$(RM) $(OBJ_CPP_SIMPLE_ST_D)
	@-$(RM) $(OBJ_CPP_FULL_ST_R)
	@-$(RM) $(OBJ_CPP_SIMPLE_ST_R)
	@-$(RM) $(OBJ_STL_FULL_ST_D)
	@-$(RM) $(OBJ_STL_SIMPLE_ST_D)
	@-$(RM) $(OBJ_STL_FULL_ST_R)
	@-$(RM) $(OBJ_STL_SIMPLE_ST_R)

test_:
	$(TARGET_TEST_C_FULL_ST_D) --unittest
	$(TARGET_TEST_C_SIMPLE_ST_D) --unittest
	$(TARGET_TEST_C_FULL_ST_R) --unittest
	$(TARGET_TEST_C_SIMPLE_ST_R) --unittest
	$(TARGET_TEST_CPP_FULL_ST_D) --unittest
	$(TARGET_TEST_CPP_SIMPLE_ST_D) --unittest
	$(TARGET_TEST_CPP_FULL_ST_R) --unittest
	$(TARGET_TEST_CPP_SIMPLE_ST_R) --unittest
	$(TARGET_TEST_STL_FULL_ST_D) --unittest
	$(TARGET_TEST_STL_SIMPLE_ST_D) --unittest
	$(TARGET_TEST_STL_FULL_ST_R) --unittest
	$(TARGET_TEST_STL_SIMPLE_ST_R) --unittest

test:	target test_



# build targets

# library

$(TARGET_LIB_ST_D): $(OBJ_PROJ_ST_D) makefile
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) $@ $(OBJ_PROJ_ST_D_PM)

$(OBJ_PROJ_orjapi__ST_D): $(PROJ_SRC_DIR)\orjapi.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_ST_D) -o$@ $(PROJ_SRC_DIR)\orjapi.c
$(OBJ_PROJ_orjmem__ST_D): $(PROJ_SRC_DIR)\orjmem.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_ST_D) -o$@ $(PROJ_SRC_DIR)\orjmem.c
$(OBJ_PROJ_orjstr__ST_D): $(PROJ_SRC_DIR)\orjstr.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_ST_D) -o$@ $(PROJ_SRC_DIR)\orjstr.c

$(TARGET_LIB_ST_R): $(OBJ_PROJ_ST_R) makefile
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)
	$(AR) $(AR_ARGS) $@ $(OBJ_PROJ_ST_R_PM)

$(OBJ_PROJ_orjapi__ST_R): $(PROJ_SRC_DIR)\orjapi.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_ST_R) -o$@ $(PROJ_SRC_DIR)\orjapi.c
$(OBJ_PROJ_orjmem__ST_R): $(PROJ_SRC_DIR)\orjmem.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_ST_R) -o$@ $(PROJ_SRC_DIR)\orjmem.c
$(OBJ_PROJ_orjstr__ST_R): $(PROJ_SRC_DIR)\orjstr.c $(LIB_HEADERS) makefile
	$(CC) $(CC_ARGS_ST_R) -o$@ $(PROJ_SRC_DIR)\orjstr.c


# C test clients

# full
$(TARGET_TEST_C_FULL_ST_D):	$(OBJ_C_FULL_ST_D) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -e$@ $(OBJ_C_FULL_ST_D) $(TARGET_LIB_ST_D)


$(OBJ_C_FULL_ST_D):	$(PROJ_TEST_DIR)\C_full\C_full.c $(TEST_C_HEADERS) makefile
	$(CC) $(CC_ARGS_ST_D) -o$@ $(PROJ_TEST_DIR)\C_full\C_full.c

# minimal
$(TARGET_TEST_C_SIMPLE_ST_D):	$(OBJ_C_SIMPLE_ST_D) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -e$@ $(OBJ_C_SIMPLE_ST_D) $(TARGET_LIB_ST_D)


$(OBJ_C_SIMPLE_ST_D):	$(PROJ_TEST_DIR)\C_simple\C_simple.c $(TEST_C_HEADERS) makefile
	$(CC) $(CC_ARGS_ST_D) -o$@ $(PROJ_TEST_DIR)\C_simple\C_simple.c

# full
$(TARGET_TEST_C_FULL_ST_R):	$(OBJ_C_FULL_ST_R) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -e$@ $(OBJ_C_FULL_ST_R) $(TARGET_LIB_ST_R)


$(OBJ_C_FULL_ST_R):	$(PROJ_TEST_DIR)\C_full\C_full.c $(TEST_C_HEADERS) makefile
	$(CC) $(CC_ARGS_ST_R) -o$@ $(PROJ_TEST_DIR)\C_full\C_full.c

# minimal
$(TARGET_TEST_C_SIMPLE_ST_R):	$(OBJ_C_SIMPLE_ST_R) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -e$@ $(OBJ_C_SIMPLE_ST_R) $(TARGET_LIB_ST_R)


$(OBJ_C_SIMPLE_ST_R):	$(PROJ_TEST_DIR)\C_simple\C_simple.c $(TEST_C_HEADERS) makefile
	$(CC) $(CC_ARGS_ST_R) -o$@ $(PROJ_TEST_DIR)\C_simple\C_simple.c



# C++ test clients

# full
$(TARGET_TEST_CPP_FULL_ST_D):	$(OBJ_CPP_FULL_ST_D) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -e$@ $(OBJ_CPP_FULL_ST_D) $(TARGET_LIB_ST_D)

$(OBJ_CPP_FULL_ST_D):	$(PROJ_TEST_DIR)\Cpp_full\Cpp_full.cpp $(TEST_CPP_HEADERS) $(SRC_PROJ_HPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_D) -o$@ $(PROJ_TEST_DIR)\Cpp_full\Cpp_full.cpp

# minimal
$(TARGET_TEST_CPP_SIMPLE_ST_D):	$(OBJ_CPP_SIMPLE_ST_D) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -e$@ $(OBJ_CPP_SIMPLE_ST_D) $(TARGET_LIB_ST_D)

$(OBJ_CPP_SIMPLE_ST_D):	$(PROJ_TEST_DIR)\Cpp_simple\Cpp_simple.cpp $(TEST_CPP_HEADERS) $(SRC_PROJ_HPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_D) -o$@ $(PROJ_TEST_DIR)\Cpp_simple\Cpp_simple.cpp

# full
$(TARGET_TEST_CPP_FULL_ST_R):	$(OBJ_CPP_FULL_ST_R) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -e$@ $(OBJ_CPP_FULL_ST_R) $(TARGET_LIB_ST_R)

$(OBJ_CPP_FULL_ST_R):	$(PROJ_TEST_DIR)\Cpp_full\Cpp_full.cpp $(TEST_CPP_HEADERS) $(SRC_PROJ_HPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_R) -o$@ $(PROJ_TEST_DIR)\Cpp_full\Cpp_full.cpp

# minimal
$(TARGET_TEST_CPP_SIMPLE_ST_R):	$(OBJ_CPP_SIMPLE_ST_R) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -e$@ $(OBJ_CPP_SIMPLE_ST_R) $(TARGET_LIB_ST_R)

$(OBJ_CPP_SIMPLE_ST_R):	$(PROJ_TEST_DIR)\Cpp_simple\Cpp_simple.cpp $(TEST_CPP_HEADERS) $(SRC_PROJ_HPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_R) -o$@ $(PROJ_TEST_DIR)\Cpp_simple\Cpp_simple.cpp



# STL test clients

# full
$(TARGET_TEST_STL_FULL_ST_D):	$(OBJ_STL_FULL_ST_D) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -e$@ $(OBJ_STL_FULL_ST_D) $(TARGET_LIB_ST_D)

$(OBJ_STL_FULL_ST_D):	$(PROJ_TEST_DIR)\STL_full\STL_full.cpp $(TEST_STL_HEADERS) $(SRC_PROJ_HPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_D) -o$@ $(PROJ_TEST_DIR)\STL_full\STL_full.cpp

# minimal
$(TARGET_TEST_STL_SIMPLE_ST_D):	$(OBJ_STL_SIMPLE_ST_D) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -e$@ $(OBJ_STL_SIMPLE_ST_D) $(TARGET_LIB_ST_D)

$(OBJ_STL_SIMPLE_ST_D):	$(PROJ_TEST_DIR)\STL_simple\STL_simple.cpp $(TEST_STL_HEADERS) $(SRC_PROJ_HPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_D) -o$@ $(PROJ_TEST_DIR)\STL_simple\STL_simple.cpp

# full
$(TARGET_TEST_STL_FULL_ST_R):	$(OBJ_STL_FULL_ST_R) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -e$@ $(OBJ_STL_FULL_ST_R) $(TARGET_LIB_ST_R)

$(OBJ_STL_FULL_ST_R):	$(PROJ_TEST_DIR)\STL_full\STL_full.cpp $(TEST_STL_HEADERS) $(SRC_PROJ_HPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_R) -o$@ $(PROJ_TEST_DIR)\STL_full\STL_full.cpp

# minimal
$(TARGET_TEST_STL_SIMPLE_ST_R):	$(OBJ_STL_SIMPLE_ST_R) makefile
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)
	$(LD) $(LD_ARGS) -e$@ $(OBJ_STL_SIMPLE_ST_R) $(TARGET_LIB_ST_R)

$(OBJ_STL_SIMPLE_ST_R):	$(PROJ_TEST_DIR)\STL_simple\STL_simple.cpp $(TEST_STL_HEADERS) $(SRC_PROJ_HPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_R) -o$@ $(PROJ_TEST_DIR)\STL_simple\STL_simple.cpp



################################################################################
