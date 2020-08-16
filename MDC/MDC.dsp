# Microsoft Developer Studio Project File - Name="MDC" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=MDC - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MDC.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MDC.mak" CFG="MDC - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MDC - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "MDC - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "MDC - Win32 Release"

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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"Release\MDCc.lib"

!ELSEIF  "$(CFG)" == "MDC - Win32 Debug"

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
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"Debug\MDCcD.lib"

!ENDIF 

# Begin Target

# Name "MDC - Win32 Release"
# Name "MDC - Win32 Debug"
# Begin Group "Files"

# PROP Default_Filter ""
# Begin Group "src"

# PROP Default_Filter ""
# Begin Group "mdc_c"

# PROP Default_Filter ""
# Begin Group "container_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\mdc\container\map.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\container\pair.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\container\vector.c
# End Source File
# End Group
# Begin Group "wchar_t_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\mdc\wchar_t\wide_decoding.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\wchar_t\wide_encoding.c
# End Source File
# End Group
# Begin Group "std_c"

# PROP Default_Filter ""
# Begin Group "threads_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\mdc\std\threads\call_once.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\std\threads\cond.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\std\threads\mutex.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\std\threads\threads.c
# End Source File
# End Group
# End Group
# End Group
# End Group
# Begin Group "include"

# PROP Default_Filter ""
# Begin Group "mdc_h"

# PROP Default_Filter ""
# Begin Group "container_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\mdc\container\map.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\container\pair.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\container\vector.h
# End Source File
# End Group
# Begin Group "wchar_t_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\mdc\wchar_t\wide_decoding.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\wchar_t\wide_encoding.h
# End Source File
# End Group
# Begin Group "std_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\mdc\std\stdbool.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\std\stdint.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\std\threads.h
# End Source File
# End Group
# End Group
# End Group
# End Group
# End Target
# End Project
