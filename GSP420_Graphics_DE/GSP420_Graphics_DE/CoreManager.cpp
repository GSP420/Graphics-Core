#include "Graphics.h"
#include <stdio.h>
#include <vector>

/*I can add more functions to the Core Manager but this is just an idea of mine of how I think the core manager could work.  If you have any other suggestion of how
we can go with this, please tell me or put in some suggestions of your own. 
*/

struct GameObject {

	Meshes m_mesh;
	D3DMATERIAL9* m_material;
	char* m_name;

	GameObject (ID3DXMesh* _mesh, D3DMATERIAL9* _mat, char* _name) {

		m_mesh.Model = _mesh; 
		m_material = _mat;
		m_name = _name; 

	}

};


/*struct GLighting {

	Lighting m_light;
	
}
*/



class CoreManager {

public:

	//std::vector<GameObject> graphics;
	const int numMeshes = 1; 
	GameObject* object[numMeshes];
	Text* text;
	Camera* cam; 


	void loadMesh(LPDIRECT3DDEVICE9 pD3DDevice) {

		
		for (int i=0; i < numMeshes; i++){
			LPCSTR name = object[i]->m_name;
			object[i]->m_mesh.load_meshes(name, pD3DDevice); 
		}
		 
	}

	void setMeshes(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scale) {

		for (int i=0; i < numMeshes; i++){
			object[i]->m_mesh.set_meshes(pos, rot, scale);
		}

	}

	void drawMesh(LPDIRECT3DDEVICE9 pD3DDevice) {

		for (int i=0; i < numMeshes; i++){
			object[i]->m_mesh.draw_meshes(pD3DDevice);
		}

	}

	void clearMesh() {

		for (int i=0; i < numMeshes; i++){
			object[i]->m_mesh.clear_meshes(); 
		}

	}

	void TextInit(DWORD size, LPDIRECT3DDEVICE9 device) {

		text->Init(size, device);

	}

	void SetText(char* string, int x, int y, int width, int height, D3DXCOLOR color){

		text->DisplayText(string, x, y, width, height, color); 

	}

	void CamInit(D3DXVECTOR3 _pos, D3DXVECTOR3 _look, D3DXVECTOR3 _up, float _fov, float _ar, float _nearClip, float _farClip) {

		cam->Init(_pos, _look, _up, _fov, _ar, _nearClip, _farClip);
	}




	CoreManager() {

	}

	~CoreManager() {

	}





};