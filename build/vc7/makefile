################################################################################
# File:		makefile
# 
# Purpose:	Makefile for the Open-RJ project for Visual C++ 7.0
#
# Created:	26th June 2004
# Updated:	28th September 2004
#
#
################################################################################

COMP_ID		=	vc7
CC			=	cl
CPPC		=	cl
AR			=	lib
LD			=	link

OPENRJ_BASE		=	..\..
OPENRJ_INCLUDE	=	$(OPENRJ_BASE)\include
OPENRJ_SRC		=	$(OPENRJ_BASE)\src
OPENRJ_LIB		=	$(OPENRJ_BASE)\lib
OPENRJ_BIN		=	$(OPENRJ_BASE)\bin
OPENRJ_MAPPINGS =	$(OPENRJ_BASE)\mappings
OPENRJ_TEST		=	$(OPENRJ_BASE)\test
OPENRJ_SAMPLES	=	$(OPENRJ_BASE)\samples

CC_ARGS			=	-c -W4 -WX -nologo -I$(OPENRJ_INCLUDE)
CC_ARGS_ST		=	-ML $(CC_ARGS)
CC_ARGS_MT		=	-MT $(CC_ARGS)
CC_ARGS_DLL		=	-MD $(CC_ARGS)
CPPC_ARGS		=	-c -W4 -WX -nologo -I$(OPENRJ_INCLUDE) -EHsc
CPPC_ARGS_ST	=	-ML $(CPPC_ARGS)
CPPC_ARGS_MT	=	-MT $(CPPC_ARGS)
CPPC_ARGS_DLL	=	-MD $(CPPC_ARGS)

LD_ARGS			=	-nologo


TARGET_LIB_ST		=	$(OPENRJ_LIB)\openrj.$(COMP_ID).lib
TARGET_LIB_MT		=	$(OPENRJ_LIB)\openrj.$(COMP_ID).mt.lib
TARGET_LIB_DLL		=	$(OPENRJ_LIB)\openrj.$(COMP_ID).dll.lib
TARGET_DLL			=	$(OPENRJ_BIN)\openrj.dll
TARGET_CLI_C_ST		=	$(OPENRJ_BIN)\openrj_c_$(COMP_ID).st.exe
TARGET_CLI_C_MT		=	$(OPENRJ_BIN)\openrj_c_$(COMP_ID).mt.exe
TARGET_CLI_C_DLL	=	$(OPENRJ_BIN)\openrj_c_$(COMP_ID).dll.exe
TARGET_CLI_CPP_ST	=	$(OPENRJ_BIN)\openrj_cpp_$(COMP_ID).st.exe
TARGET_CLI_CPP_MT	=	$(OPENRJ_BIN)\openrj_cpp_$(COMP_ID).mt.exe
TARGET_CLI_CPP_DLL	=	$(OPENRJ_BIN)\openrj_cpp_$(COMP_ID).dll.exe
TARGET_CLI_STL_ST	=	$(OPENRJ_BIN)\openrj_stl_$(COMP_ID).st.exe
TARGET_CLI_STL_MT	=	$(OPENRJ_BIN)\openrj_stl_$(COMP_ID).mt.exe
TARGET_CLI_STL_DLL	=	$(OPENRJ_BIN)\openrj_stl_$(COMP_ID).dll.exe

OBJS_LIB_ST			=											\
					.\orjapi.st.obj								\
					.\orjmem.st.obj								\
					.\orjstr.st.obj								\
																\

OBJS_LIB_MT			=											\
					.\orjapi.mt.obj								\
					.\orjmem.mt.obj								\
					.\orjstr.mt.obj								\
																\

OBJS_LIB_DLL		=											\
					.\orjapi.dll.obj							\
					.\orjmem.dll.obj							\
					.\orjstr.dll.obj							\
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

target:										\
					$(TARGET_LIB_ST)		\
					$(TARGET_LIB_MT)		\
					$(TARGET_LIB_DLL)		\
					$(TARGET_DLL)			\
					$(TARGET_CLI_C_ST)		\
					$(TARGET_CLI_C_MT)		\
					$(TARGET_CLI_C_DLL)		\
					$(TARGET_CLI_CPP_ST)	\
					$(TARGET_CLI_CPP_MT)	\
					$(TARGET_CLI_CPP_DLL)	\
					$(TARGET_CLI_STL_ST)	\
					$(TARGET_CLI_STL_MT)	\
					$(TARGET_CLI_STL_DLL)	\
											\

