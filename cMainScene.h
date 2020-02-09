#pragma once
#include "cScene.h"

class cButton;
class cCloset;
class cMainScene :public cScene
{
private:
	cTexture * m_BackGround;
	Point m_BackGroundPos;
	Point m_ClosetPos;
	cMouseCursor * m_Mouse;
	Point MousePoint;
	bool first;
	int sum;
private:
	string top_key;
	string bottom_key;
	string accessory_key;
	string shoes_key;
public:
	cMainScene();
	~cMainScene();
	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
public:
	void EvalDress(); //옷 평가
	void ClickRender();
private:
	cCloset * m_Top_Closet;
	cCloset * m_Bottom_Closet;
	cCloset * m_Accessory_Closet;
	cCloset * m_Shoes_Closet;

	cButton * m_Closet_Top_btn;
	cButton * m_Closet_Bottom_btn;
	cButton * m_Closet_Accessory_btn;
	cButton * m_Closet_Shoes_btn;
	cButton * m_Complete_btn;//제출 버튼

	cButton * m_HomeBtn;
private:
	_ClosetKind m_EDress_State;
	_ClosetKind m_EDress[4];
private:
	bool m_first;
	bool bChkSubmit;
	int m_Score;

	int Price;
public:
	eEVAL eval;

	
};