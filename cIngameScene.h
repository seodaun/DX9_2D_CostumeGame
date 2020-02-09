#pragma once
#include "cScene.h"
class cButton;
class cOrderBox;
class cIngameScene : public cScene
{
private:
	cTexture * m_BackGround;
	//cFrame * m_PlayerFrame;
	Point Pos;
	Point OrderBoxPos;

	Point _OrderBoxPos;
	int WndState;
	Point m_ChangePos;
	cTexture * m_ChangMmannequin;
	bool bClickOrder;
	bool bClickOption;
	bool bClickHow;

	cButton * m_GameExitButton;
	cButton * m_Notice_button;
	cButton * m_Option_button;
	cButton  * m_HowToPlay_button;
	cButton  * m_HowToPlay_wnd;
	cButton  * m_Wnd_Exit_btn; 

	cButton * m_BGM_off_btn;
	cButton * m_BGM_on_btn;
	cButton * m_Effect_off_btn;
	cButton * m_Effect_on_btn;
	Point m_BackGroundPos;
	Point m_MoneyIconPos;

	cButton * m_goshop;
	cButton * m_making_btn;
	//알림창 버튼
	cButton * m_notice_exit_btn;

	Point CommentPos;
	Point CommentPos2;

	cButton * m_Page_Button1;
	cButton * m_Page_Button2;
	cButton * m_Page_Button3;
	Point ShowPageButtonPos;

	cButton * m_OrderList;
	cButton * m_OptionWnd;




private:
	vector<cOrderBox*> vOrder;
	list<int>::iterator m_iter;
public:
	MCI_OPEN_PARMS mciOpen;
	MCI_PLAY_PARMS mciPlay;

	//int Money;
	string kindC;
	string Old_buffer1;
	string Old_buffer2;
	char buffer1[128];
	char buffer2[128];
	//마우스
	cMouseCursor * m_Mouse;
	Point MousePoint;
	int size;
	int count = 1;

	Point CommentPos_1;
	Point CommentPos_2;

	bool GameStart1 = false;
	bool GameStart2 = false;
public:
	cIngameScene();
	virtual ~cIngameScene();

	virtual void Init() override;
	virtual void Update() override;
	void ChangePos(int cnt);
	virtual void Render() override;
	virtual void Release() override;
public:
	void OrderBoxRender();
	void OrderBoxUpdate();
};

