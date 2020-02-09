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
	//이미지 출력 방법 : cLoadScene에서 추가한 이미지를 사용한다.
	//IMAGE->FindImage("이름")을 하여 이미지를 찾을 수 있다.
	//IMAGE->Render(이미지, 좌표, true = 이미지의 중심을 중앙으로 설정, 제거할 컬러키);
	IMAGE->Render(IMAGE->FindImage("EndingBg"), m_BackGroundPos, false);
}

void cEndingScene::Release()
{
}
