//////////////////////////////////////////////////////////////////////////////////
// $Source: /cvsroot/cdx/cdx3.0/src/cdx3d/camera.cpp,v $
// $Author: mindcry $
//
// $Log: camera.cpp,v $
// Revision 1.2  2000/08/24 19:14:36  mindcry
// Now uses the IDirect3DRM3 Interface. Thanks to Daniel Polli.
//
// Revision 1.1.1.1  2000/04/22 16:08:23  hebertjo
// Initial checkin of v3.0 to SourceForge CVS.
//
// Revision 2.0  1999/05/01 13:51:18  bsimser
// Updated revision number to 2.0
//
// Revision 1.1.1.1  1999/05/01 04:10:56  bsimser
// Initial revision to cvs
//
// $Revision: 1.2 $
//////////////////////////////////////////////////////////////////////////////////
#ifdef SAVE_RCSID
static char rcsid = "@(#) $Id: camera.cpp,v 1.2 2000/08/24 19:14:36 mindcry Exp $";
#endif

#include "CDX3D.h"

//////////////////////////////////////////////////////////////////////////////////
// CRMCamera Constructor
//////////////////////////////////////////////////////////////////////////////////
CRMCamera::CRMCamera(CRMEngine* pEngine)
{
	m_Engine = pEngine;
	m_Frame = NULL;
	m_View = NULL;
}

//////////////////////////////////////////////////////////////////////////////////
// CRMCamera Destructor
//////////////////////////////////////////////////////////////////////////////////
CRMCamera::~CRMCamera(void)
{
	RELEASE(m_View);
}

//////////////////////////////////////////////////////////////////////////////////
// CRMCamera Create
//////////////////////////////////////////////////////////////////////////////////
BOOL CRMCamera::Create(CRMScene* pScene)
{
	m_Engine->CreateFrame(pScene->m_Frame, &m_Frame);
	m_Frame->SetPosition(pScene->m_Frame, D3DVAL(0.0), D3DVAL(0.0), D3DVAL(-10.0));

	m_Engine->GetD3DRM()->CreateViewport(m_Engine->m_RMDevice, m_Frame, 0, 0,
	                                     m_Engine->m_Screen->GetWidth(),
	                                     m_Engine->m_Screen->GetHeight(), &m_View);

	m_View->SetBack(D3DVAL(5000.0));

	return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////
// CRMCamera Clear                        (need now a flag:)
//                                        D3DRMCLEAR_TARGET               
//                                        D3DRMCLEAR_ZBUFFER              
//										  D3DRMCLEAR_DIRTYRECTS   
//                                        D3DRMCLEAR_ALL
//////////////////////////////////////////////////////////////////////////////////
HRESULT CRMCamera::Clear(DWORD dwFlags)
{
	return m_View->Clear(dwFlags);
}

//////////////////////////////////////////////////////////////////////////////////
// CRMCamera Render
//////////////////////////////////////////////////////////////////////////////////
HRESULT CRMCamera::Render(CRMScene* pScene)
{
	return m_View->Render(pScene->m_Frame);
}

//////////////////////////////////////////////////////////////////////////////////
// CRMCamera ForceUpdate
//////////////////////////////////////////////////////////////////////////////////
HRESULT CRMCamera::ForceUpdate(DWORD X1, DWORD Y1, DWORD X2, DWORD Y2)
{
	return m_View->ForceUpdate(X1, Y1, X2, Y2);
}
