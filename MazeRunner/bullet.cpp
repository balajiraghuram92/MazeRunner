#include <bullet.h>

Bullet::Bullet(Maze* l,DrawSprite* de,int s_index,float x,float y,float xDir,float yDir,int i_lives):Sprite(l,de,s_index,x,y,i_lives)
{
	facingDirection.x = xDir;
	facingDirection.y  = yDir;

	classID = BULLET_CLASSID;
}

void Bullet::idleUpdate()
{
	if(Sprite::move(facingDirection.x,facingDirection.y))
	{
		list <Sprite*>::iterator Iter;

		for(Iter = maze->npc.begin();Iter != maze->npc.end();++Iter)
		{
			if((*Iter)->classID != classID && (*Iter)->getX() == (int)pos.x && (*Iter)->getY() == (int) pos.y)
			{
				(*Iter)->addLives(-1);
				addLives(-1);
			}
		}
	}
	else
		addLives(-1);

}