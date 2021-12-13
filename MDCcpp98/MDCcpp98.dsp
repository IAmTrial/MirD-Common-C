# Microsoft Developer Studio Project File - Name="MDCcpp98" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102
# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=MDCcpp98 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "MDCcpp98.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "MDCcpp98.mak" CFG="MDCcpp98 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "MDCcpp98 - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "MDCcpp98 - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "MDCcpp98 - Win32 Release Dll" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "MDCcpp98 - Win32 Debug Dll" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""

!IF  "$(CFG)" == "MDCcpp98 - Win32 Release"

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
MTL=midl.exe
CPP=cl.exe
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../MDC/include" /D "WIN32" /D "NDEBUG" /D "_LIB" /D "_UNICODE" /D "UNICODE" /YX /FD /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"Release/libMDCcpp98.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"Release\libMDCcpp98.lib"

!ELSEIF  "$(CFG)" == "MDCcpp98 - Win32 Debug"

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
MTL=midl.exe
CPP=cl.exe
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../MDC/include" /D "WIN32" /D "_DEBUG" /D "_LIB" /D "_UNICODE" /D "UNICODE" /YX /FD /GZ /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"Debug/libMDCcpp98.bsc"
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"Debug\libMDCcpp98D.lib"

!ELSEIF  "$(CFG)" == "MDCcpp98 - Win32 Release Dll"

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
CPP=cl.exe
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "DLLMDCCPP98_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /I "../MDC/include" /D "WIN32" /D "NDEBUG" /D "_UNICODE" /D "UNICODE" /D "MDC_DLLIMPORT" /D "MDC_CPP98_DLLEXPORT" /FD /c
# SUBTRACT CPP /YX
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"Release/MDCcpp98.bsc"
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 MDCc.lib libunicows.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386 /libpath:"../MDC/ReleaseDll"

!ELSEIF  "$(CFG)" == "MDCcpp98 - Win32 Debug Dll"

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
CPP=cl.exe
# ADD BASE CPP /nologo /MTd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "DLLMDCCPP98_EXPORTS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /I "../MDC/include" /D "WIN32" /D "_DEBUG" /D "_UNICODE" /D "UNICODE" /D "MDC_DLLIMPORT" /D "MDC_CPP98_DLLEXPORT" /FD /GZ /c
# SUBTRACT CPP /YX
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo /o"Debug/MDCcpp98D.bsc"
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 MDCcD.lib libunicows.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /out:"DebugDll/MDCcpp98D.dll" /pdbtype:sept /libpath:"../MDC/DebugDll"

!ENDIF 

# Begin Target

# Name "MDCcpp98 - Win32 Release"
# Name "MDCcpp98 - Win32 Debug"
# Name "MDCcpp98 - Win32 Release Dll"
# Name "MDCcpp98 - Win32 Debug Dll"
# Begin Group "Files"

# PROP Default_Filter ""
# Begin Group "include"

# PROP Default_Filter ""
# Begin Group "mdc_hpp"

# PROP Default_Filter ""
# Begin Group "error_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\mdc\error\exit_on_error.hpp
# End Source File
# End Group
# Begin Group "std_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\mdc\std\condition_variable.hpp
# End Source File
# Begin Source File

SOURCE=.\include\mdc\std\mutex.hpp
# End Source File
# Begin Source File

SOURCE=.\include\mdc\std\threads.hpp
# End Source File
# End Group
# Begin Group "wchar_t_hpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\mdc\wchar_t\wide_decoding.hpp
# End Source File
# Begin Source File

SOURCE=.\include\mdc\wchar_t\wide_encoding.hpp
# End Source File
# End Group
# End Group
# End Group
# Begin Group "src"

# PROP Default_Filter ""
# Begin Group "mdc_cpp"

# PROP Default_Filter ""
# Begin Group "error_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\mdc\error\exit_on_error.cpp
# End Source File
# End Group
# Begin Group "std_cpp"

# PROP Default_Filter ""
# Begin Group "condition_variable_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\mdc\std\condition_variable\condition_variable.cpp
# End Source File
# Begin Source File

SOURCE=.\src\mdc\std\condition_variable\condition_variable_any.cpp
# End Source File
# End Group
# Begin Group "mutex_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\mdc\std\mutex\call_once.cpp
# End Source File
# Begin Source File

SOURCE=.\src\mdc\std\mutex\mutex.cpp
# End Source File
# Begin Source File

SOURCE=.\src\mdc\std\mutex\recursive_mutex.cpp
# End Source File
# End Group
# Begin Group "threads_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\mdc\std\threads\threads.cpp
# End Source File
# End Group
# End Group
# Begin Group "wchar_t_cpp"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\mdc\wchar_t\wide_decoding.cpp
# End Source File
# Begin Source File

SOURCE=.\src\mdc\wchar_t\wide_encoding.cpp
# End Source File
# End Group
# End Group
# End Group
# End Group
# End Target
# End Project
