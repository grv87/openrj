

DC		=	dmd
AR		=	lib

DC_ARGS	=	-c

TARGET	=	.\openrj_d.lib


target:	$(TARGET)

clean:
	-@if exist *.obj del /f *.obj
	-@if exist $(TARGET) del /f $(TARGET)

.\openrj_d.lib:	.\std\openrj.obj .\etc\c\openrj\openrj.obj


.\std\openrj.obj:	.\std\openrj.d makefile
	$(DC) $(DC_ARGS) -of$@ .\std\openrj.d


.\etc\c\openrj\openrj.obj:	.\etc\c\openrj\openrj.d makefile
	$(DC) $(DC_ARGS) -of$@ .\etc\c\openrj\openrj.d


