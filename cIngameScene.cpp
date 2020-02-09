#include "stdafx.h"
#include "cIngameScene.h"
#include "cButton.h"
#include "cOrderBox.h"
#include <stdlib.h>

//bool first = true;

cIngameScene::cIngameScene()
{
}


cIngameScene::~cIngameScene()
{
	Release();
}

void cIngameScene::Init()
{


	size = 0;
	kindC = "M_1";
	bClickOrder = false;
	bClickOption = false;
	bClickHow = false;
	isChangTime = true;
	m_ChangePos.x = 320;
	m_ChangePos.y = 450;
	OrderBoxPos.x = 320;
	OrderBoxPos.y = 280;

	m_Mouse = new cMouseCursor();
	m_Mouse->Init();


	srand((unsigned)time(NULL));
	m_BackGroundPos.x = 0;
	m_BackGroundPos.y = 0;
	Pos.x = 473;
	Pos.y = 106;

	CommentPos.x = 23;
	CommentPos.y = 740;
	CommentPos2.x = 23;
	CommentPos2.y = 850;

	ShowPageButtonPos.x = 280;
	ShowPageButtonPos.y = 700;


	CommentPos_1.x = 100;
	CommentPos_1.y = 750;

	CommentPos_2.x = 100;
	CommentPos_2.y = 860;
	WndState = EMPTY_WND;
	//m_Exit_Button = new cButton(100, 500, "Exit");
	//m_Exit_Button->Init();
	m_Notice_button = new cButton(140, 130, "Notice");
	m_Notice_button->Init();

	m_goshop = new cButton(50, 130, "GoShop");
	m_goshop->Init();

	m_Option_button = new cButton(520, 40, "Option");
	m_Option_button->Init();

	m_HowToPlay_button = new cButton(450, 40, "HowToPlay");
	m_HowToPlay_button->Init();

	m_GameExitButton = new cButton(590, 40, "Exit");
	m_GameExitButton->Init();

	m_Page_Button1 = new cButton(280, 700, "PageUp");
	m_Page_Button1->Init();

	m_Page_Button2 = new cButton(320, 700, "PageUp");//40씩 차이남
	m_Page_Button2->Init();

	m_Page_Button3 = new cButton(360, 700, "PageUp");
	m_Page_Button3->Init();

	m_OrderList = new cButton(0, 0, "OrderList");
	m_OrderList->Init();
	m_Wnd_Exit_btn = new cButton(400, 200, "Exit");
	m_Wnd_Exit_btn->Init();
	m_OptionWnd = new cButton(0, 0, "Option_wnd");
	m_OptionWnd->Init();

	m_BGM_off_btn = new cButton(450, 315, "option_BGM_Off");
	m_BGM_off_btn->Init();
	m_BGM_on_btn = new cButton(300, 315, "option_BGM_On");
	m_BGM_on_btn->Init();
	m_Effect_off_btn = new cButton(300, 435, "option_effect_On");
	m_Effect_off_btn->Init();
	m_Effect_on_btn = new cButton(450, 435, "option_effect_Off");
	m_Effect_on_btn->Init();
	m_HowToPlay_wnd = new cButton(0, 0, "HelpWnd");
	m_HowToPlay_wnd->Init();
	if (lt.size() != size) {
		size = lt.size();
		vector<cOrderBox*>::iterator iter = vOrder.begin();
		vector<cOrderBox*>::iterator endIer = vOrder.end();
		for (; iter != vOrder.end(); ++iter)
		{
			delete (*iter);
		}
		vOrder.clear();
		int a = 0;
		for (auto iter = lt.begin(); iter != lt.end(); ++iter) {
			vOrder.push_back(new cOrderBox(320, 300 + (a * 90), *iter));
			a++;
		}
	}


	//isGame = false;
	//Result_temp = NULL;


}

