#ifndef BULLET_H
#define BULLET_H

#include <sprite.h>

class Bullet : public Sprite
{
public:
	Bullet(Maze* l,DrawSprite* de,int s_index,float x =1,float y =1,float xDir = 0,float yDir = 0,int i_lives = 1);
	void idleUpdate();
protected:
};

#endif