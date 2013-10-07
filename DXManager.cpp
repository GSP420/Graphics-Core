//////////////////////////////////////////////////
// File name: DXManager.cpp
// Author: David Emerson
// Description:
//

#include "DXManager.h"

DXManager::DXManager()
{
	pD3DObject = NULL;
	pD3DDevice = NULL;
}

DXManager::~DXManager()
{
	// Call shutdown function in case it was not already called
	Shutdown();
}

void DXManager::Init(HWND hWnd, int width, int height, bool windowed)
{
	pD3DObject = Direct3DCreate9(D3D_SDK_VERSION);

	d3dpp.BackBufferCount = 1;
	d3dpp.BackBufferFormat = D3DFMT_X8R8G8B8;
	d3dpp.BackBufferWidth = width;
	d3dpp.BackBufferHeight = height;
	d3dpp.Windowed = windowed;
	d3dpp.hDeviceWindow = hWnd;
	d3dpp.SwapEffect = D3DSWAPEFFECT_DISCARD;
	d3dpp.MultiSampleType = D3DMULTISAMPLE_NONE;
	d3dpp.MultiSampleQuality = 0;
	d3dpp.EnableAutoDepthStencil = true;
	d3dpp.AutoDepthStencilFormat = D3DFMT_D24S8;
	d3dpp.Flags = 0;
	d3dpp.FullScreen_RefreshRateInHz = D3DPRESENT_RATE_DEFAULT;
	d3dpp.PresentationInterval = D3DPRESENT_INTERVAL_IMMEDIATE;

	// Create D3D Device
	pD3DObject->CreateDevice(
		D3DADAPTER_DEFAULT,
		D3DDEVTYPE_HAL,
		hWnd,
		D3DCREATE_SOFTWARE_VERTEXPROCESSING,
		&d3dpp,
		&pD3DDevice);

	// Set render states
	pD3DDevice->SetRenderState(D3DRS_LIGHTING, true);
	pD3DDevice->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	pD3DDevice->SetRenderState(D3DRS_AMBIENT, D3DCOLOR_XRGB(100, 100, 100) );
}

void DXManager::BeginScene()
{
	// If device not created successfully, return
	if(!pD3DDevice)
		return;

	// Clear the backbuffer
	pD3DDevice->Clear(0, 0, 
		D3DCLEAR_TARGET | D3DCLEAR_ZBUFFER, 
		D3DXCOLOR(0.1f, 0.1f, 0.1f, 1.0f), 1.0f, 0);

	// Begin the render scene
	pD3DDevice->BeginScene();
}

void DXManager::EndScene()
{
	pD3DDevice->EndScene();
}

void DXManager::Present()
{
	pD3DDevice->Present(0, 0, 0, 0);
}

void DXManager::Shutdown()
{
	SAFE_RELEASE(pD3DDevice);
	SAFE_RELEASE(pD3DObject);
}

//void DXManager::UpdateDevice(LPDIRECT3DDEVICE9 tempDevice)
//{
//	pD3DDevice = tempDevice;
//}