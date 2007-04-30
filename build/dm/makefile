################################################################################
# File:     makefile
#
# Purpose:  Makefile for the Open-RJ project, for the Digital Mars C/C++ Compiler
#           compiler, on Win32
#
# Created:  15th Feburary 2005
# Updated:  22nd February 2007
#
################################################################################


################################################################################
# Symbols

# Identification

COMP_TAG          =   dm
PROJ_TAG          =   openrj
PROJ_VER_MAJOR    =   1
PROJ_TAG_VER      =   $(PROJ_TAG).$(PROJ_VER_MAJOR)

CC                  =   dmc
CPPC                =   dmc
AR                  =   lib
LD                  =   link
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

COMMON_INCLUDES     =   

CC_INCLUDES = \
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
 \

CPPC_INCLUDES = \
 $(INCLUDES_LEADER)\
 $(PROJ_INCLUDE)\
 $(COMMON_INCLUDES)\
 -I"$(STLSOFT)\include"\
 \

3PTY_LIBS__ST_DEBUG = \
 \

3PTY_LIBS__ST_RELEASE = \
 \


LIB_PATHS =\
 \

LIBS_LEADER         =   

COMMON_LIB          =   

# #defines

CMN_DEF_NO_IMPLICIT_LINK =\
 -DOPENRJ_NO_IMPLICIT_LINK\
 \

COMMON_DEFS         =   -DWIN32 $(CMN_DEF_NO_IMPLICIT_LINK)

CC_DEFS             =   $(COMMON_DEFS)

CPPC_DEFS           =   $(COMMON_DEFS)

# Flags

CC_F_NOLOGO             =   
CC_F_COMPILE_ONLY       =   -c
CC_F_WARNING_MAX        =   
CC_F_WARNING_ERR        =   -wx

CPPC_F_NOLOGO       =   
CPPC_F_COMPILE_ONLY =   -c
CPPC_F_WARNING_MAX  =   
CPPC_F_WARNING_ERR  =   -wx
CPPC_F_EXCEPTIONS   =   -Ae
CPPC_F_RTTI         =   -Ar

CC_TOOL_FLAGS       =   

CC_FLAGS = \
 $(CC_TOOL_FLAGS)\
 $(CC_F_NOLOGO)\
 $(CC_F_COMPILE_ONLY)\
 $(CC_F_WARNING_MAX)\
 $(CC_F_WARNING_ERR)\
 \

CPPC_TOOL_FLAGS     =   

CPPC_FLAGS = \
 $(CPPC_TOOL_FLAGS)\
 $(CPPC_F_NOLOGO)\
 $(CPPC_F_COMPILE_ONLY)\
 $(CPPC_F_WARNING_MAX)\
 $(CPPC_F_WARNING_ERR)\
 $(CPPC_F_EXCEPTIONS)\
 $(CPPC_F_RTTI)\
 \

# Arguments (= flags + defines + includes)

CC_ARGS_ST_DEBUG                =   -D_DEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_ST_RELEASE                =   -DNDEBUG -o+space $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)

CPPC_ARGS_ST_DEBUG          =   -D_DEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)
CPPC_ARGS_ST_RELEASE          =   -DNDEBUG -o+space $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)

# archiver flags and arguments

AR_ARGS             =   -c -n

# linker flags and arguments

LD_F_NOLOGO = 

LD_ARGS_ST_DEBUG            =   -DELEXECUTABLE -NOLOGO $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)
LD_ARGS_ST_RELEASE            =   -DELEXECUTABLE -NOLOGO $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)

################################################################################
# Targets

########################################
# TARGETS_LIBS

TARGET_LIB_ST_DEBUG         =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG).debug.lib
TARGET_LIB_UN_ST_DEBUG      =   $(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).debug.lib
TARGET_LIB_ST_RELEASE         =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG).lib
TARGET_LIB_UN_ST_RELEASE      =   $(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).lib

TARGETS_LIBS =\
 $(TARGET_LIB_ST_DEBUG)\
 $(TARGET_LIB_UN_ST_DEBUG)\
 $(TARGET_LIB_ST_RELEASE)\
 $(TARGET_LIB_UN_ST_RELEASE)\
 \

########################################
# TARGETS_TESTS

TARGET_TEST_C_1_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_c_1.$(COMP_TAG).debug.exe
TARGET_TEST_CPP_1_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_cpp_1.$(COMP_TAG).debug.exe
TARGET_TEST_STL_1_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_stl_1.$(COMP_TAG).debug.exe
TARGET_TEST_C_1_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_c_1.$(COMP_TAG).exe
TARGET_TEST_CPP_1_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_cpp_1.$(COMP_TAG).exe
TARGET_TEST_STL_1_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_stl_1.$(COMP_TAG).exe

TARGETS_TESTS =\
 $(TARGET_TEST_C_1_ST_DEBUG)\
 $(TARGET_TEST_C_1_ST_RELEASE)\
 $(TARGET_TEST_CPP_1_ST_DEBUG)\
 $(TARGET_TEST_CPP_1_ST_RELEASE)\
 $(TARGET_TEST_STL_1_ST_DEBUG)\
 $(TARGET_TEST_STL_1_ST_RELEASE)\
 \

########################################
# TARGETS_EXAMPLES

TARGET_EXAMPLE_C_1_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_1.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_2_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_2.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_3_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_3.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_4_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_4.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_5_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_5.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_6_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_6.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_7_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_7.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_8_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_8.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_CPP_1_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_1.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_CPP_2_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_2.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_CPP_3_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_3.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_CPP_4_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_4.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_CPP_5_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_5.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_CPP_6_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_6.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_STL_1_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_1.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_STL_2_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_2.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_STL_3_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_3.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_STL_4_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_4.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_STL_5_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_5.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_STL_6_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_6.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_STL_7_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_7.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_1_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_1.$(COMP_TAG).exe
TARGET_EXAMPLE_C_2_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_2.$(COMP_TAG).exe
TARGET_EXAMPLE_C_3_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_3.$(COMP_TAG).exe
TARGET_EXAMPLE_C_4_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_4.$(COMP_TAG).exe
TARGET_EXAMPLE_C_5_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_5.$(COMP_TAG).exe
TARGET_EXAMPLE_C_6_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_6.$(COMP_TAG).exe
TARGET_EXAMPLE_C_7_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_7.$(COMP_TAG).exe
TARGET_EXAMPLE_C_8_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_8.$(COMP_TAG).exe
TARGET_EXAMPLE_CPP_1_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_1.$(COMP_TAG).exe
TARGET_EXAMPLE_CPP_2_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_2.$(COMP_TAG).exe
TARGET_EXAMPLE_CPP_3_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_3.$(COMP_TAG).exe
TARGET_EXAMPLE_CPP_4_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_4.$(COMP_TAG).exe
TARGET_EXAMPLE_CPP_5_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_5.$(COMP_TAG).exe
TARGET_EXAMPLE_CPP_6_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_6.$(COMP_TAG).exe
TARGET_EXAMPLE_STL_1_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_1.$(COMP_TAG).exe
TARGET_EXAMPLE_STL_2_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_2.$(COMP_TAG).exe
TARGET_EXAMPLE_STL_3_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_3.$(COMP_TAG).exe
TARGET_EXAMPLE_STL_4_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_4.$(COMP_TAG).exe
TARGET_EXAMPLE_STL_5_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_5.$(COMP_TAG).exe
TARGET_EXAMPLE_STL_6_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_6.$(COMP_TAG).exe
TARGET_EXAMPLE_STL_7_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_7.$(COMP_TAG).exe

