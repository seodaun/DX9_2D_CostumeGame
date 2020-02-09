#pragma once
#include "cScene.h"
class cEndingScene : public cScene
{
private:
	cTexture * m_BackGround;
	cFrame * m_PlayerFrame;
	Point Pos;
	bool b_Move;
public:
	cEndingScene();
	virtual ~cEndingScene();

	virtual void Init() override;
	virtual void Update() override;
	virtual void Render() override;
	virtual void Release() override;
};

