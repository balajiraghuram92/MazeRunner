#ifndef WEAPON_H
#define WEAPON_H
 
#include <player.h>
#include <maze.h>
#include <drawsprite.h>

class Weapon : public Player
{
public:
	Weapon(Maze* l,DrawSprite* de,int s_index,float x = 1,float y = 1,int lives  = 3,char spell_key = ' ',char up_key = 'w',char down_key = 's',char left_key = 'a',char right_key = 'd');
	bool keyPress(char c);
protected:
	void castSpell();
private:
	char spellKey;
};

#endif