#include "world.h"
#include "game.h"
#define PLAYERHEIGHT 18
#define PLAYERWIDTH 13
#define GRIDPIXELS 8
World::World()
{
	this->sound = true;
	this->firstInit = true;
	this->tutorialPage = 0;
	this->numberOfGas = 12;
	this->time = 100;
	this->mapaActualPos = Vector2(1, 2);
	this->mapaActualPosC = Vector2(1, 2);


	for (int i = 0; i < 6; i++)
	{
		std::string a = "data/tutorial/tutorial";
		a.append(std::to_string(i));
		a.append(".tga");
		this->tutorial[i].loadTGA(a.c_str());
	}
	for (int a = 0; a < 3; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			std::string str = "data/mapas/map";
			str.append(std::to_string(a));
			str.append(std::to_string(b));
			str.append(".map");
			this->mapas[a][b] = GameMap::loadGameMap(str.c_str());
		}
	}
	
	for (int a = 0; a < 3; a++)
	{
		for (int b = 0; b < 3; b++)
		{
			std::string str = "data/mapas/mapC";
			str.append(std::to_string(a));
			str.append(std::to_string(b));
			str.append(".map");
			this->mapasC[a][b] = GameMap::loadGameMap(str.c_str());
		}
	}
	//Items for each room
	this->items[0][0].doors = new sDoor[1];
	this->items[0][0].plates = new PressurePlate[2];
	this->items[0][1].doors = new sDoor[1];
	this->items[0][1].plates = new PressurePlate[1];
	this->items[0][2].doors = new sDoor[2];
	this->items[0][2].plates = new PressurePlate[2];
	this->items[1][0].doors = new sDoor[2];
	this->items[1][0].plates = new PressurePlate[3];
	this->items[1][1].doors = new sDoor[3];
	this->items[1][1].plates = new PressurePlate[4];
	this->items[2][0].doors = new sDoor[3];
	this->items[2][0].plates = new PressurePlate[5];
	this->items[2][1].doors = new sDoor[1];
	this->items[2][1].plates = new PressurePlate[1];
	this->items[2][2].doors = new sDoor[1];
	this->items[2][2].plates = new PressurePlate[1];
		
	
	//Items 00
	this->items[0][0].doors[0].exists = true;
	this->items[0][0].doors[0].lock1 = true;
	this->items[0][0].doors[0].lock2 = true;
	this->items[0][0].plates[0] = PressurePlate(Vector2(7.5 * GRIDPIXELS, 12.5 * GRIDPIXELS), Vector2(1 * GRIDPIXELS, 10 * GRIDPIXELS), 2, eCellType::DOORP3, eCellType::FLOOR, eDoorType::HORITZONTAL2,  &this->items[0][0].doors[0]);
	this->items[0][0].plates[1] = PressurePlate(Vector2(14.5 * GRIDPIXELS, 12.5 * GRIDPIXELS), Vector2(1 * GRIDPIXELS, 10 * GRIDPIXELS), 1, eCellType::DOORP3, eCellType::FLOOR, eDoorType::HORITZONTAL2,  &this->items[0][0].doors[0]);
	this->items[0][0].size = 2;

	//Items 01
	this->items[0][1].doors[0].exists = true;
	this->items[0][1].doors[0].lock1 = true;
	this->items[0][1].doors[0].lock2 = false;
	this->items[0][1].plates[0] = PressurePlate(Vector2(16.5 * GRIDPIXELS, 3.5 * GRIDPIXELS), Vector2(4 * GRIDPIXELS, 6 * GRIDPIXELS), 1, eCellType::DOORP3, eCellType::FLOOR, eDoorType::VERTICAL,  &this->items[0][1].doors[0]);
	this->items[0][1].size = 1;


	//items 02
	this->items[0][2].doors[0].exists = true;
	this->items[0][2].doors[0].lock1 = true;
	this->items[0][2].doors[0].lock2 = false;
	this->items[0][2].doors[1].exists = true;
	this->items[0][2].doors[1].lock1 = true;
	this->items[0][2].doors[1].lock2 = false;
	this->items[0][2].plates[0] = PressurePlate(Vector2(5.5 * GRIDPIXELS, 9.5 * GRIDPIXELS), Vector2(8 * GRIDPIXELS, 8 * GRIDPIXELS), 1, eCellType::DOORP3, eCellType::FLOOR, eDoorType::HORITZONTAL3,  &this->items[0][2].doors[0]);
	this->items[0][2].plates[1] = PressurePlate(Vector2(13.5 * GRIDPIXELS, 9.5 * GRIDPIXELS), Vector2(8 * GRIDPIXELS, 5 * GRIDPIXELS), 1, eCellType::DOORP3, eCellType::FLOOR, eDoorType::HORITZONTAL3,  &this->items[0][2].doors[1]);
	this->items[0][2].size = 2;


	//items 10
	this->items[1][0].doors[0].exists = true;
	this->items[1][0].doors[0].lock1 = true;
	this->items[1][0].doors[0].lock2 = false;
	this->items[1][0].doors[1].exists = true;
	this->items[1][0].doors[1].lock1 = true;
	this->items[1][0].doors[1].lock2 = true;
	this->items[1][0].plates[0] = PressurePlate(Vector2(16.5 * GRIDPIXELS, 12.5 * GRIDPIXELS), Vector2(8 * GRIDPIXELS, 14 * GRIDPIXELS), 1, eCellType::DOORP3, eCellType::FLOOR, eDoorType::HORITZONTAL3,  &this->items[1][0].doors[0]);
	this->items[1][0].plates[1] = PressurePlate(Vector2(4.5 * GRIDPIXELS, 9.5 * GRIDPIXELS), Vector2(11 * GRIDPIXELS, 1 * GRIDPIXELS), 2, eCellType::DOORP3, eCellType::FLOOR, eDoorType::VERTICAL3,  &this->items[1][0].doors[1]);
	this->items[1][0].plates[2] = PressurePlate(Vector2(4.5 * GRIDPIXELS, 4.5 * GRIDPIXELS), Vector2(11 * GRIDPIXELS, 1 * GRIDPIXELS), 1, eCellType::DOORP3, eCellType::FLOOR, eDoorType::VERTICAL3,  &this->items[1][0].doors[1]);
	this->items[1][0].size = 3;

	//items 11
	this->items[1][1].doors[0].exists = true;
	this->items[1][1].doors[0].lock1 = true;
	this->items[1][1].doors[0].lock2 = false;
	this->items[1][1].doors[1].exists = true;
	this->items[1][1].doors[1].lock1 = true;
	this->items[1][1].doors[1].lock2 = false;
	this->items[1][1].doors[2].exists = true;
	this->items[1][1].doors[2].lock1 = true;
	this->items[1][1].doors[2].lock2 = true;
	this->items[1][1].plates[0] = PressurePlate(Vector2(16.5 * GRIDPIXELS, 3.5 * GRIDPIXELS), Vector2(8 * GRIDPIXELS, 14 * GRIDPIXELS), 1, eCellType::DOORP3, eCellType::FLOOR, eDoorType::HORITZONTAL3,  &this->items[1][1].doors[0]);
	this->items[1][1].plates[1] = PressurePlate(Vector2(12.5 * GRIDPIXELS, 10.5 * GRIDPIXELS), Vector2(0 * GRIDPIXELS, 6 * GRIDPIXELS), 1, eCellType::DOORP3, eCellType::FLOOR, eDoorType::VERTICAL,  &this->items[1][1].doors[1]);
	this->items[1][1].plates[2] = PressurePlate(Vector2(6.5 * GRIDPIXELS, 5.5 * GRIDPIXELS), Vector2(8 * GRIDPIXELS, 0 * GRIDPIXELS), 2, eCellType::DOORP3, eCellType::FLOOR, eDoorType::HORITZONTAL3,  &this->items[1][1].doors[2]);
	this->items[1][1].plates[3] = PressurePlate(Vector2(1.5 * GRIDPIXELS, 12.5 * GRIDPIXELS), Vector2(8 * GRIDPIXELS, 0 * GRIDPIXELS), 1, eCellType::DOORP3, eCellType::FLOOR, eDoorType::HORITZONTAL3,  &this->items[1][1].doors[2]);
	this->items[1][1].size = 4;

	//iTEMS 20
	this->items[2][0].doors[0].exists = true;
	this->items[2][0].doors[0].lock1 = true;
	this->items[2][0].doors[0].lock2 = true;
	this->items[2][0].doors[1].exists = true;
	this->items[2][0].doors[1].lock1 = true;
	this->items[2][0].doors[1].lock2 = true;
	this->items[2][0].doors[2].exists = true;
	this->items[2][0].doors[2].lock1 = true;
	this->items[2][0].doors[2].lock2 = false;
	this->items[2][0].plates[0] = PressurePlate(Vector2(9.5 * GRIDPIXELS, 12.5 * GRIDPIXELS), Vector2(12 * GRIDPIXELS, 4 * GRIDPIXELS), 1, eCellType::DOORP3, eCellType::FLOOR, eDoorType::HORITZONTAL3,  &this->items[2][0].doors[2]);
	this->items[2][0].plates[1] = PressurePlate(Vector2(9.5 * GRIDPIXELS, 4.5 * GRIDPIXELS), Vector2(2 * GRIDPIXELS, 7 * GRIDPIXELS), 2, eCellType::DOORP3, eCellType::FLOOR, eDoorType::HORITZONTAL3,  &this->items[2][0].doors[1]);
	this->items[2][0].plates[2] = PressurePlate(Vector2(16.5 * GRIDPIXELS, 12.5 * GRIDPIXELS), Vector2(2 * GRIDPIXELS, 7 * GRIDPIXELS), 1, eCellType::DOORP3, eCellType::FLOOR, eDoorType::HORITZONTAL3,  &this->items[2][0].doors[1]);
	this->items[2][0].plates[3] = PressurePlate(Vector2(13.5 * GRIDPIXELS, 7.5 * GRIDPIXELS), Vector2(12 * GRIDPIXELS, 9 * GRIDPIXELS), 2, eCellType::DOORP3, eCellType::FLOOR, eDoorType::HORITZONTAL2,  &this->items[2][0].doors[0]);
	this->items[2][0].plates[4] = PressurePlate(Vector2(17.5 * GRIDPIXELS, 2.5 * GRIDPIXELS), Vector2(12 * GRIDPIXELS, 9 * GRIDPIXELS), 1, eCellType::DOORP3, eCellType::FLOOR, eDoorType::HORITZONTAL2,  &this->items[2][0].doors[0]);

	this->items[2][0].size = 5;
	
	//No items
	this->items[1][2].size = 0;
	this->items[2][1].size = 0;
	this->items[2][2].size = 0;

	//LOADS
	this->tilesets.loadTGA("data/tileset.tga");
	this->outro.loadTGA("data/outro.tga");
	this->gameOver.loadTGA("data/gameOver.tga");
	this->background.loadTGA("data/tutorial/tutorial.tga");
	this->gas.loadTGA("data/gas.tga");
	this->font.loadTGA("data/bitmap-font-white.tga");
	this->minifont.loadTGA("data/mini-font-white-4x6.tga");

	//PLAYERS
	this->players[0] = Player(Sprite("data/personaje1.tga", Vector2(65, 78), PLAYERWIDTH, PLAYERHEIGHT), Vector2(60, 60), false);
	this-> players[1] = Player(Sprite("data/personaje2.tga", Vector2(80, 60), PLAYERWIDTH, PLAYERHEIGHT), Vector2(80, 60), false);

	//INIT MAPS
	mapaActual = mapas[1][2];
	mapaActualC = mapasC[1][2];
}