test:
	$(TARGET_CLI_C_ST)		$(OPENRJ_SAMPLES)\pets\pets.orj
	$(TARGET_CLI_C_MT)		$(OPENRJ_SAMPLES)\pets\pets.orj
	$(TARGET_CLI_C_DLL)		$(OPENRJ_SAMPLES)\pets\pets.orj
	$(TARGET_CLI_CPP_ST)	$(OPENRJ_SAMPLES)\pets\pets.orj
	$(TARGET_CLI_CPP_MT)	$(OPENRJ_SAMPLES)\pets\pets.orj
	$(TARGET_CLI_CPP_DLL)	$(OPENRJ_SAMPLES)\pets\pets.orj
	$(TARGET_CLI_STL_ST)	$(OPENRJ_SAMPLES)\pets\pets.orj
	$(TARGET_CLI_STL_MT)	$(OPENRJ_SAMPLES)\pets\pets.orj
	$(TARGET_CLI_STL_DLL)	$(OPENRJ_SAMPLES)\pets\pets.orj
	

clean:
	@-if exist *.obj del /f *.obj
	@-if exist $(TARGET_LIB_ST) del /f $(TARGET_LIB_ST)
	@-if exist $(TARGET_LIB_MT) del /f $(TARGET_LIB_MT)
	@-if exist $(TARGET_LIB_DLL) del /f $(TARGET_LIB_DLL)
	@-if exist $(TARGET_DLL) del /f $(TARGET_DLL)
	@-if exist $(TARGET_CLI_C_ST) del /f $(TARGET_CLI_C_ST)
	@-if exist $(TARGET_CLI_C_MT) del /f $(TARGET_CLI_C_MT)
	@-if exist $(TARGET_CLI_C_DLL) del /f $(TARGET_CLI_C_DLL)
	@-if exist $(TARGET_CLI_CPP_ST) del /f $(TARGET_CLI_CPP_ST)
	@-if exist $(TARGET_CLI_CPP_MT) del /f $(TARGET_CLI_CPP_MT)
	@-if exist $(TARGET_CLI_CPP_DLL) del /f $(TARGET_CLI_CPP_DLL)
	@-if exist $(TARGET_CLI_STL_ST) del /f $(TARGET_CLI_STL_ST)
	@-if exist $(TARGET_CLI_STL_MT) del /f $(TARGET_CLI_STL_MT)
	@-if exist $(TARGET_CLI_STL_DLL) del /f $(TARGET_CLI_STL_DLL)


# Library dependencies

$(TARGET_LIB_ST):		$(OBJS_LIB_ST)
	$(AR) -nologo -out:$@ $(OBJS_LIB_ST)

$(TARGET_LIB_MT):		$(OBJS_LIB_MT)
	$(AR) -nologo -out:$@ $(OBJS_LIB_MT)

$(TARGET_LIB_DLL):		$(OBJS_LIB_DLL)
	$(AR) -nologo -out:$@ $(OBJS_LIB_DLL)

$(TARGET_DLL):		$(TARGET_LIB_DLL) .\openrj-dll.obj
	$(LD) $(LD_ARGS) -nologo -dll -out:$@ $(TARGET_LIB_DLL) .\openrj-dll.obj

.\openrj-dll.obj:	$(OPENRJ_MAPPINGS)\DLL\openrj-dll.c
	$(CC) $(CC_ARGS_ST) -Fo$@ $(OPENRJ_MAPPINGS)\DLL\openrj-dll.c

.\orjapi.st.obj:	$(OPENRJ_SRC)\orjapi.c $(INCLUDE_FILES) makefile
	$(CC) $(CC_ARGS_ST) -Fo$@ $(OPENRJ_SRC)\orjapi.c 

.\orjapi.mt.obj:	$(OPENRJ_SRC)\orjapi.c $(INCLUDE_FILES) makefile
	$(CC) $(CC_ARGS_MT) -Fo$@ $(OPENRJ_SRC)\orjapi.c 

.\orjapi.dll.obj:	$(OPENRJ_SRC)\orjapi.c $(INCLUDE_FILES) makefile
	$(CC) $(CC_ARGS_DLL) -Fo$@ $(OPENRJ_SRC)\orjapi.c 

.\orjmem.st.obj:	$(OPENRJ_SRC)\orjmem.c $(INCLUDE_FILES) makefile
	$(CC) $(CC_ARGS_ST) -Fo$@ $(OPENRJ_SRC)\orjmem.c 

.\orjmem.mt.obj:	$(OPENRJ_SRC)\orjmem.c $(INCLUDE_FILES) makefile
	$(CC) $(CC_ARGS_MT) -Fo$@ $(OPENRJ_SRC)\orjmem.c 

.\orjmem.dll.obj:	$(OPENRJ_SRC)\orjmem.c $(INCLUDE_FILES) makefile
	$(CC) $(CC_ARGS_DLL) -Fo$@ $(OPENRJ_SRC)\orjmem.c 

.\orjstr.st.obj:	$(OPENRJ_SRC)\orjstr.c $(INCLUDE_FILES) makefile
	$(CC) $(CC_ARGS_ST) -Fo$@ $(OPENRJ_SRC)\orjstr.c 

