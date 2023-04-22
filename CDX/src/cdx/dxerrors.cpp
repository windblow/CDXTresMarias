//////////////////////////////////////////////////////////////////////////////////
// $Source: /cvsroot/cdx/cdx3.0/src/cdx/dxerrors.cpp,v $
// $Author: hebertjo $
//
// $Log: dxerrors.cpp,v $
// Revision 1.1.1.1  2000/04/22 16:13:58  hebertjo
// Initial checkin of v3.0 to SourceForge CVS.
//
// Revision 2.10  2000/01/28 16:30:43  MICHAELR
// Removed dependency on CDX3D.H
// Added include for d3drmwin.h for D3D errors
//
// Revision 2.9  2000/01/14 00:02:15  jhebert
// First checkin for v3.0
// Minor change to comply with other changes
//
//
//
// $Revision: 1.1.1.1 $
//////////////////////////////////////////////////////////////////////////////////
#ifdef SAVE_RCSID
static TCHAR rcsid[] = _T("@(#) $Id: dxerrors.cpp,v 1.1.1.1 2000/04/22 16:13:58 hebertjo Exp $");
#endif

#include "CDX.h"
#include <d3d.h>
#include "cdxscreen.h"
#include <stdarg.h>

////////////////////////////////////////////////////////////////////////
// Displays an error message box and quits the application
////////////////////////////////////////////////////////////////////////
void CDXError( CDXScreen *Screen, TCHAR *str, ... )
{
    TCHAR cp[1024] = { '\0' };
    va_list ap;

    va_start(ap, str);
    _vstprintf(cp, _tcslen(cp), str, ap);
    va_end(ap);

    if(Screen != NULL)
    {
        Screen->GetDD()->FlipToGDISurface();
        MessageBox((HWND)Screen->GetWindowHandle(), cp, _T("Error"), MB_OK | MB_ICONERROR);
    }
    else
    {
        MessageBox(NULL, cp, _T("Error"), MB_OK | MB_ICONERROR);
    }
	PostQuitMessage(0);
}