TARGETS_EXAMPLES =\
 $(TARGET_EXAMPLE_C_1_ST_DEBUG)\
 $(TARGET_EXAMPLE_C_2_ST_DEBUG)\
 $(TARGET_EXAMPLE_C_3_ST_DEBUG)\
 $(TARGET_EXAMPLE_C_4_ST_DEBUG)\
 $(TARGET_EXAMPLE_C_5_ST_DEBUG)\
 $(TARGET_EXAMPLE_C_6_ST_DEBUG)\
 $(TARGET_EXAMPLE_C_7_ST_DEBUG)\
 $(TARGET_EXAMPLE_C_8_ST_DEBUG)\
 $(TARGET_EXAMPLE_C_1_ST_RELEASE)\
 $(TARGET_EXAMPLE_C_2_ST_RELEASE)\
 $(TARGET_EXAMPLE_C_3_ST_RELEASE)\
 $(TARGET_EXAMPLE_C_4_ST_RELEASE)\
 $(TARGET_EXAMPLE_C_5_ST_RELEASE)\
 $(TARGET_EXAMPLE_C_6_ST_RELEASE)\
 $(TARGET_EXAMPLE_C_7_ST_RELEASE)\
 $(TARGET_EXAMPLE_C_8_ST_RELEASE)\
 $(TARGET_EXAMPLE_CPP_1_ST_DEBUG)\
 $(TARGET_EXAMPLE_CPP_2_ST_DEBUG)\
 $(TARGET_EXAMPLE_CPP_3_ST_DEBUG)\
 $(TARGET_EXAMPLE_CPP_4_ST_DEBUG)\
 $(TARGET_EXAMPLE_CPP_5_ST_DEBUG)\
 $(TARGET_EXAMPLE_CPP_6_ST_DEBUG)\
 $(TARGET_EXAMPLE_CPP_1_ST_RELEASE)\
 $(TARGET_EXAMPLE_CPP_2_ST_RELEASE)\
 $(TARGET_EXAMPLE_CPP_3_ST_RELEASE)\
 $(TARGET_EXAMPLE_CPP_4_ST_RELEASE)\
 $(TARGET_EXAMPLE_CPP_5_ST_RELEASE)\
 $(TARGET_EXAMPLE_CPP_6_ST_RELEASE)\
 $(TARGET_EXAMPLE_STL_1_ST_DEBUG)\
 $(TARGET_EXAMPLE_STL_2_ST_DEBUG)\
 $(TARGET_EXAMPLE_STL_3_ST_DEBUG)\
 $(TARGET_EXAMPLE_STL_4_ST_DEBUG)\
 $(TARGET_EXAMPLE_STL_5_ST_DEBUG)\
 $(TARGET_EXAMPLE_STL_6_ST_DEBUG)\
 $(TARGET_EXAMPLE_STL_7_ST_DEBUG)\
 $(TARGET_EXAMPLE_STL_1_ST_RELEASE)\
 $(TARGET_EXAMPLE_STL_2_ST_RELEASE)\
 $(TARGET_EXAMPLE_STL_3_ST_RELEASE)\
 $(TARGET_EXAMPLE_STL_4_ST_RELEASE)\
 $(TARGET_EXAMPLE_STL_5_ST_RELEASE)\
 $(TARGET_EXAMPLE_STL_6_ST_RELEASE)\
 $(TARGET_EXAMPLE_STL_7_ST_RELEASE)\
 \

########################################
# TARGETS_SAMPLES

TARGET_SAMPLE_C_1_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_1.$(COMP_TAG).debug.exe
TARGET_SAMPLE_C_2_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_2.$(COMP_TAG).debug.exe
TARGET_SAMPLE_CPP_1_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_cpp_1.$(COMP_TAG).debug.exe
TARGET_SAMPLE_STL_1_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_stl_1.$(COMP_TAG).debug.exe
TARGET_SAMPLE_STL_2_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_stl_2.$(COMP_TAG).debug.exe
TARGET_SAMPLE_STL_3_ST_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_stl_3.$(COMP_TAG).debug.exe
TARGET_SAMPLE_C_1_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_1.$(COMP_TAG).exe
TARGET_SAMPLE_C_2_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_2.$(COMP_TAG).exe
TARGET_SAMPLE_CPP_1_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_cpp_1.$(COMP_TAG).exe
TARGET_SAMPLE_STL_1_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_stl_1.$(COMP_TAG).exe
TARGET_SAMPLE_STL_2_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_stl_2.$(COMP_TAG).exe
TARGET_SAMPLE_STL_3_ST_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_stl_3.$(COMP_TAG).exe

TARGETS_SAMPLES =\
 $(TARGET_SAMPLE_C_1_ST_DEBUG)\
 $(TARGET_SAMPLE_C_2_ST_DEBUG)\
 $(TARGET_SAMPLE_C_1_ST_RELEASE)\
 $(TARGET_SAMPLE_C_2_ST_RELEASE)\
 $(TARGET_SAMPLE_CPP_1_ST_DEBUG)\
 $(TARGET_SAMPLE_CPP_1_ST_RELEASE)\
 $(TARGET_SAMPLE_STL_1_ST_DEBUG)\
 $(TARGET_SAMPLE_STL_2_ST_DEBUG)\
 $(TARGET_SAMPLE_STL_3_ST_DEBUG)\
 $(TARGET_SAMPLE_STL_1_ST_RELEASE)\
 $(TARGET_SAMPLE_STL_2_ST_RELEASE)\
 $(TARGET_SAMPLE_STL_3_ST_RELEASE)\
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

OBJ_CORE_orjapi__ST_DEBUG = $(PROJ_OBJ_DIR)\orjapi.debug.obj
OBJ_CORE_orjmem__ST_DEBUG = $(PROJ_OBJ_DIR)\orjmem.debug.obj
OBJ_CORE_orjstr__ST_DEBUG = $(PROJ_OBJ_DIR)\orjstr.debug.obj

OBJS_CORE_ST_DEBUG = \
 $(OBJ_CORE_orjapi__ST_DEBUG)\
 $(OBJ_CORE_orjmem__ST_DEBUG)\
 $(OBJ_CORE_orjstr__ST_DEBUG)\
 \

OBJ_CORE_orjapi__ST_RELEASE = $(PROJ_OBJ_DIR)\orjapi.obj
OBJ_CORE_orjmem__ST_RELEASE = $(PROJ_OBJ_DIR)\orjmem.obj
OBJ_CORE_orjstr__ST_RELEASE = $(PROJ_OBJ_DIR)\orjstr.obj

OBJS_CORE_ST_RELEASE = \
 $(OBJ_CORE_orjapi__ST_RELEASE)\
 $(OBJ_CORE_orjmem__ST_RELEASE)\
 $(OBJ_CORE_orjstr__ST_RELEASE)\
 \

OBJS_CORE =\
 $(OBJS_CORE_ST_DEBUG)\
 $(OBJS_CORE_ST_RELEASE)\
 \

########################################
# OBJS_LIBS

OBJS_LIBS =\
 $(OBJS_CORE)\
 \

########################################
# OBJS_TESTS

OBJ_TEST_C_1_ST_DEBUG        =   $(PROJ_OBJ_DIR)\test_c_1.debug.obj
OBJ_TEST_CPP_1_ST_DEBUG        =   $(PROJ_OBJ_DIR)\test_cpp_1.debug.obj
OBJ_TEST_STL_1_ST_DEBUG        =   $(PROJ_OBJ_DIR)\test_stl_1.debug.obj
OBJ_TEST_C_1_ST_RELEASE        =   $(PROJ_OBJ_DIR)\test_c_1.obj
OBJ_TEST_CPP_1_ST_RELEASE        =   $(PROJ_OBJ_DIR)\test_cpp_1.obj
OBJ_TEST_STL_1_ST_RELEASE        =   $(PROJ_OBJ_DIR)\test_stl_1.obj

OBJS_TESTS =\
 $(OBJ_TEST_C_1_ST_DEBUG)\
 $(OBJ_TEST_C_1_ST_RELEASE)\
 $(OBJ_TEST_CPP_1_ST_DEBUG)\
 $(OBJ_TEST_CPP_1_ST_RELEASE)\
 $(OBJ_TEST_STL_1_ST_DEBUG)\
 $(OBJ_TEST_STL_1_ST_RELEASE)\
 \

