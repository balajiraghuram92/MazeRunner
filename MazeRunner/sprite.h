#ifndef SPRITE_H
#define SPRITE_H

#include <drawsprite.h>
#include <iostream>
#include <maze.h>


enum
{
	SPRITE_CLASSID,
	PLAYER_CLASSID,
	AI_CLASSID,
	BULLET_CLASSID,
	WEAPON_CLASSID
};


class vector
{
public :
	float x;
	float y;

};

class Sprite
{
public:
	Sprite(Maze* l,DrawSprite* de,int s_index,float x = 1,float y = 1,int i_lives = 1);
	~Sprite();

	vector getPosition();
	float getX();
	float getY();

	virtual void addLives(int num = 1);
	int getLives();
	bool IsAlive();
	virtual bool move(float x,float y);
	virtual void idleUpdate();
	friend class Bullet;
protected:
	vector facingDirection;
	void draw(float x,float y);	
	void erase(float x,float y);
	bool isValidLevelmove(int xpos,int ypos);
	
	Maze* maze;
	DrawSprite *drawArea;
	vector pos;
	int spriteIndex;
	int numLives;
	int classID;


};
#endif