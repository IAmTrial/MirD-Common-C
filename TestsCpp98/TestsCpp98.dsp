# Microsoft Developer Studio Project File - Name="TestsCpp98" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=TestsCpp98 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "TestsCpp98.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "TestsCpp98.mak" CFG="TestsCpp98 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "TestsCpp98 - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "TestsCpp98 - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "TestsCpp98 - Win32 Release"

# PROP BASE Use_MFC 0
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
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 libunicows.lib MDCc.lib MDCcpp98.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "TestsCpp98 - Win32 Debug"

# PROP BASE Use_MFC 0
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
# ADD BASE CPP /nologo /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_MBCS" /YX /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 libunicows.lib MDCcD.lib MDCcpp98D.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "TestsCpp98 - Win32 Release"
# Name "TestsCpp98 - Win32 Debug"
# Begin Group "Files"

# PROP Default_Filter ""
# Begin Group "tests"

# PROP Default_Filter ""
# Begin Group "mdc"

# PROP Default_Filter ""
# Begin Group "error"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\test\mdc\error\exit_on_error_tests.cpp
# End Source File
# Begin Source File

SOURCE=.\test\mdc\error\exit_on_error_tests.hpp
# End Source File
# End Group
# Begin Group "std"

# PROP Default_Filter ""
# Begin Group "std_example_funcs"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\test\mdc\std\std_example_funcs\std_increment.cpp
# End Source File
# Begin Source File

SOURCE=.\test\mdc\std\std_example_funcs\std_increment.hpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\test\mdc\std\mutex_tests.cpp
# End Source File
# Begin Source File

SOURCE=.\test\mdc\std\mutex_tests.hpp
# End Source File
# Begin Source File

SOURCE=.\test\mdc\std\thread_tests.cpp
# End Source File
# Begin Source File

SOURCE=.\test\mdc\std\thread_tests.hpp
# End Source File
# End Group
# Begin Group "wchar_t"

# PROP Default_Filter ""
# Begin Group "wide_example_text"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\test\mdc\wchar_t\wide_example_text\wide_example_text.cpp
# End Source File
# Begin Source File

SOURCE=.\test\mdc\wchar_t\wide_example_text\wide_example_text.hpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\test\mdc\wchar_t\wide_decoding_tests.cpp
# End Source File
# Begin Source File

SOURCE=.\test\mdc\wchar_t\wide_decoding_tests.hpp
# End Source File
# Begin Source File

SOURCE=.\test\mdc\wchar_t\wide_encoding_tests.cpp
# End Source File
# Begin Source File

SOURCE=.\test\mdc\wchar_t\wide_encoding_tests.hpp
# End Source File
# End Group
# Begin Source File

SOURCE=.\test\mdc\error_tests.cpp
# End Source File
# Begin Source File

SOURCE=.\test\mdc\error_tests.hpp
# End Source File
# Begin Source File

SOURCE=.\test\mdc\main.cpp
# End Source File
# Begin Source File

SOURCE=.\test\mdc\std_tests.cpp
# End Source File
# Begin Source File

SOURCE=.\test\mdc\std_tests.hpp
# End Source File
# Begin Source File

SOURCE=.\test\mdc\wchar_t_tests.cpp
# End Source File
# Begin Source File

SOURCE=.\test\mdc\wchar_t_tests.hpp
# End Source File
# End Group
# End Group
# End Group
# End Target
# End Project
