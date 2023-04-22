//////////////////////////////////////////////////////////////////////////////////
// $Source: /cvsroot/cdx/cdx3.0/src/cdx3d/engine.cpp,v $
// $Author: istan $
//
// $Log: engine.cpp,v $
// Revision 1.4  2000/10/04 08:05:25  istan
// Added CDXLog debugging code to the module
//
// Revision 1.3  2000/08/24 19:14:55  mindcry
// Now uses the IDirect3DRM3 Interface. Thanks to Daniel Polli.
//
// Revision 1.2  2000/06/13 15:58:30  mindcry
// Upgraded for DX7 Compatibility (Thanks Mike)
//
// Revision 1.1.1.1  2000/04/22 16:08:40  hebertjo
// Initial checkin of v3.0 to SourceForge CVS.
//
// Revision 2.6  1999/11/24 19:44:13  MICHAELR
// Fixed return code problem, line 144 (error==DD_OK), should  have been !=
// Modified FindDevice so it does not return a local stack pointer to the GUID
// Thanks to Nick Lawroff for finding these problems
//
// Revision 2.5  1999/09/25 06:38:59  MICHAELR
// Added code snippit to FindDevices to enable hardware usage
// Code fix was from Julien Cugniere
//
// Revision 2.4  1999/08/05 02:44:21  MICHAELR
// Fixed compile errors that were reported with Engine class
//
// Revision 2.3  1999/07/15 19:26:37  MICHAELR
// several changes to facilitate switching from fullscreen to windows and back
// also added InitCRMEngine() and called from constructor to do inits
//
// Revision 2.2  1999/07/15 16:50:11  MICHAELR
// CreateFullScreen works now, thx Olivier!
//
// Revision 2.1  1999/07/11 17:58:00  MICHAELR
// Added initial code to CreateFullScreen, doesn't work though.
//
// Revision 2.0  1999/05/01 13:51:18  bsimser
// Updated revision number to 2.0
//
// Revision 1.1.1.1  1999/05/01 04:10:56  bsimser
// Initial revision to cvs
//
// $Revision: 1.4 $
//////////////////////////////////////////////////////////////////////////////////
#ifdef SAVE_RCSID
static char rcsid = "@(#) $Id: engine.cpp,v 1.4 2000/10/04 08:05:25 istan Exp $";
#endif

#include "CDX3D.h"
#include "cdxdebug.h"

//////////////////////////////////////////////////////////////////////////////////
// Initializes all member variables
// is called from all constructors!
//////////////////////////////////////////////////////////////////////////////////
void CRMEngine::InitCRMEngine()
{
	HRESULT   rval;
	LPDIRECT3DRM lpD3DRMInterface;

	CDXLOG("START: CRMEngine::InitCRMEngine");
	CDXLOG("Initialize member vars");

	// initialize member variables
	m_Direct3D = NULL;
	m_IMDevice = NULL;
	m_RMDevice = NULL;

	m_Direct3DRM = NULL;
	m_lpDDClipper = NULL;

	m_Screen = NULL;

	CDXLOG("Create the Direct3D Retained Mode Interface");

	// create the main d3drm object
	rval = Direct3DRMCreate(&lpD3DRMInterface);
	if(rval != D3DRM_OK) {
		D3DError(rval, m_Screen->GetWindowHandle(), __FILE__, __LINE__);
	}

	CDXLOG("QueryInterface for a IDirect3DRM3 Interface");

    /* Get the interface IDirect3DRM3 */
    rval = lpD3DRMInterface->QueryInterface (IID_IDirect3DRM3,
                                                (LPVOID *) &m_Direct3DRM);

	CDXLOG("Release the old IDirect3DRM interface");

	/* Release the Old IDirect3DRM */
	RELEASE(lpD3DRMInterface);

	if(rval != D3DRM_OK) {
		D3DError(rval, m_Screen->GetWindowHandle(), __FILE__, __LINE__);
	}

	CDXLOG("END: CRMEngine::InitCRMEngine");
}

//////////////////////////////////////////////////////////////////////////////////
// CRMEngine Constructor
//////////////////////////////////////////////////////////////////////////////////
CRMEngine::CRMEngine(void)
{
	CDXLOG("START: CRMEngine::CRMEngine");

	InitCRMEngine();

	CDXLOG("END: CRMEngine::CRMEngine");
}

