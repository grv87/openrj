# Microsoft Developer Studio Project File - Name="test_stl_2" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=test_stl_2 - Win32 Debug NoX
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "test_stl_2.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "test_stl_2.mak" CFG="test_stl_2 - Win32 Debug NoX"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "test_stl_2 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "test_stl_2 - Win32 Debug NoX" (based on "Win32 (x86) Application")
!MESSAGE "test_stl_2 - Win32 Debug Multithreaded" (based on "Win32 (x86) Application")
!MESSAGE "test_stl_2 - Win32 Debug Multithreaded NoX" (based on "Win32 (x86) Application")
!MESSAGE "test_stl_2 - Win32 Debug Multithreaded DLL" (based on "Win32 (x86) Application")
!MESSAGE "test_stl_2 - Win32 Debug Multithreaded DLL NoX" (based on "Win32 (x86) Application")
!MESSAGE "test_stl_2 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "test_stl_2 - Win32 Release NoX" (based on "Win32 (x86) Application")
!MESSAGE "test_stl_2 - Win32 Release Multithreaded NoX" (based on "Win32 (x86) Application")
!MESSAGE "test_stl_2 - Win32 Release Multithreaded" (based on "Win32 (x86) Application")
!MESSAGE "test_stl_2 - Win32 Release Multithreaded DLL" (based on "Win32 (x86) Application")
!MESSAGE "test_stl_2 - Win32 Release Multithreaded DLL NoX" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "test_stl_2 - Win32 Debug"

# PROP BASE Use_MFC 1
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /GX /Zi /Od /I "../../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 openrj.1.vc6.debug.lib /nologo /version:1.0 /subsystem:console /debug /machine:I386 /out:"..\..\..\..\bin/test_stl_2.vc6.debug.exe" /pdbtype:sept /libpath:"../../../../lib"

!ELSEIF  "$(CFG)" == "test_stl_2 - Win32 Debug NoX"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugNoX"
# PROP BASE Intermediate_Dir "DebugNoX"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugNoX"
# PROP Intermediate_Dir "DebugNoX"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /Zi /Od /I "../../../../include" /D "WIN32" /D "_DEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Zi /Od /I "../../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 openrj.1.vc6.debug.lib /nologo /version:1.0 /subsystem:console /debug /machine:I386 /out:"..\..\..\..\bin/test_stl_2.vc6.debug.exe" /pdbtype:sept /libpath:"../../../../lib"
# ADD LINK32 openrj.1.vc6.nox.debug.lib /nologo /version:1.0 /subsystem:console /debug /machine:I386 /out:"..\..\..\..\bin/test_stl_2.vc6.nox.debug.exe" /pdbtype:sept /libpath:"../../../../lib"

!ELSEIF  "$(CFG)" == "test_stl_2 - Win32 Debug Multithreaded"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugMT"
# PROP BASE Intermediate_Dir "DebugMT"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugMT"
# PROP Intermediate_Dir "DebugMT"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /Zi /Od /I "../../../../include" /D "WIN32" /D "_DEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /GX /Zi /Od /I "../../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 openrj.1.vc6.debug.lib /nologo /version:1.0 /subsystem:console /debug /machine:I386 /out:"..\..\..\..\bin/test_stl_2.vc6.debug.exe" /pdbtype:sept /libpath:"../../../../lib"
# ADD LINK32 openrj.1.vc6.mt.debug.lib /nologo /version:1.0 /subsystem:console /debug /machine:I386 /out:"..\..\..\..\bin/test_stl_2.vc6.mt.debug.exe" /pdbtype:sept /libpath:"../../../../lib"

!ELSEIF  "$(CFG)" == "test_stl_2 - Win32 Debug Multithreaded NoX"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugMTNoX"
# PROP BASE Intermediate_Dir "DebugMTNoX"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugMTNoX"
# PROP Intermediate_Dir "DebugMTNoX"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /Zi /Od /I "../../../../include" /D "WIN32" /D "_DEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MTd /W3 /Zi /Od /I "../../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 openrj.1.vc6.debug.lib /nologo /version:1.0 /subsystem:console /debug /machine:I386 /out:"..\..\..\..\bin/test_stl_2.vc6.debug.exe" /pdbtype:sept /libpath:"../../../../lib"
# ADD LINK32 openrj.1.vc6.mt.nox.debug.lib /nologo /version:1.0 /subsystem:console /debug /machine:I386 /out:"..\..\..\..\bin/test_stl_2.vc6.nox.debug.exe" /pdbtype:sept /libpath:"../../../../lib"

