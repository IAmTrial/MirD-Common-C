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
# ADD CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "_UNICODE" /D "UNICODE" /D "_LIB" /YX /FD /c
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
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "_DEBUG" /D "_UNICODE" /D "UNICODE" /D "_LIB" /YX /FD /GZ /c
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

SOURCE=.\src\mdc\container\map_metadata.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\container\pair.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\container\pair_metadata.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\container\vector.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\container\vector_metadata.c
# End Source File
# End Group
# Begin Group "filesystem_c"

# PROP Default_Filter ""
# Begin Group "filesystem_internal_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\mdc\filesystem\internal\file_status.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\filesystem\internal\file_status_metadata.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\filesystem\internal\filesystem_functions.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\filesystem\internal\filesystem_functions_windows.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\filesystem\internal\path.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\filesystem\internal\path_internal.h
# End Source File
# Begin Source File

SOURCE=.\src\mdc\filesystem\internal\path_metadata.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\filesystem\internal\path_windows.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\filesystem\internal\space_info.c
# End Source File
# End Group
# End Group
# Begin Group "malloc_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\mdc\malloc\malloc.c
# End Source File
# End Group
# Begin Group "object_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\mdc\object\float_object.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\object\float_object_metadata.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\object\integer_object.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\object\integer_object_metadata.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\object\string_literal_object.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\object\string_literal_object_metadata.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\object\windows_float_object.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\object\windows_float_object_metadata.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\object\windows_integer_object.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\object\windows_integer_object_metadata.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\object\windows_string_literal_object.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\object\windows_string_literal_object_metadata.c
# End Source File
# End Group
# Begin Group "object_metadata_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\mdc\object_metadata\object_metadata.c
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
# Begin Group "string_c"

# PROP Default_Filter ""
# Begin Group "basic_string_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\mdc\string\basic_string\string.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\string\basic_string\string_metadata.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\string\basic_string\wstring.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\string\basic_string\wstring_metadata.c
# End Source File
# End Group
# Begin Group "char_traits_c"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\src\mdc\string\char_traits\char_traits_char.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\string\char_traits\char_traits_wchar.c
# End Source File
# End Group
# Begin Source File

SOURCE=.\src\mdc\string\basic_string.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\string\basic_string_metadata.c
# End Source File
# Begin Source File

SOURCE=.\src\mdc\string\char_traits.c
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
# Begin Group "filesystem_h"

# PROP Default_Filter ""
# Begin Group "filesystem_internal_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\mdc\filesystem\internal\file_status.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\filesystem\internal\file_type.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\filesystem\internal\filesystem_functions.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\filesystem\internal\path.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\filesystem\internal\perms.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\filesystem\internal\space_info.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\include\mdc\filesystem\filesystem.h
# End Source File
# End Group
# Begin Group "malloc_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\mdc\malloc\malloc.h
# End Source File
# End Group
# Begin Group "object_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\mdc\object\float_object.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\object\integer_object.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\object\string_literal_object.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\object\windows_float_object.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\object\windows_integer_object.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\object\windows_string_literal_object.h
# End Source File
# End Group
# Begin Group "object_metadata_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\mdc\object_metadata\object_metadata.h
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
# Begin Group "string_h"

# PROP Default_Filter ""
# Begin Group "basic_string_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\mdc\string\basic_string\string.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\string\basic_string\tstring.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\string\basic_string\wstring.h
# End Source File
# End Group
# Begin Group "char_traits_h"

# PROP Default_Filter ""
# Begin Source File

SOURCE=.\include\mdc\string\char_traits\char_traits_char.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\string\char_traits\char_traits_tchar.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\string\char_traits\char_traits_wchar.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\include\mdc\string\basic_string.h
# End Source File
# Begin Source File

SOURCE=.\include\mdc\string\char_traits.h
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
# End Group
# End Target
# End Project
