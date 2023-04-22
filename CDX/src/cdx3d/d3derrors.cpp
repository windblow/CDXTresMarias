//////////////////////////////////////////////////////////////////////////////////
// $Source: /cvsroot/cdx/cdx3.0/src/cdx3d/d3derrors.cpp,v $
// $Author: hebertjo $
//
// $Log: d3derrors.cpp,v $
// Revision 1.1.1.1  2000/04/22 16:08:37  hebertjo
// Initial checkin of v3.0 to SourceForge CVS.
//
// Revision 1.1  1999/07/11 17:56:03  MICHAELR
// Added to repository
//
//
// $Revision: 1.1.1.1 $
//////////////////////////////////////////////////////////////////////////////////
#ifdef SAVE_RCSID
static char rcsid[] = "@(#) $Id: d3derrors.cpp,v 1.1.1.1 2000/04/22 16:08:37 hebertjo Exp $";
#endif

#include "CDX3D.h"

////////////////////////////////////////////////////////////////////////
// Traces an error (DirectDraw).
////////////////////////////////////////////////////////////////////////
void D3DError(HRESULT hErr, void* hWnd, LPCSTR szFile, int iLine)
{
	char dderr[256];
	char err[1024];

	switch (hErr)
	{
		// Direct3D Retained Mode Errors
		case D3DRM_OK : sprintf(dderr, "D3DRM_OK"); break;
		case D3DRMERR_BADOBJECT : sprintf(dderr, "D3DRMERR_BADOBJECT"); break;
		case D3DRMERR_BADTYPE : sprintf(dderr, "D3DRMERR_BADTYPE"); break;
		case D3DRMERR_BADALLOC : sprintf(dderr, "D3DRMERR_BADALLOC"); break;
		case D3DRMERR_FACEUSED : sprintf(dderr, "D3DRMERR_FACEUSED"); break;
		case D3DRMERR_NOTFOUND : sprintf(dderr, "D3DRMERR_NOTFOUND"); break;
		case D3DRMERR_NOTDONEYET : sprintf(dderr, "D3DRMERR_NOTDONEYET"); break;
		case D3DRMERR_FILENOTFOUND : sprintf(dderr, "D3DRMERR_FILENOTFOUND"); break;
		case D3DRMERR_BADFILE : sprintf(dderr, "D3DRMERR_BADFILE"); break;
		case D3DRMERR_BADDEVICE : sprintf(dderr, "D3DRMERR_BADDEVICE"); break;
		case D3DRMERR_BADVALUE : sprintf(dderr, "D3DRMERR_BADVALUE"); break;
		case D3DRMERR_BADMAJORVERSION : sprintf(dderr, "D3DRMERR_BADMAJORVERSION"); break;
		case D3DRMERR_BADMINORVERSION : sprintf(dderr, "D3DRMERR_BADMINORVERSION"); break;
		case D3DRMERR_UNABLETOEXECUTE : sprintf(dderr, "D3DRMERR_UNABLETOEXECUTE"); break;
		case D3DRMERR_LIBRARYNOTFOUND : sprintf(dderr, "D3DRMERR_LIBRARYNOTFOUND"); break;
		case D3DRMERR_INVALIDLIBRARY : sprintf(dderr, "D3DRMERR_INVALIDLIBRARY"); break;
		case D3DRMERR_PENDING : sprintf(dderr, "D3DRMERR_PENDING"); break;
		case D3DRMERR_NOTENOUGHDATA : sprintf(dderr, "D3DRMERR_NOTENOUGHDATA"); break;
		case D3DRMERR_REQUESTTOOLARGE : sprintf(dderr, "D3DRMERR_REQUESTTOOLARGE"); break;
		case D3DRMERR_REQUESTTOOSMALL : sprintf(dderr, "D3DRMERR_REQUESTTOOSMALL"); break;
		case D3DRMERR_CONNECTIONLOST : sprintf(dderr, "D3DRMERR_CONNECTIONLOST"); break;
		case D3DRMERR_LOADABORTED : sprintf(dderr, "D3DRMERR_LOADABORTED"); break;
		case D3DRMERR_NOINTERNET : sprintf(dderr, "D3DRMERR_NOINTERNET"); break;
		case D3DRMERR_BADCACHEFILE : sprintf(dderr, "D3DRMERR_BADCACHEFILE"); break;
		case D3DRMERR_BOXNOTSET : sprintf(dderr, "D3DRMERR_BOXNOTSET"); break;
		case D3DRMERR_BADPMDATA : sprintf(dderr, "D3DRMERR_BADPMDATA"); break;

		default : sprintf(dderr, "Unknown Error"); break;
	}

	sprintf(err, "Direct3D Error %s\nFILE: %s\nLINE: %d", dderr, szFile, iLine);
	MessageBox((HWND)hWnd, err, "Error", MB_OK);
	PostQuitMessage(0);
}