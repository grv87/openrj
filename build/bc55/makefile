################################################################################
# File:     makefile
#
# Purpose:  Makefile for the Open-RJ project, for the Borland C/C++ Compiler v5.5
#           compiler, on Win32
#
# Created:  15th Feburary 2005
# Updated:  28th May 2006
#
################################################################################


################################################################################
# Environment check
#

!ifndef STLSOFT
!error STLSOFT must be defined
!endif # STLSOFT

################################################################################
# Symbols

# Identification

COMP_TAG          =   bc55
PROJ_TAG          =   openrj
PROJ_VER_MAJOR    =   1
PROJ_TAG_VER      =   $(PROJ_TAG).$(PROJ_VER_MAJOR)

CC                  =   bcc32
CPPC                =   bcc32
AR                  =   tlib
LD                  =   bcc32
RM                  =   del /f
CP                  =   copy
RC                  =   rc

# Directories

PROJ_BASE_DIR       =   ..\..
PROJ_BIN_DIR        =   $(PROJ_BASE_DIR)\bin
PROJ_INCLUDE_DIR    =   $(PROJ_BASE_DIR)\include
PROJ_LIB_DIR        =   $(PROJ_BASE_DIR)\lib
PROJ_OBJ_DIR        =   .
PROJ_SRC_DIR        =   $(PROJ_BASE_DIR)\src
PROJ_MAPPINGS_DIR   =   $(PROJ_BASE_DIR)\mappings
PROJ_TESTS_DIR      =   $(PROJ_BASE_DIR)\test
PROJ_EXAMPLES_DIR   =   $(PROJ_BASE_DIR)\examples
PROJ_SAMPLES_DIR    =   $(PROJ_BASE_DIR)\samples

# Includes

INCLUDES_LEADER     =   

PROJ_INCLUDE        =   -I$(PROJ_INCLUDE_DIR)

COMMON_INCLUDES     =   -I"$(INCLUDE)"

CC_INCLUDES = \
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
 \

3PTY_LIBS__ST_D = \
 \

3PTY_LIBS__ST_R = \
 \


LIB_PATHS =\
 \

LIBS_LEADER         =   

COMMON_LIB          =   $(LIBS_LEADER) -L"$(LIB)"

# #defines

CMN_DEF_NO_IMPLICIT_LINK =\
 -DOPENRJ_NO_IMPLICIT_LINK\
 \

COMMON_DEFS         =   -DWIN32 $(CMN_DEF_NO_IMPLICIT_LINK)

CC_DEFS             =   $(COMMON_DEFS)

# Flags

CC_F_NOLOGO             =   -q
CC_F_COMPILE_ONLY       =   -c
CC_F_WARNING_MAX        =   -w
CC_F_WARNING_ERR        =   -w!

CC_TOOL_FLAGS       =   

CC_FLAGS = \
 $(CC_TOOL_FLAGS)\
 $(CC_F_NOLOGO)\
 $(CC_F_COMPILE_ONLY)\
 $(CC_F_WARNING_MAX)\
 $(CC_F_WARNING_ERR)\
 \

# Arguments (= flags + defines + includes)

CC_ARGS_ST_D                =   -D_DEBUG -UNDEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_ST_R                =   -DNDEBUG -U_DEBUG -O1 $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)

# archiver flags and arguments

AR_ARGS             =   

# linker flags and arguments

LD_F_NOLOGO = -q

LD_ARGS_ST_D            =   -q -l-x $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)
LD_ARGS_ST_R            =   -q -l-x $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)

################################################################################
# Targets

########################################
# TARGETS_LIBS

TARGET_LIB_ST_D         =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG).debug.lib
TARGET_LIB_UN_ST_D      =   $(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).debug.lib
TARGET_LIB_ST_R         =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG).lib
TARGET_LIB_UN_ST_R      =   $(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).lib

