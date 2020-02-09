#include "stdafx.h"
#include "cGameExitWnd.h"
#include"cButton.h"
#include"cWindow.h"
cGameExitWnd::cGameExitWnd(int x, int y, const string & key)
{
	m_Window = IMAGE->FindImage(key);
	m_Pos.x = x;
	m_Pos.y = y;
}


cGameExitWnd::~cGameExitWnd()
{
	Release();
}

void cGameExitWnd::Init()
{
	m_ExitNo = new cButton(300, 500, "GameExit_No");
	m_ExitNo->Init();
	m_ExitYes = new cButton(500, 500, "GameExit_Yes");
	m_ExitYes->Init();
	m_Exit_btn = new cButton(500, 200, "WndExit");
	m_Exit_btn->Init();

}

void cGameExitWnd::Update()
{
	if (bClickChk) {
		Init();
		bClickChk = false;
	}

	if (m_ExitYes->Update()) {
		PostQuitMessage(0);
	}

	if (m_Exit_btn->Update() | m_ExitNo->Update()) {
		Release();
		bClickChk = true;
		SCENE->ChangeScene("InGame");
	}

}

void cGameExitWnd::Render()
{
	if (!bClickChk)
	{
		IMAGE->Render(m_Window, m_Pos, true, RGB(255, 0, 255));
		m_Exit_btn->Render();
	}
}

void cGameExitWnd::Release()
{
	SAFE_DELETE(m_Exit_btn);
	SAFE_DELETE(m_ExitNo);
	SAFE_DELETE(m_ExitYes);

}
