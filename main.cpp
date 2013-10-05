
// Latisha's 381 Week 6 ilab
#include "settings.h"

#include <windows.h>
#include <stdio.h>
#include "Graphics.h"
#include "Text.h"
#include "DXManager.h"

#include MakePath(DXIncludePath, d3d9.h)
#include MakePath(DXIncludePath, d3dx9.h)

// macro for user input
#define KEY_DOWN(vk_code) ((GetAsyncKeyState(vk_code) & 0x8000) ? 1 : 0)

const char g_szClassName[] = "myWindowClass";
const char winTitle[] = "DirectX Demo";

HWND			hwnd;
HINSTANCE       hInstance;                          // Holds The Instance Of The Application

int width = 800;
int height = 600;

int Width = 800;
int Height = 600;


LPD3DXFONT			pFont;

// DXManager to intialize and handle DX functions
DXManager DXMgr;

LPDIRECT3DVERTEXBUFFER9 pVB;

bool Wireframe = false;

float yAngle = 0;

int NumVertices = 6;

const int NumMeshes = 1;


Meshes dwarf;  

Camera Cam;
Camera Cam1;

Text gText;

void Init() {

	D3DXCreateFont(DXMgr.GetDevice(), 30, 0, FW_BOLD, 0, false, 
                  DEFAULT_CHARSET, OUT_DEFAULT_PRECIS, DEFAULT_QUALITY,
                  DEFAULT_PITCH | FF_DONTCARE, TEXT("Times New Roman"), 
                  &pFont);

	Cam.Init();
	Cam.SetAR(Width, Height);
	Cam1.Init();
	Cam1.SetAR(Width, Height);

	gText.Init(18, DXMgr.GetDevice());

	// create/init vertex buffer
	DXMgr.GetDevice()->CreateVertexBuffer( NumVertices * sizeof(ColorVertex), 
		                           0, D3DFVF_XYZ | D3DFVF_NORMAL | D3DFVF_DIFFUSE, 
								   D3DPOOL_MANAGED, 
								   &pVB, 0);

	ColorVertex* pData;

	pVB->Lock(0, NumVertices * sizeof(ColorVertex), (void**)&pData, 0);

	pData[0].pos = D3DXVECTOR3(0, 0, 0);
	pData[0].normal = D3DXVECTOR3(0, 0, -1);
	pData[0].color =  D3DCOLOR_ARGB(255, 0, 0, 255);

	pData[1].pos = D3DXVECTOR3(10, 10, 0);
	pData[1].normal = D3DXVECTOR3(0, 0, -1);
	pData[1].color =  D3DCOLOR_ARGB(255, 0, 0, 255);

	pData[2].pos = D3DXVECTOR3(10, 0, 0);
	pData[2].normal = D3DXVECTOR3(0, 0, -1);
	pData[2].color =  D3DCOLOR_ARGB(255, 0, 0, 255);

	pData[3].pos = D3DXVECTOR3(0, 0, 0);
	pData[3].normal = D3DXVECTOR3(0, 0, -1);
	pData[3].color =  D3DCOLOR_ARGB(255, 0, 0, 255);

	pData[4].pos = D3DXVECTOR3(0, 10, 0);
	pData[4].normal = D3DXVECTOR3(0, 0, -1);
	pData[4].color =  D3DCOLOR_ARGB(255, 0, 0, 255);

	pData[5].pos = D3DXVECTOR3(10, 10, 0);
	pData[5].normal = D3DXVECTOR3(0, 0, -1);
	pData[5].color =  D3DCOLOR_ARGB(255, 0, 0, 255);

	pVB->Unlock();

	dwarf.load_meshes("Dwarf.x", DXMgr.GetDevice());  
	dwarf.pos.z = 10.0f;
	dwarf.pos.y = 8.0f;
}




void Update(float dt) {

	// check for user input
	if (KEY_DOWN(VK_LEFT)) {
		Cam1.pos.x = (Cam.pos.x += 0.05);
	}
	if (KEY_DOWN(VK_RIGHT)) {
		Cam1.pos.x = (Cam.pos.x -= 0.05);
	}
	if (KEY_DOWN(VK_UP)) {
		Cam1.pos.z = (Cam.pos.z += 0.1);
	}
	if (KEY_DOWN(VK_DOWN)) {
		Cam1.pos.z = (Cam.pos.z -= 0.1);
	}
	if (KEY_DOWN('W')) {
		Cam1.pos.y = (Cam.pos.y += 0.01);
	}
	if (KEY_DOWN('S')) {
		Cam1.pos.y = (Cam.pos.y -= 0.01);
	}

	if (KEY_DOWN('A')) {
		Cam1.Rotate(-0.5);
	}
	if (KEY_DOWN('D')) {
		Cam1.Rotate(0.5);
	}
	

	dwarf.rot.y += 0.1 * dt;
	if(dwarf.rot.y > 360) dwarf.rot.y = 0.0f;

	char str[128];
	sprintf(str, "Graphics Core");
	SetWindowText(hwnd, str);
}

