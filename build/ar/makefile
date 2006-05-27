################################################################################
# File:     makefile
#
# Purpose:  Makefile for the Open-RJ project, for the Arturius C/C++ Compiler Multiplexer
#           compiler, on Win32
#
# Created:  15th Feburary 2005
# Updated:  28th May 2006
#
################################################################################


################################################################################
# Symbols

# Identification

COMP_TAG          =   ar
PROJ_TAG          =   openrj
PROJ_VER_MAJOR    =   1
PROJ_TAG_VER      =   $(PROJ_TAG).$(PROJ_VER_MAJOR)

CC                  =   arcc.debug
CPPC                =   arcc.debug
AR                  =   lib
LD                  =   arld
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

3PTY_LIBS__DEBUG = \
 \

3PTY_LIBS__RELEASE = \
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
CC_F_WARNING_MAX        =   --warning-level=maximum
CC_F_WARNING_ERR        =   --warnings-as-errors=on

CPPC_F_NOLOGO       =   
CPPC_F_COMPILE_ONLY =   -c
CPPC_F_WARNING_MAX  =   --warning-level=maximum
CPPC_F_WARNING_ERR  =   --warnings-as-errors=on
CPPC_F_EXCEPTIONS   =   --exception-handling=on
CPPC_F_RTTI         =   

CC_TOOL_FLAGS       =   --tools=bc56,bc56,cw8,dm840,dm845,dmb-stlport,gcc34,icl8,vc6,vc6-stlp,vc7,vc7-stlp,vc71,vc71-stlp,ow12 --active-tool=vc/6 --announce-tools

CC_FLAGS = \
 $(CC_TOOL_FLAGS)\
 $(CC_F_NOLOGO)\
 $(CC_F_COMPILE_ONLY)\
 $(CC_F_WARNING_MAX)\
 $(CC_F_WARNING_ERR)\
 \

CPPC_TOOL_FLAGS     =   --tools=bc56,bc56,cw8,dm840,dm845,dmb-stlport,gcc34,icl8,vc6,vc6-stlp,vc7,vc7-stlp,vc71,vc71-stlp --active-tool=vc/6 --announce-tools

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

CC_ARGS_DEBUG                =   -D_DEBUG -UNDEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)
CC_ARGS_RELEASE                =   -DNDEBUG -U_DEBUG $(CC_FLAGS) $(CC_DEFS) $(CC_INCLUDES)

CPPC_ARGS_DEBUG          =   -D_DEBUG -UNDEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)
CPPC_ARGS_RELEASE          =   -DNDEBUG -U_DEBUG $(CPPC_FLAGS) $(CPPC_DEFS) $(CPPC_INCLUDES)

# archiver flags and arguments

AR_ARGS             =   

# linker flags and arguments

LD_F_NOLOGO = 

LD_ARGS_DEBUG            =    $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)
LD_ARGS_RELEASE            =    $(LD_F_NOLOGO) $(LIB_PATHS) $(COMMON_LIB)

################################################################################
# Targets

########################################
# TARGETS_LIBS

TARGET_LIB_DEBUG         =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG).debug.lib
TARGET_LIB_UN_DEBUG      =   $(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).debug.lib
TARGET_LIB_RELEASE         =   $(PROJ_LIB_DIR)\$(PROJ_TAG_VER).$(COMP_TAG).release.lib
TARGET_LIB_UN_RELEASE      =   $(PROJ_LIB_DIR)\$(PROJ_TAG).$(COMP_TAG).release.lib

TARGETS_LIBS =\
 $(TARGET_LIB_DEBUG)\
 $(TARGET_LIB_UN_DEBUG)\
 $(TARGET_LIB_RELEASE)\
 $(TARGET_LIB_UN_RELEASE)\
 \

########################################
# TARGETS_TESTS

TARGET_TEST_C_1_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_c_1.$(COMP_TAG).debug.exe
TARGET_TEST_CPP_1_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_cpp_1.$(COMP_TAG).debug.exe
TARGET_TEST_STL_1_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_stl_1.$(COMP_TAG).debug.exe
TARGET_TEST_C_1_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_c_1.$(COMP_TAG).release.exe
TARGET_TEST_CPP_1_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_cpp_1.$(COMP_TAG).release.exe
TARGET_TEST_STL_1_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).test_stl_1.$(COMP_TAG).release.exe

TARGETS_TESTS =\
 $(TARGET_TEST_C_1_DEBUG)\
 $(TARGET_TEST_C_1_RELEASE)\
 $(TARGET_TEST_CPP_1_DEBUG)\
 $(TARGET_TEST_CPP_1_RELEASE)\
 $(TARGET_TEST_STL_1_DEBUG)\
 $(TARGET_TEST_STL_1_RELEASE)\
 \

########################################
# TARGETS_EXAMPLES

TARGET_EXAMPLE_C_1_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_1.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_2_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_2.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_3_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_3.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_4_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_4.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_5_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_5.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_6_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_6.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_7_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_7.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_8_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_8.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_CPP_1_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_1.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_CPP_2_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_2.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_CPP_3_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_3.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_CPP_4_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_4.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_CPP_5_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_5.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_CPP_6_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_6.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_STL_1_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_1.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_STL_2_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_2.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_STL_3_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_3.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_STL_4_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_4.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_STL_5_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_5.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_STL_6_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_6.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_STL_7_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_7.$(COMP_TAG).debug.exe
TARGET_EXAMPLE_C_1_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_1.$(COMP_TAG).release.exe
TARGET_EXAMPLE_C_2_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_2.$(COMP_TAG).release.exe
TARGET_EXAMPLE_C_3_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_3.$(COMP_TAG).release.exe
TARGET_EXAMPLE_C_4_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_4.$(COMP_TAG).release.exe
TARGET_EXAMPLE_C_5_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_5.$(COMP_TAG).release.exe
TARGET_EXAMPLE_C_6_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_6.$(COMP_TAG).release.exe
TARGET_EXAMPLE_C_7_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_7.$(COMP_TAG).release.exe
TARGET_EXAMPLE_C_8_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_c_8.$(COMP_TAG).release.exe
TARGET_EXAMPLE_CPP_1_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_1.$(COMP_TAG).release.exe
TARGET_EXAMPLE_CPP_2_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_2.$(COMP_TAG).release.exe
TARGET_EXAMPLE_CPP_3_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_3.$(COMP_TAG).release.exe
TARGET_EXAMPLE_CPP_4_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_4.$(COMP_TAG).release.exe
TARGET_EXAMPLE_CPP_5_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_5.$(COMP_TAG).release.exe
TARGET_EXAMPLE_CPP_6_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_cpp_6.$(COMP_TAG).release.exe
TARGET_EXAMPLE_STL_1_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_1.$(COMP_TAG).release.exe
TARGET_EXAMPLE_STL_2_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_2.$(COMP_TAG).release.exe
TARGET_EXAMPLE_STL_3_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_3.$(COMP_TAG).release.exe
TARGET_EXAMPLE_STL_4_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_4.$(COMP_TAG).release.exe
TARGET_EXAMPLE_STL_5_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_5.$(COMP_TAG).release.exe
TARGET_EXAMPLE_STL_6_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_6.$(COMP_TAG).release.exe
TARGET_EXAMPLE_STL_7_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).example_stl_7.$(COMP_TAG).release.exe

