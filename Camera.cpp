
#include "Camera.h"


Camera::Camera()
{
		pos  = D3DXVECTOR3(0, 10, -20);
		look = D3DXVECTOR3(0, 5, 0);
		up   = D3DXVECTOR3(0, 1, 0);
}
Camera::~Camera()
{
}

void Camera::Init()
{
		pos = D3DXVECTOR3(0, 10, 0);
		look = D3DXVECTOR3(0, 10, 1);
		up = D3DXVECTOR3(0, 1, 0);

		fov = 50;

		ar = 1.0;				// needs to be reset!

		nearClip = 1.0;
		farClip = 1000.0;
}

void Camera::Init(D3DXVECTOR3 _pos, D3DXVECTOR3 _look, D3DXVECTOR3 _up, float _fov, float _ar, float _nearClip, float _farClip)
{
		pos = D3DXVECTOR3(0, 10, 0);
		look = D3DXVECTOR3(0, 10, 1);
		up = D3DXVECTOR3(0, 1, 0);

		fov = 50;

		ar = 1.0;				// needs to be reset!

		nearClip = 1.0;
		farClip = 1000.0;
}

void Camera::SetAR(int wd, int ht)
{

	ar = (float)wd / (float)ht;
}

void Camera::dxGetProjection(D3DXMATRIX* pm)
{
	//Here we specify the field of view, aspect ratio and near and far clipping planes.
		D3DXMatrixPerspectiveFovLH(
			pm,
			fov * D3DX_PI/180.0, 
			ar, 
			nearClip,
			farClip);
}

void Camera::dxSetProjection(LPDIRECT3DDEVICE9 pd3dDevice) 
{
		D3DXMATRIX p;
		
		//Here we specify the field of view, aspect ratio and near and far clipping planes.
		D3DXMatrixPerspectiveFovLH(
			&p, 
			fov * D3DX_PI/180.0, 
			ar, 
			nearClip,
			farClip);

		pd3dDevice->SetTransform(D3DTS_PROJECTION, &p);

}

void Camera::dxSetView(LPDIRECT3DDEVICE9 pd3dDevice)
{

		D3DXMATRIX v;

		D3DXMatrixLookAtLH(
			&v, 
			&pos,
			&look, 
			&up  );
			

		pd3dDevice->SetTransform(D3DTS_VIEW, &v);
}

void Camera::dxGetView(D3DXMATRIX* pm) 
{

		D3DXMatrixLookAtLH(
			pm, 
			&pos,
			&look, 
			&up  );
			
}

void Camera::MoveForward(float distance) 
{
		D3DXVECTOR3 fwd = look - pos;
		D3DXVec3Normalize(&fwd, &fwd);

		pos = pos + fwd * distance;
		look = look + fwd * distance;
}

void Camera::Strafe(char dir) 
{
			D3DXVECTOR3 camDir;
			D3DXVECTOR3 upVec = D3DXVECTOR3(0.0f, 1.0f, 0.0f);

			camDir = look - pos;
			D3DXVec3Normalize(&camDir, &camDir);
			// calculate the cross product
			D3DXVec3Cross(&camDir, &camDir, &upVec);
			//normalize the camDir vector
			D3DXVec3Normalize(&camDir, &camDir);


			if (dir = 'L')
			{
				pos +=  camDir * 0.75;
				look +=  camDir * 0.75;
			}
			else
				pos -=  camDir * 0.75;
				look -=  camDir * 0.75; 
}

void Camera::Rotate(float angle) {
		        D3DXMATRIX ry;
                D3DXVECTOR4 result;
                D3DXVECTOR3 camDir;
                
                camDir = look - pos;
	            D3DXMatrixRotationY(&ry, D3DXToRadian(angle)); 

                D3DXVec3Transform(&result, &camDir, &ry);
                look = pos + D3DXVECTOR3(result.x, result.y, result.z);
	}	