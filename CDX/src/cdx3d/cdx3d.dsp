# Microsoft Developer Studio Project File - Name="CDX3D" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (ALPHA) Static Library" 0x0604
# TARGTYPE "Win32 (x86) Static Library" 0x0104

CFG=CDX3D - Win32 DX3 Alpha Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "cdx3d.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "cdx3d.mak" CFG="CDX3D - Win32 DX3 Alpha Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "CDX3D - Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "CDX3D - Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "CDX3D - Win32 DX3 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE "CDX3D - Win32 DX3 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "CDX3D - Win32 DX3 Alpha Debug" (based on "Win32 (ALPHA) Static Library")
!MESSAGE "CDX3D - Win32 DX3 Alpha Release" (based on "Win32 (ALPHA) Static Library")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""

!IF  "$(CFG)" == "CDX3D - Win32 Release"

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
# ADD CPP /nologo /W3 /GX /O2 /I "..\cdx" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\lib\vc\intel\cdx3d.lib"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 Debug"

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
# ADD CPP /nologo /W3 /Gm /GX /ZI /Od /I "..\cdx" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "CDX_LOG" /YX /FD /GZ /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo
# ADD LIB32 /nologo /out:"..\..\lib\vc\intel\cdx3dd.lib"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "CDX3D___Win32_DX3_Debug"
# PROP BASE Intermediate_Dir "CDX3D___Win32_DX3_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugDX3"
# PROP Intermediate_Dir "DebugDX3"
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /W3 /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /YX /FD /GZ /c
# ADD CPP /nologo /W3 /GX /ZI /Od /I "..\cdx" /D "WIN32" /D "_DEBUG" /D "_MBCS" /D "_LIB" /D "NTDX3" /D "CDX_LOG" /YX /FD /GZ /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\vc\intel\cdx3d.lib"
# ADD LIB32 /nologo /out:"..\..\lib\vc\intel\cdx3ddx3d.lib"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "CDX3D___Win32_DX3_Release"
# PROP BASE Intermediate_Dir "CDX3D___Win32_DX3_Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseDX3"
# PROP Intermediate_Dir "ReleaseDX3"
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /YX /FD /c
# ADD CPP /nologo /W3 /GX /O2 /I "..\cdx" /D "WIN32" /D "NDEBUG" /D "_MBCS" /D "_LIB" /D "NTDX3" /YX /FD /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\vc\intel\cdx3d.lib"
# ADD LIB32 /nologo /out:"..\..\lib\vc\intel\cdx3ddx3.lib"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Alpha Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "CDX3D___Win32_DX3_Alpha_Debug"
# PROP BASE Intermediate_Dir "CDX3D___Win32_DX3_Alpha_Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugADX3"
# PROP Intermediate_Dir "DebugADX3"
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /Gt0 /W3 /GX /Od /I "..\cdx" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "NTDX3" /D "CDX_LOG" /YX /FD /ZI /GZ /c
# ADD CPP /nologo /Gt0 /W3 /GX /Od /I "..\cdx" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "NTDX3" /D "CDX_LOG" /YX /FD /ZI /GZ /c
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\vc\intel\cdx3ddx3d.lib"
# ADD LIB32 /nologo /out:"..\..\lib\vc\alpha\cdx3ddx3d.lib"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Alpha Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "CDX3D___Win32_DX3_Alpha_Release"
# PROP BASE Intermediate_Dir "CDX3D___Win32_DX3_Alpha_Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseADX3"
# PROP Intermediate_Dir "ReleaseADX3"
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /Gt0 /W3 /GX /O2 /I "..\cdx" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "NTDX3" /YX /FD /c
# ADD CPP /nologo /Gt0 /W3 /GX /O2 /I "..\cdx" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "NTDX3" /YX /FD /c
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LIB32=link.exe -lib
# ADD BASE LIB32 /nologo /out:"..\..\lib\vc\intel\cdx3ddx3.lib"
# ADD LIB32 /nologo /out:"..\..\lib\vc\alpha\cdx3ddx3.lib"

!ENDIF 

# Begin Target

# Name "CDX3D - Win32 Release"
# Name "CDX3D - Win32 Debug"
# Name "CDX3D - Win32 DX3 Debug"
# Name "CDX3D - Win32 DX3 Release"
# Name "CDX3D - Win32 DX3 Alpha Debug"
# Name "CDX3D - Win32 DX3 Alpha Release"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\camera.cpp

!IF  "$(CFG)" == "CDX3D - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Alpha Debug"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\cdx\cdxdebug.cpp

!IF  "$(CFG)" == "CDX3D - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Alpha Debug"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\d3derrors.cpp

!IF  "$(CFG)" == "CDX3D - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Alpha Debug"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\engine.cpp

!IF  "$(CFG)" == "CDX3D - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Alpha Debug"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\frame.cpp

!IF  "$(CFG)" == "CDX3D - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Alpha Debug"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\light.cpp

!IF  "$(CFG)" == "CDX3D - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Alpha Debug"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\scene.cpp

!IF  "$(CFG)" == "CDX3D - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Alpha Debug"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Alpha Release"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\shape.cpp

!IF  "$(CFG)" == "CDX3D - Win32 Release"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 Debug"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Alpha Debug"

!ELSEIF  "$(CFG)" == "CDX3D - Win32 DX3 Alpha Release"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\cdx3d.h
# End Source File
# Begin Source File

SOURCE=.\cdx3dcamera.h
# End Source File
# Begin Source File

SOURCE=.\cdx3dengine.h
# End Source File
# Begin Source File

SOURCE=.\cdx3dframe.h
# End Source File
# Begin Source File

SOURCE=.\cdx3dlight.h
# End Source File
# Begin Source File

SOURCE=.\cdx3dscene.h
# End Source File
# Begin Source File

SOURCE=.\cdx3dshape.h
# End Source File
# Begin Source File

SOURCE=..\cdx\cdxdebug.h
# End Source File
# End Group
# End Target
# End Project