TARGETS_EXAMPLES =\
 $(TARGET_EXAMPLE_C_1_DEBUG)\
 $(TARGET_EXAMPLE_C_2_DEBUG)\
 $(TARGET_EXAMPLE_C_3_DEBUG)\
 $(TARGET_EXAMPLE_C_4_DEBUG)\
 $(TARGET_EXAMPLE_C_5_DEBUG)\
 $(TARGET_EXAMPLE_C_6_DEBUG)\
 $(TARGET_EXAMPLE_C_7_DEBUG)\
 $(TARGET_EXAMPLE_C_8_DEBUG)\
 $(TARGET_EXAMPLE_C_1_RELEASE)\
 $(TARGET_EXAMPLE_C_2_RELEASE)\
 $(TARGET_EXAMPLE_C_3_RELEASE)\
 $(TARGET_EXAMPLE_C_4_RELEASE)\
 $(TARGET_EXAMPLE_C_5_RELEASE)\
 $(TARGET_EXAMPLE_C_6_RELEASE)\
 $(TARGET_EXAMPLE_C_7_RELEASE)\
 $(TARGET_EXAMPLE_C_8_RELEASE)\
 $(TARGET_EXAMPLE_CPP_1_DEBUG)\
 $(TARGET_EXAMPLE_CPP_2_DEBUG)\
 $(TARGET_EXAMPLE_CPP_3_DEBUG)\
 $(TARGET_EXAMPLE_CPP_4_DEBUG)\
 $(TARGET_EXAMPLE_CPP_5_DEBUG)\
 $(TARGET_EXAMPLE_CPP_6_DEBUG)\
 $(TARGET_EXAMPLE_CPP_1_RELEASE)\
 $(TARGET_EXAMPLE_CPP_2_RELEASE)\
 $(TARGET_EXAMPLE_CPP_3_RELEASE)\
 $(TARGET_EXAMPLE_CPP_4_RELEASE)\
 $(TARGET_EXAMPLE_CPP_5_RELEASE)\
 $(TARGET_EXAMPLE_CPP_6_RELEASE)\
 $(TARGET_EXAMPLE_STL_1_DEBUG)\
 $(TARGET_EXAMPLE_STL_2_DEBUG)\
 $(TARGET_EXAMPLE_STL_3_DEBUG)\
 $(TARGET_EXAMPLE_STL_4_DEBUG)\
 $(TARGET_EXAMPLE_STL_5_DEBUG)\
 $(TARGET_EXAMPLE_STL_6_DEBUG)\
 $(TARGET_EXAMPLE_STL_7_DEBUG)\
 $(TARGET_EXAMPLE_STL_1_RELEASE)\
 $(TARGET_EXAMPLE_STL_2_RELEASE)\
 $(TARGET_EXAMPLE_STL_3_RELEASE)\
 $(TARGET_EXAMPLE_STL_4_RELEASE)\
 $(TARGET_EXAMPLE_STL_5_RELEASE)\
 $(TARGET_EXAMPLE_STL_6_RELEASE)\
 $(TARGET_EXAMPLE_STL_7_RELEASE)\
 \

########################################
# TARGETS_SAMPLES

TARGET_SAMPLE_C_1_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_1.$(COMP_TAG).debug.exe
TARGET_SAMPLE_C_2_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_2.$(COMP_TAG).debug.exe
TARGET_SAMPLE_CPP_1_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_cpp_1.$(COMP_TAG).debug.exe
TARGET_SAMPLE_STL_1_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_stl_1.$(COMP_TAG).debug.exe
TARGET_SAMPLE_STL_2_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_stl_2.$(COMP_TAG).debug.exe
TARGET_SAMPLE_STL_3_DEBUG        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_stl_3.$(COMP_TAG).debug.exe
TARGET_SAMPLE_C_1_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_1.$(COMP_TAG).release.exe
TARGET_SAMPLE_C_2_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_c_2.$(COMP_TAG).release.exe
TARGET_SAMPLE_CPP_1_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_cpp_1.$(COMP_TAG).release.exe
TARGET_SAMPLE_STL_1_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_stl_1.$(COMP_TAG).release.exe
TARGET_SAMPLE_STL_2_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_stl_2.$(COMP_TAG).release.exe
TARGET_SAMPLE_STL_3_RELEASE        =   $(PROJ_BIN_DIR)\$(PROJ_TAG_VER).sample_stl_3.$(COMP_TAG).release.exe

TARGETS_SAMPLES =\
 $(TARGET_SAMPLE_C_1_DEBUG)\
 $(TARGET_SAMPLE_C_2_DEBUG)\
 $(TARGET_SAMPLE_C_1_RELEASE)\
 $(TARGET_SAMPLE_C_2_RELEASE)\
 $(TARGET_SAMPLE_CPP_1_DEBUG)\
 $(TARGET_SAMPLE_CPP_1_RELEASE)\
 $(TARGET_SAMPLE_STL_1_DEBUG)\
 $(TARGET_SAMPLE_STL_2_DEBUG)\
 $(TARGET_SAMPLE_STL_3_DEBUG)\
 $(TARGET_SAMPLE_STL_1_RELEASE)\
 $(TARGET_SAMPLE_STL_2_RELEASE)\
 $(TARGET_SAMPLE_STL_3_RELEASE)\
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

