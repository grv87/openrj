# Microsoft Developer Studio Project File - Name="openrj_Ch" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Generic Project" 0x010a

CFG=openrj_Ch - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "openrj_Ch.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "openrj_Ch.mak" CFG="openrj_Ch - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "openrj_Ch - Win32 Release" (based on "Win32 (x86) Generic Project")
!MESSAGE "openrj_Ch - Win32 Debug" (based on "Win32 (x86) Generic Project")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
MTL=midl.exe

!IF  "$(CFG)" == "openrj_Ch - Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""

!ELSEIF  "$(CFG)" == "openrj_Ch - Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Target_Dir ""

!ENDIF 

# Begin Target

# Name "openrj_Ch - Win32 Release"
# Name "openrj_Ch - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "c;cpp"
# Begin Source File

SOURCE=..\dllmain.c
# End Source File
# Begin Source File

SOURCE=..\libopenrjch.c
# End Source File
# End Group
# Begin Group "Function Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\ORJ_CreateDatabaseFromMemoryA.chf
# End Source File
# Begin Source File

SOURCE=..\ORJ_Database_GetRecordA.chf
# End Source File
# Begin Source File

SOURCE=..\ORJ_Field_GetNameA.chf
# End Source File
# Begin Source File

SOURCE=..\ORJ_Field_GetNameAndValueA.chf
# End Source File
# Begin Source File

SOURCE=..\ORJ_Field_GetRecordA.chf
# End Source File
# Begin Source File

SOURCE=..\ORJ_Field_GetValueA.chf
# End Source File
# Begin Source File

SOURCE=..\ORJ_FreeDatabaseA.chf
# End Source File
# Begin Source File

SOURCE=..\ORJ_GetErrorStringA.chf
# End Source File
# Begin Source File

SOURCE=..\ORJ_GetParseErrorStringA.chf
# End Source File
# Begin Source File

SOURCE=..\ORJ_ReadDatabaseA.chf
# End Source File
# Begin Source File

SOURCE=..\ORJ_Record_FindFieldByNameA.chf
# End Source File
# Begin Source File

SOURCE=..\ORJ_Record_GetDatabaseA.chf
# End Source File
# Begin Source File

SOURCE=..\ORJ_Record_GetFieldA.chf
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter ""
# Begin Group "Open-RJ Header Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\..\..\include\openrj\openrj.h
# End Source File
# Begin Source File

SOURCE=..\..\..\include\openrj\openrj_assert.h
# End Source File
# End Group
# End Group
# Begin Group "Ch Script Files"

# PROP Default_Filter ""
# Begin Source File

SOURCE=..\test.ch
# End Source File
# End Group
# End Target
# End Project
