#pragma once 
class cButton;
class Comment 
{
private:
	cTexture * m_BackGround;
	cFrame * m_PlayerFrame;
	Point Pos;
	Point m_TitleBgPos; 

	cMouseCursor * m_Mouse;
	Point MousePoint;
	//int m_Comment_1;
	//int m_Comment_2;
	//int m_Comment_3;

public:


	int MyScore;
	int MyComment;

	string m_Comment1 = "NULL";
	string m_Comment2 = "NULL";
	string m_Comment3 = "NULL";

	Point CommentPos1;
	Point CommentPos2;
	Point CommentPos3;
	int CommentCount=1;

	unsigned int nSeed = (unsigned)time(NULL);

	enum {
		GOOD,
		BAD
	};
public:
	Comment();
	  ~Comment();

	  void Init();
	  void Update();
	  void Render();
	  void Release();
};
