#include "stdafx.h"
#include "cStoreWnd.h"
#include"cButton.h"

cStoreWnd::cStoreWnd(int x, int y, const string & key)
{
	m_Window = IMAGE->FindImage(key);
	m_Pos.x = x;
	m_Pos.y = y;
}


cStoreWnd::~cStoreWnd()
{
	Release();
}

void cStoreWnd::Init()
{
	m_Exit_btn = new cButton(500, 200, "WndExit");
	m_Exit_btn->Init();

	m_Upgrade_No = new cButton(200, 600, "GameExit_No");
	m_Upgrade_No->Init();

	m_Upgrade_Yes = new cButton(400, 600, "GameExit_Yes");
	m_Upgrade_Yes->Init();
}




void cStoreWnd::Update()
{
	if (bClickChk) {
		Init();
		bClickChk = false;
	}
	if (!bClickChk) { 
		if (m_Exit_btn->Update()) {
			Release();
			//TextOut(hdc, 100, 100, L"money", 15);
			bClickChk = true;
			SCENE->ChangeScene("InGame");
		}
		else if (m_Upgrade_No->Update()) {
			DEBUG_LOG("UPGRADE NO!");
			//업그레이드 조건 넣어줌
		}
		else if (m_Upgrade_Yes->Update()) {
			DEBUG_LOG("UPGRADE YES!");
			//업그레이드 조건 넣어줌
		}
	}

}

void cStoreWnd::Render()
{
	if (!bClickChk) {
		IMAGE->Render(m_Window, m_Pos, true, RGB(255, 0, 255));
		m_Exit_btn->Render();
		m_Upgrade_No->Render();
		m_Upgrade_Yes->Render();
	}
	IMAGE->PrintTexture("Money =" + to_string(Money), { 300 , 300 });
}

void cStoreWnd::Release()
{

	SAFE_DELETE(m_Exit_btn);
	SAFE_DELETE(m_Upgrade_No);
	SAFE_DELETE(m_Upgrade_Yes);

}