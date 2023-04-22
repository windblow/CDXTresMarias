# Microsoft Developer Studio Project File - Name="cdxdll" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 5.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Dynamic-Link Library" 0x0102
# TARGTYPE "Win32 (ALPHA) Dynamic-Link Library" 0x0602

CFG=cdxdll - Win32 DX3 Alpha Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "cdxdll.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "cdxdll.mak" CFG="cdxdll - Win32 DX3 Alpha Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "cdxdll - Win32 Release" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "cdxdll - Win32 Debug" (based on "Win32 (x86) Dynamic-Link Library")
!MESSAGE "cdxdll - Win32 DX3 Release" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "cdxdll - Win32 DX3 Debug" (based on\
 "Win32 (x86) Dynamic-Link Library")
!MESSAGE "cdxdll - Win32 DX3 Alpha Release" (based on\
 "Win32 (ALPHA) Dynamic-Link Library")
!MESSAGE "cdxdll - Win32 DX3 Alpha Debug" (based on\
 "Win32 (ALPHA) Dynamic-Link Library")
!MESSAGE 

# Begin Project
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""

!IF  "$(CFG)" == "cdxdll - Win32 Release"

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
CPP=cl.exe
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "CDXDLL_EXPORTS" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "..\cdx3d" /I "..\cdx" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_CDX_BUILDDLL" /YX /FD /c
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /machine:I386
# ADD LINK32 ddraw.lib dxguid.lib dplay.lib dsound.lib dinput.lib dplayx.lib winmm.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib ole32.lib /nologo /dll /machine:I386 /out:"..\..\bin\vc\intel\cdx.dll" /implib:"..\..\lib\vc\intel\cdxdll.lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

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
CPP=cl.exe
# ADD BASE CPP /nologo /MTd /W3 /GX /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "CDXDLL_EXPORTS" /YX /FD /ZI /GZ /c
# ADD CPP /nologo /MTd /W3 /Gm /GX /Zi /Od /I "..\cdx3d" /I "..\cdx" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_CDX_BUILDDLL" /D "CDX_LOG" /YX /FD /ZI /GZ /c
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib odbc32.lib odbccp32.lib /nologo /dll /debug /machine:I386 /pdbtype:sept
# ADD LINK32 ddraw.lib dxguid.lib dplay.lib dsound.lib dinput.lib dplayx.lib winmm.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib ole32.lib /nologo /dll /debug /machine:I386 /out:"..\..\bin\vc\intel\cdxd.dll" /implib:"..\..\lib\vc\intel\cdxdlld.lib" /pdbtype:sept
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "cdxdll___Win32_DX3_Release"
# PROP BASE Intermediate_Dir "cdxdll___Win32_DX3_Release"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseDX3"
# PROP Intermediate_Dir "ReleaseDX3"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /MT /W3 /GX /O2 /I "..\cdx3d" /I "..\cdx" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_CDX_BUILDDLL" /YX /FD /c
# ADD CPP /nologo /MT /W3 /GX /O2 /I "..\cdx3d" /I "..\cdx" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_CDX_BUILDDLL" /D "NTDX3" /YX /FD /c
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 ddraw.lib dxguid.lib dplay.lib dsound.lib dinput.lib dplayx.lib winmm.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib ole32.lib /nologo /dll /machine:I386 /out:"..\..\bin\vc\intel\cdx.dll" /implib:"..\..\lib\vc\intel\cdxdll.lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 ddraw.lib dxguid.lib dplay.lib dsound.lib dinput.lib dplayx.lib winmm.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib ole32.lib /nologo /dll /machine:I386 /out:"..\..\bin\vc\intel\cdxdx3.dll" /implib:"..\..\lib\vc\intel\cdxdlldx3.lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "cdxdll___Win32_DX3_Debug"
# PROP BASE Intermediate_Dir "cdxdll___Win32_DX3_Debug"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugDX3"
# PROP Intermediate_Dir "DebugDX3"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
CPP=cl.exe
# ADD BASE CPP /nologo /MTd /W3 /GX /Od /I "..\cdx3d" /I "..\cdx" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_CDX_BUILDDLL" /D "CDX_LOG" /YX /FD /ZI /GZ /c
# ADD CPP /nologo /MTd /W3 /GX /Od /I "..\cdx3d" /I "..\cdx" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_CDX_BUILDDLL" /D "CDX_LOG" /D "NTDX3" /YX /FD /ZI /GZ /c
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 ddraw.lib dxguid.lib dplay.lib dsound.lib dinput.lib dplayx.lib winmm.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib ole32.lib /nologo /dll /debug /machine:I386 /out:"..\..\bin\vc\intel\cdxd.dll" /implib:"..\..\lib\vc\intel\cdxdlld.lib" /pdbtype:sept
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 ddraw.lib dxguid.lib dplay.lib dsound.lib dinput.lib dplayx.lib winmm.lib kernel32.lib user32.lib gdi32.lib comdlg32.lib advapi32.lib ole32.lib /nologo /dll /debug /machine:I386 /out:"..\..\bin\vc\intel\cdxdx3d.dll" /implib:"..\..\lib\vc\intel\cdxdlldx3d.lib" /pdbtype:sept
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "cdxdll___Win32_DX3_Alpha_Release0"
# PROP BASE Intermediate_Dir "cdxdll___Win32_DX3_Alpha_Release0"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "ReleaseADX3"
# PROP Intermediate_Dir "ReleaseADX3"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
MTL=midl.exe
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /mktyplib203 /win32
CPP=cl.exe
# ADD BASE CPP /nologo /MT /Gt0 /W3 /GX /O2 /I "..\cdx3d" /I "..\cdx" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "NTDX3" /YX /FD /c
# ADD CPP /nologo /MT /Gt0 /W3 /GX /O2 /I "..\cdx3d" /I "..\cdx" /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_CDX_BUILDDLL" /D "NTDX3" /YX /FD /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "NDEBUG"
# ADD RSC /l 0x409 /d "NDEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 ddraw.lib dxguid.lib dplay.lib dsound.lib dinput.lib dplayx.lib winmm.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /machine:ALPHA /out:"..\..\bin\vc\intel\cdxdx3.dll" /implib:"..\..\lib\vc\intel\cdxdll.lib"
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 ddraw.lib dxguid.lib dplay.lib dsound.lib dinput.lib dplayx.lib winmm.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /machine:ALPHA /out:"..\..\bin\vc\alpha\cdxdx3.dll" /implib:"..\..\lib\vc\alpha\cdxdlldx3.lib"
# SUBTRACT LINK32 /pdb:none

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "cdxdll___Win32_DX3_Alpha_Debug"
# PROP BASE Intermediate_Dir "cdxdll___Win32_DX3_Alpha_Debug"
# PROP BASE Ignore_Export_Lib 0
# PROP BASE Target_Dir ""
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "DebugADX3"
# PROP Intermediate_Dir "DebugADX3"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
MTL=midl.exe
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /mktyplib203 /win32
CPP=cl.exe
# ADD BASE CPP /nologo /Gt0 /W3 /GX /Od /I "..\cdx3d" /I "..\cdx" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "NTDX3" /YX /FD /MTd /ZI /GZ /c
# ADD CPP /nologo /Gt0 /W3 /GX /Od /I "..\cdx3d" /I "..\cdx" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_MBCS" /D "_USRDLL" /D "_CDX_BUILDDLL" /D "CDX_LOG" /D "NTDX3" /YX /FD /MTd /ZI /c
RSC=rc.exe
# ADD BASE RSC /l 0x409 /d "_DEBUG"
# ADD RSC /l 0x409 /d "_DEBUG"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 ddraw.lib dxguid.lib dplay.lib dsound.lib dinput.lib dplayx.lib winmm.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /debug /machine:ALPHA /out:"..\..\bin\vc\intel\cdxdx3d.dll" /implib:"..\..\lib\vc\intel\cdxdlld.lib" /pdbtype:sept
# SUBTRACT BASE LINK32 /pdb:none
# ADD LINK32 ddraw.lib dxguid.lib dplay.lib dsound.lib dinput.lib dplayx.lib winmm.lib kernel32.lib user32.lib gdi32.lib winspool.lib comdlg32.lib advapi32.lib shell32.lib ole32.lib oleaut32.lib uuid.lib /nologo /subsystem:windows /dll /debug /machine:ALPHA /out:"..\..\bin\vc\alpha\cdxdx3d.dll" /implib:"..\..\lib\vc\alpha\cdxdlldx3d.lib" /pdbtype:sept
# SUBTRACT LINK32 /pdb:none