OBJ_CORE_orjapi__DEBUG = $(PROJ_OBJ_DIR)\orjapi.debug.obj
OBJ_CORE_orjmem__DEBUG = $(PROJ_OBJ_DIR)\orjmem.debug.obj
OBJ_CORE_orjstr__DEBUG = $(PROJ_OBJ_DIR)\orjstr.debug.obj

OBJS_CORE_DEBUG = \
 $(OBJ_CORE_orjapi__DEBUG)\
 $(OBJ_CORE_orjmem__DEBUG)\
 $(OBJ_CORE_orjstr__DEBUG)\
 \

OBJ_CORE_orjapi__RELEASE = $(PROJ_OBJ_DIR)\orjapi.release.obj
OBJ_CORE_orjmem__RELEASE = $(PROJ_OBJ_DIR)\orjmem.release.obj
OBJ_CORE_orjstr__RELEASE = $(PROJ_OBJ_DIR)\orjstr.release.obj

OBJS_CORE_RELEASE = \
 $(OBJ_CORE_orjapi__RELEASE)\
 $(OBJ_CORE_orjmem__RELEASE)\
 $(OBJ_CORE_orjstr__RELEASE)\
 \


OBJS_CORE =\
 $(OBJS_CORE_DEBUG)\
 $(OBJS_CORE_RELEASE)\
 \

########################################
# OBJS_LIBS

OBJS_LIBS =\
 $(OBJS_CORE)\
 \

########################################
# OBJS_TESTS

OBJ_TEST_C_1_DEBUG        =   $(PROJ_OBJ_DIR)\test_c_1.debug.obj
OBJ_TEST_CPP_1_DEBUG        =   $(PROJ_OBJ_DIR)\test_cpp_1.debug.obj
OBJ_TEST_STL_1_DEBUG        =   $(PROJ_OBJ_DIR)\test_stl_1.debug.obj
OBJ_TEST_C_1_RELEASE        =   $(PROJ_OBJ_DIR)\test_c_1.release.obj
OBJ_TEST_CPP_1_RELEASE        =   $(PROJ_OBJ_DIR)\test_cpp_1.release.obj
OBJ_TEST_STL_1_RELEASE        =   $(PROJ_OBJ_DIR)\test_stl_1.release.obj

OBJS_TESTS =\
 $(OBJ_TEST_C_1_DEBUG)\
 $(OBJ_TEST_C_1_RELEASE)\
 $(OBJ_TEST_CPP_1_DEBUG)\
 $(OBJ_TEST_CPP_1_RELEASE)\
 $(OBJ_TEST_STL_1_DEBUG)\
 $(OBJ_TEST_STL_1_RELEASE)\
 \

########################################
# OBJS_EXAMPLES

OBJ_EXAMPLE_C_1_DEBUG        =   $(PROJ_OBJ_DIR)\example_c_1.debug.obj
OBJ_EXAMPLE_C_2_DEBUG        =   $(PROJ_OBJ_DIR)\example_c_2.debug.obj
OBJ_EXAMPLE_C_3_DEBUG        =   $(PROJ_OBJ_DIR)\example_c_3.debug.obj
OBJ_EXAMPLE_C_4_DEBUG        =   $(PROJ_OBJ_DIR)\example_c_4.debug.obj
OBJ_EXAMPLE_C_5_DEBUG        =   $(PROJ_OBJ_DIR)\example_c_5.debug.obj
OBJ_EXAMPLE_C_6_DEBUG        =   $(PROJ_OBJ_DIR)\example_c_6.debug.obj
OBJ_EXAMPLE_C_7_DEBUG        =   $(PROJ_OBJ_DIR)\example_c_7.debug.obj
OBJ_EXAMPLE_C_8_DEBUG        =   $(PROJ_OBJ_DIR)\example_c_8.debug.obj
OBJ_EXAMPLE_CPP_1_DEBUG        =   $(PROJ_OBJ_DIR)\example_cpp_1.debug.obj
OBJ_EXAMPLE_CPP_2_DEBUG        =   $(PROJ_OBJ_DIR)\example_cpp_2.debug.obj
OBJ_EXAMPLE_CPP_3_DEBUG        =   $(PROJ_OBJ_DIR)\example_cpp_3.debug.obj
OBJ_EXAMPLE_CPP_4_DEBUG        =   $(PROJ_OBJ_DIR)\example_cpp_4.debug.obj
OBJ_EXAMPLE_CPP_5_DEBUG        =   $(PROJ_OBJ_DIR)\example_cpp_5.debug.obj
OBJ_EXAMPLE_CPP_6_DEBUG        =   $(PROJ_OBJ_DIR)\example_cpp_6.debug.obj
OBJ_EXAMPLE_STL_1_DEBUG        =   $(PROJ_OBJ_DIR)\example_stl_1.debug.obj
OBJ_EXAMPLE_STL_2_DEBUG        =   $(PROJ_OBJ_DIR)\example_stl_2.debug.obj
OBJ_EXAMPLE_STL_3_DEBUG        =   $(PROJ_OBJ_DIR)\example_stl_3.debug.obj
OBJ_EXAMPLE_STL_4_DEBUG        =   $(PROJ_OBJ_DIR)\example_stl_4.debug.obj
OBJ_EXAMPLE_STL_5_DEBUG        =   $(PROJ_OBJ_DIR)\example_stl_5.debug.obj
OBJ_EXAMPLE_STL_6_DEBUG        =   $(PROJ_OBJ_DIR)\example_stl_6.debug.obj
OBJ_EXAMPLE_STL_7_DEBUG        =   $(PROJ_OBJ_DIR)\example_stl_7.debug.obj
OBJ_EXAMPLE_C_1_RELEASE        =   $(PROJ_OBJ_DIR)\example_c_1.release.obj
OBJ_EXAMPLE_C_2_RELEASE        =   $(PROJ_OBJ_DIR)\example_c_2.release.obj
OBJ_EXAMPLE_C_3_RELEASE        =   $(PROJ_OBJ_DIR)\example_c_3.release.obj
OBJ_EXAMPLE_C_4_RELEASE        =   $(PROJ_OBJ_DIR)\example_c_4.release.obj
OBJ_EXAMPLE_C_5_RELEASE        =   $(PROJ_OBJ_DIR)\example_c_5.release.obj
OBJ_EXAMPLE_C_6_RELEASE        =   $(PROJ_OBJ_DIR)\example_c_6.release.obj
OBJ_EXAMPLE_C_7_RELEASE        =   $(PROJ_OBJ_DIR)\example_c_7.release.obj
OBJ_EXAMPLE_C_8_RELEASE        =   $(PROJ_OBJ_DIR)\example_c_8.release.obj
OBJ_EXAMPLE_CPP_1_RELEASE        =   $(PROJ_OBJ_DIR)\example_cpp_1.release.obj
OBJ_EXAMPLE_CPP_2_RELEASE        =   $(PROJ_OBJ_DIR)\example_cpp_2.release.obj
OBJ_EXAMPLE_CPP_3_RELEASE        =   $(PROJ_OBJ_DIR)\example_cpp_3.release.obj
OBJ_EXAMPLE_CPP_4_RELEASE        =   $(PROJ_OBJ_DIR)\example_cpp_4.release.obj
OBJ_EXAMPLE_CPP_5_RELEASE        =   $(PROJ_OBJ_DIR)\example_cpp_5.release.obj
OBJ_EXAMPLE_CPP_6_RELEASE        =   $(PROJ_OBJ_DIR)\example_cpp_6.release.obj
OBJ_EXAMPLE_STL_1_RELEASE        =   $(PROJ_OBJ_DIR)\example_stl_1.release.obj
OBJ_EXAMPLE_STL_2_RELEASE        =   $(PROJ_OBJ_DIR)\example_stl_2.release.obj
OBJ_EXAMPLE_STL_3_RELEASE        =   $(PROJ_OBJ_DIR)\example_stl_3.release.obj
OBJ_EXAMPLE_STL_4_RELEASE        =   $(PROJ_OBJ_DIR)\example_stl_4.release.obj
OBJ_EXAMPLE_STL_5_RELEASE        =   $(PROJ_OBJ_DIR)\example_stl_5.release.obj
OBJ_EXAMPLE_STL_6_RELEASE        =   $(PROJ_OBJ_DIR)\example_stl_6.release.obj
OBJ_EXAMPLE_STL_7_RELEASE        =   $(PROJ_OBJ_DIR)\example_stl_7.release.obj