void cIngameScene::Update()
{
	MousePoint.x = INPUT->GetMousePos().x;
	MousePoint.y = INPUT->GetMousePos().y;
	m_Mouse->Update(MousePoint);

	char a[128];
	if (m_Page_Button1->Update()) {
		count = 1;
		ShowPageButtonPos.x = 280;
		sprintf_s(a, "M_%d", count);
		kindC = a;
	}
	if (m_Page_Button2->Update()) {
		count = 2;
		ShowPageButtonPos.x = 320;
		sprintf_s(a, "M_%d", count);
		kindC = a;
	}
	if (m_Page_Button3->Update()) {
		count = 3;
		ShowPageButtonPos.x = 360;
		sprintf_s(a, "M_%d", count);
		kindC = a;
	}
	if (CKchangTime) {//배경에서 이미지 바뀌는 코드 넣어야 함
		CKchangTime = false;
		count += 1;
		if (count > 3) count = 1;
		sprintf_s(a, "M_%d", count);
		kindC = a;
		ShowPageButtonPos.x += 40;
		if (ShowPageButtonPos.x > 360) ShowPageButtonPos.x = 280;
	}

	if (EFFECT) {
		if (INPUT->MouseLDown())
			PlaySound(TEXT("./Sound/Clickeffect.wav"), NULL, SND_ASYNC);//클릭 효과음
	}
	if ((bClickOption || bClickOrder || bClickHow) && m_Wnd_Exit_btn->Update()) {
		bClickOrder = false;
		bClickOption = false;
		bClickHow = false;
	}
	else if (bClickOption&&m_OptionWnd->_Update()) {}	//다른 버튼 클릭 x
	else if (bClickOrder&&m_OrderList->_Update()) {
		if (lt.size() != size) {
			size = lt.size();
			vector<cOrderBox*>::iterator iter = vOrder.begin();
			vector<cOrderBox*>::iterator endIer = vOrder.end();
			for (; iter != vOrder.end(); ++iter) delete (*iter);
			vOrder.clear();
			int a = 0;
			for (auto iter = lt.begin(); iter != lt.end(); ++iter) {
				vOrder.push_back(new cOrderBox(320, 300 + (a * 90), *iter));
				a++;
			}
		}
		int a = 0;
		for (auto iter = vOrder.begin(); iter != vOrder.end(); iter++) {
			if ((*iter)->Update()) {
				ChangePos(a);
				nEXConcept = (*iter)->GetKey();
				GameNum = nEXConcept;
				SCENE->ChangeScene("MainGame");
			}
			else a++;
		}
	}	//다른 버튼 클릭 x
	else if (bClickHow&&m_OrderList->_Update()) {}		//다른 버튼 클릭 x

	else if (m_Notice_button->Update()) bClickOrder = true; //알림 버튼 클릭
	else if (m_Option_button->Update())bClickOption = true;				//옵션 버튼 클릭
	else if (m_HowToPlay_button->Update())bClickHow = true;				//도움말 버튼 클릭

	else if (m_goshop->Update()) SCENE->ChangeScene("Shop");
	else if (m_GameExitButton->Update()) PostQuitMessage(0);
	if (m_BGM_off_btn->Update() && bClickOption) {//옵션창 버튼
		mciSendCommand(1, MCI_STOP, MCI_DGV_PLAY_REPEAT, NULL);
		BGM = false;
	}

	else if (m_BGM_on_btn->Update() && bClickOption) {
		mciSendCommand(1, MCI_PLAY, MCI_DGV_PLAY_REPEAT, (DWORD)(LPVOID)&mciPlay);
		BGM = true;
	}
	else if (m_Effect_off_btn->Update()) {
		EFFECT = false;
	}
	else if (m_Effect_on_btn->Update()) {
		EFFECT = true;
	}
}
void cIngameScene::ChangePos(int i) {
	int a = 0;
	bool bStop = false;
	auto iter = lt.begin();
	while (iter != lt.end() && bStop == false) {
		if (a == i) {
			iter = lt.erase(iter++);
			bStop = true;
		}
		else if (a >= 5) {
			DEBUG_LOG("a오버");
		}
		else {
			a++;
			++iter;
		}
	}
}
void cIngameScene::Render()
{
	IMAGE->Render(IMAGE->FindImage("InGameBG"), m_BackGroundPos, false);
	IMAGE->Render(IMAGE->FindImage(kindC), m_ChangePos, true);
	IMAGE->Render(IMAGE->FindImage("MyMoney"), Pos, false, RGB(255, 0, 255));

	IMAGE->Render(IMAGE->FindImage("CommentWnd"), CommentPos, false, RGB(255, 0, 255));
	IMAGE->Render(IMAGE->FindImage("CommentWnd"), CommentPos2, false, RGB(255, 0, 255));

	m_Notice_button->Render();	//알림버튼 그림
	m_goshop->Render();//상점가는 버튼 
	m_GameExitButton->Render();
	m_HowToPlay_button->Render();
	m_Option_button->Render();
	m_Page_Button1->Render();
	m_Page_Button2->Render();
	m_Page_Button3->Render();

	IMAGE->PrintTexture("" + to_string(Money), { Pos.x - 50 , Pos.y + 15 });
	IMAGE->Render(IMAGE->FindImage("PageDown"), ShowPageButtonPos, true, RGB(255, 0, 255));
	if (bClickOrder) {	//주문버튼
		OrderBoxRender();
	}
	if (bClickOption) { //옵션 버튼 누를 경우
		m_OptionWnd->_Render();
		m_BGM_off_btn->Render();
		m_BGM_on_btn->Render();
		m_Effect_on_btn->Render();
		m_Effect_off_btn->Render();
	}
	if (bClickHow) m_HowToPlay_wnd->_Render();//도움말 버튼

	if (bClickOrder || bClickOption || bClickHow) m_Wnd_Exit_btn->Render();//닫기 버튼


	if (isGame) {

		if (asdf == FIRST) {

			if (Result_temp == GOOD) {
				sprintf_s(buffer1, ("Comment%d_Good"), GameNum);
				Old_buffer1=buffer1;
				IMAGE->Render(IMAGE->FindImage(buffer1), CommentPos_1, false, RGB(255, 0, 255));
			}
			else if (Result_temp == BAD) {
				sprintf_s(buffer1, ("Comment%d_Bad"), GameNum);
				Old_buffer1 = buffer1;
				IMAGE->Render(IMAGE->FindImage(buffer1), CommentPos_1, false, RGB(255, 0, 255));
			}
		}

		if (asdf == SECOND) {

			if (Result_temp == GOOD) {
				sprintf_s(buffer2, ("Comment%d_Good"), GameNum);
				Old_buffer2 = buffer2;
				IMAGE->Render(IMAGE->FindImage(buffer2), CommentPos_2, false, RGB(255, 0, 255));
			}
			else if (Result_temp == BAD) {
				sprintf_s(buffer2, ("Comment%d_Bad"), GameNum);
				Old_buffer2 = buffer2;
				IMAGE->Render(IMAGE->FindImage(buffer2), CommentPos_2, false, RGB(255, 0, 255));
			}
		}

		if (old == FIRST) {
			IMAGE->Render(IMAGE->FindImage(Old_buffer1), CommentPos_1, false, RGB(255, 0, 255));
		}

		if (old == SECOND){
			IMAGE->Render(IMAGE->FindImage(Old_buffer2), CommentPos_2, false, RGB(255, 0, 255));
		}
	}

	m_Mouse->Render(MousePoint);

	//Pos.x = 473;
	//Pos.y = 106;
}

