
#pragma once
#include"cButton.h"
#include"cScene.h"

class cShopScene : public cScene
{
private:
	cTexture * ShopBackGround;
	Point m_ShopBgPos;

	//cButton * m_BuyButton[4][4];
	cButton * m_Product[4][4];
	cButton * m_Exit;
	Point pos;
	cMouseCursor * m_Mouse;
	Point MousePoint;

	cButton * m_next_btn;
	cButton * m_before_btn;
private:
	bool m_bBuyBtn[4][4];
	_EPRODUCSTATE m_product_state[4][4] = {};
	int m_state;
public:
	cShopScene();
	~cShopScene();

	void Init();
	void Update();
	void Render();
	void Release();
public:
	void BuyDress();
	void CntBuyList(int i, int j);
};