!ENDIF 

# Begin Target

# Name "cdxdll - Win32 Release"
# Name "cdxdll - Win32 Debug"
# Name "cdxdll - Win32 DX3 Release"
# Name "cdxdll - Win32 DX3 Debug"
# Name "cdxdll - Win32 DX3 Alpha Release"
# Name "cdxdll - Win32 DX3 Alpha Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=..\cdx\cdxdebug.cpp

!IF  "$(CFG)" == "cdxdll - Win32 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=.\cdxdllmain.cpp

!IF  "$(CFG)" == "cdxdll - Win32 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\cdx\cdxfile.cpp

!IF  "$(CFG)" == "cdxdll - Win32 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\cdx\cdxinput.cpp

!IF  "$(CFG)" == "cdxdll - Win32 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\cdx\cdxiso.cpp

!IF  "$(CFG)" == "cdxdll - Win32 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\cdx\cdxlayer.cpp

!IF  "$(CFG)" == "cdxdll - Win32 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\cdx\cdxlink.cpp

!IF  "$(CFG)" == "cdxdll - Win32 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\cdx\cdxlog.cpp

!IF  "$(CFG)" == "cdxdll - Win32 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\cdx\cdxmap.cpp

!IF  "$(CFG)" == "cdxdll - Win32 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\cdx\cdxmapcell.cpp