void cIngameScene::Release()
{
	SAFE_DELETE(m_Mouse);
	SAFE_DELETE(m_goshop);
	SAFE_DELETE(m_Option_button);
	SAFE_DELETE(m_Notice_button);
	SAFE_DELETE(m_HowToPlay_button);
	SAFE_DELETE(m_GameExitButton);
	SAFE_DELETE(m_Page_Button1);
	SAFE_DELETE(m_Page_Button2);
	SAFE_DELETE(m_Page_Button3);
	SAFE_DELETE(m_OrderList);
	SAFE_DELETE(m_Wnd_Exit_btn);
	SAFE_DELETE(m_OptionWnd);

	SAFE_DELETE(m_BGM_off_btn);
	SAFE_DELETE(m_BGM_on_btn);
	SAFE_DELETE(m_Effect_on_btn);
	SAFE_DELETE(m_Effect_off_btn);
	SAFE_DELETE(m_HowToPlay_wnd);
	for (auto i = 0; i < vOrder.size(); ++i) {
		SAFE_DELETE(vOrder[i]);

	}
	vOrder.clear();
}
void cIngameScene::OrderBoxRender()
{
	m_OrderList->_Render();
	if (vOrder.size() > 0) {
		for (auto iter = vOrder.begin(); iter != vOrder.end(); iter++) {
			(*iter)->Render();
		}
	}
}

