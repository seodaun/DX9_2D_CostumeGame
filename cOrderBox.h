#pragma once
class cButton;
class cOrderBox
{
public:
	cOrderBox(int x, int y,  int key);
	~cOrderBox();
	void Init();
	void Render();
	bool Update();
	void Release();
public:
	void SetPos(int x, int y) {
		m_OrderBoxPos.x = x;
		m_OrderBoxPos.y = y;
	}
	int GetY() { return m_OrderBoxPos.y; }
	int GetKey() { 
		return concept; }
private:
	Point m_OrderBoxPos;
	Point m_OrderKeyPos;
	cButton * m_making_btn;
	string m_order_key;
	int concept; 
	char buf[128];
};