TARGETS_LIBS =\
 $(TARGET_LIB_ST_D)\
 $(TARGET_LIB_UN_ST_D)\
 $(TARGET_LIB_ST_R)\
 $(TARGET_LIB_UN_ST_R)\
 \

########################################
# TARGETS_TESTS

TARGET_TEST_C_1_ST_D        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_c_1.$(COMP_TAG).debug.exe
TARGET_TEST_C_1_ST_R        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_c_1.$(COMP_TAG).exe

TARGETS_TESTS =\
 $(TARGET_TEST_C_1_ST_D)\
 $(TARGET_TEST_C_1_ST_R)\
 \

########################################
# TARGETS_EXAMPLES

TARGET_EXAMPLE_C_1_ST_D        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_1.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_2_ST_D        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_2.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_3_ST_D        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_3.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_4_ST_D        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_4.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_5_ST_D        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_5.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_6_ST_D        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_6.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_7_ST_D        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_7.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_8_ST_D        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_8.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_1_ST_R        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_1.$(COMP_TAG).exe
TARGET_EXAMPLE_C_2_ST_R        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_2.$(COMP_TAG).exe
TARGET_EXAMPLE_C_3_ST_R        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_3.$(COMP_TAG).exe
TARGET_EXAMPLE_C_4_ST_R        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_4.$(COMP_TAG).exe
TARGET_EXAMPLE_C_5_ST_R        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_5.$(COMP_TAG).exe
TARGET_EXAMPLE_C_6_ST_R        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_6.$(COMP_TAG).exe
TARGET_EXAMPLE_C_7_ST_R        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_7.$(COMP_TAG).exe
TARGET_EXAMPLE_C_8_ST_R        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_8.$(COMP_TAG).exe

TARGETS_EXAMPLES =\
 $(TARGET_EXAMPLE_C_1_ST_D)\
 $(TARGET_EXAMPLE_C_2_ST_D)\
 $(TARGET_EXAMPLE_C_3_ST_D)\
 $(TARGET_EXAMPLE_C_4_ST_D)\
 $(TARGET_EXAMPLE_C_5_ST_D)\
 $(TARGET_EXAMPLE_C_6_ST_D)\
 $(TARGET_EXAMPLE_C_7_ST_D)\
 $(TARGET_EXAMPLE_C_8_ST_D)\
 $(TARGET_EXAMPLE_C_1_ST_R)\
 $(TARGET_EXAMPLE_C_2_ST_R)\
 $(TARGET_EXAMPLE_C_3_ST_R)\
 $(TARGET_EXAMPLE_C_4_ST_R)\
 $(TARGET_EXAMPLE_C_5_ST_R)\
 $(TARGET_EXAMPLE_C_6_ST_R)\
 $(TARGET_EXAMPLE_C_7_ST_R)\
 $(TARGET_EXAMPLE_C_8_ST_R)\
 \

########################################
# TARGETS_SAMPLES

TARGET_SAMPLE_C_1_ST_D        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_1.$(COMP_TAG).debug.exe
TARGET_SAMPLE_C_2_ST_D        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_2.$(COMP_TAG).debug.exe
TARGET_SAMPLE_C_1_ST_R        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_1.$(COMP_TAG).exe
TARGET_SAMPLE_C_2_ST_R        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_2.$(COMP_TAG).exe

TARGETS_SAMPLES =\
 $(TARGET_SAMPLE_C_1_ST_D)\
 $(TARGET_SAMPLE_C_2_ST_D)\
 $(TARGET_SAMPLE_C_1_ST_R)\
 $(TARGET_SAMPLE_C_2_ST_R)\
 \

########################################
# TARGETS

TARGETS = \
 $(TARGETS_LIBS)\
 $(TARGETS_TESTS)\
 $(TARGETS_EXAMPLES)\
 $(TARGETS_SAMPLES)\
 \

########################################
# OBJS_CORE