//////////////////////////////////////////////////////////////////////////////////
// CRMEngine Destructor
//////////////////////////////////////////////////////////////////////////////////
CRMEngine::~CRMEngine(void)
{
	CDXLOG("START: CRMEngine::~CRMEngine");

	CDXLOG("Release interfaces");

	RELEASE(m_Direct3D);
	RELEASE(m_IMDevice);
	RELEASE(m_RMDevice);

	RELEASE(m_Direct3DRM);
	RELEASE(m_lpDDClipper);

	m_Screen = NULL;

	CDXLOG("END: CRMEngine::~CRMEngine");
}

DWORD CRMEngine::bppToDbd(int bpp)
{
	CDXLOG("START: CRMEngine::bppToDbd");

	switch(bpp) {
	case 1:
		return DDBD_1;
	case 2:
		return DDBD_2;
	case 4:
		return DDBD_4;
	case 8:
		return DDBD_8;
	case 16:
		return DDBD_16;
	case 24:
		return DDBD_24;
	case 32:
		return DDBD_32;
	}

	return 0;

	CDXLOG("END: CRMEngine::bppToDbd");
}

LPGUID CRMEngine::FindDevice(int BPP, LPGUID OUT guid)
{
#if DIRECTDRAW_VERSION >= CDX_DDVER
	LPDIRECTDRAW7 lpDD;
#else
	LPDIRECTDRAW lpDD;
#endif
	LPDIRECT3D lpD3D;
	D3DFINDDEVICESEARCH devSearch;
	static D3DFINDDEVICERESULT devResult;
	HRESULT error;

	CDXLOG("START: CRMEngine::FindDevice");

	CDXLOG("Get the DirectDraw Object from the Screen");

	// get the DirectDraw object
	lpDD = m_Screen->GetDD();
	if (lpDD==NULL) return NULL;

	CDXLOG("QueryInterface for a IDirect3D interface");

	if(lpDD->QueryInterface(IID_IDirect3D, (void**)&lpD3D)) {
		return NULL;
	}

	ZeroMemory(&devSearch, sizeof(devSearch));
	devSearch.dwSize = sizeof(devSearch);
	devSearch.dwFlags = D3DFDS_COLORMODEL;
	devSearch.dcmColorModel = D3DCOLOR_RGB;

	// Julien Cugniere reported we needed this line to enable hardware support for the engine
	// added by: MICHAELR
	devSearch.bHardware = TRUE;

	devSearch.dwFlags |= D3DFDS_HARDWARE;

	ZeroMemory(&devResult, sizeof(devResult));
	devResult.dwSize = sizeof(devResult);

	CDXLOG("Attempt to FindDevice");

	error = lpD3D->FindDevice(&devSearch, &devResult);
	if(error != DD_OK) {
    	CDXLOG("FindDevice Failed");
		if(devResult.ddHwDesc.dwFlags &&
			!(devResult.ddHwDesc.dwDeviceRenderBitDepth & bppToDbd(BPP))) {
			devSearch.dwFlags |= D3DFDS_HARDWARE;
			devSearch.bHardware = FALSE;
			ZeroMemory(&devResult, sizeof(devResult));
			devResult.dwSize = sizeof(devResult);
        	CDXLOG("Do a software FindDevice search");
			// do a software search now
			error = lpD3D->FindDevice(&devSearch, &devResult);
		}
	}

	CDXLOG("Release the IDirect3D interface");

	lpD3D->Release();

	CDXLOG("END: CRMEngine::FindDevice");

	if(error==DD_OK)
	{
    	CDXLOG("Copy Device GUID into Out Buffer");

		// copy the guid into the out buffer
		memcpy(guid, &devResult.guid, sizeof(GUID));
		return guid;
	}
	else
		return NULL;
}

