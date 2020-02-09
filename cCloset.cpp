#include "stdafx.h"
#include "cCloset.h"
#include"cButton.h" 
#define DRESS_BTN_Y 730
#define DRESS_BTN_X 125
cCloset::cCloset(_ClosetKind ClosetKind)
	:m_ClosetKind(ClosetKind)
{
	chkBtn = eNULL;
	beforeBtn = eNULL;
	nCntTopPos = 0;
}

cCloset::~cCloset()
{
	Release();
	SAFE_DELETE(m_next_btn);
	SAFE_DELETE(m_before_btn);
}
void cCloset::Init()
{
	for (int i = 0; i < 4; i++)
		b_first[i] = true;
	bNextBtn = false;
	switch (m_ClosetKind) {
	case eTOP:		Init_top();
	case eBOTTOM:	Init_bottom();
	case eACCESSORY:Init_accessory();
	case eSHOES:	Init_shoes();
	}
	m_next_btn = new cButton(601, 736, "Next");
	m_next_btn->Init();
	m_before_btn = new cButton(38, 735, "Before");
	m_before_btn->Init();
}
void cCloset::Render()
{
	switch (m_ClosetKind) {
	case eTOP: {
		if (!bNextBtn) {
			m_top_1_btn->Render();
			m_top_2_btn->Render();
			m_top_3_btn->Render();
			m_top_4_btn->Render();
		}
		else
			NextCloseRender();
		break;
	}
	case eBOTTOM: {
		if (!bNextBtn) {
			m_bottom_1_btn->Render();
			m_bottom_2_btn->Render();
			m_bottom_3_btn->Render();
			m_bottom_4_btn->Render();
		}
		else NextCloseRender();
		break;
	}
	case eACCESSORY: {
		if (!bNextBtn) {
			m_accessory_1_btn->Render();
			m_accessory_2_btn->Render();
			m_accessory_3_btn->Render();
			m_accessory_4_btn->Render();
		}
		else NextCloseRender();
		break;
	}
	case eSHOES: {
		if (!bNextBtn) {
			m_shoes_1_btn->Render();
			m_shoes_2_btn->Render();
			m_shoes_3_btn->Render();
			m_shoes_4_btn->Render();
		}
		else NextCloseRender();
		break;
	}
	}

	m_next_btn->Render();
	m_before_btn->Render();
}