!ELSEIF  "$(CFG)" == "test_stl_2 - Win32 Debug Multithreaded DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugDLL"
# PROP BASE Intermediate_Dir "DebugDLL"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugDLL"
# PROP Intermediate_Dir "DebugDLL"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /Zi /Od /I "../../../../include" /D "WIN32" /D "_DEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /GX /Zi /Od /I "../../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 openrj.1.vc6.debug.lib /nologo /version:1.0 /subsystem:console /debug /machine:I386 /out:"..\..\..\..\bin/test_stl_2.vc6.debug.exe" /pdbtype:sept /libpath:"../../../../lib"
# ADD LINK32 openrj.1.vc6.dll.debug.lib /nologo /version:1.0 /subsystem:console /debug /machine:I386 /out:"..\..\..\..\bin/test_stl_2.vc6.dll.debug.exe" /pdbtype:sept /libpath:"../../../../lib"

!ELSEIF  "$(CFG)" == "test_stl_2 - Win32 Debug Multithreaded DLL NoX"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "DebugDLLNoX"
# PROP BASE Intermediate_Dir "DebugDLLNoX"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugDLLNoX"
# PROP Intermediate_Dir "DebugDLLNoX"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W3 /GX /Zi /Od /I "../../../../include" /D "WIN32" /D "_DEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Zi /Od /I "../../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "_DEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "_DEBUG"
# ADD RSC /l 0xc09 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 openrj.1.vc6.debug.lib /nologo /version:1.0 /subsystem:console /debug /machine:I386 /out:"..\..\..\..\bin/test_stl_2.vc6.debug.exe" /pdbtype:sept /libpath:"../../../../lib"
# ADD LINK32 openrj.1.vc6.dll.nox.debug.lib /nologo /version:1.0 /subsystem:console /debug /machine:I386 /out:"..\..\..\..\bin/test_stl_2.vc6.dll.nox.debug.exe" /pdbtype:sept /libpath:"../../../../lib"

!ELSEIF  "$(CFG)" == "test_stl_2 - Win32 Release"

# PROP BASE Use_MFC 1
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /YX /FD /c
# ADD CPP /nologo /W4 /GX /O1 /I "../../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 openrj.1.vc6.lib /nologo /version:1.0 /subsystem:console /machine:I386 /out:"..\..\..\..\bin/test_stl_2.vc6.exe" /libpath:"../../../../lib"

!ELSEIF  "$(CFG)" == "test_stl_2 - Win32 Release NoX"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseNoX"
# PROP BASE Intermediate_Dir "ReleaseNoX"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseNoX"
# PROP Intermediate_Dir "ReleaseNoX"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W4 /GX /O1 /I "../../../../include" /D "WIN32" /D "NDEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /c
# ADD CPP /nologo /W4 /O1 /I "../../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 openrj.1.vc6.lib /nologo /version:1.0 /subsystem:console /machine:I386 /out:"..\..\..\..\bin/test_stl_2.vc6.exe" /libpath:"../../../../lib"
# ADD LINK32 openrj.1.vc6.nox.lib /nologo /version:1.0 /subsystem:console /machine:I386 /out:"..\..\..\..\bin/test_stl_2.vc6.nox.exe" /libpath:"../../../../lib"

!ELSEIF  "$(CFG)" == "test_stl_2 - Win32 Release Multithreaded NoX"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMTNoX"
# PROP BASE Intermediate_Dir "ReleaseMTNoX"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMTNoX"
# PROP Intermediate_Dir "ReleaseMTNoX"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W4 /GX /O1 /I "../../../../include" /D "WIN32" /D "NDEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /c
# ADD CPP /nologo /MT /W4 /O1 /I "../../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 openrj.1.vc6.lib /nologo /version:1.0 /subsystem:console /machine:I386 /out:"..\..\..\..\bin/test_stl_2.vc6.exe" /libpath:"../../../../lib"
# ADD LINK32 openrj.1.vc6.mt.nox.lib /nologo /version:1.0 /subsystem:console /machine:I386 /out:"..\..\..\..\bin/test_stl_2.vc6.mt.nox.exe" /libpath:"../../../../lib"