void Render() {


	if (Wireframe) {
		DXMgr.GetDevice()->SetRenderState(D3DRS_FILLMODE, D3DFILL_WIREFRAME);
	}
	else {
		DXMgr.GetDevice()->SetRenderState(D3DRS_FILLMODE, D3DFILL_SOLID);
	}

	// set material
	D3DMATERIAL9 mat;
	ZeroMemory(&mat, sizeof(D3DMATERIAL9));
	mat.Ambient.r = 0;
	mat.Ambient.g = 0;
	mat.Ambient.b = 1;
	mat.Diffuse.r = 0;
	mat.Diffuse.g = 0;
	mat.Diffuse.b = 1;
	mat.Specular.r = 0;
	mat.Specular.g = 0;
	mat.Specular.b = 1;
	
	DXMgr.GetDevice()->SetMaterial(&mat);


	// set light
	D3DLIGHT9 light;
	ZeroMemory(&light, sizeof(D3DLIGHT9));
	light.Type = D3DLIGHT_DIRECTIONAL;
	light.Direction = D3DXVECTOR3(1, 0, 0);
	light.Diffuse.r = 1;
	light.Diffuse.g = 1;
	light.Diffuse.b = 1;
	DXMgr.GetDevice()->SetLight(0, &light);
	DXMgr.GetDevice()->LightEnable(0, true);

	DXMgr.BeginScene();

	Cam1.dxSetProjection(DXMgr.GetDevice());

	Cam1.dxSetView(DXMgr.GetDevice());

	DXMgr.BeginScene();

	
	dwarf.draw_meshes(DXMgr.GetDevice());



	char str[128];
	RECT rect;
	rect.left = 0;
	rect.top = 0;
	rect.right = 300;
	rect.bottom = 120;
	sprintf(str, "GSP 420 week 4");
	pFont->DrawText(NULL, str, -1, &rect,
			DT_TOP | DT_LEFT | DT_NOCLIP , D3DCOLOR_ARGB(255, 
			255, 
			255, 
			255));

	gText.DisplayText("This is printed from the Text class!", 10, 50, 50, 25, WHITE);

	DXMgr.EndScene();

	DXMgr.Present();


}

void Shutdown() {

	if (DXMgr.GetDevice()) 
	{
		DXMgr.Shutdown();
	}
}

// Step 4: the Window Procedure
LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	switch(msg)
	{
		case WM_MOUSEMOVE:
			{
				POINT pt;
				GetCursorPos(&pt);
				ScreenToClient(hwnd, &pt);
				break;

			}

		case WM_RBUTTONDOWN: 
			{
			}
		break;

		case WM_KEYDOWN:
			int fwKeys;
			LPARAM keyData;
			fwKeys = (int)wParam;    // virtual-key code 
			keyData = lParam;          // key data 

			switch(fwKeys)
			{

				case VK_ESCAPE:

					PostQuitMessage(0);
		                       
					break;

				case VK_SPACE:
					Wireframe = !Wireframe;
					break;
			}
			break;



		case WM_CLOSE:
		case WM_DESTROY:
			PostQuitMessage(0);
		break;
		default:
			return DefWindowProc(hwnd, msg, wParam, lParam);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE _hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	WNDCLASSEX wc;
	
	MSG Msg;

	hInstance = _hInstance;

	//Step 1: Registering the Window Class
	wc.cbSize		 = sizeof(WNDCLASSEX);
	wc.style		 = 0;
	wc.lpfnWndProc	 = WndProc;
	wc.cbClsExtra	 = 0;
	wc.cbWndExtra	 = 0;
	wc.hInstance	 = hInstance;
	wc.hIcon		 = LoadIcon(NULL, IDI_APPLICATION);
	wc.hCursor		 = LoadCursor(NULL, IDC_ARROW);
	wc.hbrBackground = (HBRUSH)(COLOR_WINDOW+1);
	wc.lpszMenuName  = NULL;
	wc.lpszClassName = g_szClassName;
	wc.hIconSm		 = LoadIcon(NULL, IDI_APPLICATION);

	if(!RegisterClassEx(&wc))
	{
		MessageBox(NULL, "Window Registration Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	// Step 2: Creating the Window
	hwnd = CreateWindowEx(
		WS_EX_CLIENTEDGE,
		g_szClassName,
		winTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT, width, height,
		NULL, NULL, hInstance, NULL);

	if(hwnd == NULL)
	{
		MessageBox(NULL, "Window Creation Failed!", "Error!",
			MB_ICONEXCLAMATION | MB_OK);
		return 0;
	}

	ShowWindow(hwnd, nCmdShow);
	UpdateWindow(hwnd);

	DXMgr.Init(hwnd, width, height, true);
	Init();

	float currTime, prevTime;
	float dt;

	currTime = prevTime = timeGetTime();

	// Step 3: The Message Loop
	while(true) {

		
		if (PeekMessage(&Msg,NULL,0,0,PM_REMOVE)) {

			if (Msg.message == WM_QUIT) {
				break;
			}
	
			TranslateMessage(&Msg);
			DispatchMessage(&Msg);
		}

		currTime = timeGetTime();
		dt = currTime - prevTime;

		Update(dt);

		Render();

		prevTime = currTime;

	}

	Shutdown();

	return Msg.wParam;
}
