//////////////////////////////////////////////////////////////////////////////////
// $Source: /cvsroot/cdx/cdx3.0/src/cdxdll/cdxdllmain.cpp,v $
// $Author: hebertjo $
//
// $Log: cdxdllmain.cpp,v $
// Revision 1.1.1.1  2000/04/22 16:08:23  hebertjo
// Initial checkin of v3.0 to SourceForge CVS.
//
// Revision 1.1  1999/08/29 22:24:02  MICHAELR
// added to repository
//
//
//
// $Revision: 1.1.1.1 $
//////////////////////////////////////////////////////////////////////////////////
#ifdef SAVE_RCSID
static char rcsid = "@(#) $Id: cdxdllmain.cpp,v 1.1.1.1 2000/04/22 16:08:23 hebertjo Exp $";
#endif

#define WIN32_EXTRA_LEAN
#include <windows.h>

HINSTANCE hinstCDXDLL = NULL;

BOOL WINAPI DllMain (HINSTANCE hinstDll, DWORD fdwReason, LPVOID lpvReserved) 
{
	hinstCDXDLL = hinstDll;
	return TRUE;
}