!IF  "$(CFG)" == "cdxdll - Win32 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\cdx\cdxmusic.cpp

!IF  "$(CFG)" == "cdxdll - Win32 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\cdx\cdxmusiccd.cpp

!IF  "$(CFG)" == "cdxdll - Win32 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\cdx\cdxpacker.cpp

!IF  "$(CFG)" == "cdxdll - Win32 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\cdx\cdxresource.cpp

!IF  "$(CFG)" == "cdxdll - Win32 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\cdx\cdxscreen.cpp

!IF  "$(CFG)" == "cdxdll - Win32 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\cdx\cdxsound.cpp

!IF  "$(CFG)" == "cdxdll - Win32 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\cdx\cdxsoundbuffer.cpp

!IF  "$(CFG)" == "cdxdll - Win32 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\cdx\cdxsprite.cpp

!IF  "$(CFG)" == "cdxdll - Win32 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\cdx\cdxspritelist.cpp

!IF  "$(CFG)" == "cdxdll - Win32 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\cdx\cdxsurface.cpp

!IF  "$(CFG)" == "cdxdll - Win32 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\cdx\cdxtile.cpp

!IF  "$(CFG)" == "cdxdll - Win32 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\cdx\ddutils.cpp

!IF  "$(CFG)" == "cdxdll - Win32 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\cdx\dxerrors.cpp

!IF  "$(CFG)" == "cdxdll - Win32 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

!ENDIF 

# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=..\cdx\cdx.h
# End Source File
# Begin Source File

SOURCE=..\cdx\cdxdebug.h
# End Source File
# Begin Source File

SOURCE=..\cdx\cdxfile.h
# End Source File
# Begin Source File

SOURCE=..\cdx\cdxinput.h
# End Source File
# Begin Source File

SOURCE=..\cdx\cdxlayer.h
# End Source File
# Begin Source File

SOURCE=..\cdx\cdxlink.h
# End Source File
# Begin Source File

SOURCE=..\cdx\cdxlog.h
# End Source File
# Begin Source File

SOURCE=..\cdx\cdxmap.h
# End Source File
# Begin Source File

SOURCE=..\cdx\cdxmusic.h
# End Source File
# Begin Source File

SOURCE=..\cdx\cdxpacker.h
# End Source File
# Begin Source File

SOURCE=..\cdx\cdxresource.h
# End Source File
# Begin Source File

SOURCE=..\cdx\cdxscreen.h
# End Source File
# Begin Source File

SOURCE=..\cdx\cdxsound.h
# End Source File
# Begin Source File

SOURCE=..\cdx\cdxsprite.h
# End Source File
# Begin Source File

SOURCE=..\cdx\cdxsurface.h
# End Source File
# Begin Source File

SOURCE=..\cdx\cdxtile.h
# End Source File
# Begin Source File

SOURCE=..\cdx\cdxtypes.h
# End Source File
# End Group
# Begin Source File

SOURCE=..\cdx\cdxtemplate.cpp

!IF  "$(CFG)" == "cdxdll - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# Begin Source File

SOURCE=..\cdx\cdxtemplate.h

!IF  "$(CFG)" == "cdxdll - Win32 Release"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cdxdll - Win32 Debug"

# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Debug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Release"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ELSEIF  "$(CFG)" == "cdxdll - Win32 DX3 Alpha Debug"

# PROP BASE Exclude_From_Build 1
# PROP Exclude_From_Build 1

!ENDIF 

# End Source File
# End Target
# End Project
