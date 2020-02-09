#pragma once
class cButton;
class cGameExitWnd
{
public:
	cGameExitWnd(int x, int y, const string & key);
	~cGameExitWnd();
public:
	void Init();
	void Update();
	void Render();
	void Release();
public:
	MCI_PLAY_PARMS mciPlay;
private:
	bool bClickChk = true;

	cTexture * m_Window;

	cButton * m_ExitYes;
	cButton * m_ExitNo;
	
	Point m_Pos;

	cButton * m_Making_btn;
	cButton * m_Exit_btn;
};