OBJ_CORE_orjapi__ST_D = $(PROJ_OBJ_DIR)\orjapi.debug.obj
OBJ_CORE_orjmem__ST_D = $(PROJ_OBJ_DIR)\orjmem.debug.obj
OBJ_CORE_orjstr__ST_D = $(PROJ_OBJ_DIR)\orjstr.debug.obj

OBJS_CORE_ST_D_PM =\
 -+$(OBJ_CORE_orjapi__ST_D)\
 -+$(OBJ_CORE_orjmem__ST_D)\
 -+$(OBJ_CORE_orjstr__ST_D)\
 \

OBJ_CORE_orjapi__ST_R = $(PROJ_OBJ_DIR)\orjapi.obj
OBJ_CORE_orjmem__ST_R = $(PROJ_OBJ_DIR)\orjmem.obj
OBJ_CORE_orjstr__ST_R = $(PROJ_OBJ_DIR)\orjstr.obj

OBJS_CORE_ST_R_PM =\
 -+$(OBJ_CORE_orjapi__ST_R)\
 -+$(OBJ_CORE_orjmem__ST_R)\
 -+$(OBJ_CORE_orjstr__ST_R)\
 \


OBJS_CORE =\
 $(OBJS_CORE_ST_D)\
 $(OBJS_CORE_ST_R)\
 \

########################################
# OBJS_LIBS

OBJS_LIBS =\
 $(OBJS_CORE)\
 \

########################################
# OBJS_TESTS

OBJ_TEST_C_1_ST_D        =   $(PROJ_OBJ_DIR)\test_c_1.debug.obj
OBJ_TEST_C_1_ST_R        =   $(PROJ_OBJ_DIR)\test_c_1.obj

OBJS_TESTS =\
 $(OBJ_TEST_C_1_ST_D)\
 $(OBJ_TEST_C_1_ST_R)\
 \

########################################
# OBJS_EXAMPLES

OBJ_EXAMPLE_C_1_ST_D        =   $(PROJ_OBJ_DIR)\example_c_1.debug.obj
OBJ_EXAMPLE_C_2_ST_D        =   $(PROJ_OBJ_DIR)\example_c_2.debug.obj
OBJ_EXAMPLE_C_3_ST_D        =   $(PROJ_OBJ_DIR)\example_c_3.debug.obj
OBJ_EXAMPLE_C_4_ST_D        =   $(PROJ_OBJ_DIR)\example_c_4.debug.obj
OBJ_EXAMPLE_C_5_ST_D        =   $(PROJ_OBJ_DIR)\example_c_5.debug.obj
OBJ_EXAMPLE_C_6_ST_D        =   $(PROJ_OBJ_DIR)\example_c_6.debug.obj
OBJ_EXAMPLE_C_7_ST_D        =   $(PROJ_OBJ_DIR)\example_c_7.debug.obj
OBJ_EXAMPLE_C_8_ST_D        =   $(PROJ_OBJ_DIR)\example_c_8.debug.obj
OBJ_EXAMPLE_C_1_ST_R        =   $(PROJ_OBJ_DIR)\example_c_1.obj
OBJ_EXAMPLE_C_2_ST_R        =   $(PROJ_OBJ_DIR)\example_c_2.obj
OBJ_EXAMPLE_C_3_ST_R        =   $(PROJ_OBJ_DIR)\example_c_3.obj
OBJ_EXAMPLE_C_4_ST_R        =   $(PROJ_OBJ_DIR)\example_c_4.obj
OBJ_EXAMPLE_C_5_ST_R        =   $(PROJ_OBJ_DIR)\example_c_5.obj
OBJ_EXAMPLE_C_6_ST_R        =   $(PROJ_OBJ_DIR)\example_c_6.obj
OBJ_EXAMPLE_C_7_ST_R        =   $(PROJ_OBJ_DIR)\example_c_7.obj
OBJ_EXAMPLE_C_8_ST_R        =   $(PROJ_OBJ_DIR)\example_c_8.obj

