#pragma once
#include "cScene.h"
class cWindow;
class cButton;
class cTitleScene : public cScene
{
private:
	cTexture * m_BackGround;
	cFrame * m_PlayerFrame;
	Point Pos;
	Point m_TitleBgPos;
	bool b_Move;
	bool isOver;
	int WndState;

	cWindow *  m_Window;
	cButton * m_StartButton;
	cButton * m_GameExitButton;
	cButton * m_option_button;
	cButton * m_HowToPlay_button;

	cButton * m_OptionWnd;
	cButton * m_HowToPlay_wnd;
	cButton * m_BGM_off_btn;
	cButton * m_BGM_on_btn;
	cButton * m_Effect_off_btn;
	cButton * m_Effect_on_btn;

	cButton * m_Wnd_Exit_btn;
private:
	bool chkOption;
	bool chkHow;
public:
	//¸¶¿ì½º
	cMouseCursor * m_Mouse;
	Point MousePoint;
	MCI_OPEN_PARMS mciOpen;
	MCI_PLAY_PARMS mciPlay;
public:
	cTitleScene();
	virtual ~cTitleScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;

};
