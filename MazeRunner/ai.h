#ifndef AI_H
#define AI_H

#include <sprite.h>

class Maze;
class Player;

class Ai : public Sprite
{
public:
	Ai(Maze* l,DrawSprite* de,int s_index,float x = 1,float y = 1,int i_lives = 1);

	void addTarget(Player* g);
	bool move(float x,float y);
	void idleUpdate();
protected:
	void simulateAI();
	Player* target;
};

#endif