#include <game.h>
#define GAME_SPEED  33.333

bool Game::run(void)
{
	maze = new Maze(&drawArea,30,20);
	drawArea.CreateBackgroundTile(TILE_EMPTY,' ');
	drawArea.CreateBackgroundTile(TILE_WALL,219);
	
	
	drawArea.createSprite(SPRITE_PLAYER,1);
	drawArea.createSprite(SPRITE_ENEMY,'@');
	drawArea.createSprite(SPRITE_FIREBALL,'#');
	player = new Weapon(maze,&drawArea,0);
	maze->draw();
	maze->addPlayer(player);
	maze->addEnemies(3);
	char key = ' ';
	posx = 0;
	framecount = 0;
	lasttime = 0;
	starttime = timeGetTime();
	player->move(0,0);
	while (key != 'q')
	{
		while(!getInput(&key))
			timerUpdate(); 
		maze->keyPress(key);
	}

	delete player;
	return true;
}

bool Game::getInput(char* c)
{
	if(kbhit())
	{
		*c = getch();
		return true;
	}
	return false;
}


void Game::timerUpdate(void)
{
	double currenttime = timeGetTime() - lasttime;
	if(currenttime < GAME_SPEED)
		return;
	maze->Update();
	framecount++;
	lasttime = timeGetTime();
}