########################################
# OBJS_EXAMPLES

OBJ_EXAMPLE_C_1_ST_DEBUG        =   $(PROJ_OBJ_DIR)\example_c_1.debug.obj
OBJ_EXAMPLE_C_2_ST_DEBUG        =   $(PROJ_OBJ_DIR)\example_c_2.debug.obj
OBJ_EXAMPLE_C_3_ST_DEBUG        =   $(PROJ_OBJ_DIR)\example_c_3.debug.obj
OBJ_EXAMPLE_C_4_ST_DEBUG        =   $(PROJ_OBJ_DIR)\example_c_4.debug.obj
OBJ_EXAMPLE_C_5_ST_DEBUG        =   $(PROJ_OBJ_DIR)\example_c_5.debug.obj
OBJ_EXAMPLE_C_6_ST_DEBUG        =   $(PROJ_OBJ_DIR)\example_c_6.debug.obj
OBJ_EXAMPLE_C_7_ST_DEBUG        =   $(PROJ_OBJ_DIR)\example_c_7.debug.obj
OBJ_EXAMPLE_C_8_ST_DEBUG        =   $(PROJ_OBJ_DIR)\example_c_8.debug.obj
OBJ_EXAMPLE_CPP_1_ST_DEBUG        =   $(PROJ_OBJ_DIR)\example_cpp_1.debug.obj
OBJ_EXAMPLE_CPP_2_ST_DEBUG        =   $(PROJ_OBJ_DIR)\example_cpp_2.debug.obj
OBJ_EXAMPLE_CPP_3_ST_DEBUG        =   $(PROJ_OBJ_DIR)\example_cpp_3.debug.obj
OBJ_EXAMPLE_CPP_4_ST_DEBUG        =   $(PROJ_OBJ_DIR)\example_cpp_4.debug.obj
OBJ_EXAMPLE_CPP_5_ST_DEBUG        =   $(PROJ_OBJ_DIR)\example_cpp_5.debug.obj
OBJ_EXAMPLE_CPP_6_ST_DEBUG        =   $(PROJ_OBJ_DIR)\example_cpp_6.debug.obj
OBJ_EXAMPLE_STL_1_ST_DEBUG        =   $(PROJ_OBJ_DIR)\example_stl_1.debug.obj
OBJ_EXAMPLE_STL_2_ST_DEBUG        =   $(PROJ_OBJ_DIR)\example_stl_2.debug.obj
OBJ_EXAMPLE_STL_3_ST_DEBUG        =   $(PROJ_OBJ_DIR)\example_stl_3.debug.obj
OBJ_EXAMPLE_STL_4_ST_DEBUG        =   $(PROJ_OBJ_DIR)\example_stl_4.debug.obj
OBJ_EXAMPLE_STL_5_ST_DEBUG        =   $(PROJ_OBJ_DIR)\example_stl_5.debug.obj
OBJ_EXAMPLE_STL_6_ST_DEBUG        =   $(PROJ_OBJ_DIR)\example_stl_6.debug.obj
OBJ_EXAMPLE_STL_7_ST_DEBUG        =   $(PROJ_OBJ_DIR)\example_stl_7.debug.obj
OBJ_EXAMPLE_C_1_ST_RELEASE        =   $(PROJ_OBJ_DIR)\example_c_1.obj
OBJ_EXAMPLE_C_2_ST_RELEASE        =   $(PROJ_OBJ_DIR)\example_c_2.obj
OBJ_EXAMPLE_C_3_ST_RELEASE        =   $(PROJ_OBJ_DIR)\example_c_3.obj
OBJ_EXAMPLE_C_4_ST_RELEASE        =   $(PROJ_OBJ_DIR)\example_c_4.obj
OBJ_EXAMPLE_C_5_ST_RELEASE        =   $(PROJ_OBJ_DIR)\example_c_5.obj
OBJ_EXAMPLE_C_6_ST_RELEASE        =   $(PROJ_OBJ_DIR)\example_c_6.obj
OBJ_EXAMPLE_C_7_ST_RELEASE        =   $(PROJ_OBJ_DIR)\example_c_7.obj
OBJ_EXAMPLE_C_8_ST_RELEASE        =   $(PROJ_OBJ_DIR)\example_c_8.obj
OBJ_EXAMPLE_CPP_1_ST_RELEASE        =   $(PROJ_OBJ_DIR)\example_cpp_1.obj
OBJ_EXAMPLE_CPP_2_ST_RELEASE        =   $(PROJ_OBJ_DIR)\example_cpp_2.obj
OBJ_EXAMPLE_CPP_3_ST_RELEASE        =   $(PROJ_OBJ_DIR)\example_cpp_3.obj
OBJ_EXAMPLE_CPP_4_ST_RELEASE        =   $(PROJ_OBJ_DIR)\example_cpp_4.obj
OBJ_EXAMPLE_CPP_5_ST_RELEASE        =   $(PROJ_OBJ_DIR)\example_cpp_5.obj
OBJ_EXAMPLE_CPP_6_ST_RELEASE        =   $(PROJ_OBJ_DIR)\example_cpp_6.obj
OBJ_EXAMPLE_STL_1_ST_RELEASE        =   $(PROJ_OBJ_DIR)\example_stl_1.obj
OBJ_EXAMPLE_STL_2_ST_RELEASE        =   $(PROJ_OBJ_DIR)\example_stl_2.obj
OBJ_EXAMPLE_STL_3_ST_RELEASE        =   $(PROJ_OBJ_DIR)\example_stl_3.obj
OBJ_EXAMPLE_STL_4_ST_RELEASE        =   $(PROJ_OBJ_DIR)\example_stl_4.obj
OBJ_EXAMPLE_STL_5_ST_RELEASE        =   $(PROJ_OBJ_DIR)\example_stl_5.obj
OBJ_EXAMPLE_STL_6_ST_RELEASE        =   $(PROJ_OBJ_DIR)\example_stl_6.obj
OBJ_EXAMPLE_STL_7_ST_RELEASE        =   $(PROJ_OBJ_DIR)\example_stl_7.obj

OBJS_EXAMPLES =\
 $(OBJ_EXAMPLE_C_1_ST_DEBUG)\
 $(OBJ_EXAMPLE_C_2_ST_DEBUG)\
 $(OBJ_EXAMPLE_C_3_ST_DEBUG)\
 $(OBJ_EXAMPLE_C_4_ST_DEBUG)\
 $(OBJ_EXAMPLE_C_5_ST_DEBUG)\
 $(OBJ_EXAMPLE_C_6_ST_DEBUG)\
 $(OBJ_EXAMPLE_C_7_ST_DEBUG)\
 $(OBJ_EXAMPLE_C_8_ST_DEBUG)\
 $(OBJ_EXAMPLE_C_1_ST_RELEASE)\
 $(OBJ_EXAMPLE_C_2_ST_RELEASE)\
 $(OBJ_EXAMPLE_C_3_ST_RELEASE)\
 $(OBJ_EXAMPLE_C_4_ST_RELEASE)\
 $(OBJ_EXAMPLE_C_5_ST_RELEASE)\
 $(OBJ_EXAMPLE_C_6_ST_RELEASE)\
 $(OBJ_EXAMPLE_C_7_ST_RELEASE)\
 $(OBJ_EXAMPLE_C_8_ST_RELEASE)\
 $(OBJ_EXAMPLE_CPP_1_ST_DEBUG)\
 $(OBJ_EXAMPLE_CPP_2_ST_DEBUG)\
 $(OBJ_EXAMPLE_CPP_3_ST_DEBUG)\
 $(OBJ_EXAMPLE_CPP_4_ST_DEBUG)\
 $(OBJ_EXAMPLE_CPP_5_ST_DEBUG)\
 $(OBJ_EXAMPLE_CPP_6_ST_DEBUG)\
 $(OBJ_EXAMPLE_CPP_1_ST_RELEASE)\
 $(OBJ_EXAMPLE_CPP_2_ST_RELEASE)\
 $(OBJ_EXAMPLE_CPP_3_ST_RELEASE)\
 $(OBJ_EXAMPLE_CPP_4_ST_RELEASE)\
 $(OBJ_EXAMPLE_CPP_5_ST_RELEASE)\
 $(OBJ_EXAMPLE_CPP_6_ST_RELEASE)\
 $(OBJ_EXAMPLE_STL_1_ST_DEBUG)\
 $(OBJ_EXAMPLE_STL_2_ST_DEBUG)\
 $(OBJ_EXAMPLE_STL_3_ST_DEBUG)\
 $(OBJ_EXAMPLE_STL_4_ST_DEBUG)\
 $(OBJ_EXAMPLE_STL_5_ST_DEBUG)\
 $(OBJ_EXAMPLE_STL_6_ST_DEBUG)\
 $(OBJ_EXAMPLE_STL_7_ST_DEBUG)\
 $(OBJ_EXAMPLE_STL_1_ST_RELEASE)\
 $(OBJ_EXAMPLE_STL_2_ST_RELEASE)\
 $(OBJ_EXAMPLE_STL_3_ST_RELEASE)\
 $(OBJ_EXAMPLE_STL_4_ST_RELEASE)\
 $(OBJ_EXAMPLE_STL_5_ST_RELEASE)\
 $(OBJ_EXAMPLE_STL_6_ST_RELEASE)\
 $(OBJ_EXAMPLE_STL_7_ST_RELEASE)\
 \

