################################################################################
# File:		makefile
#
# Purpose:	Makefile for the Open-RJ project
#
# Created:	18th June 2004
# Updated:	29th September 2004
#
#
################################################################################

COMP_ID		=	dm
CC			=	dmc
CPPC		=	dmc
AR			=	lib
LD			=	link

OPENRJ_BASE		=	..\..
OPENRJ_INCLUDE	=	$(OPENRJ_BASE)\include
OPENRJ_SRC		=	$(OPENRJ_BASE)\src
OPENRJ_LIB		=	$(OPENRJ_BASE)\lib
OPENRJ_BIN		=	$(OPENRJ_BASE)\bin
OPENRJ_TEST		=	$(OPENRJ_BASE)\test

CC_ARGS			=	-c -I$(OPENRJ_INCLUDE)
CPPC_ARGS		=	-Ae -c -I$(OPENRJ_INCLUDE) -I"$(INCLUDE)"

LD_ARGS			=	/noi


TARGET_LIB		=	$(OPENRJ_LIB)\openrj.$(COMP_ID).lib
TARGET_CLI_C	=	$(OPENRJ_BIN)\openrj_c_$(COMP_ID).exe
TARGET_CLI_CPP	=	$(OPENRJ_BIN)\openrj_cpp_$(COMP_ID).exe
TARGET_CLI_STL	=	$(OPENRJ_BIN)\openrj_stl_$(COMP_ID).exe

OBJS			=												\
					.\orjapi.obj								\
					.\orjmem.obj								\
					.\orjstr.obj								\
																\

OBJS_LIB		=												\
					.\orjapi.obj								\
					+.\orjmem.obj								\
					+.\orjstr.obj								\
																\
	
INCLUDE_FILES	=												\
					$(OPENRJ_INCLUDE)\openrj\openrj.h			\
					$(OPENRJ_INCLUDE)\openrj\openrj_assert.h	\
					$(OPENRJ_INCLUDE)\openrj\openrj_memory.h	\
																\
												
INCLUDE_FILES_CPP	=												\
						$(INCLUDE_FILES)							\
						$(OPENRJ_INCLUDE)\openrj\cpp\openrj.hpp		\
						$(OPENRJ_INCLUDE)\openrj\cpp\field.hpp		\
						$(OPENRJ_INCLUDE)\openrj\cpp\record.hpp		\
						$(OPENRJ_INCLUDE)\openrj\cpp\database.hpp	\
																	\

target:									\
					$(TARGET_LIB)		\
					$(TARGET_CLI_C)		\
					$(TARGET_CLI_CPP)	\
					$(TARGET_CLI_STL)	\
										\

clean:
	@-if exist *.obj del /f *.obj
	@-if exist *.map del /f *.map
	@-if exist $(TARGET_LIB) del /f $(TARGET_LIB)
	@-if exist $(TARGET_CLI_C) del /f $(TARGET_CLI_C)
	@-if exist $(TARGET_CLI_CPP) del /f $(TARGET_CLI_CPP)
	@-if exist $(TARGET_CLI_STL) del /f $(TARGET_CLI_STL)


# Library dependencies

$(TARGET_LIB):		$(OBJS)
	$(AR) $@ /c $(OBJS_LIB),,$@;

.\orjapi.obj:	$(OPENRJ_SRC)\orjapi.c $(INCLUDE_FILES) makefile $(OPENRJ_INCLUDE)\openrj\openrj.h
	$(CC) $(CC_ARGS) -o$@ $(OPENRJ_SRC)\orjapi.c 

.\orjmem.obj:	$(OPENRJ_SRC)\orjmem.c $(INCLUDE_FILES) makefile $(OPENRJ_INCLUDE)\openrj\openrj.h
	$(CC) $(CC_ARGS) -o$@ $(OPENRJ_SRC)\orjmem.c 

.\orjstr.obj:	$(OPENRJ_SRC)\orjstr.c $(INCLUDE_FILES) makefile $(OPENRJ_INCLUDE)\openrj\openrj.h
	$(CC) $(CC_ARGS) -o$@ $(OPENRJ_SRC)\orjstr.c 

# Client dependencies

$(TARGET_CLI_C): .\C.obj $(TARGET_LIB)
	$(LD) $(LD_ARGS) $**,"$@",,$(LIBS)
	
.\C.obj: $(OPENRJ_TEST)\C\C.c $(INCLUDE_FILES) makefile $(OPENRJ_INCLUDE)\openrj\openrj.h
	$(CC) $(CC_ARGS) -o$@ $(OPENRJ_TEST)\C\C.c

$(TARGET_CLI_CPP): .\Cpp.obj $(TARGET_LIB)
	$(LD) $(LD_ARGS) $**,"$@",,$(LIBS)
	
.\Cpp.obj: $(OPENRJ_TEST)\Cpp\Cpp.cpp $(INCLUDE_FILES_CPP) makefile $(OPENRJ_INCLUDE)\openrj\cpp\openrj.hpp $(OPENRJ_INCLUDE)\openrj\cpp\field.hpp
	$(CPPC) $(CPPC_ARGS) -o$@ $(OPENRJ_TEST)\Cpp\Cpp.cpp

$(TARGET_CLI_STL): .\STL.obj $(TARGET_LIB)
	$(LD) $(LD_ARGS) $**,"$@",,$(LIBS)
	
.\STL.obj: $(OPENRJ_TEST)\STL\STL.cpp $(INCLUDE_FILES_STL) makefile $(OPENRJ_INCLUDE)\openrj\stl\openrj.hpp $(OPENRJ_INCLUDE)\openrj\stl\field.hpp
	$(CPPC) $(CPPC_ARGS) -o$@ $(OPENRJ_TEST)\STL\STL.cpp








