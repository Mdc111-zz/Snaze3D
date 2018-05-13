#ifndef SNAKEHEADER 
#define SNAKEHEADER

#include <glut.h>

class Snake {
public:
	GLint   snakeBodyPos[2][100] = { {} };
	GLint   snakeXPos = 5;
	GLint   snakeYPos = 10;
	GLint   lastSnakeXPos[2] = {};
	GLint   lastSnakeYPos[2] = {};
	GLbyte  direction = 0;
	GLint   snakeSize = 0;
	void DrawSnake();
	bool CheckSelfCollision();
	void ResetSnake();
	void SaveSnakePosition();
};
#endif