///////////////////////////////////////////////////////
// File name: DXManager.h
// Author: David Emerson
// Description: Initializes Direct3D object and device
// and provides functions to begin and end the render
// scene and present the backbuffer

#pragma once

#include "Graphics.h"

class DXManager
{
private:
	IDirect3D9* pD3DObject;
	IDirect3DDevice9* pD3DDevice;
	D3DPRESENT_PARAMETERS d3dpp;
public:

	DXManager();
	~DXManager();

	void Init(HWND hWnd, int width, int height, bool windowed);
	void BeginScene();
	void EndScene();
	void Present();
	void Shutdown();

	// Returns a pointer to the Direct3D Device
	LPDIRECT3DDEVICE9 GetDevice() const {return pD3DDevice;}
};
