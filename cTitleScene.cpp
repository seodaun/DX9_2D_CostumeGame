#include "stdafx.h"
#include "cTitleScene.h"
#include"cButton.h"
#include <windows.h> 
#include"cMouseCursor.h"
cTitleScene::cTitleScene()
{
}


cTitleScene::~cTitleScene()
{
	Release();
}

void cTitleScene::Init()
{
	BGM = true;
	EFFECT = true;
	isChangTime = false; 

	m_Mouse = new cMouseCursor();
	m_Mouse->Init();
	
	WndState = EMPTY_WND;

	MCI_OPEN_PARMS mciOpen;
	MCI_PLAY_PARMS mciPlay;

	mciOpen.lpstrDeviceType = L"WaveAudio";
	mciOpen.lpstrElementName = L"./Sound/BGM.wav";

	mciSendCommand(1, MCI_OPEN, MCI_OPEN_TYPE | MCI_OPEN_ELEMENT, (DWORD)(LPVOID)&mciOpen);
	mciSendCommand(1, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&mciPlay);

	m_TitleBgPos.x = 0;
	m_TitleBgPos.y = 0;
	m_StartButton = new cButton(320, 550, "Start");
	m_GameExitButton =	new cButton(590, 40, "Exit");
	m_option_button =	new cButton(520, 40, "Option");
	m_HowToPlay_button =new cButton(450, 40, "HowToPlay");
	m_StartButton->Init();
	m_GameExitButton->Init();
	m_option_button->Init();
	m_HowToPlay_button->Init();
	m_OptionWnd = new cButton(0, 0, "Option_wnd");
	m_OptionWnd->Init();
	m_BGM_off_btn = new cButton(450, 315, "option_BGM_Off");
	m_BGM_off_btn->Init();
	m_BGM_on_btn = new cButton(300, 315, "option_BGM_On");
	m_BGM_on_btn->Init();
	m_Effect_off_btn = new cButton(300, 435, "option_effect_Off");
	m_Effect_off_btn->Init();
	m_Effect_on_btn = new cButton(450, 435, "option_effect_On");
	m_Effect_on_btn->Init();
	m_HowToPlay_wnd = new cButton(0, 0, "HelpWnd");
	m_HowToPlay_wnd->Init();
	m_Wnd_Exit_btn = new cButton(400, 200, "Exit");
	m_Wnd_Exit_btn->Init();
	chkOption = false;
	chkHow = false;
}
 
void cTitleScene::Update()
{
	MousePoint.x = INPUT->GetMousePos().x;
	MousePoint.y = INPUT->GetMousePos().y;

	m_Mouse->Update(MousePoint);

	if (EFFECT) {
		if (INPUT->MouseLDown())
			PlaySound(TEXT("./Sound/Clickeffect.wav"), NULL, SND_ASYNC);
	}
	
	
 
	if (m_option_button->Update()) {
		chkOption = true;
	}
	if (m_HowToPlay_button->Update()) {
		chkHow = true;
	}
	if (m_BGM_off_btn->Update() && chkOption) {//옵션창 버튼
		mciSendCommand(1, MCI_STOP, MCI_DGV_PLAY_REPEAT, NULL);
		BGM = false;
	}
	else if (m_BGM_on_btn->Update() && chkOption) {
		mciSendCommand(1, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&mciPlay);
		BGM = true;
		EFFECT = true;
	}
	else if (m_Effect_off_btn->Update() && chkOption) {
		EFFECT = true;
	}
	else if (m_Effect_on_btn->Update() && chkOption) {
		EFFECT = false;
	}
	if ((chkOption || chkHow) && m_Wnd_Exit_btn->Update()) {
		chkOption = false;
		chkHow = false;
	}
	else if (chkOption&&m_HowToPlay_wnd->_Update()) {
	}
	else if (chkHow&&m_OptionWnd->_Update()) {}
	
	
	else if (m_StartButton->Update()) {
		int m_nConcept;
		isChangTime = true;
		m_nConcept = rand() % 4;
		SCENE->ChangeScene("InGame");
	}	
	else if (m_GameExitButton->Update()) {
		PostQuitMessage(0);
	}
}

void cTitleScene::Render()
{
	//이미지 출력 방법 : cLoadScene에서 추가한 이미지를 사용한다.
	//IMAGE->FindImage("이름")을 하여 이미지를 찾을 수 있다.
	//IMAGE->Render(이미지, 좌표, true = 이미지의 중심을 중앙으로 설정, 제거할 컬러키);

	IMAGE->Render(IMAGE->FindImage("TitleBg"), m_TitleBgPos, false);
	//IMAGE->Render(IMAGE->FindImage("Game_Logo"), m_TitleBgPos, false,RGB(255,0,255));

	//IMAGE->Render(IMAGE->FindImage("MouseTest"), MousePoint, true, RGB(255, 0, 255));

	m_StartButton->Render();
	m_GameExitButton->Render();
	m_option_button->Render();
	m_HowToPlay_button->Render();
	
	if (chkOption) {
		m_OptionWnd->_Render();
		m_BGM_off_btn->Render();
		m_BGM_on_btn->Render();
		m_Effect_on_btn->Render();
		m_Effect_off_btn->Render();
		m_Wnd_Exit_btn->Render();
	}
	if (chkHow) { 
		m_HowToPlay_wnd->_Render();
		m_Wnd_Exit_btn->Render();
	}
	m_Mouse->Render(MousePoint);
}












void cTitleScene::Release()
{
	SAFE_DELETE(m_Mouse);
	SAFE_DELETE(m_OptionWnd);
	SAFE_DELETE(m_Wnd_Exit_btn);
	SAFE_DELETE(m_HowToPlay_wnd);
	SAFE_DELETE(m_StartButton);
	SAFE_DELETE(m_GameExitButton);
	SAFE_DELETE(m_option_button);
	SAFE_DELETE(m_HowToPlay_button);
	SAFE_DELETE(m_Window);
	SAFE_DELETE(m_BGM_off_btn);
	SAFE_DELETE(m_BGM_on_btn);
	SAFE_DELETE(m_Effect_on_btn);
	SAFE_DELETE(m_Effect_off_btn);
}
