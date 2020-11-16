# Microsoft Developer Studio Project File - Name="Tests" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Console Application" 0x0103

CFG=Tests - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "Tests.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "Tests.mak" CFG="Tests - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Tests - Win32 Release" (based on "Win32 (x86) Console Application")
!MESSAGE "Tests - Win32 Debug" (based on "Win32 (x86) Console Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Tests - Win32 Release"

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
# ADD CPP /nologo /MD /W3 /GX /O2 /D "MDC_ACKNOWLEDGE_LIBUNICOWS" /D "NDEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /YX /FD /c
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386
# ADD LINK32 libunicows.lib MDCc.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /machine:I386

!ELSEIF  "$(CFG)" == "Tests - Win32 Debug"

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
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "MDC_ACKNOWLEDGE_LIBUNICOWS" /D "_DEBUG" /D "_CONSOLE" /D "_UNICODE" /D "UNICODE" /YX /FD /GZ /c
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept
# ADD LINK32 libunicows.lib MDCcD.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /subsystem:console /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "Tests - Win32 Release"
# Name "Tests - Win32 Debug"
# Begin Group "Files"

# PROP Default_Filter ""
# Begin Group "tests"

# PROP Default_Filter ""
# Begin Group "mdc"

# PROP Default_Filter ""
# Begin Group "container"

# PROP Default_Filter ""
# Begin Group "map_string_int"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\tests\mdc\container\map_string_int\map_string_int.c
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\container\map_string_int\map_string_int.h
# End Source File
# End Group
# Begin Group "pair_string_int"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\tests\mdc\container\pair_string_int\pair_string_int.c
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\container\pair_string_int\pair_string_int.h
# End Source File
# End Group
# Begin Group "vector_int"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\tests\mdc\container\vector_int\vector_int.c
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\container\vector_int\vector_int.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\tests\mdc\container\map_tests.c
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\container\map_tests.h
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\container\pair_tests.c
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\container\pair_tests.h
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\container\vector_tests.c
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\container\vector_tests.h
# End Source File
# End Group
# Begin Group "filesystem"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\tests\mdc\filesystem\path_windows_tests.c
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\filesystem\path_windows_tests.h
# End Source File
# End Group
# Begin Group "std"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\tests\mdc\std\assert_tests.c
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\std\assert_tests.h
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\std\stdbool_tests.c
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\std\stdbool_tests.h
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\std\stdint_tests.c
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\std\stdint_tests.h
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\std\threads_tests.c
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\std\threads_tests.h
# End Source File
# End Group
# Begin Group "string"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\tests\mdc\string\basic_string_tests.c
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\string\basic_string_tests.h
# End Source File
# End Group
# Begin Group "wchar_t"

# PROP Default_Filter ""
# Begin Group "example_text"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\tests\mdc\wchar_t\example_text\example_text.c
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\wchar_t\example_text\example_text.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\tests\mdc\wchar_t\filew_tests.c
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\wchar_t\filew_tests.h
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\wchar_t\wide_decoding_tests.c
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\wchar_t\wide_decoding_tests.h
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\wchar_t\wide_encoding_tests.c
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\wchar_t\wide_encoding_tests.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\tests\mdc\container_tests.c
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\container_tests.h
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\filesystem_tests.c
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\filesystem_tests.h
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\main.c
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\std_tests.c
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\std_tests.h
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\string_tests.c
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\string_tests.h
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\wchar_t_tests.c
# End Source File
# Begin Source File

SOURCE=.\tests\mdc\wchar_t_tests.h
# End Source File
# End Group
# End Group
# End Group
# End Target
# End Project
