#ifndef MAZE_H
#define MAZE_H

#include <iostream>
#include <drawsprite.h>
#include <stdlib.h>
#include <list>

using std::list;

class Sprite;
class Player;

class Maze
{
public:
	Maze(DrawSprite* de,int width = 30,int height = 20);
	~Maze();
	void addPlayer(Player* p);
	void Update();
	void draw();
	bool keyPress(char c);
	friend class Sprite;

	void addEnemies(int num);
	void addNPC(Sprite* spr);
	list <Sprite*> npc;
	list <Sprite*>::iterator Iter;


protected:
	void createLevel();
private:
	int width;
	int height;

	char** maze;

	Player* player;
	DrawSprite* drawArea;
};

enum 
{
	TILE_EMPTY,
	TILE_WALL,
};

enum
{
	SPRITE_PLAYER,
	SPRITE_ENEMY,
	SPRITE_FIREBALL
};

#endif