#include "stdafx.h"
#include "cFontManager.h"


cFontManager::cFontManager()
{

}


cFontManager::~cFontManager()
{

}

void cFontManager::FontSet()
{
	HDC hdc;
	AddFontResourceA("./Fonts/JejuGothic.ttf"); 
}
