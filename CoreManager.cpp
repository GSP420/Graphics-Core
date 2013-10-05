
#include "CoreManager.h"


/*I can add more functions to the Core Manager but this is just an idea of mine of how I think the core manager could work.  If you have any other suggestion of how
we can go with this, please tell me or put in some suggestions of your own. 
*/

GameObject::GameObject (ID3DXMesh* _mesh, D3DMATERIAL9* _mat, char* _name) {

		m_mesh.Model = _mesh; 
		m_material = _mat;
		m_name = _name; 

}



void CoreManager::loadMesh(LPCSTR name) {
			
		name = object->m_name;
		object->m_mesh.load_meshes(name, manager->GetDevice()); 
		 
}

void CoreManager::setMeshes(D3DXVECTOR3 pos, D3DXVECTOR3 rot, D3DXVECTOR3 scale) {

		object->m_mesh.set_meshes(pos, rot, scale);

}

/*void CoreManager::drawMesh() {

		object->m_mesh.draw_meshes(manager->GetDevice());

}
*/

void CoreManager::clearMesh() {

		object->m_mesh.clear_meshes(); 

}

void CoreManager::TextInit(DWORD size) {

		
		text->Init(size, manager->GetDevice());

}

void CoreManager::SetText(char* string, int x, int y, int width, int height, D3DXCOLOR color){

		text->DisplayText(string, x, y, width, height, color); 

}

void CoreManager::CamInit(D3DXVECTOR3 _pos, D3DXVECTOR3 _look, D3DXVECTOR3 _up, float _fov, float _ar, float _nearClip, float _farClip) {

		cam->Init(_pos, _look, _up, _fov, _ar, _nearClip, _farClip);
}

void CoreManager::DXInit(HWND hWnd, int width, int height, bool windowed) {

		manager->Init(hWnd, width, height, windowed);

}

void CoreManager::Update() {


}


void CoreManager::BeginRender() {

		manager->BeginScene();

}

void CoreManager::EndRender () {

		manager->EndScene(); 

}

void CoreManager::DXPresent (){

		manager->Present();

}

void CoreManager::Shutdown () {

		manager->Shutdown();

}