//////////////////////////////////////////////////////////////////////////////////
// CRMEngine CreateFullScreen - creates a full screen application
//////////////////////////////////////////////////////////////////////////////////
HRESULT CRMEngine::CreateFullScreen(CDXScreen* pScreen, void *hWnd,
                                    int Width, int Height, int BPP)
{
	GUID d3dGUID;
	LPDIRECTDRAW lpDD;
	LPDIRECTDRAWSURFACE lpDDS;
	HRESULT rval;

	CDXLOG("START: CRMEngine::CreateFullScreen");

	CDXASSERT(BPP!=8);

	CDXLOG("Release any existing m_RMDevice we have");

	// first release everything that has been allocated
	RELEASE(m_RMDevice);

	CDXLOG("Save our Screen Pointer, and switch us to FullScreen mode");

	// create the CDXScreen object
	m_Screen = pScreen;
	if(FAILED(m_Screen->CreateFullScreen(hWnd, Width, Height, BPP))) {
    	CDXLOG("FullScreen mode switch failed");
		return D3DRMERR_NOTDONEYET;
	}

#if DIRECTDRAW_VERSION >= CDX_DDVER
	CDXLOG("QueryInterface for a IDirectDraw Interface");

	// query for a IDirectDraw object
	rval = m_Screen->GetDD()->QueryInterface(IID_IDirectDraw, (LPVOID*)&lpDD);
	if(rval != DD_OK) DDError(rval, NULL, __FILE__, __LINE__);

	CDXLOG("QueryInterface for a IDirectDrawSurface Interface");

	rval = m_Screen->GetBack()->GetDDS()->QueryInterface(IID_IDirectDrawSurface, (LPVOID*)&lpDDS);
	if(rval != DD_OK) DDError(rval, NULL, __FILE__, __LINE__);
#else
	CDXLOG("Save the DirectDraw and DirectDrawSurface pointers");

	lpDD = m_Screen->GetDD();
	lpDDS = m_Screen->GetBack()->GetDDS();
#endif

	CDXLOG("Attempt to CreateDeviceFromSurface");

	// create the d3d device
	rval = m_Direct3DRM->CreateDeviceFromSurface(FindDevice(BPP, &d3dGUID),
		lpDD, lpDDS,0, &m_RMDevice);
	if(FAILED(rval)) {
    	CDXLOG("Create attempt failed");
		D3DError(rval, m_Screen->GetWindowHandle(), __FILE__, __LINE__);
		return D3DRMERR_NOTDONEYET;
	}

	CDXLOG("Set the RMDevice buffer count = 2");

	/* in my doc it's specified that we should set this */
	m_RMDevice->SetBufferCount(2);

	CDXLOG("Set our defaults based on bit depth");

	// start our engine with default values based on color depth
	SetDefaults();

	CDXLOG("END: CRMEngine::CreateFullScreen");

	return D3DRM_OK;
}

//////////////////////////////////////////////////////////////////////////////////
// CRMEngine CreateWindowed - creates a windowed application
//////////////////////////////////////////////////////////////////////////////////
HRESULT CRMEngine::CreateWindowed(CDXScreen* pScreen, void *hWnd,
                                  int Width, int Height)
{
	GUID d3dGUID;

	CDXLOG("START: CRMEngine::CreateWindowed");

	CDXLOG("Release our m_RMDevice and Clipper object if we have one");

	// first release everything that has been allocated
	RELEASE(m_RMDevice);
	RELEASE(m_lpDDClipper);

	CDXLOG("Save the Screen object and do a CreateWindow");

	// create the CDXScreen object
	m_Screen = pScreen;
	if(FAILED(m_Screen->CreateWindowed(hWnd, Width, Height))) {
    	CDXLOG("CreateWindow failed");
		return D3DRMERR_NOTDONEYET;
	}

	CDXLOG("Create a Clipper object");

	// create the dd clipper object
	if(FAILED(DirectDrawCreateClipper(0, &m_lpDDClipper, NULL))) {
    	CDXLOG("Clipper creation failed");
		return D3DRMERR_NOTDONEYET;
	}

	CDXLOG("Set the hWnd of the clipper to the main window");

	// set the clipper objects hWnd
	if(FAILED(m_lpDDClipper->SetHWnd(0, (HWND)hWnd))) {
		RELEASE(m_lpDDClipper);
		return D3DRMERR_NOTDONEYET;
	}

	CDXLOG("Do a CreateDeviceFromClipper to setup the 3DRM clipper");

	// create the d3d device
	if(FAILED(m_Direct3DRM->CreateDeviceFromClipper(m_lpDDClipper,
		FindDevice(m_Screen->GetBPP(), &d3dGUID), Width, Height, &m_RMDevice))) {
		return D3DRMERR_NOTDONEYET;
	}

	CDXLOG("Call SetDefaults");

	// start our engine with default values based on color depth
	SetDefaults();

	CDXLOG("END: CRMEngine::CreateWindowed");

	return D3DRM_OK;
}