########################################
# OBJS_SAMPLES

OBJ_SAMPLE_C_1_ST_DEBUG        =   $(PROJ_OBJ_DIR)\sample_c_1.debug.obj
OBJ_SAMPLE_C_2_ST_DEBUG        =   $(PROJ_OBJ_DIR)\sample_c_2.debug.obj
OBJ_SAMPLE_CPP_1_ST_DEBUG        =   $(PROJ_OBJ_DIR)\sample_cpp_1.debug.obj
OBJ_SAMPLE_STL_1_ST_DEBUG        =   $(PROJ_OBJ_DIR)\sample_stl_1.debug.obj
OBJ_SAMPLE_STL_2_ST_DEBUG        =   $(PROJ_OBJ_DIR)\sample_stl_2.debug.obj
OBJ_SAMPLE_STL_3_ST_DEBUG        =   $(PROJ_OBJ_DIR)\sample_stl_3.debug.obj
OBJ_SAMPLE_C_1_ST_RELEASE        =   $(PROJ_OBJ_DIR)\sample_c_1.obj
OBJ_SAMPLE_C_2_ST_RELEASE        =   $(PROJ_OBJ_DIR)\sample_c_2.obj
OBJ_SAMPLE_CPP_1_ST_RELEASE        =   $(PROJ_OBJ_DIR)\sample_cpp_1.obj
OBJ_SAMPLE_STL_1_ST_RELEASE        =   $(PROJ_OBJ_DIR)\sample_stl_1.obj
OBJ_SAMPLE_STL_2_ST_RELEASE        =   $(PROJ_OBJ_DIR)\sample_stl_2.obj
OBJ_SAMPLE_STL_3_ST_RELEASE        =   $(PROJ_OBJ_DIR)\sample_stl_3.obj

OBJS_SAMPLES =\
 $(OBJ_SAMPLE_C_1_ST_DEBUG)\
 $(OBJ_SAMPLE_C_2_ST_DEBUG)\
 $(OBJ_SAMPLE_C_1_ST_RELEASE)\
 $(OBJ_SAMPLE_C_2_ST_RELEASE)\
 $(OBJ_SAMPLE_CPP_1_ST_DEBUG)\
 $(OBJ_SAMPLE_CPP_1_ST_RELEASE)\
 $(OBJ_SAMPLE_STL_1_ST_DEBUG)\
 $(OBJ_SAMPLE_STL_2_ST_DEBUG)\
 $(OBJ_SAMPLE_STL_3_ST_DEBUG)\
 $(OBJ_SAMPLE_STL_1_ST_RELEASE)\
 $(OBJ_SAMPLE_STL_2_ST_RELEASE)\
 $(OBJ_SAMPLE_STL_3_ST_RELEASE)\
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

HEADERS_MAPPING_CPP =\
 $(PROJ_INCLUDE_DIR)\openrj\cpp\openrj.hpp\
 $(PROJ_INCLUDE_DIR)\openrj\cpp\database.hpp\
 $(PROJ_INCLUDE_DIR)\openrj\cpp\field.hpp\
 $(PROJ_INCLUDE_DIR)\openrj\cpp\record.hpp\
 $(PROJ_INCLUDE_DIR)\openrj\cpp\openrjfwd.hpp\
 \

HEADERS_MAPPING_STL =\
 $(PROJ_INCLUDE_DIR)\openrj\stl\openrj.hpp\
 $(PROJ_INCLUDE_DIR)\openrj\stl\database.hpp\
 $(PROJ_INCLUDE_DIR)\openrj\stl\field.hpp\
 $(PROJ_INCLUDE_DIR)\openrj\stl\record.hpp\
 $(PROJ_INCLUDE_DIR)\openrj\stl\openrjfwd.hpp\
 $(PROJ_INCLUDE_DIR)\openrj\stl\functional.hpp\
 $(PROJ_INCLUDE_DIR)\openrj\stl\utility.hpp\
 \

########################################
# SRC_TESTS

SRC_TEST_C_1 =   $(PROJ_TESTS_DIR)\c\test_c_1\test_c_1.c
SRC_TEST_CPP_1 =   $(PROJ_TESTS_DIR)\cpp\test_cpp_1\test_cpp_1.cpp
SRC_TEST_STL_1 =   $(PROJ_TESTS_DIR)\stl\test_stl_1\test_stl_1.cpp

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
SRC_EXAMPLE_CPP_1 =   $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_1\example_cpp_1.cpp
SRC_EXAMPLE_CPP_2 =   $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_2\example_cpp_2.cpp
SRC_EXAMPLE_CPP_3 =   $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_3\example_cpp_3.cpp
SRC_EXAMPLE_CPP_4 =   $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_4\example_cpp_4.cpp
SRC_EXAMPLE_CPP_5 =   $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_5\example_cpp_5.cpp
SRC_EXAMPLE_CPP_6 =   $(PROJ_EXAMPLES_DIR)\cpp\example_cpp_6\example_cpp_6.cpp
SRC_EXAMPLE_STL_1 =   $(PROJ_EXAMPLES_DIR)\stl\example_stl_1\example_stl_1.cpp
SRC_EXAMPLE_STL_2 =   $(PROJ_EXAMPLES_DIR)\stl\example_stl_2\example_stl_2.cpp
SRC_EXAMPLE_STL_3 =   $(PROJ_EXAMPLES_DIR)\stl\example_stl_3\example_stl_3.cpp
SRC_EXAMPLE_STL_4 =   $(PROJ_EXAMPLES_DIR)\stl\example_stl_4\example_stl_4.cpp
SRC_EXAMPLE_STL_5 =   $(PROJ_EXAMPLES_DIR)\stl\example_stl_5\example_stl_5.cpp
SRC_EXAMPLE_STL_6 =   $(PROJ_EXAMPLES_DIR)\stl\example_stl_6\example_stl_6.cpp
SRC_EXAMPLE_STL_7 =   $(PROJ_EXAMPLES_DIR)\stl\example_stl_7\example_stl_7.cpp

########################################
# SRC_SAMPLES