OBJS_EXAMPLES =\
 $(OBJ_EXAMPLE_C_1_DEBUG)\
 $(OBJ_EXAMPLE_C_2_DEBUG)\
 $(OBJ_EXAMPLE_C_3_DEBUG)\
 $(OBJ_EXAMPLE_C_4_DEBUG)\
 $(OBJ_EXAMPLE_C_5_DEBUG)\
 $(OBJ_EXAMPLE_C_6_DEBUG)\
 $(OBJ_EXAMPLE_C_7_DEBUG)\
 $(OBJ_EXAMPLE_C_8_DEBUG)\
 $(OBJ_EXAMPLE_C_1_RELEASE)\
 $(OBJ_EXAMPLE_C_2_RELEASE)\
 $(OBJ_EXAMPLE_C_3_RELEASE)\
 $(OBJ_EXAMPLE_C_4_RELEASE)\
 $(OBJ_EXAMPLE_C_5_RELEASE)\
 $(OBJ_EXAMPLE_C_6_RELEASE)\
 $(OBJ_EXAMPLE_C_7_RELEASE)\
 $(OBJ_EXAMPLE_C_8_RELEASE)\
 $(OBJ_EXAMPLE_CPP_1_DEBUG)\
 $(OBJ_EXAMPLE_CPP_2_DEBUG)\
 $(OBJ_EXAMPLE_CPP_3_DEBUG)\
 $(OBJ_EXAMPLE_CPP_4_DEBUG)\
 $(OBJ_EXAMPLE_CPP_5_DEBUG)\
 $(OBJ_EXAMPLE_CPP_6_DEBUG)\
 $(OBJ_EXAMPLE_CPP_1_RELEASE)\
 $(OBJ_EXAMPLE_CPP_2_RELEASE)\
 $(OBJ_EXAMPLE_CPP_3_RELEASE)\
 $(OBJ_EXAMPLE_CPP_4_RELEASE)\
 $(OBJ_EXAMPLE_CPP_5_RELEASE)\
 $(OBJ_EXAMPLE_CPP_6_RELEASE)\
 $(OBJ_EXAMPLE_STL_1_DEBUG)\
 $(OBJ_EXAMPLE_STL_2_DEBUG)\
 $(OBJ_EXAMPLE_STL_3_DEBUG)\
 $(OBJ_EXAMPLE_STL_4_DEBUG)\
 $(OBJ_EXAMPLE_STL_5_DEBUG)\
 $(OBJ_EXAMPLE_STL_6_DEBUG)\
 $(OBJ_EXAMPLE_STL_7_DEBUG)\
 $(OBJ_EXAMPLE_STL_1_RELEASE)\
 $(OBJ_EXAMPLE_STL_2_RELEASE)\
 $(OBJ_EXAMPLE_STL_3_RELEASE)\
 $(OBJ_EXAMPLE_STL_4_RELEASE)\
 $(OBJ_EXAMPLE_STL_5_RELEASE)\
 $(OBJ_EXAMPLE_STL_6_RELEASE)\
 $(OBJ_EXAMPLE_STL_7_RELEASE)\
 \

########################################
# OBJS_SAMPLES

OBJ_SAMPLE_C_1_DEBUG        =   $(PROJ_OBJ_DIR)\sample_c_1.debug.obj
OBJ_SAMPLE_C_2_DEBUG        =   $(PROJ_OBJ_DIR)\sample_c_2.debug.obj
OBJ_SAMPLE_CPP_1_DEBUG        =   $(PROJ_OBJ_DIR)\sample_cpp_1.debug.obj
OBJ_SAMPLE_STL_1_DEBUG        =   $(PROJ_OBJ_DIR)\sample_stl_1.debug.obj
OBJ_SAMPLE_STL_2_DEBUG        =   $(PROJ_OBJ_DIR)\sample_stl_2.debug.obj
OBJ_SAMPLE_STL_3_DEBUG        =   $(PROJ_OBJ_DIR)\sample_stl_3.debug.obj
OBJ_SAMPLE_C_1_RELEASE        =   $(PROJ_OBJ_DIR)\sample_c_1.release.obj
OBJ_SAMPLE_C_2_RELEASE        =   $(PROJ_OBJ_DIR)\sample_c_2.release.obj
OBJ_SAMPLE_CPP_1_RELEASE        =   $(PROJ_OBJ_DIR)\sample_cpp_1.release.obj
OBJ_SAMPLE_STL_1_RELEASE        =   $(PROJ_OBJ_DIR)\sample_stl_1.release.obj
OBJ_SAMPLE_STL_2_RELEASE        =   $(PROJ_OBJ_DIR)\sample_stl_2.release.obj
OBJ_SAMPLE_STL_3_RELEASE        =   $(PROJ_OBJ_DIR)\sample_stl_3.release.obj