void cCloset::Update()
{
	switch (m_ClosetKind) {//선택한 옷장에 따라 다른 버튼 업데이트
	case eTOP: {
		if (bNextBtn)
			NextClosetUpdate(eTOP);
		else if (!bNextBtn) {	//before closet
			if (m_top_1_btn->Update())		_EDress[eTOP] = eTOP_1;
			else if (m_top_2_btn->Update()) _EDress[eTOP] = eTOP_2;
			else if (m_top_3_btn->Update()) _EDress[eTOP] = eTOP_3;
			else if (m_top_4_btn->Update()) _EDress[eTOP] = eTOP_4;
		}
	}break;
	case eBOTTOM: {
		if (bNextBtn)
			NextClosetUpdate(eBOTTOM);
		else if (!bNextBtn) {
			if (m_bottom_1_btn->Update()) _EDress[eBOTTOM] = eBOTTOM_1;
			if (m_bottom_2_btn->Update()) _EDress[eBOTTOM] = eBOTTOM_2;
			if (m_bottom_3_btn->Update()) _EDress[eBOTTOM] = eBOTTOM_3;
			if (m_bottom_4_btn->Update()) _EDress[eBOTTOM] = eBOTTOM_4;
		}
	}break;
	case eACCESSORY: {
		if (bNextBtn)
			NextClosetUpdate(eACCESSORY);
		else if (!bNextBtn) {
			if (m_accessory_1_btn->Update()) _EDress[eACCESSORY] = eACCESSORY_1;
			if (m_accessory_2_btn->Update()) _EDress[eACCESSORY] = eACCESSORY_2;
			if (m_accessory_3_btn->Update()) _EDress[eACCESSORY] = eACCESSORY_3;
			if (m_accessory_4_btn->Update()) _EDress[eACCESSORY] = eACCESSORY_4;
		}
	}break;
	case eSHOES: {
		if (bNextBtn)
			NextClosetUpdate(eSHOES);
		else if (!bNextBtn) {
			if (m_shoes_1_btn->Update()) _EDress[eSHOES] = eSHOES_1;
			if (m_shoes_2_btn->Update()) _EDress[eSHOES] = eSHOES_2;
			if (m_shoes_3_btn->Update()) _EDress[eSHOES] = eSHOES_3;
			if (m_shoes_4_btn->Update()) _EDress[eSHOES] = eSHOES_4;
		}
	}break;
	}

	if (m_next_btn->Update()) { //다음 버튼
		bNextBtn = true;
		switch (m_ClosetKind) {
		case eTOP: {
			b_first[0] = true; 
			Next_Init_top();		
		}break;
		case eBOTTOM: {
			b_first[1] = true;
			Next_Init_bottom(); }		break;
		case eACCESSORY:
		{
			b_first[2] = true;
			Next_Init_accessory();
		}break;
		case eSHOES: {
			b_first[3] = true;
			Next_Init_shoes();
		}break;
		}
	}
	else if (m_before_btn->Update()) {//이전 버튼
		bNextBtn = false;
		switch (m_ClosetKind) {
		case eTOP:		Release(); Init_top();		break;
		case eBOTTOM:	Release(); Init_bottom();	break;
		case eACCESSORY:Release(); Init_accessory(); break;
		case eSHOES:	Release(); Init_shoes();	break;
		}
	}
}
void cCloset::ChangeDressLock(int j, int i) { //옷 미리보기 버튼 잠금해제
	switch (j) {
	case eTOP: {
		switch (i + 5) {
		case eTOP_1: 
			m_next_top_1_btn->ChangeLock(true); break;
		case eTOP_2: 
			m_next_top_2_btn->ChangeLock(true); break;
		case eTOP_3:
			m_next_top_3_btn->ChangeLock(true); break;
		case eTOP_4:
			m_next_top_4_btn->ChangeLock(true); break;
		}
	}
		break;
	case eBOTTOM: {
		switch (i + 13) { 
		case eBOTTOM_1: m_next_bottom_1_btn->ChangeLock(true); break;
		case eBOTTOM_2: m_next_bottom_2_btn->ChangeLock(true); break;
		case eBOTTOM_3: m_next_bottom_3_btn->ChangeLock(true); break;
		case eBOTTOM_4: m_next_bottom_4_btn->ChangeLock(true); break;
		}
	}
				  break;
	case eACCESSORY: {
		switch (i + 21) { 
		case eACCESSORY_1: m_next_accessory_1_btn->ChangeLock(true); break;
		case eACCESSORY_2: m_next_accessory_2_btn->ChangeLock(true); break;
		case eACCESSORY_3: m_next_accessory_3_btn->ChangeLock(true); break;
		case eACCESSORY_4: m_next_accessory_4_btn->ChangeLock(true); break;
		}
	}
					 break;
	case eSHOES: {
		switch (i + 29) { 
		case eSHOES_1: m_next_shoes_1_btn->ChangeLock(true); break;
		case eSHOES_2: m_next_shoes_2_btn->ChangeLock(true); break;
		case eSHOES_3: m_next_shoes_3_btn->ChangeLock(true); break;
		case eSHOES_4: m_next_shoes_4_btn->ChangeLock(true); break;
		}
	}
				 break;
	}
}
void cCloset::NextClosetUpdate(_ClosetKind state)//다음 옷장 버튼을 눌렀을 경우 업데이트
{
	for (int j = 0; j < 4; j++) {
		if (bBuyList[state][j] == true) { 
			ChangeDressLock(state, j);
		}
	}
	if (bNextBtn) {
		switch (m_ClosetKind) {
		case eTOP: {
			if (m_next_top_1_btn->Update()) _EDress[eTOP] = eTOP_5;
			if (m_next_top_2_btn->Update()) _EDress[eTOP] = eTOP_6;
			if (m_next_top_3_btn->Update()) _EDress[eTOP] = eTOP_7;
			if (m_next_top_4_btn->Update()) _EDress[eTOP] = eTOP_8;
			break;
		}break;
		case eBOTTOM: {
			if (m_next_bottom_1_btn->Update()) _EDress[eBOTTOM] = eBOTTOM_5;
			if (m_next_bottom_2_btn->Update()) _EDress[eBOTTOM] = eBOTTOM_6;
			if (m_next_bottom_3_btn->Update()) _EDress[eBOTTOM] = eBOTTOM_7;
			if (m_next_bottom_4_btn->Update()) _EDress[eBOTTOM] = eBOTTOM_8;
			break;
		}
		case eACCESSORY: {
			if (m_next_accessory_1_btn->Update()) _EDress[eACCESSORY] = eACCESSORY_5;
			if (m_next_accessory_2_btn->Update()) _EDress[eACCESSORY] = eACCESSORY_6;
			if (m_next_accessory_3_btn->Update()) _EDress[eACCESSORY] = eACCESSORY_7;
			if (m_next_accessory_4_btn->Update()) _EDress[eACCESSORY] = eACCESSORY_8;
			break;
		}
		case eSHOES: {
			if (m_next_shoes_1_btn->Update()) _EDress[eSHOES] = eSHOES_5;
			if (m_next_shoes_2_btn->Update()) _EDress[eSHOES] = eSHOES_6;
			if (m_next_shoes_3_btn->Update()) _EDress[eSHOES] = eSHOES_7;
			if (m_next_shoes_4_btn->Update()) _EDress[eSHOES] = eSHOES_8;
			break;
		}
		}
	}
}
void cCloset::NextCloseRender() { //다음 옷장 랜더
	if (bNextBtn) {
		switch (m_ClosetKind) {
		case eTOP: {
			m_next_top_1_btn->Render();
			m_next_top_2_btn->Render();
			m_next_top_3_btn->Render();
			m_next_top_3_btn->Render();
			break;
		}
		case eBOTTOM: {
			m_next_bottom_1_btn->Render();
			m_next_bottom_2_btn->Render();
			m_next_bottom_3_btn->Render();
			m_next_bottom_4_btn->Render();
			break;
		}
		case eACCESSORY: {
			m_next_accessory_1_btn->Render();
			m_next_accessory_2_btn->Render();
			m_next_accessory_3_btn->Render();
			m_next_accessory_4_btn->Render();
			break;
		}
		case eSHOES: {
			m_next_shoes_1_btn->Render();
			m_next_shoes_2_btn->Render();
			m_next_shoes_3_btn->Render();
			m_next_shoes_4_btn->Render();
			break;
		}
		}
	}
}

