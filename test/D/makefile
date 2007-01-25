
DMD		=	dmd
LD		=	dmd

#OPENRJ_PHOBOS_ROOT	=	$(SYNSOFT_D_ROOT)\phobos
OPENRJ_PHOBOS_ROOT	=	H:\freelibs\openrj\Mappings\D

OPENRJ_LIB_ROOT		=	H:\freelibs\openrj\lib


DC_ARGS			=	-debug -unittest -g -I$(OPENRJ_PHOBOS_ROOT)

TARGET			=						\
					openrj_test.exe		\
										\

target:	$(TARGET)

clean:
	-@if exist $(TARGET) del /f $(TARGET)
	-@if exist *.obj del /f *.obj
	-@if exist *.map del /f *.map
	-@if exist *~ del /f *~
	-@if exist *.*~ del /f *.*~

test:	target
	$(TARGET) $(OPENRJ-TEST-FILE)

$(TARGET): openrj_test.obj openrj.obj openrj-etc.obj
	$(LD) -of$@ openrj_test.obj openrj.obj openrj-etc.obj $(OPENRJ_LIB_ROOT)\openrj.dm.lib

openrj_test.obj: openrj_test.d
	$(DMD) -c $(DC_ARGS) -of$@ openrj_test.d

openrj.obj: $(OPENRJ_PHOBOS_ROOT)\std\openrj.d
	$(DMD) -c $(DC_ARGS) -of$@ $(OPENRJ_PHOBOS_ROOT)\std\openrj.d

openrj-etc.obj: $(OPENRJ_PHOBOS_ROOT)\etc\c\openrj\openrj.d
	$(DMD) -c $(DC_ARGS) -of$@ $(OPENRJ_PHOBOS_ROOT)\etc\c\openrj\openrj.d