SRC_SAMPLE_C_1 =   $(PROJ_SAMPLES_DIR)\c\sample_c_1\sample_c_1.c
SRC_SAMPLE_C_2 =   $(PROJ_SAMPLES_DIR)\c\sample_c_2\sample_c_2.c
SRC_SAMPLE_CPP_1 =   $(PROJ_SAMPLES_DIR)\cpp\sample_cpp_1\sample_cpp_1.cpp
SRC_SAMPLE_STL_1 =   $(PROJ_SAMPLES_DIR)\stl\sample_stl_1\sample_stl_1.cpp
SRC_SAMPLE_STL_2 =   $(PROJ_SAMPLES_DIR)\stl\sample_stl_2\sample_stl_2.cpp
SRC_SAMPLE_STL_3 =   $(PROJ_SAMPLES_DIR)\stl\sample_stl_3\sample_stl_3.cpp

################################################################################
# External Targets (invokable by make)

all:                build.all

check.lib.dir:
	@-if not exist $(PROJ_LIB_DIR)\NUL mkdir $(PROJ_LIB_DIR)

check.bin.dir:
	@-if not exist $(PROJ_BIN_DIR)\NUL mkdir $(PROJ_BIN_DIR)

build.libs.core:    check.lib.dir $(TARGETS_LIBS)

build.libs.com:		makefile

build.libs.dotnet:	makefile

build.libs:         build.libs.core build.libs.com build.libs.dotnet

build.examples:     check.bin.dir $(TARGETS_EXAMPLES)

build.samples:      check.bin.dir $(TARGETS_SAMPLES)

build.test:         check.bin.dir $(TARGETS_TESTS)

build.all:          build.libs build.examples build.samples build.test

build:              build.all

compile:            $(OBJS)


test_:
	$(TARGET_TEST_C_1_ST_DEBUG) --unittest
	$(TARGET_TEST_C_1_ST_RELEASE) --unittest
	$(TARGET_TEST_CPP_1_ST_DEBUG) --unittest
	$(TARGET_TEST_CPP_1_ST_RELEASE) --unittest
	$(TARGET_TEST_STL_1_ST_DEBUG) --unittest
	$(TARGET_TEST_STL_1_ST_RELEASE) --unittest

test:		build.all test_

test.all:	test

test-all:	test.all	# backwards compatibility


usage:
	@echo "make [usage | clean | compile | all | test | target] - default is 'all'"

clean.libs.core:
	@-$(RM) $(TARGET_LIB_ST_DEBUG)
	@-$(RM) $(TARGET_LIB_UN_ST_DEBUG)
	@-$(RM) $(TARGET_LIB_ST_RELEASE)
	@-$(RM) $(TARGET_LIB_UN_ST_RELEASE)
	@-$(RM) $(OBJ_CORE_orjapi__ST_DEBUG)
	@-$(RM) $(OBJ_CORE_orjmem__ST_DEBUG)
	@-$(RM) $(OBJ_CORE_orjstr__ST_DEBUG)
	@-$(RM) $(OBJ_CORE_orjapi__ST_RELEASE)
	@-$(RM) $(OBJ_CORE_orjmem__ST_RELEASE)
	@-$(RM) $(OBJ_CORE_orjstr__ST_RELEASE)

clean.libs.com:

clean.libs.dotnet:

clean.libs:         clean.libs.core clean.libs.com clean.libs.dotnet

clean.test:
	@-$(RM) $(TARGET_TEST_C_1_ST_DEBUG)
	@-$(RM) $(TARGET_TEST_C_1_ST_RELEASE)
	@-$(RM) $(TARGET_TEST_CPP_1_ST_DEBUG)
	@-$(RM) $(TARGET_TEST_CPP_1_ST_RELEASE)
	@-$(RM) $(TARGET_TEST_STL_1_ST_DEBUG)
	@-$(RM) $(TARGET_TEST_STL_1_ST_RELEASE)
	@-$(RM) $(OBJ_TEST_C_1_ST_DEBUG)
	@-$(RM) $(OBJ_TEST_C_1_ST_RELEASE)
	@-$(RM) $(OBJ_TEST_CPP_1_ST_DEBUG)
	@-$(RM) $(OBJ_TEST_CPP_1_ST_RELEASE)
	@-$(RM) $(OBJ_TEST_STL_1_ST_DEBUG)
	@-$(RM) $(OBJ_TEST_STL_1_ST_RELEASE)

clean.examples:
	@-$(RM) $(TARGET_EXAMPLE_C_1_ST_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_C_2_ST_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_C_3_ST_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_C_4_ST_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_C_5_ST_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_C_6_ST_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_C_7_ST_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_C_8_ST_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_C_1_ST_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_C_2_ST_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_C_3_ST_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_C_4_ST_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_C_5_ST_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_C_6_ST_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_C_7_ST_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_C_8_ST_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_CPP_1_ST_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_CPP_2_ST_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_CPP_3_ST_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_CPP_4_ST_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_CPP_5_ST_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_CPP_6_ST_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_CPP_1_ST_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_CPP_2_ST_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_CPP_3_ST_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_CPP_4_ST_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_CPP_5_ST_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_CPP_6_ST_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_STL_1_ST_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_STL_2_ST_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_STL_3_ST_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_STL_4_ST_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_STL_5_ST_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_STL_6_ST_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_STL_7_ST_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_STL_1_ST_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_STL_2_ST_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_STL_3_ST_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_STL_4_ST_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_STL_5_ST_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_STL_6_ST_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_STL_7_ST_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_C_1_ST_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_C_2_ST_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_C_3_ST_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_C_4_ST_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_C_5_ST_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_C_6_ST_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_C_7_ST_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_C_8_ST_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_C_1_ST_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_C_2_ST_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_C_3_ST_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_C_4_ST_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_C_5_ST_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_C_6_ST_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_C_7_ST_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_C_8_ST_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_CPP_1_ST_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_CPP_2_ST_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_CPP_3_ST_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_CPP_4_ST_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_CPP_5_ST_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_CPP_6_ST_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_CPP_1_ST_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_CPP_2_ST_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_CPP_3_ST_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_CPP_4_ST_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_CPP_5_ST_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_CPP_6_ST_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_STL_1_ST_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_STL_2_ST_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_STL_3_ST_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_STL_4_ST_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_STL_5_ST_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_STL_6_ST_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_STL_7_ST_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_STL_1_ST_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_STL_2_ST_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_STL_3_ST_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_STL_4_ST_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_STL_5_ST_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_STL_6_ST_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_STL_7_ST_RELEASE)

clean.samples:
	@-$(RM) $(TARGET_SAMPLE_C_1_ST_DEBUG)
	@-$(RM) $(TARGET_SAMPLE_C_2_ST_DEBUG)
	@-$(RM) $(TARGET_SAMPLE_C_1_ST_RELEASE)
	@-$(RM) $(TARGET_SAMPLE_C_2_ST_RELEASE)
	@-$(RM) $(TARGET_SAMPLE_CPP_1_ST_DEBUG)
	@-$(RM) $(TARGET_SAMPLE_CPP_1_ST_RELEASE)
	@-$(RM) $(TARGET_SAMPLE_STL_1_ST_DEBUG)
	@-$(RM) $(TARGET_SAMPLE_STL_2_ST_DEBUG)
	@-$(RM) $(TARGET_SAMPLE_STL_3_ST_DEBUG)
	@-$(RM) $(TARGET_SAMPLE_STL_1_ST_RELEASE)
	@-$(RM) $(TARGET_SAMPLE_STL_2_ST_RELEASE)
	@-$(RM) $(TARGET_SAMPLE_STL_3_ST_RELEASE)
	@-$(RM) $(OBJ_SAMPLE_C_1_ST_DEBUG)
	@-$(RM) $(OBJ_SAMPLE_C_2_ST_DEBUG)
	@-$(RM) $(OBJ_SAMPLE_C_1_ST_RELEASE)
	@-$(RM) $(OBJ_SAMPLE_C_2_ST_RELEASE)
	@-$(RM) $(OBJ_SAMPLE_CPP_1_ST_DEBUG)
	@-$(RM) $(OBJ_SAMPLE_CPP_1_ST_RELEASE)
	@-$(RM) $(OBJ_SAMPLE_STL_1_ST_DEBUG)
	@-$(RM) $(OBJ_SAMPLE_STL_2_ST_DEBUG)
	@-$(RM) $(OBJ_SAMPLE_STL_3_ST_DEBUG)
	@-$(RM) $(OBJ_SAMPLE_STL_1_ST_RELEASE)
	@-$(RM) $(OBJ_SAMPLE_STL_2_ST_RELEASE)
	@-$(RM) $(OBJ_SAMPLE_STL_3_ST_RELEASE)

