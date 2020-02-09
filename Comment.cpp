#include "stdafx.h"
#include"cButton.h"
#include"Comment.h"
Comment::Comment()
{

}


Comment::~Comment()
{

}

void Comment::Init()
{ 
	m_TitleBgPos.x = 0;
	m_TitleBgPos.y = 0; 
	
	CommentPos1.x = 320;
	CommentPos1.y = 100;
	CommentPos2.x = 320;
	CommentPos2.y = 300;
	CommentPos3.x = 320;
	CommentPos3.y = 600;


	srand(nSeed);
	//m_Comment = rand()%3; 
	if (MyScore > 2) {
		MyComment = GOOD;
	}
	else if (MyScore >= 0) {
		MyComment = BAD;
	}
}

void Comment::Update()
{
	if (4 >= CommentCount) CommentCount = 1;

	MousePoint.x = INPUT->GetMousePos().x;
	MousePoint.y = INPUT->GetMousePos().y;

	m_Mouse->Update(MousePoint);
	if (EFFECT) {
		if (INPUT->MouseLDown())
			PlaySound(TEXT("./Sound/Clickeffect.wav"), NULL, SND_ASYNC);
	} 
	if(MyComment == GOOD){//이런 느낌으로 조건 넣으면 될듯

	}
	else if(MyComment == BAD){//이런 느낌으로 조건 넣으면 될듯
	
	}
	
	if (CommentCount == 1) {
		//m_Comment1
	}
	else if (CommentCount == 2) {
		//m_Comment2
	}
	else if (CommentCount == 3) {
		//m_Comment3
	}
}

void Comment::Render()
{  
	if (m_Comment1 != "NULL") {
		IMAGE->Render(IMAGE->FindImage(m_Comment1), CommentPos1, false);
	}
	if (m_Comment2 != "NULL") {
		IMAGE->Render(IMAGE->FindImage(m_Comment2), CommentPos2, false);
	}
	if (m_Comment3 != "NULL") {
		IMAGE->Render(IMAGE->FindImage(m_Comment3), CommentPos3, false);
	} 
}

void Comment::Release()
{ 
}