////////////////////////////////////////////////////////////////////////
// Traces an error (DirectDraw).
////////////////////////////////////////////////////////////////////////
void DDError(HRESULT hErr, void* hWnd, LPCWSTR szFile, int iLine)
{
	TCHAR dderr[256];
	TCHAR err[1024];

	switch (hErr)
	{
		case DDERR_ALREADYINITIALIZED : _stprintf(dderr, _T("DDERR_ALREADYINITIALIZED")); break;
		case DDERR_CANNOTATTACHSURFACE : _stprintf(dderr, _T("DDERR_CANNOTATTACHSURFACE")); break;
		case DDERR_CANNOTDETACHSURFACE : _stprintf(dderr, _T("DDERR_CANNOTDETACHSURFACE")); break;
		case DDERR_CURRENTLYNOTAVAIL : _stprintf(dderr, _T("DDERR_CURRENTLYNOTAVAIL")); break;
		case DDERR_EXCEPTION : _stprintf(dderr, _T("DDERR_EXCEPTION")); break;
		case DDERR_GENERIC : _stprintf(dderr, _T("DDERR_GENERIC")); break;
		case DDERR_HEIGHTALIGN : _stprintf(dderr, _T("DDERR_HEIGHTALIGN")); break;
		case DDERR_INCOMPATIBLEPRIMARY : _stprintf(dderr, _T("DDERR_INCOMPATIBLEPRIMARY")); break;
		case DDERR_INVALIDCAPS : _stprintf(dderr, _T("DDERR_INVALIDCAPS")); break;
		case DDERR_INVALIDCLIPLIST : _stprintf(dderr, _T("DDERR_INVALIDCLIPLIST")); break;
		case DDERR_INVALIDMODE : _stprintf(dderr, _T("DDERR_INVALIDMODE")); break;
		case DDERR_INVALIDOBJECT : _stprintf(dderr, _T("DDERR_INVALIDOBJECT")); break;
		case DDERR_INVALIDPARAMS : _stprintf(dderr, _T("DDERR_INVALIDPARAMS")); break;
		case DDERR_INVALIDPIXELFORMAT : _stprintf(dderr, _T("DDERR_INVALIDPIXELFORMAT")); break;
		case DDERR_INVALIDRECT : _stprintf(dderr, _T("DDERR_INVALIDRECT")); break;
		case DDERR_LOCKEDSURFACES : _stprintf(dderr, _T("DDERR_LOCKEDSURFACES")); break;
		case DDERR_NO3D : _stprintf(dderr, _T("DDERR_NO3D")); break;
		case DDERR_NOALPHAHW : _stprintf(dderr, _T("DDERR_NOALPHAHW")); break;
		case DDERR_NOCLIPLIST : _stprintf(dderr, _T("DDERR_NOCLIPLIST")); break;
		case DDERR_NOCOLORCONVHW : _stprintf(dderr, _T("DDERR_NOCOLORCONVHW")); break;
		case DDERR_NOCOOPERATIVELEVELSET : _stprintf(dderr, _T("DDERR_NOCOOPERATIVELEVELSET")); break;
		case DDERR_NOCOLORKEY : _stprintf(dderr, _T("DDERR_NOCOLORKEY")); break;
		case DDERR_NOCOLORKEYHW : _stprintf(dderr, _T("DDERR_NOCOLORKEYHW")); break;
		case DDERR_NODIRECTDRAWSUPPORT : _stprintf(dderr, _T("DDERR_NODIRECTDRAWSUPPORT")); break;
		case DDERR_NOEXCLUSIVEMODE : _stprintf(dderr, _T("DDERR_NOEXCLUSIVEMODE")); break;
		case DDERR_NOFLIPHW : _stprintf(dderr, _T("DDERR_NOFLIPHW")); break;
		case DDERR_NOGDI : _stprintf(dderr, _T("DDERR_NOGDI")); break;
		case DDERR_NOMIRRORHW : _stprintf(dderr, _T("DDERR_NOMIRRORHW")); break;
		case DDERR_NOTFOUND : _stprintf(dderr, _T("DDERR_NOTFOUND")); break;
		case DDERR_NOOVERLAYHW : _stprintf(dderr, _T("DDERR_NOOVERLAYHW")); break;
		case DDERR_NORASTEROPHW : _stprintf(dderr, _T("DDERR_NORASTEROPHW")); break;
		case DDERR_NOROTATIONHW : _stprintf(dderr, _T("DDERR_NOROTATIONHW")); break;
		case DDERR_NOSTRETCHHW : _stprintf(dderr, _T("DDERR_NOSTRETCHHW")); break;
		case DDERR_NOT4BITCOLOR : _stprintf(dderr, _T("DDERR_NOT4BITCOLOR")); break;
		case DDERR_NOT4BITCOLORINDEX : _stprintf(dderr, _T("DDERR_NOT4BITCOLORINDEX")); break;
		case DDERR_NOT8BITCOLOR : _stprintf(dderr, _T("DDERR_NOT8BITCOLOR")); break;
		case DDERR_NOTEXTUREHW : _stprintf(dderr, _T("DDERR_NOTEXTUREHW")); break;
		case DDERR_NOVSYNCHW : _stprintf(dderr, _T("DDERR_NOVSYNCHW")); break;
		case DDERR_NOZBUFFERHW : _stprintf(dderr, _T("DDERR_NOZBUFFERHW")); break;
		case DDERR_NOZOVERLAYHW : _stprintf(dderr, _T("DDERR_NOZOVERLAYHW")); break;
		case DDERR_OUTOFCAPS : _stprintf(dderr, _T("DDERR_OUTOFCAPS")); break;
		case DDERR_OUTOFMEMORY : _stprintf(dderr, _T("DDERR_OUTOFMEMORY")); break;
		case DDERR_OUTOFVIDEOMEMORY : _stprintf(dderr, _T("DDERR_OUTOFVIDEOMEMORY")); break;
		case DDERR_OVERLAYCANTCLIP : _stprintf(dderr, _T("DDERR_OVERLAYCANTCLIP")); break;
		case DDERR_OVERLAYCOLORKEYONLYONEACTIVE : _stprintf(dderr, _T("DDERR_OVERLAYCOLORKEYONLYONEACTIVE")); break;
		case DDERR_PALETTEBUSY : _stprintf(dderr, _T("DDERR_PALETTEBUSY")); break;
		case DDERR_COLORKEYNOTSET : _stprintf(dderr, _T("DDERR_COLORKEYNOTSET")); break;
		case DDERR_SURFACEALREADYATTACHED : _stprintf(dderr, _T("DDERR_SURFACEALREADYATTACHED")); break;
		case DDERR_SURFACEALREADYDEPENDENT : _stprintf(dderr, _T("DDERR_SURFACEALREADYDEPENDENT")); break;
		case DDERR_SURFACEBUSY : _stprintf(dderr, _T("DDERR_SURFACEBUSY")); break;
		case DDERR_CANTLOCKSURFACE : _stprintf(dderr, _T("DDERR_CANTLOCKSURFACE")); break;
		case DDERR_SURFACEISOBSCURED : _stprintf(dderr, _T("DDERR_SURFACEISOBSCURED")); break;
		case DDERR_SURFACELOST : _stprintf(dderr, _T("DDERR_SURFACELOST")); break;
		case DDERR_SURFACENOTATTACHED : _stprintf(dderr, _T("DDERR_SURFACENOTATTACHED")); break;
		case DDERR_TOOBIGHEIGHT : _stprintf(dderr, _T("DDERR_TOOBIGHEIGHT")); break;
		case DDERR_TOOBIGSIZE : _stprintf(dderr, _T("DDERR_TOOBIGSIZE")); break;
		case DDERR_TOOBIGWIDTH : _stprintf(dderr, _T("DDERR_TOOBIGWIDTH")); break;
		case DDERR_UNSUPPORTED : _stprintf(dderr, _T("DDERR_UNSUPPORTED")); break;
		case DDERR_UNSUPPORTEDFORMAT : _stprintf(dderr, _T("DDERR_UNSUPPORTEDFORMAT")); break;
		case DDERR_UNSUPPORTEDMASK : _stprintf(dderr, _T("DDERR_UNSUPPORTEDMASK")); break;
		case DDERR_VERTICALBLANKINPROGRESS : _stprintf(dderr, _T("DDERR_VERTICALBLANKINPROGRESS")); break;
		case DDERR_WASSTILLDRAWING : _stprintf(dderr, _T("DDERR_WASSTILLDRAWING")); break;
		case DDERR_XALIGN : _stprintf(dderr, _T("DDERR_XALIGN")); break;
		case DDERR_INVALIDDIRECTDRAWGUID : _stprintf(dderr, _T("DDERR_INVALIDDIRECTDRAWGUID")); break;
		case DDERR_DIRECTDRAWALREADYCREATED : _stprintf(dderr, _T("DDERR_DIRECTDRAWALREADYCREATED")); break;
		case DDERR_NODIRECTDRAWHW : _stprintf(dderr, _T("DDERR_NODIRECTDRAWHW")); break;
		case DDERR_PRIMARYSURFACEALREADYEXISTS : _stprintf(dderr, _T("DDERR_PRIMARYSURFACEALREADYEXISTS")); break;
		case DDERR_NOEMULATION : _stprintf(dderr, _T("DDERR_NOEMULATION")); break;
		case DDERR_REGIONTOOSMALL : _stprintf(dderr, _T("DDERR_REGIONTOOSMALL")); break;
		case DDERR_CLIPPERISUSINGHWND : _stprintf(dderr, _T("DDERR_CLIPPERISUSINGHWND")); break;
		case DDERR_NOCLIPPERATTACHED : _stprintf(dderr, _T("DDERR_NOCLIPPERATTACHED")); break;
		case DDERR_NOHWND : _stprintf(dderr, _T("DDERR_NOHWND")); break;
		case DDERR_HWNDSUBCLASSED : _stprintf(dderr, _T("DDERR_HWNDSUBCLASSED")); break;
		case DDERR_HWNDALREADYSET : _stprintf(dderr, _T("DDERR_HWNDALREADYSET")); break;
		case DDERR_NOPALETTEATTACHED : _stprintf(dderr, _T("DDERR_NOPALETTEATTACHED")); break;
		case DDERR_NOPALETTEHW : _stprintf(dderr, _T("DDERR_NOPALETTEHW")); break;
		case DDERR_BLTFASTCANTCLIP : _stprintf(dderr, _T("DDERR_BLTFASTCANTCLIP")); break;
		case DDERR_NOBLTHW : _stprintf(dderr, _T("DDERR_NOBLTHW")); break;
		case DDERR_NODDROPSHW : _stprintf(dderr, _T("DDERR_NODDROPSHW")); break;
		case DDERR_OVERLAYNOTVISIBLE : _stprintf(dderr, _T("DDERR_OVERLAYNOTVISIBLE")); break;
		case DDERR_NOOVERLAYDEST : _stprintf(dderr, _T("DDERR_NOOVERLAYDEST")); break;
		case DDERR_INVALIDPOSITION : _stprintf(dderr, _T("DDERR_INVALIDPOSITION")); break;
		case DDERR_NOTAOVERLAYSURFACE : _stprintf(dderr, _T("DDERR_NOTAOVERLAYSURFACE")); break;
		case DDERR_EXCLUSIVEMODEALREADYSET : _stprintf(dderr, _T("DDERR_EXCLUSIVEMODEALREADYSET")); break;
		case DDERR_NOTFLIPPABLE : _stprintf(dderr, _T("DDERR_NOTFLIPPABLE")); break;
		case DDERR_CANTDUPLICATE : _stprintf(dderr, _T("DDERR_CANTDUPLICATE")); break;
		case DDERR_NOTLOCKED : _stprintf(dderr, _T("DDERR_NOTLOCKED")); break;
		case DDERR_CANTCREATEDC : _stprintf(dderr, _T("DDERR_CANTCREATEDC")); break;
		case DDERR_NODC : _stprintf(dderr, _T("DDERR_NODC")); break;
		case DDERR_WRONGMODE : _stprintf(dderr, _T("DDERR_WRONGMODE")); break;
		case DDERR_IMPLICITLYCREATED : _stprintf(dderr, _T("DDERR_IMPLICITLYCREATED")); break;
		case DDERR_NOTPALETTIZED : _stprintf(dderr, _T("DDERR_NOTPALETTIZED")); break;
		case DDERR_UNSUPPORTEDMODE : _stprintf(dderr, _T("DDERR_UNSUPPORTEDMODE")); break;
		case DDERR_NOMIPMAPHW : _stprintf(dderr, _T("DDERR_NOMIPMAPHW")); break;
		case DDERR_INVALIDSURFACETYPE : _stprintf(dderr, _T("DDERR_INVALIDSURFACETYPE")); break;
		case DDERR_DCALREADYCREATED : _stprintf(dderr, _T("DDERR_DCALREADYCREATED")); break;
		case DDERR_CANTPAGELOCK : _stprintf(dderr, _T("DDERR_CANTPAGELOCK")); break;
		case DDERR_CANTPAGEUNLOCK : _stprintf(dderr, _T("DDERR_CANTPAGEUNLOCK")); break;
		case DDERR_NOTPAGELOCKED : _stprintf(dderr, _T("DDERR_NOTPAGELOCKED")); break;
		case DDERR_NOTINITIALIZED : _stprintf(dderr, _T("DDERR_NOTINITIALIZED")); break;

		default : _stprintf(dderr, _T("Unknown Error")); break;
	}

	_stprintf(err, _T("DirectDraw Error %s\nFILE: %s\nLINE: %d"), dderr, szFile, iLine);
	MessageBox((HWND)hWnd, err, _T("Error"), MB_OK);
	PostQuitMessage(0);
}

