################################################################################
# File:		makefile
#
# Purpose:	Makefile for the Open-RJ project for Borland 5.6.4
#
# Created:	18th June 2004
# Updated:	29th September 2004
#
#
################################################################################

COMP_ID		=	bc564
CC			=	bcc32
CPPC		=	bcc32
AR			=	tlib
LD			=	bcc32

OPENRJ_BASE		=	..\..
OPENRJ_INCLUDE	=	$(OPENRJ_BASE)\include
OPENRJ_SRC		=	$(OPENRJ_BASE)\src
OPENRJ_LIB		=	$(OPENRJ_BASE)\lib
OPENRJ_BIN		=	$(OPENRJ_BASE)\bin
OPENRJ_TEST		=	$(OPENRJ_BASE)\test

CC_ARGS			=	-q -c -I$(OPENRJ_INCLUDE)
CPPC_ARGS		=	-q -c -I$(OPENRJ_INCLUDE) -I$(STLSOFT_INCLUDE)

LD_ARGS			=	-q


TARGET_LIB		=	$(OPENRJ_LIB)\openrj.$(COMP_ID).lib
TARGET_CLI_C	=	$(OPENRJ_BIN)\openrj_c_$(COMP_ID).exe
TARGET_CLI_CPP	=	$(OPENRJ_BIN)\openrj_cpp_$(COMP_ID).exe
TARGET_CLI_STL	=	$(OPENRJ_BIN)\openrj_stl_$(COMP_ID).exe

OBJS			=												\
					.\orjapi.obj								\
					.\orjmem.obj								\
					.\orjstr.obj								\
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
	@-if exist $(TARGET_LIB) del /f $(TARGET_LIB)
	@-if exist $(TARGET_CLI_C) del /f $(TARGET_CLI_C)
	@-if exist $(TARGET_CLI_CPP) del /f $(TARGET_CLI_CPP)
	@-if exist $(TARGET_CLI_STL) del /f $(TARGET_CLI_STL)


# Library dependencies

$(TARGET_LIB):		$(OBJS)
	@itemprep "$(OBJS)" + > temp.temp
	$(AR) $@ @temp.temp
	@del /f temp.temp

.\orjapi.obj:	$(OPENRJ_SRC)\orjapi.c $(INCLUDE_FILES) makefile
	$(CC) $(CC_ARGS) -o$@ $(OPENRJ_SRC)\orjapi.c 

.\orjmem.obj:	$(OPENRJ_SRC)\orjmem.c $(INCLUDE_FILES) makefile
	$(CC) $(CC_ARGS) -o$@ $(OPENRJ_SRC)\orjmem.c 

.\orjstr.obj:	$(OPENRJ_SRC)\orjstr.c $(INCLUDE_FILES) makefile
	$(CC) $(CC_ARGS) -o$@ $(OPENRJ_SRC)\orjstr.c 

# Client dependencies

$(TARGET_CLI_C): .\C.obj $(TARGET_LIB)
	$(LD) $(LD_ARGS) -e$@ .\C.obj $(TARGET_LIB)
	
.\C.obj: $(OPENRJ_TEST)\C\C.c $(INCLUDE_FILES) makefile
	$(CC) $(CC_ARGS) -o$@ $(OPENRJ_TEST)\C\C.c

$(TARGET_CLI_CPP): .\Cpp.obj $(TARGET_LIB)
	$(LD) $(LD_ARGS) -e$@ .\Cpp.obj $(TARGET_LIB)
	
.\Cpp.obj: $(OPENRJ_TEST)\Cpp\Cpp.cpp $(INCLUDE_FILES_CPP) makefile
	$(CPPC) $(CPPC_ARGS) -o$@ $(OPENRJ_TEST)\Cpp\Cpp.cpp

$(TARGET_CLI_STL): .\STL.obj $(TARGET_LIB)
	$(LD) $(LD_ARGS) -e$@ .\STL.obj $(TARGET_LIB)
	
.\STL.obj: $(OPENRJ_TEST)\STL\STL.cpp $(INCLUDE_FILES_STL) makefile
	$(CPPC) $(CPPC_ARGS) -o$@ $(OPENRJ_TEST)\STL\STL.cpp








