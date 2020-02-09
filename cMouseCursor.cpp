#include "stdafx.h"
#include "cMouseCursor.h"

cMouseCursor::cMouseCursor()
{
	g_MNomal = IMAGE->FindImage("MouseCursor_nomal");
	g_MOnCursor = IMAGE->FindImage("MouseCursor_onclick");
	g_MClick = IMAGE->FindImage("MouseCursor_upclick");

	//x = INPUT->GetMousePos().x;
	//y = INPUT->GetMousePos().y;
}
cMouseCursor::~cMouseCursor()
{

}

void cMouseCursor::Init()
{

}

bool cMouseCursor::Update(Point pos)
{
	pos.x = INPUT->GetMousePos().x;
	pos.y = INPUT->GetMousePos().y;
	
	if (INPUT->MouseLPress() || INPUT->MouseRPress()) {
		state = mDown;

	}
	else if (INPUT->MouseLUp() || INPUT->MouseRUp()){
		state = mUp;
	}
	else {
		state = mNomal;
	}

	return false;
}

void cMouseCursor::Render(Point pos)
{

	if (state == mNomal) {
		IMAGE->Render(g_MNomal, pos, false, RGB(255, 0, 255));//g_MPos
	}
	else if (state == mDown) {
		IMAGE->Render(g_MOnCursor, pos, false, RGB(255, 0, 255));
	}
	else if (state == mUp) {
		IMAGE->Render(g_MClick, pos, false, RGB(255, 0, 255));
	}
}

void cMouseCursor::Release()
{
}

bool cMouseCursor::isClickDown(int x, int y)
{
	return false;
}

bool cMouseCursor::isOver()
{
	return false;
}
