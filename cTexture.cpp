#include "stdafx.h"
#include "cTexture.h"


cTexture::cTexture()
	: m_image(nullptr) , m_info(nullptr) , m_Oldimage(nullptr)
{
	int GetWidth = WINSIZEX;
	int GetHight = WINSIZEY;

}


cTexture::~cTexture()
{
	SAFE_DELETE(m_info);
	SAFE_DELETE(m_Oldimage);
}
