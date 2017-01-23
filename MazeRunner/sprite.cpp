#include <sprite.h>

Sprite::Sprite(Maze* l,DrawSprite* de,int s_index,float x,float y,int i_lives)
{	
maze = l;
drawArea = de;
pos.x = x;
pos.y = y;

spriteIndex = s_index;
numLives = i_lives;
classID = SPRITE_CLASSID;
facingDirection.x =1;
facingDirection.y = 0;
}

Sprite::~Sprite()
{
	//erase the dying sprite
	erase(pos.x,pos.y);
}

vector Sprite::getPosition()
{
	return pos;
}

float Sprite::getX()
{
	return pos.x;
}

float Sprite::getY()
{
	return pos.y;
}

void Sprite::addLives(int num)
{
	numLives +=num;
}
int Sprite::getLives()
{
	return numLives;
}
bool Sprite::IsAlive()
{
	return (numLives > 0);
}
bool Sprite::move(float x,float y)
{
	int xpos = (int)(pos.x + x);
	int ypos = (int)(pos.y + y);
	if(isValidLevelmove(xpos,ypos))
	{
	erase(pos.x,pos.y);
	
	pos.x += x;
	pos.y += y;

	facingDirection.x = x;
	facingDirection.y = y;
	draw(pos.x,pos.y);
	return true;
	}
	return false;

}

void Sprite::draw(float x,float y)
{
	drawArea->drawSprite(spriteIndex,(int)x,(int)y);
}
void Sprite::erase(float x,float y)
{
	drawArea->eraseSprite((int)x,(int)y);
}
bool Sprite::isValidLevelmove(int xpos,int ypos)
{
	if(maze->maze[xpos][ypos] != TILE_WALL)
		return true;
	return false;
}

void Sprite::idleUpdate()
{

}