OBJS_EXAMPLES =\
 $(OBJ_EXAMPLE_C_1_ST_D)\
 $(OBJ_EXAMPLE_C_2_ST_D)\
 $(OBJ_EXAMPLE_C_3_ST_D)\
 $(OBJ_EXAMPLE_C_4_ST_D)\
 $(OBJ_EXAMPLE_C_5_ST_D)\
 $(OBJ_EXAMPLE_C_6_ST_D)\
 $(OBJ_EXAMPLE_C_7_ST_D)\
 $(OBJ_EXAMPLE_C_8_ST_D)\
 $(OBJ_EXAMPLE_C_1_ST_R)\
 $(OBJ_EXAMPLE_C_2_ST_R)\
 $(OBJ_EXAMPLE_C_3_ST_R)\
 $(OBJ_EXAMPLE_C_4_ST_R)\
 $(OBJ_EXAMPLE_C_5_ST_R)\
 $(OBJ_EXAMPLE_C_6_ST_R)\
 $(OBJ_EXAMPLE_C_7_ST_R)\
 $(OBJ_EXAMPLE_C_8_ST_R)\
 \

########################################
# OBJS_SAMPLES

OBJ_SAMPLE_C_1_ST_D        =   $(PROJ_OBJ_DIR)\sample_c_1.debug.obj
OBJ_SAMPLE_C_2_ST_D        =   $(PROJ_OBJ_DIR)\sample_c_2.debug.obj
OBJ_SAMPLE_C_1_ST_R        =   $(PROJ_OBJ_DIR)\sample_c_1.obj
OBJ_SAMPLE_C_2_ST_R        =   $(PROJ_OBJ_DIR)\sample_c_2.obj

OBJS_SAMPLES =\
 $(OBJ_SAMPLE_C_1_ST_D)\
 $(OBJ_SAMPLE_C_2_ST_D)\
 $(OBJ_SAMPLE_C_1_ST_R)\
 $(OBJ_SAMPLE_C_2_ST_R)\
 \


########################################
# OBJS

OBJS = \
 $(OBJS_LIBS)\
 $(OBJS_TESTS)\
 $(OBJS_EXAMPLES)\
 $(OBJS_SAMPLES)\
 \

########################################
# SRC_CORE

LIB_CORE_openrj_H = $(PROJ_INCLUDE_DIR)\openrj\openrj.h
LIB_CORE_openrj_assert_H = $(PROJ_INCLUDE_DIR)\openrj\openrj_assert.h
LIB_CORE_openrj_memory_H = $(PROJ_INCLUDE_DIR)\openrj\openrj_memory.h
LIB_CORE_implicit_link_H = $(PROJ_INCLUDE_DIR)\openrj\implicit_link.h

LIB_CORE_orjapi_C = $(PROJ_SRC_DIR)\orjapi.c
LIB_CORE_orjmem_C = $(PROJ_SRC_DIR)\orjmem.c
LIB_CORE_orjstr_C = $(PROJ_SRC_DIR)\orjstr.c

########################################
# SRC_HEADERS

HEADERS_LIB	= \
 $(LIB_CORE_openrj_H)\
 $(LIB_CORE_openrj_assert_H)\
 $(LIB_CORE_openrj_memory_H)\
 $(LIB_CORE_implicit_link_H)\
 \

########################################
# SRC_TESTS

SRC_TEST_C_1 =   $(PROJ_TESTS_DIR)\c\test_c_1\test_c_1.c

########################################
# SRC_EXAMPLES

