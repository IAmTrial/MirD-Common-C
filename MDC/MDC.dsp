# Microsoft Developer Studio Project File - Name="MDC" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102
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
!MESSAGE "MDC - Win32 Release Dll" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "MDC - Win32 Debug Dll" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
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
# ADD CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "_UNICODE" /D "UNICODE" /D "_LIB" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"Release/libMDC.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"Release\libMDCc.lib"

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
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "_UNICODE" /D "UNICODE" /D "_LIB" /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"Debug/libMDC.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"Debug\libMDCcD.lib"

!ELSEIF  "$(CFG)" == "MDC - Win32 Release Dll"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseDll"
# PROP Intermediate_Dir "ReleaseDll"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "MDC_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_UNICODE" /D "UNICODE" /D "MDC_DLLEXPORT" /FD /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"Release/MDCc.bsc"
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 libunicows.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386 /out:"ReleaseDll/MDCcD.dll"

!ELSEIF  "$(CFG)" == "MDC - Win32 Debug Dll"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugDll"
# PROP Intermediate_Dir "DebugDll"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "MDC_EXPORTS" /YX /FD /GZ  /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_UNICODE" /D "UNICODE" /D "MDC_DLLEXPORT" /FD /GZ  /c
# SUBTRACT CPP /YX
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"Debug/MDCcD.bsc"
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 libunicows.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /out:"DebugDll/MDCcD.dll" /pdbtype:sept

!ENDIF 

# Begin Target

# Name "MDC - Win32 Release"
# Name "MDC - Win32 Debug"
# Name "MDC - Win32 Release Dll"
# Name "MDC - Win32 Debug Dll"
# Begin Group "Files"

# PROP Default_Filter ""
# Begin Group "include"

# PROP Default_Filter ""
# Begin Group "mdc_h"

# PROP Default_Filter ""
# Begin Group "error_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\mdc\error\exit_on_error.h
# End Source File
# End Group
# Begin Group "malloc_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\mdc\malloc\malloc.h
# End Source File
# End Group
# Begin Group "std_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\mdc\std\assert.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\std\stdbool.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\std\stdint.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\std\threads.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\std\wchar.h
# End Source File
# End Group
# Begin Group "wchar_t_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\mdc\wchar_t\filew.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\wchar_t\wide_decoding.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\wchar_t\wide_encoding.h
# End Source File
# End Group
# End Group
# End Group
# Begin Group "src"

# PROP Default_Filter ""
# Begin Group "mdc_c"

# PROP Default_Filter ""
# Begin Group "error_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\mdc\error\exit_on_error.c
# End Source File
# End Group
# Begin Group "malloc_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\mdc\malloc\malloc.c
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
# Begin Group "wchar_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\mdc\std\wchar\wchar.c
# End Source File
# End Group
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
# End Group
# End Group
# End Group
# End Target
# End Project
