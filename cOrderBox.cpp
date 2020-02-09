#include "stdafx.h"
#include "cOrderBox.h"
#include"cButton.h"

cOrderBox::cOrderBox(int x, int y, int key)
	:concept(key)
{
	m_OrderBoxPos.x = x;
	m_OrderBoxPos.y = y;
	m_OrderKeyPos.x = x-40;
	m_OrderKeyPos.y = y;
	m_making_btn = new cButton(x+120,y,"Making");
	m_making_btn->Init(); 
	sprintf_s(buf, "Order_%d", concept);
	m_order_key = buf;
}

cOrderBox::~cOrderBox()
{
	Release();
}

void cOrderBox::Init()
{

}

void cOrderBox::Render()
{
	if (this != NULL) {
		IMAGE->Render(IMAGE->FindImage("order_Contents"), m_OrderBoxPos, true, RGB(255, 0, 255));
		IMAGE->Render(IMAGE->FindImage(m_order_key), m_OrderKeyPos, true, RGB(255, 0, 255));
		m_making_btn->Render();
	}
	else {
		DEBUG_LOG("객체가 없어서 랜더가 안됨");
	}
}

bool cOrderBox::Update()
{
	if (this != NULL) {
		if (m_making_btn->Update())return true;
	}
	else {
		DEBUG_LOG("객체가 없어 업데이트가 안됨");
	}
}

void cOrderBox::Release()
{
	SAFE_DELETE(m_making_btn);
}
