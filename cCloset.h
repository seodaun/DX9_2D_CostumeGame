#pragma once

#include"cShopScene.h"
class cButton;
class cCloset:  public cShopScene
{
public:
	cCloset(_ClosetKind Closetkind);
	~cCloset();
public:
	void Init();
	void Update();
	void Render();
	void Release();
public:
	void NextClosetUpdate(_ClosetKind state);
	void NextCloseRender();
	void ChangeDressLock(int j, int i);
public:
	void Init_top();
	void Init_bottom();
	void Init_accessory();
	void Init_shoes();

	void Next_Init_top();
	void Next_Init_bottom();
	void Next_Init_accessory();
	void Next_Init_shoes();
private: 
	bool bNextBtn;
	bool first;//√ ±‚»≠ 
	int nCntTopPos;
	int nCntBotPos;
	int nCntAccPos;
	int nCntShoesPos;
	bool b_first[4];
private:
	_ClosetKind _EDress[4];
	Point m_closet_pos;
	_ClosetKind chkBtn;
	_ClosetKind beforeBtn;
private:
	cTexture * m_Closet;
	_ClosetKind m_ClosetKind;
	//ø ¿Âæ»¿« ø µÈ πˆ∆∞
	cButton * m_top_1_btn;cButton * m_top_2_btn;cButton * m_top_3_btn;cButton * m_top_4_btn;
	cButton * m_bottom_1_btn;cButton * m_bottom_2_btn;cButton * m_bottom_3_btn;cButton * m_bottom_4_btn;
	cButton * m_accessory_1_btn; cButton * m_accessory_2_btn; cButton * m_accessory_3_btn; cButton * m_accessory_4_btn;
	cButton * m_shoes_1_btn;cButton * m_shoes_2_btn;cButton * m_shoes_3_btn;cButton * m_shoes_4_btn;
private:
	cButton * m_next_top_1_btn; cButton * m_next_top_2_btn; cButton * m_next_top_3_btn; cButton * m_next_top_4_btn; cButton * m_next_top_5_btn; cButton * m_next_top_6_btn;
	cButton * m_next_bottom_1_btn; cButton * m_next_bottom_2_btn; cButton * m_next_bottom_3_btn; cButton * m_next_bottom_4_btn;
	cButton * m_next_accessory_1_btn; cButton * m_next_accessory_2_btn; cButton * m_next_accessory_3_btn; cButton * m_next_accessory_4_btn;
	cButton * m_next_shoes_1_btn; cButton * m_next_shoes_2_btn; cButton * m_next_shoes_3_btn; cButton * m_next_shoes_4_btn;
private:
	cButton * m_next_btn;
	cButton * m_before_btn;

private:
	cButton * m_TopNext_btn;	//ø ¿Â ¥Ÿ¿Ωƒ≠
	cButton * m_BotNext_btn;
	cButton * m_AccNext_btn;
	cButton * m_ShoesNext_btn;
public:
	_ClosetKind getTop()		{ return _EDress[eTOP];			}
	_ClosetKind getBottom()		{ return _EDress[eBOTTOM];		}
	_ClosetKind getAccessory()	{ return _EDress[eACCESSORY];	}
	_ClosetKind getShoes()		{ return _EDress[eSHOES];		}	
};