.\orjstr.mt.obj:	$(OPENRJ_SRC)\orjstr.c $(INCLUDE_FILES) makefile
	$(CC) $(CC_ARGS_MT) -Fo$@ $(OPENRJ_SRC)\orjstr.c 

.\orjstr.dll.obj:	$(OPENRJ_SRC)\orjstr.c $(INCLUDE_FILES) makefile
	$(CC) $(CC_ARGS_DLL) -Fo$@ $(OPENRJ_SRC)\orjstr.c 

# Client dependencies

$(TARGET_CLI_C_ST): .\C.st.obj $(TARGET_LIB_ST)
	$(LD) $(LD_ARGS) -out:$@ .\C.st.obj $(TARGET_LIB_ST)

$(TARGET_CLI_C_MT): .\C.mt.obj $(TARGET_LIB_MT)
	$(LD) $(LD_ARGS) -out:$@ .\C.mt.obj $(TARGET_LIB_MT)

$(TARGET_CLI_C_DLL): .\C.dll.obj $(TARGET_LIB_DLL)
	$(LD) $(LD_ARGS) -out:$@ .\C.dll.obj $(TARGET_LIB_DLL)
	
.\C.st.obj: $(OPENRJ_TEST)\C\C.c $(INCLUDE_FILES) makefile
	$(CC) $(CC_ARGS_ST) -Fo$@ $(OPENRJ_TEST)\C\C.c

.\C.mt.obj: $(OPENRJ_TEST)\C\C.c $(INCLUDE_FILES) makefile
	$(CC) $(CC_ARGS_MT) -Fo$@ $(OPENRJ_TEST)\C\C.c

.\C.dll.obj: $(OPENRJ_TEST)\C\C.c $(INCLUDE_FILES) makefile
	$(CC) $(CC_ARGS_DLL) -Fo$@ $(OPENRJ_TEST)\C\C.c

$(TARGET_CLI_CPP_ST): .\Cpp.st.obj $(TARGET_LIB_ST)
	$(LD) $(LD_ARGS) -out:$@ .\Cpp.st.obj $(TARGET_LIB_ST)
$(TARGET_CLI_CPP_MT): .\Cpp.mt.obj $(TARGET_LIB_MT)
	$(LD) $(LD_ARGS) -out:$@ .\Cpp.mt.obj $(TARGET_LIB_MT)
$(TARGET_CLI_CPP_DLL): .\Cpp.dll.obj $(TARGET_LIB_DLL)
	$(LD) $(LD_ARGS) -out:$@ .\Cpp.dll.obj $(TARGET_LIB_DLL)
	
.\Cpp.st.obj: $(OPENRJ_TEST)\Cpp\Cpp.cpp $(INCLUDE_FILES_CPP) makefile
	$(CPPC) $(CPPC_ARGS_ST) -Fo$@ $(OPENRJ_TEST)\Cpp\Cpp.cpp
.\Cpp.mt.obj: $(OPENRJ_TEST)\Cpp\Cpp.cpp $(INCLUDE_FILES_CPP) makefile
	$(CPPC) $(CPPC_ARGS_MT) -Fo$@ $(OPENRJ_TEST)\Cpp\Cpp.cpp
.\Cpp.dll.obj: $(OPENRJ_TEST)\Cpp\Cpp.cpp $(INCLUDE_FILES_CPP) makefile
	$(CPPC) $(CPPC_ARGS_DLL) -Fo$@ $(OPENRJ_TEST)\Cpp\Cpp.cpp

$(TARGET_CLI_STL_ST): .\STL.st.obj $(TARGET_LIB_ST)
	$(LD) $(LD_ARGS) -out:$@ .\STL.st.obj $(TARGET_LIB_ST)
$(TARGET_CLI_STL_MT): .\STL.mt.obj $(TARGET_LIB_MT)
	$(LD) $(LD_ARGS) -out:$@ .\STL.mt.obj $(TARGET_LIB_MT)
$(TARGET_CLI_STL_DLL): .\STL.dll.obj $(TARGET_LIB_DLL)
	$(LD) $(LD_ARGS) -out:$@ .\STL.dll.obj $(TARGET_LIB_DLL)
	
.\STL.st.obj: $(OPENRJ_TEST)\STL\STL.cpp $(INCLUDE_FILES_STL) makefile
	$(CPPC) $(CPPC_ARGS_ST) -Fo$@ $(OPENRJ_TEST)\STL\STL.cpp
.\STL.mt.obj: $(OPENRJ_TEST)\STL\STL.cpp $(INCLUDE_FILES_STL) makefile
	$(CPPC) $(CPPC_ARGS_MT) -Fo$@ $(OPENRJ_TEST)\STL\STL.cpp
.\STL.dll.obj: $(OPENRJ_TEST)\STL\STL.cpp $(INCLUDE_FILES_STL) makefile
	$(CPPC) $(CPPC_ARGS_DLL) -Fo$@ $(OPENRJ_TEST)\STL\STL.cpp