SRC_EXAMPLE_C_1 =   $(PROJ_EXAMPLES_DIR)\c\example_c_1\example_c_1.c
SRC_EXAMPLE_C_2 =   $(PROJ_EXAMPLES_DIR)\c\example_c_2\example_c_2.c
SRC_EXAMPLE_C_3 =   $(PROJ_EXAMPLES_DIR)\c\example_c_3\example_c_3.c
SRC_EXAMPLE_C_4 =   $(PROJ_EXAMPLES_DIR)\c\example_c_4\example_c_4.c
SRC_EXAMPLE_C_5 =   $(PROJ_EXAMPLES_DIR)\c\example_c_5\example_c_5.c
SRC_EXAMPLE_C_6 =   $(PROJ_EXAMPLES_DIR)\c\example_c_6\example_c_6.c
SRC_EXAMPLE_C_7 =   $(PROJ_EXAMPLES_DIR)\c\example_c_7\example_c_7.c
SRC_EXAMPLE_C_8 =   $(PROJ_EXAMPLES_DIR)\c\example_c_8\example_c_8.c

########################################
# SRC_SAMPLES

SRC_SAMPLE_C_1 =   $(PROJ_SAMPLES_DIR)\c\sample_c_1\sample_c_1.c
SRC_SAMPLE_C_2 =   $(PROJ_SAMPLES_DIR)\c\sample_c_2\sample_c_2.c

################################################################################
# External Targets (invokable by make)

all:                build.all

check.lib.dir:
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)

check.bin.dir:
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)

build.libs.core:    check.lib.dir $(TARGETS_LIBS)

build.libs.com:

build.libs.dotnet:

build.libs:         build.libs.core build.libs.com build.libs.dotnet

build.examples:     check.bin.dir $(TARGETS_EXAMPLES)

build.samples:      check.bin.dir $(TARGETS_SAMPLES)

build.test:         check.bin.dir $(TARGETS_TESTS)

build.all:          build.libs build.examples build.samples build.test

build:              build.all

compile:            $(OBJS)


test_:
	$(TARGET_TEST_C_1_ST_D) --unittest
	$(TARGET_TEST_C_1_ST_R) --unittest

test:		build.all test_

test.all:	test

test-all:	test.all	# backwards compatibility


usage:
	@echo "make [usage | clean | compile | all | test | target] - default is 'all'"

clean.libs.core:
	@-$(RM) $(TARGET_LIB_ST_D)
	@-$(RM) $(TARGET_LIB_UN_ST_D)
	@-$(RM) $(TARGET_LIB_ST_R)
	@-$(RM) $(TARGET_LIB_UN_ST_R)
	@-$(RM) $(OBJ_CORE_orjapi__ST_D)
	@-$(RM) $(OBJ_CORE_orjmem__ST_D)
	@-$(RM) $(OBJ_CORE_orjstr__ST_D)
	@-$(RM) $(OBJ_CORE_orjapi__ST_R)
	@-$(RM) $(OBJ_CORE_orjmem__ST_R)
	@-$(RM) $(OBJ_CORE_orjstr__ST_R)

clean.libs.com:

clean.libs.dotnet:

clean.libs:         clean.libs.core clean.libs.com clean.libs.dotnet

clean.test:
	@-$(RM) $(TARGET_TEST_C_1_ST_D)
	@-$(RM) $(TARGET_TEST_C_1_ST_R)
	@-$(RM) $(OBJ_TEST_C_1_ST_D)
	@-$(RM) $(OBJ_TEST_C_1_ST_R)

