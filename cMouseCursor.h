#pragma once
class cMouseCursor
{
public:
	cTexture * g_MNomal;
	cTexture * g_MOnCursor;
	cTexture * g_MClick;

	Point g_MPos;
	int state;

	enum MouseState {
		mNomal, mDown, mUp,
	};

private:
public:
	cMouseCursor();
	~cMouseCursor();

	void Init();
	bool Update(Point pos);
	void Render(Point pos);
	void Release();

	bool isClickDown(int x, int y);
	bool isOver();
};

