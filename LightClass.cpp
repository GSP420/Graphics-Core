
#include "LightClass.h"
#include "CoreManager.h"



void LightClass::createDirectionLight(LPDIRECT3DDEVICE9 device, D3DXVECTOR3 dir, D3DXCOLOR diffuseColor, D3DXCOLOR ambientColor)
{
	//ZeroMemory( &light, sizeof(D3DLIGHT9) );
	// Create and turn on a directional m_light

	// Set the type of m_light
	m_light.Type = D3DLIGHT_DIRECTIONAL;


	// Normalize the m_light direction
	D3DXVec3Normalize((D3DXVECTOR3*) &m_light.Direction, &dir);

	// Set the diffuse color for this m_light
	m_light.Diffuse = diffuseColor;

	//Set the ambient colot for this m_light
	m_light.Ambient = ambientColor;

	//Set the range of this m_light
	m_light.Range		= sqrt(FLT_MAX);

	// Tell Direct3D to set the newly created m_light
	device->SetLight (0, &m_light);

	// Enable the new m_light
	device->LightEnable (0, TRUE);
}

void LightClass::createPointLight(LPDIRECT3DDEVICE9 device, D3DXVECTOR3 pos, D3DXCOLOR diffuseColor, D3DXCOLOR ambientColor)
{	

	//ZeroMemory( &light, sizeof(D3DLIGHT9) );
	// Set the type of m_light
	m_light.Type = D3DLIGHT_POINT;

	// Set the position of the m_light
	m_light.Position = pos;

	// Set the diffuse color for this m_light
	m_light.Diffuse = diffuseColor;

	//Set the ambient colot for this m_light
	m_light.Ambient = ambientColor;

	//Set the range of this m_light
	m_light.Range		= sqrt(FLT_MAX);

	// Tell Direct3D to set the newly created m_light
	device->SetLight (0, &m_light);

	// Enable the new m_light
	device->LightEnable (0, TRUE);
}

void LightClass::createSpotlight(LPDIRECT3DDEVICE9 device, D3DXVECTOR3 dir, D3DXVECTOR3 pos, D3DXCOLOR diffuseColor, D3DXCOLOR ambientColor)
{
	//ZeroMemory( &light, sizeof(D3DLIGHT9) );
	// Set the type of m_light
	m_light.Type = D3DLIGHT_SPOT;

	// Set direction m_light is pointing
	D3DXVec3Normalize((D3DXVECTOR3*)&m_light.Direction, &dir);

	// Set the position of the m_light
	m_light.Position = pos;

	// Set the diffuse color for this m_light
	m_light.Diffuse = diffuseColor;

	//Set the ambient colot for this m_light
	m_light.Ambient = ambientColor;

	//Set the range of this m_light
	m_light.Range		= sqrt(FLT_MAX);

	// Tell Direct3D to set the newly created m_light
	device->SetLight (0, &m_light);

	// Enable the new m_light
	device->LightEnable (0, TRUE);
}

void LightClass::disableLight(LPDIRECT3DDEVICE9 device)
{
	device->SetLight (0, NULL);
	device->LightEnable (0, FALSE);
}

void LightClass::enableLight(LPDIRECT3DDEVICE9 device)
{
	device->SetLight (0, &m_light);
	device->LightEnable (0, TRUE);
}