# Microsoft Developer Studio Project File - Name="CDX" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (ALPHA) Static Library" 0x0604
# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=CDX - Win32 Release
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "cdx.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "cdx.mak" CFG="CDX - Win32 Release"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CDX - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "CDX - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "CDX - Win32 DX3 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "CDX - Win32 DX3 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "CDX - Win32 DX3 Alpha Release" (based on "Win32 (ALPHA) Static Library")
!MESSAGE "CDX - Win32 DX3 Alpha Debug" (based on "Win32 (ALPHA) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""

!IF  "$(CFG)" == "CDX - Win32 Release"

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
CPP=cl.exe
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "..\cdx3d" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\lib\vc\intel\cdx.lib"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

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
CPP=cl.exe
# ADD BASE CPP /nologo /W3 /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "..\cdx3d" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "CDX_LOG" /YX /FD /GZ /c
# SUBTRACT CPP /Fr
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\lib\vc\intel\cdxd.lib"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "CDX___Win32_DX3_Debug"
# PROP BASE Intermediate_Dir "CDX___Win32_DX3_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugDX3"
# PROP Intermediate_Dir "DebugDX3"
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /W3 /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /GX /ZI /Od /I "..\cdx3d" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NTDX3" /D "CDX_LOG" /YX /FD /GZ /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\vc\intel\cdxd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\vc\intel\cdxdx3d.lib"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "CDX___Win32_DX3_Release"
# PROP BASE Intermediate_Dir "CDX___Win32_DX3_Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseDX3"
# PROP Intermediate_Dir "ReleaseDX3"
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "..\cdx3d" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "NTDX3" /YX /FD /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\vc\intel\cdx.lib"
# ADD LIB32 /nologo /out:"..\..\lib\vc\intel\cdxdx3.lib"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "CDX___Win32_DX3_Alpha_Release"
# PROP BASE Intermediate_Dir "CDX___Win32_DX3_Alpha_Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseADX3"
# PROP Intermediate_Dir "ReleaseADX3"
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /Gt0 /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "NTDX3" /YX /FD /c
# ADD CPP /nologo /Gt0 /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "NTDX3" /YX /FD /c
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\vc\intel\cdx.lib"
# ADD LIB32 /nologo /out:"..\..\lib\vc\alpha\cdxdx3.lib"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "CDX___Win32_DX3_Alpha_Debug"
# PROP BASE Intermediate_Dir "CDX___Win32_DX3_Alpha_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugADX3"
# PROP Intermediate_Dir "DebugADX3"
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /Gt0 /W3 /GX /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "NTDX3" /YX /FD /ZI /GZ /c
# ADD CPP /nologo /Gt0 /W3 /GX /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "NTDX3" /D "CDX_LOG" /YX /FD /ZI /c
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\vc\intel\cdxd.lib"
# ADD LIB32 /nologo /out:"..\..\lib\vc\alpha\cdxdx3d.lib"

!ENDIF 

# Begin Target

# Name "CDX - Win32 Release"
# Name "CDX - Win32 Debug"
# Name "CDX - Win32 DX3 Debug"
# Name "CDX - Win32 DX3 Release"
# Name "CDX - Win32 DX3 Alpha Release"
# Name "CDX - Win32 DX3 Alpha Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\cdxfile.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdximage.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdximagebase.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdximagebmp.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdximagejpg.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdximagepcx.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdximagepsd.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdximagetga.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdxinput.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdxiso.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdxlayer.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdxlink.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdxlog.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdxmap.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdxmapcell.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdxmidi.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdxmusic.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdxmusiccd.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdxresource.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdxscreen.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdxsound.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdxsoundbuffer.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdxsprite.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdxspritelist.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdxsurface.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdxtile.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\ddutils.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\dxerrors.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\cdx.h
# End Source File
# Begin Source File

SOURCE=.\cdxclist.h
# End Source File
# Begin Source File

SOURCE=.\cdxfile.h
# End Source File
# Begin Source File

SOURCE=.\cdximage.h
# End Source File
# Begin Source File

SOURCE=.\cdximagebase.h
# End Source File
# Begin Source File

SOURCE=.\cdximagebmp.h
# End Source File
# Begin Source File

SOURCE=.\cdximagejpg.h
# End Source File
# Begin Source File

SOURCE=.\cdximagepcx.h
# End Source File
# Begin Source File

SOURCE=.\cdximagepsd.h
# End Source File
# Begin Source File

SOURCE=.\cdximagetga.h
# End Source File
# Begin Source File

SOURCE=.\cdxinput.h
# End Source File
# Begin Source File

SOURCE=.\cdxlayer.h
# End Source File
# Begin Source File

SOURCE=.\cdxlink.h
# End Source File
# Begin Source File

SOURCE=.\cdxlog.h
# End Source File
# Begin Source File

SOURCE=.\cdxmap.h
# End Source File
# Begin Source File

SOURCE=.\cdxmidi.h
# End Source File
# Begin Source File

SOURCE=.\cdxmusic.h
# End Source File
# Begin Source File

SOURCE=.\cdxresource.h
# End Source File
# Begin Source File

SOURCE=.\cdxscreen.h
# End Source File
# Begin Source File

SOURCE=.\cdxsound.h
# End Source File
# Begin Source File

SOURCE=.\cdxsprite.h
# End Source File
# Begin Source File

SOURCE=.\cdxstructs.h
# End Source File
# Begin Source File

SOURCE=.\cdxsurface.h
# End Source File
# Begin Source File

SOURCE=.\cdxtile.h
# End Source File
# Begin Source File

SOURCE=.\cdxtypes.h
# End Source File
# End Group
# Begin Source File

SOURCE=.\cdxtemplate.cpp

!IF  "$(CFG)" == "CDX - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdxtemplate.h

!IF  "$(CFG)" == "CDX - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "CDX - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Debug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "CDX - Win32 DX3 Alpha Debug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Target
# End Project
