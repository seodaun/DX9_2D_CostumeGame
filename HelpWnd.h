#pragma once

class cButton;
class HelpWnd
{
public:
	HelpWnd();
	~HelpWnd();


public:
	void Init();
	void Update();
	void Render();
	void Release();

	cTexture * m_Window;
	cButton * goMain;

};

