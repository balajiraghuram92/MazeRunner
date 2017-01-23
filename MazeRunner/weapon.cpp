#include <weapon.h>
#include <bullet.h>


Weapon::Weapon(Maze* l,DrawSprite* de,int s_index,float x,float y,int lives,char spell_key,char up_key,char down_key,char left_key,char right_key):Player(l,de,s_index,x,y,lives,up_key,down_key,left_key,right_key)
{
	spellKey = spell_key;
	classID = WEAPON_CLASSID;

}

bool Weapon::keyPress(char c)
{
	bool val = Player::keyPress(c);
	if(val == false)
	{
		if(c == spellKey)
		{
			castSpell();
			return true;
		}
		return false;
	}
}


void Weapon::castSpell()
{
	Bullet* temp = new Bullet(maze,drawArea,SPRITE_FIREBALL,(int)pos.x + facingDirection.x,(int)pos.y + facingDirection.y,facingDirection.x,facingDirection.y);

	maze->addNPC((Sprite*)temp);
}
	