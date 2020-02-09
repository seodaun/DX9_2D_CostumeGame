#include "stdafx.h"
#include "cMainScene.h"
#include "cCloset.h"
#include "cButton.h"  
#include <stdlib.h>
#define DRESS_BTN_Y 888 

cMainScene::cMainScene()
{

}

cMainScene::~cMainScene()
{
	Release();
}

void cMainScene::Init()
{
	first = true;
	sum = 0;
	bChkSubmit = false;
	isChangTime = false;
	m_Mouse = new cMouseCursor();
	m_Mouse->Init();

	for (int i = eTOP; i < eSHOES + 1; i++) m_EDress[i] = eNULL;
	m_BackGroundPos.x = 0;
	m_BackGroundPos.y = 0;

	m_ClosetPos.x = 320;
	m_ClosetPos.y = 450;

	m_Top_Closet = new cCloset(eTOP);
	m_Bottom_Closet = new cCloset(eBOTTOM);
	m_Accessory_Closet = new cCloset(eACCESSORY);
	m_Shoes_Closet = new cCloset(eSHOES);
	m_Top_Closet->Init();
	m_Bottom_Closet->Init();
	m_Accessory_Closet->Init();
	m_Shoes_Closet->Init();

	m_Closet_Top_btn = new cButton(81, DRESS_BTN_Y, "Closet_Top");
	m_Closet_Top_btn->Init();
	m_Closet_Bottom_btn = new cButton(218, DRESS_BTN_Y, "Closet_Bottom");
	m_Closet_Bottom_btn->Init();
	m_Closet_Accessory_btn = new cButton(536, DRESS_BTN_Y, "Closet_Accessory");
	m_Closet_Accessory_btn->Init();
	m_Closet_Shoes_btn = new cButton(370, DRESS_BTN_Y, "Closet_Shoes");
	m_Closet_Shoes_btn->Init();
	m_Complete_btn = new cButton(540, 100, "Clear");
	m_Complete_btn->Init();
	m_HomeBtn = new cButton(500, 100, "Exit");
	m_HomeBtn->Init();
	m_EDress_State = eTOP;

	top_key = "Null";
	bottom_key = "Null";
	accessory_key = "Null";
	shoes_key = "Null";
	m_first = true;
	isGame = true;

	if (asdf == ZERO) asdf = FIRST;
	else if (asdf == FIRST) {
		asdf = SECOND; old = FIRST;
	}
	else if (asdf == SECOND) {
		asdf = FIRST;
		old = SECOND;
	}
	

}

void cMainScene::Update()
{
	char buf[128];
	int key;
	MousePoint.x = INPUT->GetMousePos().x;
	MousePoint.y = INPUT->GetMousePos().y;
	m_Mouse->Update(MousePoint);

	if (EFFECT) {
		if (INPUT->MouseLDown())
			PlaySound(TEXT("./Sound/Clickeffect.wav"), NULL, SND_ASYNC);//클릭 효과음
	}
	if (!bChkSubmit) {//제출버튼을 누르지 않은 경우
		if (m_Closet_Top_btn->Update())		 m_EDress_State = eTOP;
		if (m_Closet_Bottom_btn->Update())	 m_EDress_State = eBOTTOM;
		if (m_Closet_Accessory_btn->Update())m_EDress_State = eACCESSORY;
		if (m_Closet_Shoes_btn->Update())	 m_EDress_State = eSHOES;
		if (m_Complete_btn->Update()) bChkSubmit = true; //제출버튼
		switch (m_EDress_State) {
		case eBOTTOM: {
			m_Bottom_Closet->Update();
			m_EDress[eBOTTOM] = m_Bottom_Closet->getBottom(); //누른 옷의 정보를 가져옴
			if ((m_EDress[eBOTTOM] >= 13 && m_EDress[eBOTTOM] <= 20)) {
				key = m_EDress[eBOTTOM] - 12;
				sprintf_s(buf, "Bottom_%d", key);
				bottom_key = buf;
			} break;
		}
		case eTOP: {
			m_Top_Closet->Update();
			m_EDress[eTOP] = m_Top_Closet->getTop();
			if ((m_EDress[eTOP] >= 5 && m_EDress[eTOP] <= 12)) {
				key = m_EDress[eTOP] - 4;
				sprintf_s(buf, "Top_%d", key);
				top_key = buf;
			} break;
		}
		case eACCESSORY: {
			m_Accessory_Closet->Update();
			m_EDress[eACCESSORY] = m_Accessory_Closet->getAccessory();
			if ((m_EDress[eACCESSORY] >= 21 && m_EDress[eACCESSORY] <= 28)) {
				key = m_EDress[eACCESSORY] - 20;
				sprintf_s(buf, "Accessory_%d", key);
				accessory_key = buf;
			} break;
		}
		case eSHOES: {
			m_Shoes_Closet->Update();
			m_EDress[eSHOES] = m_Shoes_Closet->getShoes();
			if ((m_EDress[eSHOES] >= 29 && m_EDress[eSHOES] <= 33)) {
				key = m_EDress[eSHOES] - 28;
				sprintf_s(buf, "Shoes_%d", key);
				shoes_key = buf;
			} break;
		}
		}
	}
	else { 
		if(m_first)EvalDress();
		if (m_HomeBtn->Update()) {
			SCENE->ChangeScene("InGame"); 
		}
	}
}
void cMainScene::EvalDress() //점수 계산
{
	int _nScore = 0; 
	switch (nEXConcept) {
	case 1: {
		for (int i = 0; i < 4; i++) if(5+(8*i)==m_EDress[i])_nScore++;
		break;
	}
	case 2: {for (int i = 0; i < 4; i++) if (6 + (8 * i) == m_EDress[i])_nScore++;
		break;
	}
	case 3: {for (int i = 0; i < 4; i++) if (7 + (8 * i) == m_EDress[i])_nScore++;
		break;
	}
	case 4: {for (int i = 0; i < 4; i++) if (8 + (8 * i) == m_EDress[i])_nScore++;
		break;
	}
	}
	m_Score= _nScore;
	if (m_Score > 2) {
		eval = GOOD;
		Price = m_Score * 1000;
		Money += Price;
	}
	else {
		eval = BAD;
		Price = m_Score -4* 1000;
		Money += Price;
	}
	m_first = false;
}

