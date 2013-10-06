#include "Graphics.h"
#include <stdio.h>
#include <vector>


struct GameObject {

	Meshes m_mesh;
	D3DMATERIAL9* m_material;
	char* m_name;

	GameObject (ID3DXMesh* _mesh, D3DMATERIAL9* _mat, char* _name);
};


/*struct GLighting {

	Lighting m_light;
	
}
*/



class CoreManager {

public:

	//std::vector<GameObject> graphics;
	//const int numMeshes = 1; 
	GameObject* object;
	Text* text;
	Camera* cam;
	DXManager manager;
	LightClass* lightbulb;


	void loadMesh(LPCSTR name);
	void setMeshes(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scale);
	//void drawMesh();
	void clearMesh();
	void TextInit(DWORD size);
	void SetText(char* string, int x, int y, int width, int height, D3DXCOLOR color);
	void CamInit(D3DXVECTOR3 _pos, D3DXVECTOR3 _look, D3DXVECTOR3 _up, float _fov, float _ar, float _nearClip, float _farClip);
	void SpotLight(D3DXVECTOR3 dir, D3DXVECTOR3 pos, D3DXCOLOR diffuseColor, D3DXCOLOR ambientColor);
	void DirectionalLight(D3DXVECTOR3 dir, D3DXCOLOR diffuseColor, D3DXCOLOR ambientColor);
	void PointLight(D3DXVECTOR3 pos, D3DXCOLOR diffuseColor, D3DXCOLOR ambientColor); 
	void DXInit(HWND hWnd, int width, int height, bool windowed);
	void Update();
	void BeginRender();
	void EndRender ();
	void DXPresent ();
	void Shutdown ();

	CoreManager() {

	}

	~CoreManager() {
		Shutdown();
	}


};
