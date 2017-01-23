#ifndef DRAWSPRITE_H
#define DRAWSPRITE_H

#include <iostream>
#include <Windows.h>

using namespace std;

class DrawSprite
{
public :
	DrawSprite(int xSize = 30, int ySize = 20);
	~DrawSprite();
	int createSprite(int index,char c);
	void deleteSprite(int index);

	void setMap(char** data);
	void drawBackground();
	void CreateBackgroundTile(int index,char c);

	void eraseSprite(int posx,int posy);
	void drawSprite(int index,int posx,int posy);

protected :
	char** map;
	int screenWidth,screenHeight;
	char spriteImage[16];
	char tileImage[16];

private :
	void gotoxy(int x,int y);
	void cursorVisibility(bool Visibility);
};

#endif