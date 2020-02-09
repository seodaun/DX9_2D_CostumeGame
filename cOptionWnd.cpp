#include "stdafx.h"
#include "cOptionWnd.h"
#include"cButton.h"
#include"cWindow.h"
cOptionWnd::cOptionWnd(int x, int y, const string & key)
{
	m_Window = IMAGE->FindImage(key);
	m_Pos.x = x;
	m_Pos.y = y; 
}


cOptionWnd::~cOptionWnd()
{
	Release();
}

void cOptionWnd::Init()
{
	m_BGMOFF = new cButton(280, 320, "option_BGM_On");
	m_BGMOFF->Init();
	m_BGMON = new cButton(360, 320, "option_BGM_Off");
	m_BGMON->Init();
	//m_SoundON = new cButton()

	m_Exit_btn = new cButton(500, 200, "WndExit");
	m_Exit_btn->Init();
}

void cOptionWnd::Update()
{
	if (bClickChk) {
		Init();
		bClickChk = false;
	}
	if (!bClickChk) {
		if (m_BGMOFF->Update()) {
			mciSendCommand(1, MCI_STOP, MCI_DGV_PLAY_REPEAT, NULL);
			BGM = false;
			EFFECT = false;
		}
		if (m_BGMON->Update()) {
			mciSendCommand(1, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&mciPlay);
			BGM = true;
			EFFECT = true;
		}
		if (m_Exit_btn->Update()) {

			bClickChk = true;
			SCENE->ChangeScene("InGame");
		}
	}
}

void cOptionWnd::Render()
{
	if (!bClickChk) {
		IMAGE->Render(m_Window, m_Pos, true, RGB(255, 0, 255));
		m_BGMOFF->Render();
		m_BGMON->Render();
		m_Exit_btn->Render();
	}
}

void cOptionWnd::Release()
{
	SAFE_DELETE(m_BGMOFF);
	SAFE_DELETE(m_BGMON);
	SAFE_DELETE(m_Exit_btn);
}