clean: clean.libs clean.test clean.examples clean.samples

################################################################################
# Internal Targets (invokable by make)

########################################
# core


$(TARGET_LIB_UN_ST_DEBUG): $(TARGET_LIB_ST_DEBUG)
	@$(CP) $(TARGET_LIB_ST_DEBUG) $@

$(TARGET_LIB_ST_DEBUG): $(OBJS_CORE_ST_DEBUG) makefile
	$(AR) $(AR_ARGS) $@ $(OBJS_CORE_ST_DEBUG)

$(OBJ_CORE_orjapi__ST_DEBUG): $(PROJ_SRC_DIR)\orjapi.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_DEBUG) -o$@ $(PROJ_SRC_DIR)\orjapi.c
$(OBJ_CORE_orjmem__ST_DEBUG): $(PROJ_SRC_DIR)\orjmem.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_DEBUG) -o$@ $(PROJ_SRC_DIR)\orjmem.c
$(OBJ_CORE_orjstr__ST_DEBUG): $(PROJ_SRC_DIR)\orjstr.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_DEBUG) -o$@ $(PROJ_SRC_DIR)\orjstr.c


$(TARGET_LIB_UN_ST_RELEASE): $(TARGET_LIB_ST_RELEASE)
	@$(CP) $(TARGET_LIB_ST_RELEASE) $@

$(TARGET_LIB_ST_RELEASE): $(OBJS_CORE_ST_RELEASE) makefile
	$(AR) $(AR_ARGS) $@ $(OBJS_CORE_ST_RELEASE)

$(OBJ_CORE_orjapi__ST_RELEASE): $(PROJ_SRC_DIR)\orjapi.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_RELEASE) -o$@ $(PROJ_SRC_DIR)\orjapi.c
$(OBJ_CORE_orjmem__ST_RELEASE): $(PROJ_SRC_DIR)\orjmem.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_RELEASE) -o$@ $(PROJ_SRC_DIR)\orjmem.c
$(OBJ_CORE_orjstr__ST_RELEASE): $(PROJ_SRC_DIR)\orjstr.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_RELEASE) -o$@ $(PROJ_SRC_DIR)\orjstr.c


########################################
# test

# C test client

$(TARGET_TEST_C_1_ST_DEBUG):	$(OBJ_TEST_C_1_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_TEST_C_1_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_TEST_C_1_ST_DEBUG):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_DEBUG) -o$@ $(SRC_TEST_C_1)

$(TARGET_TEST_C_1_ST_RELEASE):	$(OBJ_TEST_C_1_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_TEST_C_1_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_TEST_C_1_ST_RELEASE):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_RELEASE) -o$@ $(SRC_TEST_C_1)

# C++ test client

$(TARGET_TEST_CPP_1_ST_DEBUG):	$(OBJ_TEST_CPP_1_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_TEST_CPP_1_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_TEST_CPP_1_ST_DEBUG):	$(SRC_TEST_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_DEBUG) -o$@ $(SRC_TEST_CPP_1)

$(TARGET_TEST_CPP_1_ST_RELEASE):	$(OBJ_TEST_CPP_1_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_TEST_CPP_1_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_TEST_CPP_1_ST_RELEASE):	$(SRC_TEST_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_RELEASE) -o$@ $(SRC_TEST_CPP_1)

# STL test client

$(TARGET_TEST_STL_1_ST_DEBUG):	$(OBJ_TEST_STL_1_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_TEST_STL_1_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_TEST_STL_1_ST_DEBUG):	$(SRC_TEST_STL_1) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_ST_DEBUG) -o$@ $(SRC_TEST_STL_1)

$(TARGET_TEST_STL_1_ST_RELEASE):	$(OBJ_TEST_STL_1_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_TEST_STL_1_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_TEST_STL_1_ST_RELEASE):	$(SRC_TEST_STL_1) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_ST_RELEASE) -o$@ $(SRC_TEST_STL_1)

########################################
# examples

# C example client

$(TARGET_EXAMPLE_C_1_ST_DEBUG):	$(OBJ_EXAMPLE_C_1_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_EXAMPLE_C_1_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_EXAMPLE_C_1_ST_DEBUG):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_DEBUG) -o$@ $(SRC_EXAMPLE_C_1)

$(TARGET_EXAMPLE_C_2_ST_DEBUG):	$(OBJ_EXAMPLE_C_2_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_EXAMPLE_C_2_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_EXAMPLE_C_2_ST_DEBUG):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_DEBUG) -o$@ $(SRC_EXAMPLE_C_2)

$(TARGET_EXAMPLE_C_3_ST_DEBUG):	$(OBJ_EXAMPLE_C_3_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_EXAMPLE_C_3_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_EXAMPLE_C_3_ST_DEBUG):	$(SRC_EXAMPLE_C_3) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_DEBUG) -o$@ $(SRC_EXAMPLE_C_3)

$(TARGET_EXAMPLE_C_4_ST_DEBUG):	$(OBJ_EXAMPLE_C_4_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_EXAMPLE_C_4_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_EXAMPLE_C_4_ST_DEBUG):	$(SRC_EXAMPLE_C_4) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_DEBUG) -o$@ $(SRC_EXAMPLE_C_4)

$(TARGET_EXAMPLE_C_5_ST_DEBUG):	$(OBJ_EXAMPLE_C_5_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_EXAMPLE_C_5_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_EXAMPLE_C_5_ST_DEBUG):	$(SRC_EXAMPLE_C_5) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_DEBUG) -o$@ $(SRC_EXAMPLE_C_5)

$(TARGET_EXAMPLE_C_6_ST_DEBUG):	$(OBJ_EXAMPLE_C_6_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_EXAMPLE_C_6_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_EXAMPLE_C_6_ST_DEBUG):	$(SRC_EXAMPLE_C_6) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_DEBUG) -o$@ $(SRC_EXAMPLE_C_6)

$(TARGET_EXAMPLE_C_7_ST_DEBUG):	$(OBJ_EXAMPLE_C_7_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_EXAMPLE_C_7_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_EXAMPLE_C_7_ST_DEBUG):	$(SRC_EXAMPLE_C_7) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_DEBUG) -o$@ $(SRC_EXAMPLE_C_7)

$(TARGET_EXAMPLE_C_8_ST_DEBUG):	$(OBJ_EXAMPLE_C_8_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_EXAMPLE_C_8_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_EXAMPLE_C_8_ST_DEBUG):	$(SRC_EXAMPLE_C_8) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_DEBUG) -o$@ $(SRC_EXAMPLE_C_8)

$(TARGET_EXAMPLE_C_1_ST_RELEASE):	$(OBJ_EXAMPLE_C_1_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_EXAMPLE_C_1_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_EXAMPLE_C_1_ST_RELEASE):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_RELEASE) -o$@ $(SRC_EXAMPLE_C_1)

$(TARGET_EXAMPLE_C_2_ST_RELEASE):	$(OBJ_EXAMPLE_C_2_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_EXAMPLE_C_2_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_EXAMPLE_C_2_ST_RELEASE):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_RELEASE) -o$@ $(SRC_EXAMPLE_C_2)

