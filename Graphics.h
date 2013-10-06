//////////////////////////////////////////////////////
// File name: Graphics.h
// Author: Latisha Harris and David Emerson
// Description: Holds material parameters and texture
//				information for 3D surfaces, and 
//				Meshes/Camera varables and functions.
//////////////////////////////////////////////////////

#pragma once

#include <windows.h>
#include "settings.h"
#include "Camera.h"
#include "Material.h"
#include "Meshes.h"
#include "Text.h"
#include "DXManager.h"
#include "LightClass.h"


#include MakePath(DXIncludePath, d3d9.h)
#include MakePath(DXIncludePath, d3dx9.h)

/*struct ColorVertex
{
    D3DXVECTOR3 pos;
    D3DXVECTOR3 normal;
    D3DCOLOR color;
	static IDirect3DVertexDeclaration9* Decl;
};*/
