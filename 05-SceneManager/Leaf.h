#pragma once

#include "GameObject.h"
#include "Detection.h"

#define LEAF_FLYING_SPEED 0.05f
#define LEAF_MAX_VX 0.11f
#define LEAF_MAX_VY 0.010f
#define LEAF_AX 0.00015f
#define LEAF_BBOX_WIDTH 17
#define LEAF_BBOX_HEIGHT 17
#define LEAF_BBOX_HEIGHT_DIE 7

#define LEAF_FLY_TIME_OUT 300


#define LEAF_STATE_NOT_ACTIVATED 0
#define LEAF_STATE_FLYING 100

#define LEAF_SPAWN_OFFSET 0



class CLeaf : public CGameObject
{
protected:
	float ax;
	float ay;
	bool activated = false;
	
	ULONGLONG flyTimeOutStart = 0;

	virtual void GetBoundingBox(float& left, float& top, float& right, float& bottom);
	virtual void Update(DWORD dt, vector<LPGAMEOBJECT>* coObjects);
	virtual void Render();
	virtual void OnNoCollision(DWORD dt);
	int IsCollidable() { return 0; };
	int IsBlocking() { return 0; }
	void OnCollisionWith (LPCOLLISIONEVENT e);



public:
	CLeaf(float x, float y, bool ativate);
	void SetState(int state);
	int GetObjectType() { return OBJECT_TYPE_LEAF; };
};