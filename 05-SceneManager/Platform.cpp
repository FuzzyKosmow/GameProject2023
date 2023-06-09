#include "Platform.h"

#include "Sprite.h"
#include "Sprites.h"

#include "Textures.h"

void CPlatform::RenderBoundingBox()
{
	D3DXVECTOR3 p(x, y, 0);
	RECT rect;

	LPTEXTURE bbox = CTextures::GetInstance()->Get(ID_TEX_BBOX);

	float l, t, r, b;

	GetBoundingBox(l, t, r, b);
	rect.left = 0;
	rect.top = 0;
	rect.right = (int)r - (int)l;
	rect.bottom = (int)b - (int)t;

	float cx, cy;
	CGame::GetInstance()->GetCamPos(cx, cy);

	float xx = x - this->cellWidth / 2 + rect.right / 2;

	CGame::GetInstance()->Draw(xx - cx, y - cy, bbox, nullptr, BBOX_ALPHA, rect.right - 1, rect.bottom - 1);
}

void CPlatform::Render()
{
	if (this->length <= 0) return; 
	float xx = x; 
	CSprites * s = CSprites::GetInstance();

	s->Get(this->spriteIdBegin)->Draw(xx, y);
	xx += this->cellWidth;
	if (spriteIdMiddle != -1)
	{
		for (int i = 1; i < this->length - 1; i++)
		{
			s->Get(this->spriteIdMiddle)->Draw(xx, y);
			xx += this->cellWidth;
		}
	}
	
	if (length>1)
		s->Get(this->spriteIdEnd)->Draw(xx, y);

	/*RenderBoundingBox();*/
}

void CPlatform::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	float cellWidth_div_2 = this->cellWidth / 2;
	l = x - cellWidth_div_2;
	t = y - this->cellHeight / 2;
	r = l + this->cellWidth * this->length;
	b = t + this->cellHeight;
}

void CVerticalObject::RenderBoundingBox()
{
	D3DXVECTOR3 p(x, y, 0);
	RECT rect;
	LPTEXTURE bbox = CTextures::GetInstance()->Get(ID_TEX_BBOX);
	float l, t, r, b;
	GetBoundingBox(l, t, r, b);
	rect.left = 0;
	rect.top = 0;
	rect.right = (int)r - (int)l;
	rect.bottom = (int)b - (int)t;
	float cx, cy;
	CGame::GetInstance()->GetCamPos(cx, cy);
	float yy = y - this->cellHeight / 2 + rect.bottom / 2;
	CGame::GetInstance()->Draw(x- cx, yy- cy, bbox, nullptr, BBOX_ALPHA, rect.right - 1, rect.bottom - 1);
}

//Render from top to bottom
void CVerticalObject::Render()
{
	if (this->height <= 0) return;
	if (this == NULL)
		return;
	float yy = y;
	CSprites * s = CSprites::GetInstance();
	s->Get(this->spriteIdBegin)->Draw(x, yy);
	yy += this->cellHeight;
	for (int i = 1; i < this->height - 1; i++)
	{
		
		s->Get(this->spriteIdMiddle)->Draw(x, yy);
		yy -= this->cellHeight;
	}
	if (height>1)
		s->Get(this->spriteIdEnd)->Draw(x, yy);
	
}

void CVerticalObject::GetBoundingBox(float& l, float& t, float& r, float& b)
{
	if (blocking)
	{
		float cellHeight_div_2 = this->cellHeight / 2;
		l = x - this->cellWidth / 2;
		t = y - cellHeight_div_2;
		r = l + this->cellWidth;
		b = t + this->cellHeight * this->height;
	}
	
}


