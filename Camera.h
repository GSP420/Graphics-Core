#ifndef CAMERA_H
#define CAMERA_H

#include "settings.h"
#include <d3d9.h>
#include <d3dx9.h>

class Camera {
public:
	Camera();
	~Camera();


	D3DXVECTOR3		pos, look, up;
	float		fov;
	float		ar;
	float		nearClip, farClip;


	void Init();
	void Init(D3DXVECTOR3 _pos, D3DXVECTOR3 _look, D3DXVECTOR3 _up, float _fov, float _ar, float _nearClip, float _farClip);
	void SetAR(int wd, int ht);
	void dxGetProjection(D3DXMATRIX* pm);
	void dxSetProjection(LPDIRECT3DDEVICE9 pd3dDevice);
	void dxSetView(LPDIRECT3DDEVICE9 pd3dDevice);
	void dxGetView(D3DXMATRIX* pm);
	void MoveForward(float distance);
	void Strafe(char dir);
	void Rotate(float angle);

};

#endif