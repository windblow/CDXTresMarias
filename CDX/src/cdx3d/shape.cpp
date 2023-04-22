//////////////////////////////////////////////////////////////////////////////////
// $Source: /cvsroot/cdx/cdx3.0/src/cdx3d/shape.cpp,v $
// $Author: mindcry $
//
// $Log: shape.cpp,v $
// Revision 1.2  2000/08/24 19:16:27  mindcry
// Now uses the IDirect3DRM3 Interface. Thanks to Daniel Polli.
//
// Revision 1.1.1.1  2000/04/22 16:08:42  hebertjo
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
static char rcsid = "@(#) $Id: shape.cpp,v 1.2 2000/08/24 19:16:27 mindcry Exp $";
#endif

#include "CDX3D.h"
#include <math.h>

static const double PI =  3.14159265359;

//////////////////////////////////////////////////////////////////////////////////
// CRMShape Constructor
//////////////////////////////////////////////////////////////////////////////////
CRMShape::CRMShape(CRMEngine* pEngine)
{
	m_MeshBld = NULL;
	m_Engine = pEngine;
	m_Engine->CreateFrame(NULL, &m_Frame);
	m_Engine->CreateMeshBuilder(&m_MeshBld);
}

//////////////////////////////////////////////////////////////////////////////////
// CRMShape Destructor
//////////////////////////////////////////////////////////////////////////////////
CRMShape::~CRMShape(void)
{
	RELEASE(m_MeshBld);
}