void cCloset::Init_top()
{
	m_top_1_btn = new cButton(DRESS_BTN_X, DRESS_BTN_Y, "Top_1");
	m_top_1_btn->Init();
	m_top_2_btn = new cButton(DRESS_BTN_X + 135, DRESS_BTN_Y, "Top_2");
	m_top_2_btn->Init();
	m_top_3_btn = new cButton(DRESS_BTN_X + 135 * 2, DRESS_BTN_Y, "Top_3"); \
	m_top_3_btn->Init();
	m_top_4_btn = new cButton(DRESS_BTN_X + 135 * 3, DRESS_BTN_Y, "Top_4");
	m_top_4_btn->Init();
}
void cCloset::Init_bottom()
{
	m_bottom_1_btn = new cButton(DRESS_BTN_X, DRESS_BTN_Y, "Bottom_1");
	m_bottom_1_btn->Init();
	m_bottom_2_btn = new cButton(DRESS_BTN_X + 135, DRESS_BTN_Y, "Bottom_2");
	m_bottom_2_btn->Init();
	m_bottom_3_btn = new cButton(DRESS_BTN_X + 135 * 2, DRESS_BTN_Y, "Bottom_3");
	m_bottom_3_btn->Init();
	m_bottom_4_btn = new cButton(DRESS_BTN_X + 135 * 3, DRESS_BTN_Y, "Bottom_4");
	m_bottom_4_btn->Init();
}
void cCloset::Init_accessory()
{
	m_accessory_1_btn = new cButton(DRESS_BTN_X, DRESS_BTN_Y, "Accessory_1");
	m_accessory_1_btn->Init();
	m_accessory_2_btn = new cButton(DRESS_BTN_X + 135, DRESS_BTN_Y, "Accessory_2");
	m_accessory_2_btn->Init();
	m_accessory_3_btn = new cButton(DRESS_BTN_X + 135 * 2, DRESS_BTN_Y, "Accessory_3");
	m_accessory_3_btn->Init();
	m_accessory_4_btn = new cButton(DRESS_BTN_X + 135 * 3, DRESS_BTN_Y, "Accessory_4");
	m_accessory_4_btn->Init();
}
void cCloset::Init_shoes()
{
	m_shoes_1_btn = new cButton(DRESS_BTN_X, DRESS_BTN_Y, "Shoes_1");
	m_shoes_1_btn->Init();
	m_shoes_2_btn = new cButton(DRESS_BTN_X + 135, DRESS_BTN_Y, "Shoes_2");
	m_shoes_2_btn->Init();
	m_shoes_3_btn = new cButton(DRESS_BTN_X + 135 * 2, DRESS_BTN_Y, "Shoes_3");
	m_shoes_3_btn->Init();
	m_shoes_4_btn = new cButton(DRESS_BTN_X + 135 * 3, DRESS_BTN_Y, "Shoes_4");
	m_shoes_4_btn->Init();
}