$(TARGET_EXAMPLE_C_3_ST_RELEASE):	$(OBJ_EXAMPLE_C_3_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_EXAMPLE_C_3_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_EXAMPLE_C_3_ST_RELEASE):	$(SRC_EXAMPLE_C_3) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_RELEASE) -o$@ $(SRC_EXAMPLE_C_3)

$(TARGET_EXAMPLE_C_4_ST_RELEASE):	$(OBJ_EXAMPLE_C_4_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_EXAMPLE_C_4_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_EXAMPLE_C_4_ST_RELEASE):	$(SRC_EXAMPLE_C_4) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_RELEASE) -o$@ $(SRC_EXAMPLE_C_4)

$(TARGET_EXAMPLE_C_5_ST_RELEASE):	$(OBJ_EXAMPLE_C_5_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_EXAMPLE_C_5_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_EXAMPLE_C_5_ST_RELEASE):	$(SRC_EXAMPLE_C_5) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_RELEASE) -o$@ $(SRC_EXAMPLE_C_5)

$(TARGET_EXAMPLE_C_6_ST_RELEASE):	$(OBJ_EXAMPLE_C_6_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_EXAMPLE_C_6_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_EXAMPLE_C_6_ST_RELEASE):	$(SRC_EXAMPLE_C_6) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_RELEASE) -o$@ $(SRC_EXAMPLE_C_6)

$(TARGET_EXAMPLE_C_7_ST_RELEASE):	$(OBJ_EXAMPLE_C_7_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_EXAMPLE_C_7_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_EXAMPLE_C_7_ST_RELEASE):	$(SRC_EXAMPLE_C_7) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_RELEASE) -o$@ $(SRC_EXAMPLE_C_7)

$(TARGET_EXAMPLE_C_8_ST_RELEASE):	$(OBJ_EXAMPLE_C_8_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_EXAMPLE_C_8_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_EXAMPLE_C_8_ST_RELEASE):	$(SRC_EXAMPLE_C_8) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_RELEASE) -o$@ $(SRC_EXAMPLE_C_8)

# C++ example client

$(TARGET_EXAMPLE_CPP_1_ST_DEBUG):	$(OBJ_EXAMPLE_CPP_1_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_EXAMPLE_CPP_1_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_EXAMPLE_CPP_1_ST_DEBUG):	$(SRC_EXAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_DEBUG) -o$@ $(SRC_EXAMPLE_CPP_1)

$(TARGET_EXAMPLE_CPP_2_ST_DEBUG):	$(OBJ_EXAMPLE_CPP_2_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_EXAMPLE_CPP_2_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_EXAMPLE_CPP_2_ST_DEBUG):	$(SRC_EXAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_DEBUG) -o$@ $(SRC_EXAMPLE_CPP_2)

$(TARGET_EXAMPLE_CPP_3_ST_DEBUG):	$(OBJ_EXAMPLE_CPP_3_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_EXAMPLE_CPP_3_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_EXAMPLE_CPP_3_ST_DEBUG):	$(SRC_EXAMPLE_CPP_3) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_DEBUG) -o$@ $(SRC_EXAMPLE_CPP_3)

$(TARGET_EXAMPLE_CPP_4_ST_DEBUG):	$(OBJ_EXAMPLE_CPP_4_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_EXAMPLE_CPP_4_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_EXAMPLE_CPP_4_ST_DEBUG):	$(SRC_EXAMPLE_CPP_4) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_DEBUG) -o$@ $(SRC_EXAMPLE_CPP_4)

$(TARGET_EXAMPLE_CPP_5_ST_DEBUG):	$(OBJ_EXAMPLE_CPP_5_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_EXAMPLE_CPP_5_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_EXAMPLE_CPP_5_ST_DEBUG):	$(SRC_EXAMPLE_CPP_5) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_DEBUG) -o$@ $(SRC_EXAMPLE_CPP_5)

$(TARGET_EXAMPLE_CPP_6_ST_DEBUG):	$(OBJ_EXAMPLE_CPP_6_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_EXAMPLE_CPP_6_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_EXAMPLE_CPP_6_ST_DEBUG):	$(SRC_EXAMPLE_CPP_6) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_DEBUG) -o$@ $(SRC_EXAMPLE_CPP_6)

$(TARGET_EXAMPLE_CPP_1_ST_RELEASE):	$(OBJ_EXAMPLE_CPP_1_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_EXAMPLE_CPP_1_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_EXAMPLE_CPP_1_ST_RELEASE):	$(SRC_EXAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_RELEASE) -o$@ $(SRC_EXAMPLE_CPP_1)

$(TARGET_EXAMPLE_CPP_2_ST_RELEASE):	$(OBJ_EXAMPLE_CPP_2_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_EXAMPLE_CPP_2_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_EXAMPLE_CPP_2_ST_RELEASE):	$(SRC_EXAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_RELEASE) -o$@ $(SRC_EXAMPLE_CPP_2)

$(TARGET_EXAMPLE_CPP_3_ST_RELEASE):	$(OBJ_EXAMPLE_CPP_3_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_EXAMPLE_CPP_3_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_EXAMPLE_CPP_3_ST_RELEASE):	$(SRC_EXAMPLE_CPP_3) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_RELEASE) -o$@ $(SRC_EXAMPLE_CPP_3)

$(TARGET_EXAMPLE_CPP_4_ST_RELEASE):	$(OBJ_EXAMPLE_CPP_4_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_EXAMPLE_CPP_4_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_EXAMPLE_CPP_4_ST_RELEASE):	$(SRC_EXAMPLE_CPP_4) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_RELEASE) -o$@ $(SRC_EXAMPLE_CPP_4)

$(TARGET_EXAMPLE_CPP_5_ST_RELEASE):	$(OBJ_EXAMPLE_CPP_5_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_EXAMPLE_CPP_5_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_EXAMPLE_CPP_5_ST_RELEASE):	$(SRC_EXAMPLE_CPP_5) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_RELEASE) -o$@ $(SRC_EXAMPLE_CPP_5)

$(TARGET_EXAMPLE_CPP_6_ST_RELEASE):	$(OBJ_EXAMPLE_CPP_6_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_EXAMPLE_CPP_6_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_EXAMPLE_CPP_6_ST_RELEASE):	$(SRC_EXAMPLE_CPP_6) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_RELEASE) -o$@ $(SRC_EXAMPLE_CPP_6)

# STL example client

$(TARGET_EXAMPLE_STL_1_ST_DEBUG):	$(OBJ_EXAMPLE_STL_1_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_EXAMPLE_STL_1_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_EXAMPLE_STL_1_ST_DEBUG):	$(SRC_EXAMPLE_STL_1) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_ST_DEBUG) -o$@ $(SRC_EXAMPLE_STL_1)

$(TARGET_EXAMPLE_STL_2_ST_DEBUG):	$(OBJ_EXAMPLE_STL_2_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_EXAMPLE_STL_2_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_EXAMPLE_STL_2_ST_DEBUG):	$(SRC_EXAMPLE_STL_2) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_ST_DEBUG) -o$@ $(SRC_EXAMPLE_STL_2)

$(TARGET_EXAMPLE_STL_3_ST_DEBUG):	$(OBJ_EXAMPLE_STL_3_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_EXAMPLE_STL_3_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_EXAMPLE_STL_3_ST_DEBUG):	$(SRC_EXAMPLE_STL_3) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_ST_DEBUG) -o$@ $(SRC_EXAMPLE_STL_3)

$(TARGET_EXAMPLE_STL_4_ST_DEBUG):	$(OBJ_EXAMPLE_STL_4_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_EXAMPLE_STL_4_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_EXAMPLE_STL_4_ST_DEBUG):	$(SRC_EXAMPLE_STL_4) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_ST_DEBUG) -o$@ $(SRC_EXAMPLE_STL_4)