void World::drawMap(Image* framebuffer)
{
	//size in pixels of a cell, we assume every row has 16 cells so the cell size must be image.width / 16
	
	//tilesets[0].resize(64, 64);
	int cs = tilesets.width / 16;
	//for every cell
	for (int x = 0; x < mapaActual->width; ++x)
		for (int y = 0; y < mapaActual->height; ++y)
		{
			//get cell info
			sCell& cell = mapaActual->getCell(x, y);
			if (cell.type == 0) //skip empty
				continue;
			int type = (int)cell.type;
			//compute tile pos in tileset image
			int tilex = (type % 16) * cs; 	//x pos in tileset
			int tiley = floor(type / 16) * cs;	//y pos in tileset
			Area area(tilex, tiley, cs, cs); //tile area
			int screenx = x * cs; //place offset here if you want
			int screeny = y * cs;
			//avoid rendering out of screen stuff
			if (screenx < -cs || screenx > framebuffer->width ||
				screeny < -cs || screeny > framebuffer->height)
				continue;

			//draw region of tileset inside framebuffer
			framebuffer->drawImage(tilesets, 		//image
				screenx, screeny, 	//pos in screen
				area); 		//area
		}

}

void World::updateMap()
{
	float* player1Y = &this->players[0].pos.y;
	float* player2Y = &this->players[1].pos.y;
	float* player1X = &this->players[0].pos.x;
	float* player2X = &this->players[1].pos.x;
	
	//Player going top frambuffer
	if (*player1Y < -10 || *player2Y < -10) {

		if (this->mapaActualPos.x > 0) {

			*player1Y = (float)110;
			*player1X = (float)77;
			*player2Y = (float)110;
			*player2X = (float)77;
			this->mapaActualPos.x--;
			this->mapaActualPosC.x--;
			updateMaps();
			
			
		}
	}
	//Player going down frambuffer
	if (*player1Y > 120 || *player2Y > 120) {

		if (this->mapaActualPos.x < 2) {

			*player1Y = (float)2;
			*player1X = (float)77;
			*player2Y = (float)2;
			*player2X = (float)77;
			this->mapaActualPos.x++;
			this->mapaActualPosC.x++;
			updateMaps();

		}
	}
	//Player going left frambuffer
	if (*player1X < -6 || *player2X < -6) {

		if (this->mapaActualPos.y > 0) {

			*player1X = (float)150;
			*player1Y = (float)58;
			*player2X = (float)150;
			*player2Y = (float)58;
			this->mapaActualPos.y--;
			this->mapaActualPosC.y--;
			updateMaps();

		}
	}
	//Player going right frambuffer
	if (*player1X > 160 || *player2X > 160) {

		//player exits through right in the final door
		if (this->mapaActualPos == Vector2(1,2) ) {
			Game::instance->currentStage = eStages::STAGEOUTRO;
			this->players[0].pos = Vector2(60, 60);
			this->players[1].pos = Vector2(80, 60);
			this->currentSound->stop();
			this->currentSound = Game::instance->synth.playSample("data/sounds/Interestellar.wav", 0.5, true);
			std::cout << "WIN " << std::endl;
		}
		else if (this->mapaActualPos.y < 2) {

			*player1X = (float)0;
			*player1Y = (float)58;
			*player2X = (float)0;
			*player2Y = (float)58;

			this->mapaActualPos.y++;
			this->mapaActualPosC.y++;
			updateMaps();

		}
	}

}