OBJS_SAMPLES =\
 $(OBJ_SAMPLE_C_1_DEBUG)\
 $(OBJ_SAMPLE_C_2_DEBUG)\
 $(OBJ_SAMPLE_C_1_RELEASE)\
 $(OBJ_SAMPLE_C_2_RELEASE)\
 $(OBJ_SAMPLE_CPP_1_DEBUG)\
 $(OBJ_SAMPLE_CPP_1_RELEASE)\
 $(OBJ_SAMPLE_STL_1_DEBUG)\
 $(OBJ_SAMPLE_STL_2_DEBUG)\
 $(OBJ_SAMPLE_STL_3_DEBUG)\
 $(OBJ_SAMPLE_STL_1_RELEASE)\
 $(OBJ_SAMPLE_STL_2_RELEASE)\
 $(OBJ_SAMPLE_STL_3_RELEASE)\
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
	$(TARGET_TEST_C_1_DEBUG) --unittest
	$(TARGET_TEST_C_1_RELEASE) --unittest
	$(TARGET_TEST_CPP_1_DEBUG) --unittest
	$(TARGET_TEST_CPP_1_RELEASE) --unittest
	$(TARGET_TEST_STL_1_DEBUG) --unittest
	$(TARGET_TEST_STL_1_RELEASE) --unittest

test:		build.all test_

test.all:	test

test-all:	test.all	# backwards compatibility


usage:
	@echo "make [usage | clean | compile | all | test | target] - default is 'all'"

clean.libs.core:
	@-$(RM) $(TARGET_LIB_DEBUG)
	@-$(RM) $(TARGET_LIB_UN_DEBUG)
	@-$(RM) $(TARGET_LIB_RELEASE)
	@-$(RM) $(TARGET_LIB_UN_RELEASE)
	@-$(RM) $(OBJ_CORE_orjapi__DEBUG)
	@-$(RM) $(OBJ_CORE_orjmem__DEBUG)
	@-$(RM) $(OBJ_CORE_orjstr__DEBUG)
	@-$(RM) $(OBJ_CORE_orjapi__RELEASE)
	@-$(RM) $(OBJ_CORE_orjmem__RELEASE)
	@-$(RM) $(OBJ_CORE_orjstr__RELEASE)

clean.libs.com:

clean.libs.dotnet:

clean.libs:         clean.libs.core clean.libs.com clean.libs.dotnet

clean.test:
	@-$(RM) $(TARGET_TEST_C_1_DEBUG)
	@-$(RM) $(TARGET_TEST_C_1_RELEASE)
	@-$(RM) $(TARGET_TEST_CPP_1_DEBUG)
	@-$(RM) $(TARGET_TEST_CPP_1_RELEASE)
	@-$(RM) $(TARGET_TEST_STL_1_DEBUG)
	@-$(RM) $(TARGET_TEST_STL_1_RELEASE)
	@-$(RM) $(OBJ_TEST_C_1_DEBUG)
	@-$(RM) $(OBJ_TEST_C_1_RELEASE)
	@-$(RM) $(OBJ_TEST_CPP_1_DEBUG)
	@-$(RM) $(OBJ_TEST_CPP_1_RELEASE)
	@-$(RM) $(OBJ_TEST_STL_1_DEBUG)
	@-$(RM) $(OBJ_TEST_STL_1_RELEASE)

clean.examples:
	@-$(RM) $(TARGET_EXAMPLE_C_1_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_C_2_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_C_3_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_C_4_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_C_5_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_C_6_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_C_7_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_C_8_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_C_1_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_C_2_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_C_3_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_C_4_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_C_5_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_C_6_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_C_7_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_C_8_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_CPP_1_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_CPP_2_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_CPP_3_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_CPP_4_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_CPP_5_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_CPP_6_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_CPP_1_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_CPP_2_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_CPP_3_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_CPP_4_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_CPP_5_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_CPP_6_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_STL_1_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_STL_2_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_STL_3_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_STL_4_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_STL_5_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_STL_6_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_STL_7_DEBUG)
	@-$(RM) $(TARGET_EXAMPLE_STL_1_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_STL_2_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_STL_3_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_STL_4_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_STL_5_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_STL_6_RELEASE)
	@-$(RM) $(TARGET_EXAMPLE_STL_7_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_C_1_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_C_2_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_C_3_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_C_4_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_C_5_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_C_6_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_C_7_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_C_8_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_C_1_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_C_2_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_C_3_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_C_4_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_C_5_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_C_6_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_C_7_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_C_8_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_CPP_1_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_CPP_2_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_CPP_3_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_CPP_4_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_CPP_5_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_CPP_6_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_CPP_1_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_CPP_2_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_CPP_3_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_CPP_4_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_CPP_5_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_CPP_6_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_STL_1_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_STL_2_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_STL_3_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_STL_4_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_STL_5_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_STL_6_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_STL_7_DEBUG)
	@-$(RM) $(OBJ_EXAMPLE_STL_1_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_STL_2_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_STL_3_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_STL_4_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_STL_5_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_STL_6_RELEASE)
	@-$(RM) $(OBJ_EXAMPLE_STL_7_RELEASE)

