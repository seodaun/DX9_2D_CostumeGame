#include "stdafx.h"
#include "cEndingScene.h"


cEndingScene::cEndingScene()
{
}


cEndingScene::~cEndingScene()
{
}

void cEndingScene::Init()
{
}

void cEndingScene::Update()
{
}

void cEndingScene::Render()
{
	Point m_BackGroundPos;
	m_BackGroundPos.x = 0;
	m_BackGroundPos.y = 0;
	//�̹��� ��� ��� : cLoadScene���� �߰��� �̹����� ����Ѵ�.
	//IMAGE->FindImage("�̸�")�� �Ͽ� �̹����� ã�� �� �ִ�.
	//IMAGE->Render(�̹���, ��ǥ, true = �̹����� �߽��� �߾����� ����, ������ �÷�Ű);
	IMAGE->Render(IMAGE->FindImage("EndingBg"), m_BackGroundPos, false);
}

void cEndingScene::Release()
{
}
