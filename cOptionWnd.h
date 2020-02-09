#pragma once

class cButton;
class cOptionWnd
{
public:
	cOptionWnd(int x, int y, const string & key);
	~cOptionWnd();

public:
	void Init();
	void Update();
	void Render();
	void Release(); 
public:
		MCI_PLAY_PARMS mciPlay;
private:
	bool bClickChk=true;

	cButton * m_BGMON;
	cButton * m_BGMOFF;
	cButton * m_SoundON;
	cButton * m_SoundOFF;


	cTexture * m_Window;

	Point m_Pos;

	cButton * m_Making_btn;
	cButton * m_Exit_btn;
};

