#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <drawsprite.h>
#include <player.h>
#include <maze.h>
#include <weapon.h>

using namespace std;

class  Game
{
public :
	bool run(void);

protected:
	bool getInput(char* c);
	void timerUpdate(void);

private:
	double framecount;
	double starttime;
	double lasttime;
	DrawSprite drawArea;
	int posx;
	Weapon* player;
	Maze* maze;
};

#endif