clean.samples:
	@-$(RM) $(TARGET_SAMPLE_C_1_DEBUG)
	@-$(RM) $(TARGET_SAMPLE_C_2_DEBUG)
	@-$(RM) $(TARGET_SAMPLE_C_1_RELEASE)
	@-$(RM) $(TARGET_SAMPLE_C_2_RELEASE)
	@-$(RM) $(TARGET_SAMPLE_CPP_1_DEBUG)
	@-$(RM) $(TARGET_SAMPLE_CPP_1_RELEASE)
	@-$(RM) $(TARGET_SAMPLE_STL_1_DEBUG)
	@-$(RM) $(TARGET_SAMPLE_STL_2_DEBUG)
	@-$(RM) $(TARGET_SAMPLE_STL_3_DEBUG)
	@-$(RM) $(TARGET_SAMPLE_STL_1_RELEASE)
	@-$(RM) $(TARGET_SAMPLE_STL_2_RELEASE)
	@-$(RM) $(TARGET_SAMPLE_STL_3_RELEASE)
	@-$(RM) $(OBJ_SAMPLE_C_1_DEBUG)
	@-$(RM) $(OBJ_SAMPLE_C_2_DEBUG)
	@-$(RM) $(OBJ_SAMPLE_C_1_RELEASE)
	@-$(RM) $(OBJ_SAMPLE_C_2_RELEASE)
	@-$(RM) $(OBJ_SAMPLE_CPP_1_DEBUG)
	@-$(RM) $(OBJ_SAMPLE_CPP_1_RELEASE)
	@-$(RM) $(OBJ_SAMPLE_STL_1_DEBUG)
	@-$(RM) $(OBJ_SAMPLE_STL_2_DEBUG)
	@-$(RM) $(OBJ_SAMPLE_STL_3_DEBUG)
	@-$(RM) $(OBJ_SAMPLE_STL_1_RELEASE)
	@-$(RM) $(OBJ_SAMPLE_STL_2_RELEASE)
	@-$(RM) $(OBJ_SAMPLE_STL_3_RELEASE)

clean: clean.libs clean.test clean.examples clean.samples

################################################################################
# Internal Targets (invokable by make)

########################################
# core


$(TARGET_LIB_UN_DEBUG): $(TARGET_LIB_DEBUG)
	@$(CP) $(TARGET_LIB_DEBUG) $@

$(TARGET_LIB_DEBUG): $(OBJS_CORE_DEBUG) makefile
	$(AR) $(AR_ARGS) $@ $(OBJS_CORE_DEBUG)

$(OBJ_CORE_orjapi__DEBUG): $(PROJ_SRC_DIR)\orjapi.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(PROJ_SRC_DIR)\orjapi.c
$(OBJ_CORE_orjmem__DEBUG): $(PROJ_SRC_DIR)\orjmem.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(PROJ_SRC_DIR)\orjmem.c
$(OBJ_CORE_orjstr__DEBUG): $(PROJ_SRC_DIR)\orjstr.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(PROJ_SRC_DIR)\orjstr.c


$(TARGET_LIB_UN_RELEASE): $(TARGET_LIB_RELEASE)
	@$(CP) $(TARGET_LIB_RELEASE) $@

$(TARGET_LIB_RELEASE): $(OBJS_CORE_RELEASE) makefile
	$(AR) $(AR_ARGS) $@ $(OBJS_CORE_RELEASE)

$(OBJ_CORE_orjapi__RELEASE): $(PROJ_SRC_DIR)\orjapi.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(PROJ_SRC_DIR)\orjapi.c
$(OBJ_CORE_orjmem__RELEASE): $(PROJ_SRC_DIR)\orjmem.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(PROJ_SRC_DIR)\orjmem.c
$(OBJ_CORE_orjstr__RELEASE): $(PROJ_SRC_DIR)\orjstr.c $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(PROJ_SRC_DIR)\orjstr.c


########################################
# test

# C test client

$(TARGET_TEST_C_1_DEBUG):	$(OBJ_TEST_C_1_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_TEST_C_1_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_TEST_C_1_DEBUG):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(SRC_TEST_C_1)

$(TARGET_TEST_C_1_RELEASE):	$(OBJ_TEST_C_1_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_TEST_C_1_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_TEST_C_1_RELEASE):	$(SRC_TEST_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(SRC_TEST_C_1)

# C++ test client

$(TARGET_TEST_CPP_1_DEBUG):	$(OBJ_TEST_CPP_1_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_TEST_CPP_1_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_TEST_CPP_1_DEBUG):	$(SRC_TEST_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(SRC_TEST_CPP_1)

$(TARGET_TEST_CPP_1_RELEASE):	$(OBJ_TEST_CPP_1_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_TEST_CPP_1_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_TEST_CPP_1_RELEASE):	$(SRC_TEST_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(SRC_TEST_CPP_1)

# STL test client

$(TARGET_TEST_STL_1_DEBUG):	$(OBJ_TEST_STL_1_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_TEST_STL_1_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_TEST_STL_1_DEBUG):	$(SRC_TEST_STL_1) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(SRC_TEST_STL_1)

$(TARGET_TEST_STL_1_RELEASE):	$(OBJ_TEST_STL_1_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_TEST_STL_1_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_TEST_STL_1_RELEASE):	$(SRC_TEST_STL_1) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(SRC_TEST_STL_1)

########################################
# examples

# C example client

$(TARGET_EXAMPLE_C_1_DEBUG):	$(OBJ_EXAMPLE_C_1_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_C_1_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_C_1_DEBUG):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_C_1)

$(TARGET_EXAMPLE_C_2_DEBUG):	$(OBJ_EXAMPLE_C_2_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_C_2_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_C_2_DEBUG):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_C_2)

$(TARGET_EXAMPLE_C_3_DEBUG):	$(OBJ_EXAMPLE_C_3_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_C_3_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_C_3_DEBUG):	$(SRC_EXAMPLE_C_3) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_C_3)

$(TARGET_EXAMPLE_C_4_DEBUG):	$(OBJ_EXAMPLE_C_4_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_C_4_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_C_4_DEBUG):	$(SRC_EXAMPLE_C_4) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_C_4)

$(TARGET_EXAMPLE_C_5_DEBUG):	$(OBJ_EXAMPLE_C_5_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_C_5_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_C_5_DEBUG):	$(SRC_EXAMPLE_C_5) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_C_5)

$(TARGET_EXAMPLE_C_6_DEBUG):	$(OBJ_EXAMPLE_C_6_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_C_6_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_C_6_DEBUG):	$(SRC_EXAMPLE_C_6) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_C_6)

$(TARGET_EXAMPLE_C_7_DEBUG):	$(OBJ_EXAMPLE_C_7_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_C_7_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_C_7_DEBUG):	$(SRC_EXAMPLE_C_7) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_C_7)

