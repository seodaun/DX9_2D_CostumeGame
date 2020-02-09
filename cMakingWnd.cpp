#include "stdafx.h"
#include "cMakingWnd.h"
#include"cButton.h"

int temp = 0;
int nConcept;
cMakingWnd::cMakingWnd(int x, int y, const string & key)
{
	m_Window = IMAGE->FindImage(key);
	m_Pos.x = x;
	m_Pos.y = y;
}


cMakingWnd::~cMakingWnd()
{
	Release();
}

void cMakingWnd::Init()//랜덤값으로 주문
{
	srand(nSeed);
	CountOrder = rand() % 3 + 1;//주문지 늘어나면 여기서 추가시키면 됨
	nConcept = CountOrder;
	if (temp == CountOrder) {
		while (1)
		{
			CountOrder = rand() % 3 + 1;
			if (CountOrder != temp)
				nConcept = CountOrder;
			break;
		}
	}
	temp = CountOrder;

	//CountOrder = 1;
	char buffer[128];
	sprintf_s(buffer, "Order_%d", CountOrder);
	strOrder = buffer;

	m_OrderPos.x = 320;
	m_OrderPos.y = 300;

	m_Making_btn = new cButton(320, 480, "Making");
	m_Making_btn->Init();
	m_Exit_btn = new cButton(500, 200, "WndExit");
	m_Exit_btn->Init();
}

void cMakingWnd::Update()
{
	if (bClickChk) {
		Init();
		bClickChk = false;
	}
	if (m_Making_btn->Update()) {
		chkOrder = false;
		SCENE->ChangeScene("MainGame");
	}
	if (m_Exit_btn->Update()) {
		Release();
		bClickChk = true;
		SCENE->ChangeScene("InGame");
	}
}

void cMakingWnd::Render()
{
	if (!bClickChk) {

		IMAGE->Render(m_Window, m_Pos, true, RGB(255, 0, 255));
		IMAGE->Render(IMAGE->FindImage(strOrder), m_OrderPos, true);
		m_Making_btn->Render();
		m_Exit_btn->Render();
	}
	//Order_1

	//	IMAGE->Render(IMAGE->FindImage(m_Comment3), CommentPos3, false);

}

void cMakingWnd::Release()
{
	SAFE_DELETE(m_Making_btn);
	SAFE_DELETE(m_Exit_btn);
}
