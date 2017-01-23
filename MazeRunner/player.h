#ifndef PLAYER_H
#define PLAYER_H

#include <sprite.h>
#include <maze.h>

class Player: public Sprite
{
public:
	Player(Maze* l,DrawSprite* de,int s_index,float x = 1,float y = 1,int lives  = 3,char up_key = 'w',char down_key = 's',char left_key = 'a',char right_key = 'd');

	virtual bool keyPress(char c);
	virtual void addLives(int num =1);
protected:
	char upkey;
	char downKey;
	char leftKey;
	char rightKey;

};

#endif