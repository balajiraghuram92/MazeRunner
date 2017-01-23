#include <drawsprite.h>

DrawSprite::DrawSprite(int xsize,int ysize) : screenWidth(xsize),screenHeight(ysize)
{
	screenWidth = xsize;
	screenHeight = ysize;

	cursorVisibility(false);
	
	map = 0;
}

DrawSprite::~DrawSprite()
{
	cursorVisibility(true);
}

int DrawSprite::createSprite(int index,char c)
{
	if(index >= 0 && index < 16)
	{
	spriteImage[index] = c;
	return index;
	}
	return -1;
}


void DrawSprite::deleteSprite(int index)
{

}

void DrawSprite::drawSprite(int index,int posx,int posy)
{
	gotoxy(posx,posy);
	cout << spriteImage[index] << endl;
}

void DrawSprite::eraseSprite(int posx,int posy)
{
	gotoxy(posx,posy);
	cout<<' ';
}

void DrawSprite::gotoxy(int x,int y)
{
	HANDLE output_handle;
	output_handle = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.X = x;
	pos.Y  = y;
	SetConsoleCursorPosition(output_handle,pos);
}

void DrawSprite::cursorVisibility(bool Visibility)
{
	HANDLE output_handle;
	CONSOLE_CURSOR_INFO cciInfo;
	cciInfo.dwSize = 1;
	cciInfo.bVisible = Visibility;
	output_handle = GetStdHandle(STD_OUTPUT_HANDLE);

	SetConsoleCursorInfo(output_handle,&cciInfo);
}

void DrawSprite::setMap(char** data)
{
	map = data;
}

void DrawSprite::drawBackground()
{
	if(map)
	{
		for(int y = 0 ; y < screenHeight ; y++)
		{
			gotoxy(0,y);
			for(int x= 0; x < screenWidth ; x++)
			{ 
				cout<<tileImage[map[x][y]];
			}
		}
	}
}

void DrawSprite::CreateBackgroundTile(int index,char c)
{
	if(index >= 0 && index < 16)
	{
		tileImage[index] = c;
	}
} 