Vector2i World::worldToCell(Vector2 worldSize, int cellsize)
{
	return worldSize/cellsize;
}

bool World::isValid(Vector2 worldPos)
{
	Vector2i cellCord = worldToCell(worldPos, 8);
	int type = mapaActualC->getCell(cellCord.x, cellCord.y).type;
	

	//Checking all possible types for collision
	switch (type) {
	case 128:
		return false;
		break;
	case 129://FLOOR
		return true;
		break;
	case 130://GAS
		mapaActualC->setCell(cellCord.x, cellCord.y, eCellType::FLOOR);
		this->mapaActual->setCell(cellCord.x, cellCord.y, eCellType::FLOORO);
		Game::instance->synth.playSample("data/sounds/glup.wav", 1, false);
		this->numberOfGas--;
		return true;
		break;
	case 15:
		return false;
		break;
	case 1:
		return false;
		break;
	case 2:
		return false;
		break;
	case 3:
		return false;
		break;
	case 4:
		return false;
		break;
	case 13:
		return false;
		break;
	case 11:
		return false;
		break;
	case 12:
		return false;
		break;
	case 14:
		return false;
		break;
	case 7:
		return false;
		break;
	case 6:
		return false;
		break;
	case 8:
		return false;
		break;
	case 9:
		return false;
		break;
	case 10:
		return false;
		break;
	case 5:
		return false;
		break;
	default:
		return true;
	}
	
	
}

void World::updateMaps()
{
	this->mapaActual = this->mapas[(int)mapaActualPos.x][(int)mapaActualPos.y];
	this->mapaActualC = this->mapasC[(int)mapaActualPosC.x][(int)mapaActualPosC.y];
}

