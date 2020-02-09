#pragma once
class cFontManager : public singleton<cSceneManager>
{
public:
	//HFONT Font = CreateFont(30, 0, 0, 0, 0, 0, 0, 0, DEFAULT_CHARSET, 0, 0, 0, 0, "JejuGothic");
	//AddFontResourceA("./Font/JejuGothic.ttf");

public:
	cFontManager();
	~cFontManager();
	void FontSet();
};
