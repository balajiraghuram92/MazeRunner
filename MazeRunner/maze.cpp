#include <maze.h>
#include <ai.h>
#include <player.h>

Maze::Maze(DrawSprite* de,int w,int h)
{
	drawArea = de;

	width = w;
	height = h;

	player =0;

	// create memory for our level
	maze = new char*[width];
	for(int x = 0; x < width ;x++)
	{
		maze[x] = new char[height];
	}

	//create the level
	createLevel();

	drawArea->setMap(maze);
	
}

Maze::~Maze()
{
	for(int x = 0 ; x < width ; x++)
		delete[] maze[x];
	delete[] maze;

	for(Iter = npc.begin() ; Iter != npc.end();++Iter)
	delete (*Iter);
}

void Maze::createLevel()
{
	for(int x =0 ;x <width ;x++)
	{
		for(int y =0 ;y < height ; y++)
		{
			int random = rand() % 100;
			if(y == 0 || y == height -1 || x == 0 || x == width -1 )
			{
				maze[x][y] = TILE_WALL;
			}
			else
			{
			if(random < 90 || (x < 3 && y < 3))
				maze[x][y] = TILE_EMPTY;
			else
				maze[x][y] = TILE_WALL;
			}
		}
	}
}

void Maze::draw()
{
	drawArea->drawBackground();
}

void Maze::addPlayer(Player* p)
{
	player = p;
}

bool Maze::keyPress(char c)
{
	if(player)
	{
		if(player->keyPress(c))
			return true;
		return false;
	}
}

void Maze::Update()
{
	for(Iter = npc.begin() ; Iter != npc.end();++Iter)
	{
		(*Iter)->idleUpdate();
		if((*Iter)->IsAlive() == false)
		{
			Sprite* temp =*Iter;

			Iter--;
			delete temp;
			npc.remove(temp);
		}
	}
}

void Maze::addEnemies(int num)
{
	int  i = num;

	while(i>0)
	{
		int xpos = int((float(rand() % 100))/ 100 * (width - 2)+1);
		int ypos = int((float(rand() % 100)) / 100 * (height -2)+1);
		if(maze[xpos][ypos] != TILE_WALL)
		{
			Ai* temp = new Ai(this,drawArea,SPRITE_ENEMY,(float)xpos,(float)ypos);
			temp->addTarget(player);

			addNPC((Sprite*)temp);
			i--;
		}
	}

}

void Maze::addNPC(Sprite* spr)
{
	npc.push_back(spr);
}