//////////////////////////////////////////////////////////////////////////////////
// CRMShape Create
// dwFlags: D3DRMGENERATENORMALS_PRECOMPACT			(defaut)
//			D3DRMGENERATENORMALS_USECREASE_ANGLE
//////////////////////////////////////////////////////////////////////////////////
BOOL CRMShape::Create(D3DVECTOR* pVectors, int nVectors,
                     D3DVECTOR* pNormals, int nNormals,
					 THIS_ D3DVALUE crease,int* pFaceData,
					 BOOL bAutoGen,DWORD dwFlags)
{
	HRESULT rval;

	rval = m_MeshBld->AddFaces(nVectors, pVectors, nNormals, pNormals,
	                          (ULONG*)pFaceData, NULL);
	if(rval != D3DRM_OK) return FALSE;

	if((nNormals == 0) && bAutoGen) m_MeshBld->GenerateNormals(crease,dwFlags);

	m_MeshBld->SetPerspective(TRUE);
	m_Frame->AddVisual(m_MeshBld);

	return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////
// CRMShape CreateCube
//////////////////////////////////////////////////////////////////////////////////
BOOL CRMShape::CreateCube(double x, double y, double z)
{
	D3DVALUE x1 = D3DVAL(x / 2);
	D3DVALUE y1 = D3DVAL(y / 2);
	D3DVALUE z1 = D3DVAL(z / 2);

	D3DVECTOR vert[] =
	{
		{-x1, -y1, -z1},
		{-x1, -y1,  z1},
		{ x1, -y1,  z1},
		{ x1, -y1, -z1},
		{-x1,  y1, -z1},
		{-x1,  y1,  z1},
		{ x1,  y1,  z1},
		{ x1,  y1, -z1}
	};

	D3DVECTOR nlist [] =
	{
		{ 1,  0,  0},
		{ 0,  1,  0},
		{ 0,  0,  1},
		{-1,  0,  0},
		{ 0, -1,  0},
		{ 0,  0, -1}
	};

	int flist [] = {4, 0, 4, 3, 4, 2, 4, 1, 4,
                  4, 3, 0, 7, 0, 6, 0, 2,	0,
                  4, 4, 1, 5, 1, 6, 1, 7,	1,
                  4, 0, 3, 1, 3, 5, 3, 4,	3,
                  4, 0, 5, 4, 5, 7, 5, 3,	5,
                  4, 2, 2, 6, 2, 5, 2, 1,	2, 0};

	BOOL rval = Create(vert, 8, nlist, 6,0, flist);

	return rval;
}

//////////////////////////////////////////////////////////////////////////////////
// CRMShape CreateSphere
//////////////////////////////////////////////////////////////////////////////////
BOOL CRMShape::CreateSphere(double r, int nBands)
{
	int i;

	// Make sure the number of bands is >= 3
	if(nBands < 3) nBands = 3;

	// Compute the vertex count
	int iVertices = (nBands - 1) * nBands + 2;

	// Compute the face count
	int iFaces = nBands * nBands;

	// Create the list of vertices
	D3DVECTOR* Vertices = new D3DVECTOR[iVertices];
	D3DVECTOR* pv = Vertices;

	// Create the face list
	int* FaceData = new int[iFaces * 5];
	int* pfd = FaceData;

	// Set up the first vertex at the top
	pv->x = D3DVAL(0);
	pv->y = D3DVAL(r);
	pv->z = D3DVAL(0);
	pv++;
	int iv = 1;	// Next free vertex number

	// Top band
	double da = PI / nBands;
	double a = da;

	// Compute the y value for the bottom of the band
	double y = r * cos(a);
	double rband = r * sin(a);
	double ab = 0;

	// Write out the vertices for the bottom of this band
	int iv1 = iv; // First vertex on this band
	for(i = 0; i < nBands; i++)
	{
		pv->x = D3DVAL(rband * sin(ab));
		pv->y = D3DVAL(y);
		pv->z = D3DVAL(rband * cos(ab));
		pv++;
		iv++;
		ab += da * 2;
	}

	// Write out the face values
	for(i = 0; i < nBands; i++)
	{
		*pfd++ = 3;
		*pfd++ = iv1 + (i % nBands);
		*pfd++ = iv1 + ((i + 1) % nBands);
		*pfd++ = 0; // Top point
	}

	// Now do the middle bands
	for(int iBand = 1; iBand < nBands-1; iBand++)
	{
		a += da;
		y = r * cos(a);
		rband = r * sin(a);
		// Write out the vertices for the bottom of this band
		ab = 0;
		int iv1 = iv; // First vertex on this band
		for(i = 0; i < nBands; i++)
		{
			pv->x = D3DVAL(rband * sin(ab));
			pv->y = D3DVAL(y);
			pv->z = D3DVAL(rband * cos(ab));
			pv++;
			iv++;
			ab += da * 2;
		}

		// Write out the face values
		for(i = 0; i < nBands; i++)
		{
			*pfd++ = 4;
			*pfd++ = iv1 + (i % nBands);
			*pfd++ = iv1 + ((i + 1) % nBands);
			*pfd++ = iv1 - nBands + ((i + 1) % nBands);
			*pfd++ = iv1 - nBands + (i % nBands);
		}
	}

	// Now do the last band
	// Write out the vertex for the bottom of this band
	iv1 = iv; // First vertex on this band
	pv->x = D3DVAL(0);
	pv->y = D3DVAL(-r);
	pv->z = D3DVAL(0);
	pv++;
	iv++;

	// Write out the face values
	for (i = 0; i < nBands; i++)
	{
		*pfd++ = 3;
		*pfd++ = iv1; // Bottom point
		*pfd++ = iv1 - nBands + ((i + 1) % nBands);
		*pfd++ = iv1 - nBands + (i % nBands);
	}

	*pfd = 0; // End the face list

  BOOL res = Create(Vertices, iv, NULL, 0,0, FaceData, TRUE);
	delete [] Vertices;
	delete [] FaceData;

	return res;
}

//////////////////////////////////////////////////////////////////////////////////
// CRMShape Load
//////////////////////////////////////////////////////////////////////////////////
BOOL CRMShape::Load(const char* szFilename)
{
	HRESULT rval;

	rval = m_MeshBld->Load((void*)(const char*)szFilename, NULL,
                         D3DRMLOAD_FROMFILE | D3DRMLOAD_FIRST, NULL, NULL);
	if(rval != D3DRM_OK) return FALSE;

	m_MeshBld->SetPerspective(TRUE);
	m_Frame->AddVisual(m_MeshBld);

	return TRUE;
}

//////////////////////////////////////////////////////////////////////////////////
// CRMShape SetColor
//////////////////////////////////////////////////////////////////////////////////
HRESULT CRMShape::SetColor(double r, double g, double b)
{
	return m_MeshBld->SetColorRGB(r, g, b);
}