//////////////////////////////////////////////////////////////////////////////////
// CRMEngine Update
//////////////////////////////////////////////////////////////////////////////////
HRESULT CRMEngine::Update(void)
{
	CDXLOG2("START: CRMEngine::Update");
	return m_RMDevice->Update();
}

//////////////////////////////////////////////////////////////////////////////////
// CRMEngine CreateFrame
//////////////////////////////////////////////////////////////////////////////////
HRESULT CRMEngine::CreateFrame(LPDIRECT3DRMFRAME3 pParent, LPDIRECT3DRMFRAME3* pFrame)
{
	CDXLOG("START: CRMEngine::CreateFrame");
	return m_Direct3DRM->CreateFrame(pParent, pFrame);
}

//////////////////////////////////////////////////////////////////////////////////
// CRMEngine CreateLight
//////////////////////////////////////////////////////////////////////////////////
HRESULT CRMEngine::CreateLight(D3DRMLIGHTTYPE type, double r, double g, double b,
                               LPDIRECT3DRMLIGHT* pLight)
{
	CDXLOG("START: CRMEngine::CreateLight");
	return m_Direct3DRM->CreateLightRGB(type, D3DVAL(r), D3DVAL(g), D3DVAL(b), pLight);
}

//////////////////////////////////////////////////////////////////////////////////
// CRMEngine CreateMeshBuilder
//////////////////////////////////////////////////////////////////////////////////
HRESULT CRMEngine::CreateMeshBuilder(LPDIRECT3DRMMESHBUILDER3* pMeshBld)
{
	CDXLOG("START: CRMEngine::CreateMeshBuilder");
	return m_Direct3DRM->CreateMeshBuilder(pMeshBld);
}

//////////////////////////////////////////////////////////////////////////////////
// CRMEngine SetDither
//////////////////////////////////////////////////////////////////////////////////
HRESULT CRMEngine::SetDither(BOOL Dither)
{
	CDXLOG("START: CRMEngine::SetDither");
	return m_RMDevice->SetDither(Dither);
}

//////////////////////////////////////////////////////////////////////////////////
// CRMEngine SetQuality
//////////////////////////////////////////////////////////////////////////////////
HRESULT CRMEngine::SetQuality(D3DRMRENDERQUALITY Quality)
{
	CDXLOG("START: CRMEngine::SetQuality");
	return m_RMDevice->SetQuality(Quality);
}

//////////////////////////////////////////////////////////////////////////////////
// CRMEngine SetShades
//////////////////////////////////////////////////////////////////////////////////
HRESULT CRMEngine::SetShades(DWORD Shades)
{
	CDXLOG("START: CRMEngine::SetShades");
	return m_RMDevice->SetShades(Shades);
}

//////////////////////////////////////////////////////////////////////////////////
// CRMEngine SetTextureQuality
//////////////////////////////////////////////////////////////////////////////////
HRESULT CRMEngine::SetTextureQuality(D3DRMTEXTUREQUALITY TextureQuality)
{
	CDXLOG("START: CRMEngine::SetTextureQuality");
	return m_RMDevice->SetTextureQuality(TextureQuality);
}

//////////////////////////////////////////////////////////////////////////////////
// CRMEngine Tick
//////////////////////////////////////////////////////////////////////////////////
HRESULT CRMEngine::Tick(double Tick)
{
	CDXLOG2("START: CRMEngine::Tick");
	return m_Direct3DRM->Tick(Tick);
}

//////////////////////////////////////////////////////////////////////////////////
// Sets some default values for the engine based on the current bit depth.
//////////////////////////////////////////////////////////////////////////////////
void CRMEngine::SetDefaults(void)
{
	int bpp;

	CDXLOG("START: CRMEngine::SetDefaults");

	bpp = m_Screen->GetBPP();

	switch(bpp) {
	case 1:
		SetShades(4);
		break;

	case 16:
		SetShades(32);
		SetDither(FALSE);
		break;

	case 24:
	case 32:
		SetShades(256);
		SetDither(FALSE);
		break;

	default:
		SetDither(FALSE);
	}

	CDXLOG("END: CRMEngine::SetDefaults");
}