$(TARGET_EXAMPLE_C_8_DEBUG):	$(OBJ_EXAMPLE_C_8_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_C_8_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_C_8_DEBUG):	$(SRC_EXAMPLE_C_8) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_C_8)

$(TARGET_EXAMPLE_C_1_RELEASE):	$(OBJ_EXAMPLE_C_1_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_C_1_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_C_1_RELEASE):	$(SRC_EXAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_C_1)

$(TARGET_EXAMPLE_C_2_RELEASE):	$(OBJ_EXAMPLE_C_2_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_C_2_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_C_2_RELEASE):	$(SRC_EXAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_C_2)

$(TARGET_EXAMPLE_C_3_RELEASE):	$(OBJ_EXAMPLE_C_3_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_C_3_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_C_3_RELEASE):	$(SRC_EXAMPLE_C_3) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_C_3)

$(TARGET_EXAMPLE_C_4_RELEASE):	$(OBJ_EXAMPLE_C_4_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_C_4_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_C_4_RELEASE):	$(SRC_EXAMPLE_C_4) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_C_4)

$(TARGET_EXAMPLE_C_5_RELEASE):	$(OBJ_EXAMPLE_C_5_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_C_5_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_C_5_RELEASE):	$(SRC_EXAMPLE_C_5) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_C_5)

$(TARGET_EXAMPLE_C_6_RELEASE):	$(OBJ_EXAMPLE_C_6_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_C_6_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_C_6_RELEASE):	$(SRC_EXAMPLE_C_6) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_C_6)

$(TARGET_EXAMPLE_C_7_RELEASE):	$(OBJ_EXAMPLE_C_7_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_C_7_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_C_7_RELEASE):	$(SRC_EXAMPLE_C_7) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_C_7)

$(TARGET_EXAMPLE_C_8_RELEASE):	$(OBJ_EXAMPLE_C_8_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_C_8_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_C_8_RELEASE):	$(SRC_EXAMPLE_C_8) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_C_8)

# C++ example client

$(TARGET_EXAMPLE_CPP_1_DEBUG):	$(OBJ_EXAMPLE_CPP_1_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_CPP_1_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_CPP_1_DEBUG):	$(SRC_EXAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_CPP_1)

$(TARGET_EXAMPLE_CPP_2_DEBUG):	$(OBJ_EXAMPLE_CPP_2_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_CPP_2_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_CPP_2_DEBUG):	$(SRC_EXAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_CPP_2)

$(TARGET_EXAMPLE_CPP_3_DEBUG):	$(OBJ_EXAMPLE_CPP_3_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_CPP_3_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_CPP_3_DEBUG):	$(SRC_EXAMPLE_CPP_3) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_CPP_3)

$(TARGET_EXAMPLE_CPP_4_DEBUG):	$(OBJ_EXAMPLE_CPP_4_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_CPP_4_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_CPP_4_DEBUG):	$(SRC_EXAMPLE_CPP_4) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_CPP_4)

$(TARGET_EXAMPLE_CPP_5_DEBUG):	$(OBJ_EXAMPLE_CPP_5_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_CPP_5_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_CPP_5_DEBUG):	$(SRC_EXAMPLE_CPP_5) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_CPP_5)

$(TARGET_EXAMPLE_CPP_6_DEBUG):	$(OBJ_EXAMPLE_CPP_6_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_CPP_6_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_CPP_6_DEBUG):	$(SRC_EXAMPLE_CPP_6) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_CPP_6)

$(TARGET_EXAMPLE_CPP_1_RELEASE):	$(OBJ_EXAMPLE_CPP_1_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_CPP_1_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_CPP_1_RELEASE):	$(SRC_EXAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_CPP_1)

$(TARGET_EXAMPLE_CPP_2_RELEASE):	$(OBJ_EXAMPLE_CPP_2_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_CPP_2_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_CPP_2_RELEASE):	$(SRC_EXAMPLE_CPP_2) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_CPP_2)

$(TARGET_EXAMPLE_CPP_3_RELEASE):	$(OBJ_EXAMPLE_CPP_3_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_CPP_3_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_CPP_3_RELEASE):	$(SRC_EXAMPLE_CPP_3) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_CPP_3)

$(TARGET_EXAMPLE_CPP_4_RELEASE):	$(OBJ_EXAMPLE_CPP_4_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_CPP_4_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_CPP_4_RELEASE):	$(SRC_EXAMPLE_CPP_4) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_CPP_4)

$(TARGET_EXAMPLE_CPP_5_RELEASE):	$(OBJ_EXAMPLE_CPP_5_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_CPP_5_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_CPP_5_RELEASE):	$(SRC_EXAMPLE_CPP_5) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_CPP_5)

$(TARGET_EXAMPLE_CPP_6_RELEASE):	$(OBJ_EXAMPLE_CPP_6_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_CPP_6_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_CPP_6_RELEASE):	$(SRC_EXAMPLE_CPP_6) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_CPP_6)

# STL example client

$(TARGET_EXAMPLE_STL_1_DEBUG):	$(OBJ_EXAMPLE_STL_1_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_STL_1_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_STL_1_DEBUG):	$(SRC_EXAMPLE_STL_1) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_STL_1)

$(TARGET_EXAMPLE_STL_2_DEBUG):	$(OBJ_EXAMPLE_STL_2_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_STL_2_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_STL_2_DEBUG):	$(SRC_EXAMPLE_STL_2) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_STL_2)

$(TARGET_EXAMPLE_STL_3_DEBUG):	$(OBJ_EXAMPLE_STL_3_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_STL_3_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_STL_3_DEBUG):	$(SRC_EXAMPLE_STL_3) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_STL_3)

$(TARGET_EXAMPLE_STL_4_DEBUG):	$(OBJ_EXAMPLE_STL_4_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_STL_4_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_STL_4_DEBUG):	$(SRC_EXAMPLE_STL_4) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_STL_4)

$(TARGET_EXAMPLE_STL_5_DEBUG):	$(OBJ_EXAMPLE_STL_5_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_STL_5_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_STL_5_DEBUG):	$(SRC_EXAMPLE_STL_5) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_STL_5)

$(TARGET_EXAMPLE_STL_6_DEBUG):	$(OBJ_EXAMPLE_STL_6_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_STL_6_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_STL_6_DEBUG):	$(SRC_EXAMPLE_STL_6) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_STL_6)