////////////////////////////////////////////////////////////////////////
// Traces an error (DirectSound).
////////////////////////////////////////////////////////////////////////
void DSError(HRESULT hErr, void* hWnd)
{
	TCHAR dserr[256];
	TCHAR err[1024];

	switch (hErr)
	{
		case DSERR_ALLOCATED : _stprintf(dserr, _T("DSERR_ALLOCATED")); break;
		case DSERR_CONTROLUNAVAIL : _stprintf(dserr, _T("DSERR_CONTROLUNAVAIL")); break;
		case DSERR_INVALIDPARAM : _stprintf(dserr, _T("DSERR_INVALIDPARAM")); break;
		case DSERR_INVALIDCALL : _stprintf(dserr, _T("DSERR_INVALIDCALL")); break;
		case DSERR_GENERIC : _stprintf(dserr, _T("DSERR_GENERIC")); break;
		case DSERR_PRIOLEVELNEEDED : _stprintf(dserr, _T("DSERR_PRIOLEVELNEEDED")); break;
		case DSERR_OUTOFMEMORY : _stprintf(dserr, _T("DSERR_OUTOFMEMORY")); break;
		case DSERR_BADFORMAT : _stprintf(dserr, _T("DSERR_BADFORMAT")); break;
		case DSERR_UNSUPPORTED : _stprintf(dserr, _T("DSERR_UNSUPPORTED")); break;
		case DSERR_NODRIVER : _stprintf(dserr, _T("DSERR_NODRIVER")); break;
		case DSERR_ALREADYINITIALIZED : _stprintf(dserr, _T("DSERR_ALREADYINITIALIZED")); break;
		case DSERR_NOAGGREGATION : _stprintf(dserr, _T("DSERR_NOAGGREGATION")); break;
		case DSERR_BUFFERLOST : _stprintf(dserr, _T("DSERR_BUFFERLOST")); break;
		case DSERR_OTHERAPPHASPRIO : _stprintf(dserr, _T("DSERR_OTHERAPPHASPRIO")); break;
		case DSERR_UNINITIALIZED : _stprintf(dserr, _T("DSERR_UNINITIALIZED")); break;

		default : _stprintf(dserr, _T("Unknown Error")); break;
	}

	_stprintf(err, _T("DirectSound Error '%s.'\nContinue with Sound turned off?"), dserr);
	int ret = MessageBox( (HWND)hWnd, err, _T("Error"), MB_YESNO );
	if( ret==IDNO ) PostQuitMessage(0);
}


