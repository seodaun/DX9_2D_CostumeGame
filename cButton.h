#pragma once
class cButton
{
private :
	cTexture * m_Nomal;
	cTexture * m_OnCursor;
	cTexture * m_Click;

	cTexture * m_Nomal2;
	cTexture * m_OnCursor2;
	cTexture * m_Click2;

	Point m_Pos;

	RECT m_rt;
	
	bool b_OnCursor;
	bool b_Click;

	bool bChkLock;
public:
	cButton(int x, int y, const string & key, const string & key2);
	cButton(int x, int y , const string& key);
	
	~cButton();

	void Init();
	void Init(bool bChkLock);
	bool Update();
	bool _Update();
	void Render();
	void _Render();
	void ClickRender();
	void StateRender(_EPRODUCSTATE state);
	void Release();
	void ChangeLock(bool lock) {
		if (this == nullptr)
			DEBUG_LOG("Hello");
		bChkLock = lock;
	}

	bool isOver();
};

