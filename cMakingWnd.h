#pragma once
#include "cScene.h"
class cButton;
class cMakingWnd : public cScene
{
public:
	cMakingWnd(int x, int y, const string & key);
	~cMakingWnd();
public:
	void Init();
	void Update();
	void Render();
	void Release();
private:
	bool bClickChk = true;
private:
	cTexture * m_Window;
	Point m_Pos;

	cButton * m_Making_btn;
	cButton * m_Exit_btn;
	Point m_OrderPos;
public:
	int CountOrder = 0;
	string strOrder;
	unsigned int nSeed = (unsigned)time(NULL);
	//int temp=0;
};

