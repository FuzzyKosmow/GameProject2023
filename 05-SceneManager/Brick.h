#pragma once
	#include "GameObject.h"
	#include "ParticleSystem.h"

	




	#define ID_ANI_BRICK 10003
	#define BRICK_WIDTH 16
	#define BRICK_BBOX_WIDTH 16
	#define BRICK_BBOX_HEIGHT 16
	#define ID_SPRITE_BRICK_BREAK_PARTICLE 900000
	#define BRICK_PARTICLE_SPAWN_COUNT 4
	#define BRICK_BREAK_SCORE 10
	//As of now it only have one state, static. If broke, the thing is just gone. I guess?

	class CBrick : public CGameObject {

	public:

		CBrick(float x, float y) : CGameObject(x, y) {};
		void Render();
		void Update(DWORD dt) {}
		void GetBoundingBox(float& l, float& t, float& r, float& b);
		virtual int IsCollidable() { return 1; };
		virtual int IsBlocking() { return 1; };
		void Break();
		int GetObjectType () { return OBJECT_TYPE_BRICK; }
		
	};