clean.examples:
	@-$(RM) $(TARGET_EXAMPLE_C_1_ST_D)
	@-$(RM) $(TARGET_EXAMPLE_C_2_ST_D)
	@-$(RM) $(TARGET_EXAMPLE_C_3_ST_D)
	@-$(RM) $(TARGET_EXAMPLE_C_4_ST_D)
	@-$(RM) $(TARGET_EXAMPLE_C_5_ST_D)
	@-$(RM) $(TARGET_EXAMPLE_C_6_ST_D)
	@-$(RM) $(TARGET_EXAMPLE_C_7_ST_D)
	@-$(RM) $(TARGET_EXAMPLE_C_8_ST_D)
	@-$(RM) $(TARGET_EXAMPLE_C_1_ST_R)
	@-$(RM) $(TARGET_EXAMPLE_C_2_ST_R)
	@-$(RM) $(TARGET_EXAMPLE_C_3_ST_R)
	@-$(RM) $(TARGET_EXAMPLE_C_4_ST_R)
	@-$(RM) $(TARGET_EXAMPLE_C_5_ST_R)
	@-$(RM) $(TARGET_EXAMPLE_C_6_ST_R)
	@-$(RM) $(TARGET_EXAMPLE_C_7_ST_R)
	@-$(RM) $(TARGET_EXAMPLE_C_8_ST_R)
	@-$(RM) $(OBJ_EXAMPLE_C_1_ST_D)
	@-$(RM) $(OBJ_EXAMPLE_C_2_ST_D)
	@-$(RM) $(OBJ_EXAMPLE_C_3_ST_D)
	@-$(RM) $(OBJ_EXAMPLE_C_4_ST_D)
	@-$(RM) $(OBJ_EXAMPLE_C_5_ST_D)
	@-$(RM) $(OBJ_EXAMPLE_C_6_ST_D)
	@-$(RM) $(OBJ_EXAMPLE_C_7_ST_D)
	@-$(RM) $(OBJ_EXAMPLE_C_8_ST_D)
	@-$(RM) $(OBJ_EXAMPLE_C_1_ST_R)
	@-$(RM) $(OBJ_EXAMPLE_C_2_ST_R)
	@-$(RM) $(OBJ_EXAMPLE_C_3_ST_R)
	@-$(RM) $(OBJ_EXAMPLE_C_4_ST_R)
	@-$(RM) $(OBJ_EXAMPLE_C_5_ST_R)
	@-$(RM) $(OBJ_EXAMPLE_C_6_ST_R)
	@-$(RM) $(OBJ_EXAMPLE_C_7_ST_R)
	@-$(RM) $(OBJ_EXAMPLE_C_8_ST_R)

clean.samples:
	@-$(RM) $(TARGET_SAMPLE_C_1_ST_D)
	@-$(RM) $(TARGET_SAMPLE_C_2_ST_D)
	@-$(RM) $(TARGET_SAMPLE_C_1_ST_R)
	@-$(RM) $(TARGET_SAMPLE_C_2_ST_R)
	@-$(RM) $(OBJ_SAMPLE_C_1_ST_D)
	@-$(RM) $(OBJ_SAMPLE_C_2_ST_D)
	@-$(RM) $(OBJ_SAMPLE_C_1_ST_R)
	@-$(RM) $(OBJ_SAMPLE_C_2_ST_R)

clean: clean.libs clean.test clean.examples clean.samples

################################################################################
# Internal Targets (invokable by make)

########################################
# core


$(TARGET_LIB_UN_ST_D): $(TARGET_LIB_ST_D)
	@$(CP) $(TARGET_LIB_ST_D) $@

$(TARGET_LIB_ST_D): $(OBJS_CORE_ST_D) makefile
	$(AR) $(AR_ARGS) $@ $(OBJS_CORE_ST_D_PM)

$(OBJ_CORE_orjapi__ST_D): $(PROJ_SRC_DIR)\orjapi.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -o$@ $(PROJ_SRC_DIR)\orjapi.c
$(OBJ_CORE_orjmem__ST_D): $(PROJ_SRC_DIR)\orjmem.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -o$@ $(PROJ_SRC_DIR)\orjmem.c
$(OBJ_CORE_orjstr__ST_D): $(PROJ_SRC_DIR)\orjstr.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -o$@ $(PROJ_SRC_DIR)\orjstr.c


$(TARGET_LIB_UN_ST_R): $(TARGET_LIB_ST_R)
	@$(CP) $(TARGET_LIB_ST_R) $@

$(TARGET_LIB_ST_R): $(OBJS_CORE_ST_R) makefile
	$(AR) $(AR_ARGS) $@ $(OBJS_CORE_ST_R_PM)