void cMainScene::ClickRender()//누른 옷장 버튼의 기본 이미지 변경
{
	switch (m_EDress_State) {
	case eTOP: {
		m_Closet_Top_btn->ClickRender();
		m_Closet_Bottom_btn->Render();
		m_Closet_Accessory_btn->Render();
		m_Closet_Shoes_btn->Render();
		break;
	}
	case eBOTTOM: {
		m_Closet_Top_btn->Render();
		m_Closet_Bottom_btn->ClickRender();
		m_Closet_Accessory_btn->Render();
		m_Closet_Shoes_btn->Render(); break;
	}
	case eACCESSORY: {
		m_Closet_Top_btn->Render();
		m_Closet_Bottom_btn->Render();
		m_Closet_Accessory_btn->ClickRender();
		m_Closet_Shoes_btn->Render(); break;
	}
	case eSHOES: {
		m_Closet_Shoes_btn->ClickRender();
		m_Closet_Top_btn->Render();
		m_Closet_Bottom_btn->Render();
		m_Closet_Accessory_btn->Render(); break;
	}
	}
}

void cMainScene::Render()
{
	IMAGE->Render(IMAGE->FindImage("MainGameBg"), m_BackGroundPos, false);
	IMAGE->Render(IMAGE->FindImage("Mannequin"), m_ClosetPos, true, RGB(255, 0, 255));
	ClickRender();
	m_Complete_btn->Render();
	switch (m_EDress_State) {
	case eTOP:		m_Top_Closet->Render();			break;
	case eBOTTOM:	m_Bottom_Closet->Render();		break;
	case eACCESSORY:m_Accessory_Closet->Render();	break;
	case eSHOES:	m_Shoes_Closet->Render();		break;
	}
	if (bottom_key != "Null")	IMAGE->Render(IMAGE->FindImage(bottom_key), m_ClosetPos, true, RGB(255, 0, 255));
	if (top_key != "Null")		IMAGE->Render(IMAGE->FindImage(top_key), m_ClosetPos, true, RGB(255, 0, 255));
	if (accessory_key != "Null")IMAGE->Render(IMAGE->FindImage(accessory_key), m_ClosetPos, true, RGB(255, 0, 255));
	if (shoes_key != "Null")	IMAGE->Render(IMAGE->FindImage(shoes_key), m_ClosetPos, true, RGB(255, 0, 255));

	if (bChkSubmit) {
		m_HomeBtn->Render(); 
		if (eval==GOOD) {//만족
			IMAGE->Render(IMAGE->FindImage("Good_ResultBg"), m_BackGroundPos, false, RGB(255, 0, 255));
			IMAGE->PrintTexture("" + to_string(sum + (Price)), { 300,500 });
			Result_temp = GOOD;
		}
		else if (eval==BAD) { //불만족 
			IMAGE->Render(IMAGE->FindImage("Bad_ResultBg"), m_BackGroundPos, false, RGB(255, 0, 255));
			IMAGE->PrintTexture("" + to_string(sum - (Price)), { 300,500 });
			Result_temp = BAD;
		}
	}

	m_Mouse->Render(MousePoint);
}

void cMainScene::Release()
{
	SAFE_DELETE(m_Mouse);
	SAFE_DELETE(m_Top_Closet);
	SAFE_DELETE(m_Bottom_Closet);
	SAFE_DELETE(m_Accessory_Closet);
	SAFE_DELETE(m_Shoes_Closet);
	SAFE_DELETE(m_Closet_Top_btn);
	SAFE_DELETE(m_Closet_Bottom_btn);
	SAFE_DELETE(m_Closet_Accessory_btn);
	SAFE_DELETE(m_Closet_Shoes_btn);
	SAFE_DELETE(m_HomeBtn);

	SAFE_DELETE(m_Complete_btn);
}