////////////////////////////////////////////////////////////////////////
// DXErrorToString
// Returns a pointer to a string describing the given DD, D3D or D3DRM error code.
////////////////////////////////////////////////////////////////////////
const TCHAR * DXErrorToString(HRESULT hErr)
{
  switch(hErr)
  {
    case DD_OK:
  /* Also includes D3D_OK and D3DRM_OK */
        return _T("No error.\0");
    case DDERR_ALREADYINITIALIZED:
        return _T("This object is already initialized.\0");
    case DDERR_BLTFASTCANTCLIP:
        return _T("Return if a clipper object is attached to the source surface passed into a BltFast call.\0");
    case DDERR_CANNOTATTACHSURFACE:
        return _T("This surface can not be attached to the requested surface.\0");
    case DDERR_CANNOTDETACHSURFACE:
        return _T("This surface can not be detached from the requested surface.\0");
    case DDERR_CANTCREATEDC:
        return _T("Windows can not create any more DCs.\0");
    case DDERR_CANTDUPLICATE:
        return _T("Can't duplicate primary & 3D surfaces, or surfaces that are implicitly created.\0");
    case DDERR_CLIPPERISUSINGHWND:
        return _T("An attempt was made to set a cliplist for a clipper object that is already monitoring an hwnd.\0");
    case DDERR_COLORKEYNOTSET:
        return _T("No src color key specified for this operation.\0");
    case DDERR_CURRENTLYNOTAVAIL:
        return _T("Support is currently not available.\0");
    case DDERR_DIRECTDRAWALREADYCREATED:
        return _T("A DirectDraw object representing this driver has already been created for this process.\0");
    case DDERR_EXCEPTION:
        return _T("An exception was encountered while performing the requested operation.\0");
    case DDERR_EXCLUSIVEMODEALREADYSET:
        return _T("An attempt was made to set the cooperative level when it was already set to exclusive.\0");
    case DDERR_GENERIC:
        return _T("Generic failure.\0");
    case DDERR_HEIGHTALIGN:
        return _T("Height of rectangle provided is not a multiple of reqd alignment.\0");
    case DDERR_HWNDALREADYSET:
        return _T("The CooperativeLevel HWND has already been set. It can not be reset while the process has surfaces or palettes created.\0");
    case DDERR_HWNDSUBCLASSED:
        return _T("HWND used by DirectDraw CooperativeLevel has been subclassed, this prevents DirectDraw from restoring state.\0");
    case DDERR_IMPLICITLYCREATED:
        return _T("This surface can not be restored because it is an implicitly created surface.\0");
    case DDERR_INCOMPATIBLEPRIMARY:
        return _T("Unable to match primary surface creation request with existing primary surface.\0");
    case DDERR_INVALIDCAPS:
        return _T("One or more of the caps bits passed to the callback are incorrect.\0");
    case DDERR_INVALIDCLIPLIST:
        return _T("DirectDraw does not support the provided cliplist.\0");
    case DDERR_INVALIDDIRECTDRAWGUID:
        return _T("The GUID passed to DirectDrawCreate is not a valid DirectDraw driver identifier.\0");
    case DDERR_INVALIDMODE:
        return _T("DirectDraw does not support the requested mode.\0");
    case DDERR_INVALIDOBJECT:
        return _T("DirectDraw received a pointer that was an invalid DIRECTDRAW object.\0");
    case DDERR_INVALIDPARAMS:
        return _T("One or more of the parameters passed to the function are incorrect.\0");
    case DDERR_INVALIDPIXELFORMAT:
        return _T("The pixel format was invalid as specified.\0");
    case DDERR_INVALIDPOSITION:
        return _T("Returned when the position of the overlay on the destination is no longer legal for that destination.\0");
    case DDERR_INVALIDRECT:
        return _T("Rectangle provided was invalid.\0");
    case DDERR_LOCKEDSURFACES:
        return _T("Operation could not be carried out because one or more surfaces are locked.\0");
    case DDERR_NO3D:
        return _T("There is no 3D present.\0");
    case DDERR_NOALPHAHW:
        return _T("Operation could not be carried out because there is no alpha accleration hardware present or available.\0");
    case DDERR_NOBLTHW:
        return _T("No blitter hardware present.\0");
    case DDERR_NOCLIPLIST:
        return _T("No cliplist available.\0");
    case DDERR_NOCLIPPERATTACHED:
        return _T("No clipper object attached to surface object.\0");
    case DDERR_NOCOLORCONVHW:
        return _T("Operation could not be carried out because there is no color conversion hardware present or available.\0");
    case DDERR_NOCOLORKEY:
        return _T("Surface doesn't currently have a color key\0");
    case DDERR_NOCOLORKEYHW:
        return _T("Operation could not be carried out because there is no hardware support of the destination color key.\0");
    case DDERR_NOCOOPERATIVELEVELSET:
        return _T("Create function called without DirectDraw object method SetCooperativeLevel being called.\0");
    case DDERR_NODC:
        return _T("No DC was ever created for this surface.\0");
    case DDERR_NODDROPSHW:
        return _T("No DirectDraw ROP hardware.\0");
    case DDERR_NODIRECTDRAWHW:
        return _T("A hardware-only DirectDraw object creation was attempted but the driver did not support any hardware.\0");
    case DDERR_NOEMULATION:
        return _T("Software emulation not available.\0");
    case DDERR_NOEXCLUSIVEMODE:
        return _T("Operation requires the application to have exclusive mode but the application does not have exclusive mode.\0");
    case DDERR_NOFLIPHW:
        return _T("Flipping visible surfaces is not supported.\0");
    case DDERR_NOGDI:
        return _T("There is no GDI present.\0");
    case DDERR_NOHWND:
        return _T("Clipper notification requires an HWND or no HWND has previously been set as the CooperativeLevel HWND.\0");
    case DDERR_NOMIRRORHW:
        return _T("Operation could not be carried out because there is no hardware present or available.\0");
    case DDERR_NOOVERLAYDEST:
        return _T("Returned when GetOverlayPosition is called on an overlay that UpdateOverlay has never been called on to establish a destination.\0");
    case DDERR_NOOVERLAYHW:
        return _T("Operation could not be carried out because there is no overlay hardware present or available.\0");
    case DDERR_NOPALETTEATTACHED:
        return _T("No palette object attached to this surface.\0");
    case DDERR_NOPALETTEHW:
        return _T("No hardware support for 16 or 256 color palettes.\0");
    case DDERR_NORASTEROPHW:
        return _T("Operation could not be carried out because there is no appropriate raster op hardware present or available.\0");
    case DDERR_NOROTATIONHW:
        return _T("Operation could not be carried out because there is no rotation hardware present or available.\0");
    case DDERR_NOSTRETCHHW:
        return _T("Operation could not be carried out because there is no hardware support for stretching.\0");
    case DDERR_NOT4BITCOLOR:
        return _T("DirectDrawSurface is not in 4 bit color palette and the requested operation requires 4 bit color palette.\0");
    case DDERR_NOT4BITCOLORINDEX:
        return _T("DirectDrawSurface is not in 4 bit color index palette and the requested operation requires 4 bit color index palette.\0");
    case DDERR_NOT8BITCOLOR:
        return _T("DirectDrawSurface is not in 8 bit color mode and the requested operation requires 8 bit color.\0");
    case DDERR_NOTAOVERLAYSURFACE:
        return _T("Returned when an overlay member is called for a non-overlay surface.\0");
    case DDERR_NOTEXTUREHW:
        return _T("Operation could not be carried out because there is no texture mapping hardware present or available.\0");
    case DDERR_NOTFLIPPABLE:
        return _T("An attempt has been made to flip a surface that is not flippable.\0");
    case DDERR_NOTFOUND:
        return _T("Requested item was not found.\0");
    case DDERR_NOTLOCKED:
        return _T("Surface was not locked.  An attempt to unlock a surface that was not locked at all, or by this process, has been attempted.\0");
    case DDERR_NOTPALETTIZED:
        return _T("The surface being used is not a palette-based surface.\0");
    case DDERR_NOVSYNCHW:
        return _T("Operation could not be carried out because there is no hardware support for vertical blank synchronized operations.\0");
    case DDERR_NOZBUFFERHW:
        return _T("Operation could not be carried out because there is no hardware support for zbuffer blitting.\0");
    case DDERR_NOZOVERLAYHW:
        return _T("Overlay surfaces could not be z layered based on their BltOrder because the hardware does not support z layering of overlays.\0");
    case DDERR_OUTOFCAPS:
        return _T("The hardware needed for the requested operation has already been allocated.\0");
    case DDERR_OUTOFMEMORY:
        return _T("DirectDraw does not have enough memory to perform the operation.\0");
    case DDERR_OUTOFVIDEOMEMORY:
        return _T("DirectDraw does not have enough memory to perform the operation.\0");
    case DDERR_OVERLAYCANTCLIP:
        return _T("The hardware does not support clipped overlays.\0");
    case DDERR_OVERLAYCOLORKEYONLYONEACTIVE:
        return _T("Can only have ony color key active at one time for overlays.\0");
    case DDERR_OVERLAYNOTVISIBLE:
        return _T("Returned when GetOverlayPosition is called on a hidden overlay.\0");
    case DDERR_PALETTEBUSY:
        return _T("Access to this palette is being refused because the palette is already locked by another thread.\0");
    case DDERR_PRIMARYSURFACEALREADYEXISTS:
        return _T("This process already has created a primary surface.\0");
    case DDERR_REGIONTOOSMALL:
        return _T("Region passed to Clipper::GetClipList is too small.\0");
    case DDERR_SURFACEALREADYATTACHED:
        return _T("This surface is already attached to the surface it is being attached to.\0");
    case DDERR_SURFACEALREADYDEPENDENT:
        return _T("This surface is already a dependency of the surface it is being made a dependency of.\0");
    case DDERR_SURFACEBUSY:
        return _T("Access to this surface is being refused because the surface is already locked by another thread.\0");
    case DDERR_SURFACEISOBSCURED:
        return _T("Access to surface refused because the surface is obscured.\0");
    case DDERR_SURFACELOST:
        return _T("Access to this surface is being refused because the surface memory is gone. The DirectDrawSurface object representing this surface should have Restore called on it.\0");
    case DDERR_SURFACENOTATTACHED:
        return _T("The requested surface is not attached.\0");
    case DDERR_TOOBIGHEIGHT:
        return _T("Height requested by DirectDraw is too large.\0");
    case DDERR_TOOBIGSIZE:
        return _T("Size requested by DirectDraw is too large, but the individual height and width are OK.\0");
    case DDERR_TOOBIGWIDTH:
        return _T("Width requested by DirectDraw is too large.\0");
    case DDERR_UNSUPPORTED:
        return _T("Action not supported.\0");
    case DDERR_UNSUPPORTEDFORMAT:
        return _T("FOURCC format requested is unsupported by DirectDraw.\0");
    case DDERR_UNSUPPORTEDMASK:
        return _T("Bitmask in the pixel format requested is unsupported by DirectDraw.\0");
    case DDERR_VERTICALBLANKINPROGRESS:
        return _T("Vertical blank is in progress.\0");
    case DDERR_WASSTILLDRAWING:
        return _T("Informs DirectDraw that the previous Blt which is transfering information to or from this Surface is incomplete.\0");
    case DDERR_WRONGMODE:
        return _T("This surface can not be restored because it was created in a different mode.\0");
    case DDERR_XALIGN:
        return _T("Rectangle provided was not horizontally aligned on required boundary.\0");
    case D3DERR_BADMAJORVERSION:
        return _T("D3DERR_BADMAJORVERSION\0");
    case D3DERR_BADMINORVERSION:
        return _T("D3DERR_BADMINORVERSION\0");
    case D3DERR_EXECUTE_LOCKED:
        return _T("D3DERR_EXECUTE_LOCKED\0");
    case D3DERR_EXECUTE_NOT_LOCKED:
        return _T("D3DERR_EXECUTE_NOT_LOCKED\0");
    case D3DERR_EXECUTE_CREATE_FAILED:
        return _T("D3DERR_EXECUTE_CREATE_FAILED\0");
    case D3DERR_EXECUTE_DESTROY_FAILED:
        return _T("D3DERR_EXECUTE_DESTROY_FAILED\0");
    case D3DERR_EXECUTE_LOCK_FAILED:
        return _T("D3DERR_EXECUTE_LOCK_FAILED\0");
    case D3DERR_EXECUTE_UNLOCK_FAILED:
        return _T("D3DERR_EXECUTE_UNLOCK_FAILED\0");
    case D3DERR_EXECUTE_FAILED:
        return _T("D3DERR_EXECUTE_FAILED\0");
    case D3DERR_EXECUTE_CLIPPED_FAILED:
        return _T("D3DERR_EXECUTE_CLIPPED_FAILED\0");
    case D3DERR_TEXTURE_NO_SUPPORT:
        return _T("D3DERR_TEXTURE_NO_SUPPORT\0");
    case D3DERR_TEXTURE_NOT_LOCKED:
        return _T("D3DERR_TEXTURE_NOT_LOCKED\0");
    case D3DERR_TEXTURE_LOCKED:
        return _T("D3DERR_TEXTURELOCKED\0");
    case D3DERR_TEXTURE_CREATE_FAILED:
        return _T("D3DERR_TEXTURE_CREATE_FAILED\0");
    case D3DERR_TEXTURE_DESTROY_FAILED:
        return _T("D3DERR_TEXTURE_DESTROY_FAILED\0");
    case D3DERR_TEXTURE_LOCK_FAILED:
        return _T("D3DERR_TEXTURE_LOCK_FAILED\0");
    case D3DERR_TEXTURE_UNLOCK_FAILED:
        return _T("D3DERR_TEXTURE_UNLOCK_FAILED\0");
    case D3DERR_TEXTURE_LOAD_FAILED:
        return _T("D3DERR_TEXTURE_LOAD_FAILED\0");
    case D3DERR_MATRIX_CREATE_FAILED:
        return _T("D3DERR_MATRIX_CREATE_FAILED\0");
    case D3DERR_MATRIX_DESTROY_FAILED:
        return _T("D3DERR_MATRIX_DESTROY_FAILED\0");
    case D3DERR_MATRIX_SETDATA_FAILED:
        return _T("D3DERR_MATRIX_SETDATA_FAILED\0");
    case D3DERR_SETVIEWPORTDATA_FAILED:
        return _T("D3DERR_SETVIEWPORTDATA_FAILED\0");
    case D3DERR_MATERIAL_CREATE_FAILED:
        return _T("D3DERR_MATERIAL_CREATE_FAILED\0");
    case D3DERR_MATERIAL_DESTROY_FAILED:
        return _T("D3DERR_MATERIAL_DESTROY_FAILED\0");
    case D3DERR_MATERIAL_SETDATA_FAILED:
        return _T("D3DERR_MATERIAL_SETDATA_FAILED\0");
    case D3DERR_LIGHT_SET_FAILED:
        return _T("D3DERR_LIGHT_SET_FAILED\0");
/*	  case D3DRMERR_BADOBJECT:
	      return _T("D3DRMERR_BADOBJECT\0");
	  case D3DRMERR_BADTYPE:
	      return _T("D3DRMERR_BADTYPE\0");
	  case D3DRMERR_BADALLOC:
	      return _T("D3DRMERR_BADALLOC\0");
	  case D3DRMERR_FACEUSED:
	      return _T("D3DRMERR_FACEUSED\0");
	  case D3DRMERR_NOTFOUND:
	      return _T("D3DRMERR_NOTFOUND\0");
	  case D3DRMERR_NOTDONEYET:
	      return _T("D3DRMERR_NOTDONEYET\0");
	  case D3DRMERR_FILENOTFOUND:
	      return _T("The file was not found.\0");
	  case D3DRMERR_BADFILE:
	      return _T("D3DRMERR_BADFILE\0");
	  case D3DRMERR_BADDEVICE:
	      return _T("D3DRMERR_BADDEVICE\0");
	  case D3DRMERR_BADVALUE:
	      return _T("D3DRMERR_BADVALUE\0");
	  case D3DRMERR_BADMAJORVERSION:
	      return _T("D3DRMERR_BADMAJORVERSION\0");
	  case D3DRMERR_BADMINORVERSION:
	      return _T("D3DRMERR_BADMINORVERSION\0");
	  case D3DRMERR_UNABLETOEXECUTE:
	      return _T("D3DRMERR_UNABLETOEXECUTE\0");
*/    default:
        return _T("Unrecognized error value.\0");
  }
}
