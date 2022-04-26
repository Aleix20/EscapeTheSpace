#ifndef WORLD_H
#define WORLD_H
#include "includes.h"
#include "image.h"
#include "utils.h"
#include "synth.h"
#include "framework.h"
#include "player.h"
#include "gamemap.h"
#include "pressurePlate.h"

constexpr auto NUMBEROFPLAYERS = 2;
constexpr auto NUMBEROFMAPS = 3;
constexpr auto NUMBEROFTILESETS = 1;
constexpr auto NUMBEROFPAGESTUT = 6;
struct sItems {
	sDoor* doors;
	PressurePlate* plates;
	int size;
};
class World
{
private:
	
	
public:
	Player players[NUMBEROFPLAYERS];
	GameMap* mapas[NUMBEROFMAPS][NUMBEROFMAPS];
	GameMap* mapasC[NUMBEROFMAPS][NUMBEROFMAPS];
	GameMap* mapaActual;
	GameMap* mapaActualC;
	sItems items[NUMBEROFMAPS][NUMBEROFMAPS];
	Image tilesets;
	Image outro;
	Image background;
	Image gameOver;
	Image gas;
	Image tutorial[NUMBEROFPAGESTUT];
	Image font;
	Image minifont;
	Vector2 mapaActualPos ;
	Vector2 mapaActualPosC ;
	Synth::SamplePlayback* currentSound;
	bool sound;
	bool firstInit;

	int tutorialPage;
	int numberOfGas;
	float time;
	World();
	void drawMap(Image* framebuffer);
	void updateMap();
	Vector2i worldToCell(Vector2 worldSize, int cellsize);
	bool isValid(Vector2 worldPos);
	void updateMaps();


};

#endif