void cCloset::Next_Init_top()
{
	if (b_first[eTOP]) {
		Release();
		m_next_top_1_btn = new cButton(DRESS_BTN_X + 135 * nCntBuyPos[eTOP][0], DRESS_BTN_Y, "Top_1");
		m_next_top_1_btn->Init(false);
		m_next_top_2_btn = new cButton(DRESS_BTN_X + 135 * nCntBuyPos[eTOP][1], DRESS_BTN_Y, "Top_1");
		m_next_top_2_btn->Init(false);
		m_next_top_3_btn = new cButton(DRESS_BTN_X + 135 * nCntBuyPos[eTOP][2], DRESS_BTN_Y, "Top_1");
		m_next_top_3_btn->Init(false);
		m_next_top_4_btn = new cButton(DRESS_BTN_X + 135 * nCntBuyPos[eTOP][3], DRESS_BTN_Y, "Top_1");
		m_next_top_4_btn->Init(false);
		b_first[eTOP] = false;
	}
}
void cCloset::Next_Init_bottom()
{
	if (b_first[eBOTTOM]) {
		Release();
		m_next_bottom_1_btn = new cButton(DRESS_BTN_X + 135 * nCntBuyPos[eBOTTOM][0], DRESS_BTN_Y, "Top_1");
		m_next_bottom_1_btn->Init(false);
		m_next_bottom_2_btn = new cButton(DRESS_BTN_X + 135 * nCntBuyPos[eBOTTOM][1], DRESS_BTN_Y, "Top_1");
		m_next_bottom_2_btn->Init(false);
		m_next_bottom_3_btn = new cButton(DRESS_BTN_X + 135 * nCntBuyPos[eBOTTOM][2], DRESS_BTN_Y, "Top_1");
		m_next_bottom_3_btn->Init(false);
		m_next_bottom_4_btn = new cButton(DRESS_BTN_X + 135 * nCntBuyPos[eBOTTOM][3], DRESS_BTN_Y, "Top_1");
		m_next_bottom_4_btn->Init(false);
		b_first[1] = false;
	}
}
void cCloset::Next_Init_accessory()
{
	if (b_first[2]) {
		Release();
		m_next_accessory_1_btn = new cButton(DRESS_BTN_X + 135 * nCntBuyPos[eACCESSORY][0], DRESS_BTN_Y, "Top_1");
		m_next_accessory_1_btn->Init(false);
		m_next_accessory_2_btn = new cButton(DRESS_BTN_X + 135 * nCntBuyPos[eACCESSORY][1], DRESS_BTN_Y, "Top_1");
		m_next_accessory_2_btn->Init(false);
		m_next_accessory_3_btn = new cButton(DRESS_BTN_X + 135 * nCntBuyPos[eACCESSORY][2], DRESS_BTN_Y, "Top_1");
		m_next_accessory_3_btn->Init(false);
		m_next_accessory_4_btn = new cButton(DRESS_BTN_X + 135 * nCntBuyPos[eACCESSORY][3], DRESS_BTN_Y, "Top_1");
		m_next_accessory_4_btn->Init(false);
		b_first[2] = false;
	}
}
void cCloset::Next_Init_shoes()
{
	if (b_first[eSHOES]) {
		Release();
		m_next_shoes_1_btn = new cButton(DRESS_BTN_X + 135 * nCntBuyPos[eSHOES][0], DRESS_BTN_Y, "Top_1");
		m_next_shoes_1_btn->Init(false);
		m_next_shoes_2_btn = new cButton(DRESS_BTN_X + 135 * nCntBuyPos[eSHOES][1], DRESS_BTN_Y, "Top_1");
		m_next_shoes_2_btn->Init(false);
		m_next_shoes_3_btn = new cButton(DRESS_BTN_X + 135 * nCntBuyPos[eSHOES][2], DRESS_BTN_Y, "Top_1");
		m_next_shoes_3_btn->Init(false);
		m_next_shoes_4_btn = new cButton(DRESS_BTN_X + 135 * nCntBuyPos[eSHOES][3], DRESS_BTN_Y, "Top_1");
		m_next_shoes_4_btn->Init(false);
		b_first[3] = false;
	}
}
void cCloset::Release()
{

	SAFE_DELETE(m_top_1_btn);
	SAFE_DELETE(m_top_2_btn);
	SAFE_DELETE(m_top_3_btn);
	SAFE_DELETE(m_top_4_btn);
	SAFE_DELETE(m_TopNext_btn);

	SAFE_DELETE(m_bottom_1_btn);
	SAFE_DELETE(m_bottom_2_btn);
	SAFE_DELETE(m_bottom_3_btn);
	SAFE_DELETE(m_bottom_4_btn);

	SAFE_DELETE(m_accessory_1_btn);
	SAFE_DELETE(m_accessory_2_btn);
	SAFE_DELETE(m_accessory_3_btn);
	SAFE_DELETE(m_accessory_4_btn);

	SAFE_DELETE(m_shoes_1_btn);
	SAFE_DELETE(m_shoes_2_btn);
	SAFE_DELETE(m_shoes_3_btn);
	SAFE_DELETE(m_shoes_4_btn);

	SAFE_DELETE(m_next_top_1_btn);
	SAFE_DELETE(m_next_top_2_btn);
	SAFE_DELETE(m_next_top_3_btn);
	SAFE_DELETE(m_next_top_4_btn);

	SAFE_DELETE(m_next_bottom_1_btn);
	SAFE_DELETE(m_next_bottom_2_btn);
	SAFE_DELETE(m_next_bottom_3_btn);
	SAFE_DELETE(m_next_bottom_4_btn);

	SAFE_DELETE(m_next_accessory_1_btn);
	SAFE_DELETE(m_next_accessory_2_btn);
	SAFE_DELETE(m_next_accessory_3_btn);
	SAFE_DELETE(m_next_accessory_4_btn);

	SAFE_DELETE(m_next_shoes_1_btn);
	SAFE_DELETE(m_next_shoes_2_btn);
	SAFE_DELETE(m_next_shoes_3_btn);
	SAFE_DELETE(m_next_shoes_4_btn);
	// 
}