$(TARGET_EXAMPLE_STL_5_ST_DEBUG):	$(OBJ_EXAMPLE_STL_5_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_EXAMPLE_STL_5_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_EXAMPLE_STL_5_ST_DEBUG):	$(SRC_EXAMPLE_STL_5) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_ST_DEBUG) -o$@ $(SRC_EXAMPLE_STL_5)

$(TARGET_EXAMPLE_STL_6_ST_DEBUG):	$(OBJ_EXAMPLE_STL_6_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_EXAMPLE_STL_6_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_EXAMPLE_STL_6_ST_DEBUG):	$(SRC_EXAMPLE_STL_6) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_ST_DEBUG) -o$@ $(SRC_EXAMPLE_STL_6)

$(TARGET_EXAMPLE_STL_7_ST_DEBUG):	$(OBJ_EXAMPLE_STL_7_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_EXAMPLE_STL_7_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_EXAMPLE_STL_7_ST_DEBUG):	$(SRC_EXAMPLE_STL_7) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_ST_DEBUG) -o$@ $(SRC_EXAMPLE_STL_7)

$(TARGET_EXAMPLE_STL_1_ST_RELEASE):	$(OBJ_EXAMPLE_STL_1_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_EXAMPLE_STL_1_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_EXAMPLE_STL_1_ST_RELEASE):	$(SRC_EXAMPLE_STL_1) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_ST_RELEASE) -o$@ $(SRC_EXAMPLE_STL_1)

$(TARGET_EXAMPLE_STL_2_ST_RELEASE):	$(OBJ_EXAMPLE_STL_2_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_EXAMPLE_STL_2_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_EXAMPLE_STL_2_ST_RELEASE):	$(SRC_EXAMPLE_STL_2) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_ST_RELEASE) -o$@ $(SRC_EXAMPLE_STL_2)

$(TARGET_EXAMPLE_STL_3_ST_RELEASE):	$(OBJ_EXAMPLE_STL_3_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_EXAMPLE_STL_3_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_EXAMPLE_STL_3_ST_RELEASE):	$(SRC_EXAMPLE_STL_3) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_ST_RELEASE) -o$@ $(SRC_EXAMPLE_STL_3)

$(TARGET_EXAMPLE_STL_4_ST_RELEASE):	$(OBJ_EXAMPLE_STL_4_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_EXAMPLE_STL_4_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_EXAMPLE_STL_4_ST_RELEASE):	$(SRC_EXAMPLE_STL_4) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_ST_RELEASE) -o$@ $(SRC_EXAMPLE_STL_4)

$(TARGET_EXAMPLE_STL_5_ST_RELEASE):	$(OBJ_EXAMPLE_STL_5_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_EXAMPLE_STL_5_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_EXAMPLE_STL_5_ST_RELEASE):	$(SRC_EXAMPLE_STL_5) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_ST_RELEASE) -o$@ $(SRC_EXAMPLE_STL_5)

$(TARGET_EXAMPLE_STL_6_ST_RELEASE):	$(OBJ_EXAMPLE_STL_6_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_EXAMPLE_STL_6_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_EXAMPLE_STL_6_ST_RELEASE):	$(SRC_EXAMPLE_STL_6) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_ST_RELEASE) -o$@ $(SRC_EXAMPLE_STL_6)

$(TARGET_EXAMPLE_STL_7_ST_RELEASE):	$(OBJ_EXAMPLE_STL_7_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_EXAMPLE_STL_7_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_EXAMPLE_STL_7_ST_RELEASE):	$(SRC_EXAMPLE_STL_7) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_ST_RELEASE) -o$@ $(SRC_EXAMPLE_STL_7)

########################################
# samples

# C sample client

$(TARGET_SAMPLE_C_1_ST_DEBUG):	$(OBJ_SAMPLE_C_1_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_SAMPLE_C_1_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_SAMPLE_C_1_ST_DEBUG):	$(SRC_SAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_DEBUG) -o$@ $(SRC_SAMPLE_C_1)

$(TARGET_SAMPLE_C_2_ST_DEBUG):	$(OBJ_SAMPLE_C_2_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_SAMPLE_C_2_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_SAMPLE_C_2_ST_DEBUG):	$(SRC_SAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_DEBUG) -o$@ $(SRC_SAMPLE_C_2)

$(TARGET_SAMPLE_C_1_ST_RELEASE):	$(OBJ_SAMPLE_C_1_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_SAMPLE_C_1_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_SAMPLE_C_1_ST_RELEASE):	$(SRC_SAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_RELEASE) -o$@ $(SRC_SAMPLE_C_1)

$(TARGET_SAMPLE_C_2_ST_RELEASE):	$(OBJ_SAMPLE_C_2_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_SAMPLE_C_2_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_SAMPLE_C_2_ST_RELEASE):	$(SRC_SAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_ST_RELEASE) -o$@ $(SRC_SAMPLE_C_2)

# C++ sample client

$(TARGET_SAMPLE_CPP_1_ST_DEBUG):	$(OBJ_SAMPLE_CPP_1_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_SAMPLE_CPP_1_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_SAMPLE_CPP_1_ST_DEBUG):	$(SRC_SAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_DEBUG) -o$@ $(SRC_SAMPLE_CPP_1)

$(TARGET_SAMPLE_CPP_1_ST_RELEASE):	$(OBJ_SAMPLE_CPP_1_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_SAMPLE_CPP_1_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_SAMPLE_CPP_1_ST_RELEASE):	$(SRC_SAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST_RELEASE) -o$@ $(SRC_SAMPLE_CPP_1)

# STL sample client

$(TARGET_SAMPLE_STL_1_ST_DEBUG):	$(OBJ_SAMPLE_STL_1_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_SAMPLE_STL_1_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_SAMPLE_STL_1_ST_DEBUG):	$(SRC_SAMPLE_STL_1) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_ST_DEBUG) -o$@ $(SRC_SAMPLE_STL_1)

$(TARGET_SAMPLE_STL_2_ST_DEBUG):	$(OBJ_SAMPLE_STL_2_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_SAMPLE_STL_2_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_SAMPLE_STL_2_ST_DEBUG):	$(SRC_SAMPLE_STL_2) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_ST_DEBUG) -o$@ $(SRC_SAMPLE_STL_2)

$(TARGET_SAMPLE_STL_3_ST_DEBUG):	$(OBJ_SAMPLE_STL_3_ST_DEBUG) makefile
	$(LD) $(LD_ARGS_ST_DEBUG) $(OBJ_SAMPLE_STL_3_ST_DEBUG),"$@",,$(TARGET_LIB_ST_DEBUG)

$(OBJ_SAMPLE_STL_3_ST_DEBUG):	$(SRC_SAMPLE_STL_3) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_ST_DEBUG) -o$@ $(SRC_SAMPLE_STL_3)

$(TARGET_SAMPLE_STL_1_ST_RELEASE):	$(OBJ_SAMPLE_STL_1_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_SAMPLE_STL_1_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_SAMPLE_STL_1_ST_RELEASE):	$(SRC_SAMPLE_STL_1) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_ST_RELEASE) -o$@ $(SRC_SAMPLE_STL_1)

$(TARGET_SAMPLE_STL_2_ST_RELEASE):	$(OBJ_SAMPLE_STL_2_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_SAMPLE_STL_2_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_SAMPLE_STL_2_ST_RELEASE):	$(SRC_SAMPLE_STL_2) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_ST_RELEASE) -o$@ $(SRC_SAMPLE_STL_2)

$(TARGET_SAMPLE_STL_3_ST_RELEASE):	$(OBJ_SAMPLE_STL_3_ST_RELEASE) makefile
	$(LD) $(LD_ARGS_ST_RELEASE) $(OBJ_SAMPLE_STL_3_ST_RELEASE),"$@",,$(TARGET_LIB_ST_RELEASE)

$(OBJ_SAMPLE_STL_3_ST_RELEASE):	$(SRC_SAMPLE_STL_3) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_ST_RELEASE) -o$@ $(SRC_SAMPLE_STL_3)

################################################################################
