################################################################################
#  File:    makefile
# 
#  Purpose: Visual C++ makefile for the Open-RJ Ch mapping
# 
#  Created: 7th August 2004
#  Updated: 29th September 2004
# 
#  Home:    http://openrj.org/
# 
#  Copyright (c) 2004, Matthew Wilson and Synesis Software
#  All rights reserved.
# 
#  Redistribution and use in source and binary forms, with or without 
#  modification, are permitted provided that the following conditions are met:
# 
#  - Redistributions of source code must retain the above copyright notice, this
#    list of conditions and the following disclaimer. 
#  - Redistributions in binary form must reproduce the above copyright notice,
#    this list of conditions and the following disclaimer in the documentation
#    and/or other materials provided with the distribution.
#  - Neither the names of Matthew Wilson and Synesis Software nor the names of
#    any contributors may be used to endorse or promote products derived from
#    this software without specific prior written permission.
# 
#  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
#  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
#  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
#  ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
#  LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
#  CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
#  SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
#  INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
#  CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
#  ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
#  POSSIBILITY OF SUCH DAMAGE.
# 
################################################################################


CC			=	cl
LD			=	link

CC_F_NOLOGO	=	-nologo
CC_F_MT		=	-MD

CC_ARGS		=	$(CC_F_NOLOGO) $(CC_F_MT)
LD_ARGS		=	-nologo


#CH_ROOT		=	P:\Programs\Ch

CH_INCLUDE	=	$(CH_ROOT)\extern\include
CH_LIB		=	$(CH_ROOT)\extern\lib

LIBPATH0	=	$(CH_ROOT)\extern\lib
LIBPATH1	=	$(OPENRJ_DEV)\lib

INCLUDES	=	-I$(OPENRJ_DEV)\include -I$(CH_EXTERN)\include
LIBS		=	openrj.vc71.lib advapi32.lib user32.lib kernel32.lib msvcrt.lib ch.lib chsdk.lib

OBJECTS		=					\
				libopenrjch.o	\
#				dllmain.o		\
								\



target:	libopenrjch.dl

libopenrjch.dl:	$(OBJECTS) makefile
	$(LD) $(LD_ARGS) -dll -libpath:$(LIBPATH0) -libpath:$(LIBPATH1) -out:$@ -nodefaultlib $(LIBS) $(OBJECTS)

libopenrjch.o:	libopenrjch.c makefile
	$(CC) $(CC_ARGS) -c $(INCLUDES) -Fo$@ libopenrjch.c

dllmain.o:		dllmain.c makefile
	$(CC) $(CC_ARGS) -c $(INCLUDES) -Fo$@ dllmain.c

clean:
	rm -f *.o *.dl *.lib *.exp *.*~
