#include <player.h>

Player::Player(Maze* l,DrawSprite*de,int s_index,float x,float y,int lives,char up_key,char down_key,char left_key,char right_key):Sprite(l,de,s_index,x,y,lives)
{
	 upkey  = up_key;
	 downKey = down_key;
	 leftKey = left_key;
	 rightKey = right_key;

	classID = PLAYER_CLASSID;
}

bool Player::keyPress(char c)
{
if(c == upkey)
{
	return  move (0,-1);
}
else if(c == downKey)
{
	return move(0,1);
}
else if(c == leftKey)
{
	return move(-1,0);
}
else if(c == rightKey)
{
	return move(1,0);
}
return false;
}

void Player::addLives(int num)
{
	Sprite::addLives(num);
	if(Sprite::IsAlive())
	{
		pos.x = 1;
		pos.y = 1;
		move(0,0);
	}
}