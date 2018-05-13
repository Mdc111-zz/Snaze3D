#ifndef SNAKEHEADER 
#define SNAKEHEADER

#include <glut.h>
class Snake {
public:
	GLint   snakeBodyPos[2][100] = { {} };
	GLint   snakeXPos = 5;
	GLint   snakeYPos = 10;
	GLint   snakeSize = 0;
	void DrawSnake();
};
#endif