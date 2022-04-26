#ifndef GAMEMAP_H
#define GAMEMAP_H
#include "utils.h"
class GameMap
{
public:
	int width;
	int height;
	sCell* data;
	GameMap();
	GameMap(int w, int h);
	sCell& getCell(int x, int y);
	void setCell(int x, int y, eCellType type);
	static GameMap* loadGameMap(const char* filename);
	
	
	
};
#endif

