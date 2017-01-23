#include <ai.h>
#include <player.h>
#include <maze.h>

#include <math.h>
#include <stdlib.h>

Ai::Ai(Maze* l,DrawSprite* de,int s_index,float x,float y,int i_lives):Sprite(l,de,s_index,x,y,i_lives)
{
	target = 0;
	classID = AI_CLASSID;
}

bool Ai::move(float x,float y)
{
	int xpos = (int)(pos.x + x);
	int ypos = (int)(pos.y + y);
	if(isValidLevelmove(xpos,ypos))
	{
		list <Sprite*>::iterator Iter;
		for(Iter = maze->npc.begin(); Iter != maze->npc.end();++Iter)
		{
			if((*Iter) != this && int((*Iter)->getX()) == xpos & int((*Iter)->getY()) == ypos)
				return false;
		}
	erase(pos.x,pos.y);
	
	pos.x += x;
	pos.y += y;

	facingDirection.x = x;
	facingDirection.y = y;
	draw(pos.x,pos.y);
	if((int)target->getX() == xpos && (int)target->getY() == ypos)
		target->addLives(-1);
	return true;
	}
	return false;
}

void Ai::idleUpdate()
{
	if(target)
		simulateAI();
}

void Ai::addTarget(Player* g)
{
	target = g;
}

void Ai::simulateAI()
{
	vector target_pos = target->getPosition();
	vector direction;

	direction.x = target_pos.x - pos.x;
	direction.y = target_pos.y - pos.y;

	float mag = sqrt(direction.x*direction.x + direction.y * direction.y);
	direction.x = direction.x/ (mag * 25);
	direction.y = direction.y/ (mag * 25);

	if(!move(direction.x,direction.y))
	{
		while(!move(float(rand() % 3 -1),float(rand() % 3 -1)))
		{

		}
	}
	
}