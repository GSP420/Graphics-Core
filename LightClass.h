
#pragma once

#include "settings.h"
#include <d3d9.h>
#include <d3dx9.h>

class LightClass
{
	D3DLIGHT9 m_light;

	LightClass();
	~LightClass();

public:
	void createDirectionLight(LPDIRECT3DDEVICE9 &device, D3DXVECTOR3 dir, D3DXCOLOR diffuseColor, D3DXCOLOR ambientColor);
	void createPointLight(LPDIRECT3DDEVICE9 &device, D3DXVECTOR3 pos, D3DXCOLOR diffuseColor, D3DXCOLOR ambientColor);
	void createSpotlight(LPDIRECT3DDEVICE9 &device, D3DXVECTOR3 dir, D3DXVECTOR3 pos, D3DXCOLOR diffuseColor, D3DXCOLOR ambientColor);\
	void disableLight(LPDIRECT3DDEVICE9 &device);
	void enableLight(LPDIRECT3DDEVICE9 &device);
};