/*  by Javi Agenjo 2013 UPF  javi.agenjo@gmail.com
	This contains several functions that can be useful when programming your game.
*/
#ifndef UTILS_H
#define UTILS_H

#include <string>
#include <sstream>
#include <iostream>   
#include <vector>
#include <string> 
#include "includes.h"
#include "framework.h"




class Shader;
class Texture;

enum eCellType : uint8 {
	EMPTY,
	GAS = 130,
	FLOORO = 20,
	WALL = 128,
	FLOOR = 129,
	DOORW = 15,
	DOORP = 1,
	DOORP1 = 2,
	DOORP3 = 3,
	DOORP4 = 6,
	DOORYO = 9,
	DOORO = 10,
	DOORBC = 8,
	DOORPUR= 7,
	DOORY = 4,
	DOORG = 13,
	DOORB = 11,
	DOORGC = 12,
	DOORGC1 =14,
	DOORR = 5
};

enum eStages:uint8 {
	STAGEMENU = 0,
	STAGEINTRO = 1,
	STAGEPLAY = 2,
	STAGEGAMEOVER = 3,
	STAGEOUTRO = 4
};
enum eDoorType : uint8 {
	VERTICAL = 0,
	VERTICAL3=4,
	HORITZONTAL3 = 3,
	HORITZONTAL2 = 2,
	HORITZONTAL1 = 1

};

struct sDoor {
	bool exists;
	bool lock1;
	bool lock2;
};




struct sCell {
	eCellType type;
	
};
struct sMapHeader {
	int w; //width of map
	int h; //height of map
	unsigned char bytes; //num bytes per cell
	unsigned char extra[7]; //filling bytes, not used
};

//General functions **************
long getTime(); //returns time since computer started (in milliseconds)
long getPrecisionTime();
std::string toString(float v);

//generic rendering fuctions
void drawGrid();
int drawText(float x, float y, std::string text, Vector4 c, float scale = 1); //returns the width in pixels
void drawPoints(std::vector<Vector3> points, float size, Vector4 color);
void drawLines(std::vector<Vector3> points, Vector4 color, bool strip = false);
void drawLines2D( const std::vector<Vector3>& points, Vector4 color, bool strip = false);
void drawRect(float x, float y, float w, float h, Vector4 color, float angle = 0, bool fill = false);
void drawRect2D(float x, float y, float w, float h, Vector4 color, Texture* tex = NULL, bool wireframe = false, Shader* shader = NULL);

//check opengl errors
bool checkGLErrors();

//files
std::string getPath();
bool readFile(const std::string& filename, std::string& content);

//returns the size of the dekstop (not the window, the full desktop)
Vector2 getDesktopSize( int display_index = 0 );

std::vector<std::string> tokenize(const std::string& source, const char* delimiters, bool process_strings = false);
std::vector<std::string>& split(const std::string &s, char delim, std::vector<std::string> &elems);
std::vector<std::string> split(const std::string &s, char delim);

std::string getGPUStats();


inline int inrange(int value, int range) { value = value % range; if (value < 0) value += range; return value; }


#endif
