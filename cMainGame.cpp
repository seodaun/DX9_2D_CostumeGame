#include "stdafx.h"
#include "cMainGame.h"

#include "cLoadScene.h"
#include "cIngameScene.h"
#include"cTitleScene.h"
#include"cMainScene.h"
#include"cShopScene.h" 
cMainGame::cMainGame()
{
}


cMainGame::~cMainGame()
{
	Release();
}

void cMainGame::Init(HWND hWnd)
{
	m_hWnd = hWnd;

	m_hDC = GetDC(m_hWnd);

	//m_hBackBuffer = CreateCompatibleDC(m_hDC);
	//m_hBitmap = LoadBitmap(m_hIns, MAKEINTRESOURCE(m_hBackBuffer));//CreateCompatibleBitmap(m_hDC, D_SCREEN_WIDTH, D_SCREEN_HEIGHT);
	//SelectObject(m_hBackBuffer, (HBITMAP)m_hBitmap);
	//ReleaseDC(m_hWnd, m_hDC);

	//SetTimer(m_hWnd, 0, 10, NULL);

	SetTimer(m_hWnd, 0, 1000, NULL);

	IMAGE->Init();

	//Init ���� Scene�� �߰������ش� ������� �̸�, Scene Ŭ����
	SCENE->AddScene("Load", new cLoadScene);
	SCENE->AddScene("Title", new cTitleScene);
	SCENE->AddScene("InGame", new cIngameScene);
	SCENE->AddScene("MainGame", new cMainScene);
	SCENE->AddScene("Shop", new cShopScene); 

	//SCENE->AddScene("MainGame", new MainGame);
	
	//�뷡 ư��
	//PlaySound(TEXT("./Sound/BGM.wav"), NULL, SND_ASYNC|SND_LOOP);
	
	//ó������ ������ ������ �ٲ۴�
	SCENE->ChangeScene("Load");
}

void cMainGame::Update()
{

	SCENE->Update();
	INPUT->Update(); 
}

void cMainGame::Render()
{
	//HDC hdc = GetDC(m_hWnd);
	HDC m_MemDC;
	HBITMAP hBitmap;
	HBITMAP OldBitMap;

	RECT WindowRect;
	GetClientRect(m_hWnd, &WindowRect);

	m_MemDC = CreateCompatibleDC(m_hDC);
	hBitmap = CreateCompatibleBitmap(m_hDC, WindowRect.right, WindowRect.bottom);
	OldBitMap = (HBITMAP)SelectObject(m_MemDC, hBitmap);


	IMAGE->InputHDC(m_MemDC);
	SCENE->Render();

	BitBlt(m_hDC, 0, 0, WindowRect.right, WindowRect.bottom, m_MemDC, 0, 0, SRCCOPY);
	DeleteObject(SelectObject(m_MemDC, OldBitMap));
	DeleteDC(m_MemDC);

}

void cMainGame::Release()
{ 
	
	KillTimer(m_hWnd, 0);

	cImageManager::ResetInstance();
	cInputManager::ResetInstance();
	cSceneManager::ResetInstance(); 
}

void cMainGame::InputHDC(HDC hdc)
{
	m_hDC = hdc;
}

void cMainGame::InputHINSTANCE(HINSTANCE hinstance)
{
	m_hIns = hinstance;
}