!ELSEIF  "$(CFG)" == "test_stl_2 - Win32 Release Multithreaded"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseMT"
# PROP BASE Intermediate_Dir "ReleaseMT"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseMT"
# PROP Intermediate_Dir "ReleaseMT"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W4 /GX /O1 /I "../../../../include" /D "WIN32" /D "NDEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /c
# ADD CPP /nologo /MT /W4 /GX /O1 /I "../../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 openrj.1.vc6.lib /nologo /version:1.0 /subsystem:console /machine:I386 /out:"..\..\..\..\bin/test_stl_2.vc6.exe" /libpath:"../../../../lib"
# ADD LINK32 openrj.1.vc6.mt.lib /nologo /version:1.0 /subsystem:console /machine:I386 /out:"..\..\..\..\bin/test_stl_2.vc6.mt.exe" /libpath:"../../../../lib"

!ELSEIF  "$(CFG)" == "test_stl_2 - Win32 Release Multithreaded DLL"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseDLL"
# PROP BASE Intermediate_Dir "ReleaseDLL"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseDLL"
# PROP Intermediate_Dir "ReleaseDLL"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W4 /GX /O1 /I "../../../../include" /D "WIN32" /D "NDEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /c
# ADD CPP /nologo /MD /W4 /GX /O1 /I "../../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 openrj.1.vc6.lib /nologo /version:1.0 /subsystem:console /machine:I386 /out:"..\..\..\..\bin/test_stl_2.vc6.exe" /libpath:"../../../../lib"
# ADD LINK32 openrj.1.vc6.dll.lib /nologo /version:1.0 /subsystem:console /machine:I386 /out:"..\..\..\..\bin/test_stl_2.vc6.dll.exe" /libpath:"../../../../lib"

!ELSEIF  "$(CFG)" == "test_stl_2 - Win32 Release Multithreaded DLL NoX"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "ReleaseDLLNoX"
# PROP BASE Intermediate_Dir "ReleaseDLLNoX"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseDLLNoX"
# PROP Intermediate_Dir "ReleaseDLLNoX"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /W4 /GX /O1 /I "../../../../include" /D "WIN32" /D "NDEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /c
# ADD CPP /nologo /MD /W4 /O1 /I "../../../../include" /I "$(STLSOFT)/include" /D "WIN32" /D "NDEBUG" /D "STRICT" /D "_CONSOLE" /FR /YX /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0xc09 /d "NDEBUG"
# ADD RSC /l 0xc09 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 openrj.1.vc6.lib /nologo /version:1.0 /subsystem:console /machine:I386 /out:"..\..\..\..\bin/test_stl_2.vc6.exe" /libpath:"../../../../lib"
# ADD LINK32 openrj.1.vc6.dll.nox.lib /nologo /version:1.0 /subsystem:console /machine:I386 /out:"..\..\..\..\bin/test_stl_2.vc6.dll.nox.exe" /libpath:"../../../../lib"

!ENDIF 

# Begin Target

# Name "test_stl_2 - Win32 Debug"
# Name "test_stl_2 - Win32 Debug NoX"
# Name "test_stl_2 - Win32 Debug Multithreaded"
# Name "test_stl_2 - Win32 Debug Multithreaded NoX"
# Name "test_stl_2 - Win32 Debug Multithreaded DLL"
# Name "test_stl_2 - Win32 Debug Multithreaded DLL NoX"
# Name "test_stl_2 - Win32 Release"
# Name "test_stl_2 - Win32 Release NoX"
# Name "test_stl_2 - Win32 Release Multithreaded NoX"
# Name "test_stl_2 - Win32 Release Multithreaded"
# Name "test_stl_2 - Win32 Release Multithreaded DLL"
# Name "test_stl_2 - Win32 Release Multithreaded DLL NoX"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\test_stl_2.cpp
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Group "Open-RJ Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE="$(OPENRJ_ROOT)\include\openrj\openrj.h"
# End Source File
# End Group
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# End Group
# End Target
# End Project