$(OBJ_CORE_orjapi__ST_R): $(PROJ_SRC_DIR)\orjapi.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -o$@ $(PROJ_SRC_DIR)\orjapi.c
$(OBJ_CORE_orjmem__ST_R): $(PROJ_SRC_DIR)\orjmem.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -o$@ $(PROJ_SRC_DIR)\orjmem.c
$(OBJ_CORE_orjstr__ST_R): $(PROJ_SRC_DIR)\orjstr.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -o$@ $(PROJ_SRC_DIR)\orjstr.c


########################################
# test

# C test client

$(TARGET_TEST_C_1_ST_D):	$(OBJ_TEST_C_1_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -e$@ $(OBJ_TEST_C_1_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_TEST_C_1_ST_D):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -o$@ $(SRC_TEST_C_1)

$(TARGET_TEST_C_1_ST_R):	$(OBJ_TEST_C_1_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -e$@ $(OBJ_TEST_C_1_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_TEST_C_1_ST_R):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -o$@ $(SRC_TEST_C_1)

########################################
# examples

# C example client

$(TARGET_EXAMPLE_C_1_ST_D):	$(OBJ_EXAMPLE_C_1_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -e$@ $(OBJ_EXAMPLE_C_1_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_EXAMPLE_C_1_ST_D):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -o$@ $(SRC_EXAMPLE_C_1)

$(TARGET_EXAMPLE_C_2_ST_D):	$(OBJ_EXAMPLE_C_2_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -e$@ $(OBJ_EXAMPLE_C_2_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_EXAMPLE_C_2_ST_D):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -o$@ $(SRC_EXAMPLE_C_2)

$(TARGET_EXAMPLE_C_3_ST_D):	$(OBJ_EXAMPLE_C_3_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -e$@ $(OBJ_EXAMPLE_C_3_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_EXAMPLE_C_3_ST_D):	$(SRC_EXAMPLE_C_3) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -o$@ $(SRC_EXAMPLE_C_3)

$(TARGET_EXAMPLE_C_4_ST_D):	$(OBJ_EXAMPLE_C_4_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -e$@ $(OBJ_EXAMPLE_C_4_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_EXAMPLE_C_4_ST_D):	$(SRC_EXAMPLE_C_4) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -o$@ $(SRC_EXAMPLE_C_4)

$(TARGET_EXAMPLE_C_5_ST_D):	$(OBJ_EXAMPLE_C_5_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -e$@ $(OBJ_EXAMPLE_C_5_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_EXAMPLE_C_5_ST_D):	$(SRC_EXAMPLE_C_5) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -o$@ $(SRC_EXAMPLE_C_5)

$(TARGET_EXAMPLE_C_6_ST_D):	$(OBJ_EXAMPLE_C_6_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -e$@ $(OBJ_EXAMPLE_C_6_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_EXAMPLE_C_6_ST_D):	$(SRC_EXAMPLE_C_6) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -o$@ $(SRC_EXAMPLE_C_6)

$(TARGET_EXAMPLE_C_7_ST_D):	$(OBJ_EXAMPLE_C_7_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -e$@ $(OBJ_EXAMPLE_C_7_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_EXAMPLE_C_7_ST_D):	$(SRC_EXAMPLE_C_7) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -o$@ $(SRC_EXAMPLE_C_7)

$(TARGET_EXAMPLE_C_8_ST_D):	$(OBJ_EXAMPLE_C_8_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -e$@ $(OBJ_EXAMPLE_C_8_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_EXAMPLE_C_8_ST_D):	$(SRC_EXAMPLE_C_8) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -o$@ $(SRC_EXAMPLE_C_8)

$(TARGET_EXAMPLE_C_1_ST_R):	$(OBJ_EXAMPLE_C_1_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -e$@ $(OBJ_EXAMPLE_C_1_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_EXAMPLE_C_1_ST_R):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -o$@ $(SRC_EXAMPLE_C_1)

$(TARGET_EXAMPLE_C_2_ST_R):	$(OBJ_EXAMPLE_C_2_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -e$@ $(OBJ_EXAMPLE_C_2_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_EXAMPLE_C_2_ST_R):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -o$@ $(SRC_EXAMPLE_C_2)

$(TARGET_EXAMPLE_C_3_ST_R):	$(OBJ_EXAMPLE_C_3_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -e$@ $(OBJ_EXAMPLE_C_3_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_EXAMPLE_C_3_ST_R):	$(SRC_EXAMPLE_C_3) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -o$@ $(SRC_EXAMPLE_C_3)

$(TARGET_EXAMPLE_C_4_ST_R):	$(OBJ_EXAMPLE_C_4_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -e$@ $(OBJ_EXAMPLE_C_4_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_EXAMPLE_C_4_ST_R):	$(SRC_EXAMPLE_C_4) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -o$@ $(SRC_EXAMPLE_C_4)

$(TARGET_EXAMPLE_C_5_ST_R):	$(OBJ_EXAMPLE_C_5_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -e$@ $(OBJ_EXAMPLE_C_5_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_EXAMPLE_C_5_ST_R):	$(SRC_EXAMPLE_C_5) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -o$@ $(SRC_EXAMPLE_C_5)

$(TARGET_EXAMPLE_C_6_ST_R):	$(OBJ_EXAMPLE_C_6_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -e$@ $(OBJ_EXAMPLE_C_6_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_EXAMPLE_C_6_ST_R):	$(SRC_EXAMPLE_C_6) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -o$@ $(SRC_EXAMPLE_C_6)

$(TARGET_EXAMPLE_C_7_ST_R):	$(OBJ_EXAMPLE_C_7_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -e$@ $(OBJ_EXAMPLE_C_7_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_EXAMPLE_C_7_ST_R):	$(SRC_EXAMPLE_C_7) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -o$@ $(SRC_EXAMPLE_C_7)

$(TARGET_EXAMPLE_C_8_ST_R):	$(OBJ_EXAMPLE_C_8_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -e$@ $(OBJ_EXAMPLE_C_8_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_EXAMPLE_C_8_ST_R):	$(SRC_EXAMPLE_C_8) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -o$@ $(SRC_EXAMPLE_C_8)

########################################
# samples

# C sample client

$(TARGET_SAMPLE_C_1_ST_D):	$(OBJ_SAMPLE_C_1_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -e$@ $(OBJ_SAMPLE_C_1_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_SAMPLE_C_1_ST_D):	$(SRC_SAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -o$@ $(SRC_SAMPLE_C_1)

$(TARGET_SAMPLE_C_2_ST_D):	$(OBJ_SAMPLE_C_2_ST_D) makefile
	$(LD) $(LD_ARGS_ST_D) -e$@ $(OBJ_SAMPLE_C_2_ST_D) $(TARGET_LIB_ST_D) $(3PTY_LIBS__ST_D)

$(OBJ_SAMPLE_C_2_ST_D):	$(SRC_SAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_D) -o$@ $(SRC_SAMPLE_C_2)

$(TARGET_SAMPLE_C_1_ST_R):	$(OBJ_SAMPLE_C_1_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -e$@ $(OBJ_SAMPLE_C_1_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_SAMPLE_C_1_ST_R):	$(SRC_SAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -o$@ $(SRC_SAMPLE_C_1)

$(TARGET_SAMPLE_C_2_ST_R):	$(OBJ_SAMPLE_C_2_ST_R) makefile
	$(LD) $(LD_ARGS_ST_R) -e$@ $(OBJ_SAMPLE_C_2_ST_R) $(TARGET_LIB_ST_R) $(3PTY_LIBS__ST_R)

$(OBJ_SAMPLE_C_2_ST_R):	$(SRC_SAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_R) -o$@ $(SRC_SAMPLE_C_2)

################################################################################