$(TARGET_EXAMPLE_STL_7_DEBUG):	$(OBJ_EXAMPLE_STL_7_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_EXAMPLE_STL_7_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_EXAMPLE_STL_7_DEBUG):	$(SRC_EXAMPLE_STL_7) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(SRC_EXAMPLE_STL_7)

$(TARGET_EXAMPLE_STL_1_RELEASE):	$(OBJ_EXAMPLE_STL_1_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_STL_1_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_STL_1_RELEASE):	$(SRC_EXAMPLE_STL_1) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_STL_1)

$(TARGET_EXAMPLE_STL_2_RELEASE):	$(OBJ_EXAMPLE_STL_2_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_STL_2_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_STL_2_RELEASE):	$(SRC_EXAMPLE_STL_2) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_STL_2)

$(TARGET_EXAMPLE_STL_3_RELEASE):	$(OBJ_EXAMPLE_STL_3_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_STL_3_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_STL_3_RELEASE):	$(SRC_EXAMPLE_STL_3) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_STL_3)

$(TARGET_EXAMPLE_STL_4_RELEASE):	$(OBJ_EXAMPLE_STL_4_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_STL_4_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_STL_4_RELEASE):	$(SRC_EXAMPLE_STL_4) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_STL_4)

$(TARGET_EXAMPLE_STL_5_RELEASE):	$(OBJ_EXAMPLE_STL_5_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_STL_5_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_STL_5_RELEASE):	$(SRC_EXAMPLE_STL_5) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_STL_5)

$(TARGET_EXAMPLE_STL_6_RELEASE):	$(OBJ_EXAMPLE_STL_6_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_STL_6_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_STL_6_RELEASE):	$(SRC_EXAMPLE_STL_6) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_STL_6)

$(TARGET_EXAMPLE_STL_7_RELEASE):	$(OBJ_EXAMPLE_STL_7_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_EXAMPLE_STL_7_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_EXAMPLE_STL_7_RELEASE):	$(SRC_EXAMPLE_STL_7) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(SRC_EXAMPLE_STL_7)

########################################
# samples

# C sample client

$(TARGET_SAMPLE_C_1_DEBUG):	$(OBJ_SAMPLE_C_1_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_SAMPLE_C_1_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_SAMPLE_C_1_DEBUG):	$(SRC_SAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(SRC_SAMPLE_C_1)

$(TARGET_SAMPLE_C_2_DEBUG):	$(OBJ_SAMPLE_C_2_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_SAMPLE_C_2_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_SAMPLE_C_2_DEBUG):	$(SRC_SAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_DEBUG) --output-path=$@ $(SRC_SAMPLE_C_2)

$(TARGET_SAMPLE_C_1_RELEASE):	$(OBJ_SAMPLE_C_1_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_SAMPLE_C_1_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_SAMPLE_C_1_RELEASE):	$(SRC_SAMPLE_C_1) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(SRC_SAMPLE_C_1)

$(TARGET_SAMPLE_C_2_RELEASE):	$(OBJ_SAMPLE_C_2_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_SAMPLE_C_2_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_SAMPLE_C_2_RELEASE):	$(SRC_SAMPLE_C_2) $(HEADERS_LIB) makefile
	$(CC) $(CC_ARGS_RELEASE) --output-path=$@ $(SRC_SAMPLE_C_2)

# C++ sample client

$(TARGET_SAMPLE_CPP_1_DEBUG):	$(OBJ_SAMPLE_CPP_1_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_SAMPLE_CPP_1_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_SAMPLE_CPP_1_DEBUG):	$(SRC_SAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(SRC_SAMPLE_CPP_1)

$(TARGET_SAMPLE_CPP_1_RELEASE):	$(OBJ_SAMPLE_CPP_1_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_SAMPLE_CPP_1_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_SAMPLE_CPP_1_RELEASE):	$(SRC_SAMPLE_CPP_1) $(HEADERS_LIB) $(HEADERS_MAPPING_CPP) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(SRC_SAMPLE_CPP_1)

# STL sample client

$(TARGET_SAMPLE_STL_1_DEBUG):	$(OBJ_SAMPLE_STL_1_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_SAMPLE_STL_1_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_SAMPLE_STL_1_DEBUG):	$(SRC_SAMPLE_STL_1) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(SRC_SAMPLE_STL_1)

$(TARGET_SAMPLE_STL_2_DEBUG):	$(OBJ_SAMPLE_STL_2_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_SAMPLE_STL_2_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_SAMPLE_STL_2_DEBUG):	$(SRC_SAMPLE_STL_2) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(SRC_SAMPLE_STL_2)

$(TARGET_SAMPLE_STL_3_DEBUG):	$(OBJ_SAMPLE_STL_3_DEBUG) makefile
	$(LD) $(LD_ARGS_DEBUG) $@ $(OBJ_SAMPLE_STL_3_DEBUG) $(TARGET_LIB_DEBUG) $(3PTY_LIBS__DEBUG)

$(OBJ_SAMPLE_STL_3_DEBUG):	$(SRC_SAMPLE_STL_3) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_DEBUG) --output-path=$@ $(SRC_SAMPLE_STL_3)

$(TARGET_SAMPLE_STL_1_RELEASE):	$(OBJ_SAMPLE_STL_1_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_SAMPLE_STL_1_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_SAMPLE_STL_1_RELEASE):	$(SRC_SAMPLE_STL_1) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(SRC_SAMPLE_STL_1)

$(TARGET_SAMPLE_STL_2_RELEASE):	$(OBJ_SAMPLE_STL_2_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_SAMPLE_STL_2_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_SAMPLE_STL_2_RELEASE):	$(SRC_SAMPLE_STL_2) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(SRC_SAMPLE_STL_2)

$(TARGET_SAMPLE_STL_3_RELEASE):	$(OBJ_SAMPLE_STL_3_RELEASE) makefile
	$(LD) $(LD_ARGS_RELEASE) $@ $(OBJ_SAMPLE_STL_3_RELEASE) $(TARGET_LIB_RELEASE) $(3PTY_LIBS__RELEASE)

$(OBJ_SAMPLE_STL_3_RELEASE):	$(SRC_SAMPLE_STL_3) $(HEADERS_LIB) $(HEADERS_MAPPING_STL) makefile
	$(CPPC) $(CPPC_ARGS_RELEASE) --output-path=$@ $(SRC_SAMPLE_STL_3)

################################################################################
