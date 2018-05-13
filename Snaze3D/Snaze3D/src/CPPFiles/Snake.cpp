#include <time.h>
#include "../headerFiles/Snake.h"

#pragma region Snake

bool Snake::CheckSelfCollision() {
	for (int i = 0; i<snakeSize; i++)
		if (snakeBodyPos[0][i] == snakeXPos && snakeBodyPos[1][i] == snakeYPos) return true;
	return false;
}

void Snake::DrawSnake()
{
	//Drawing the head & the plane
	glPushMatrix();

	//Here we will draw the Head of the snake
	glTranslatef(snakeXPos, 0, snakeYPos);//Give it the location according to _x & _z
	glColor3f(1.0, 1.0, 0.0);
	glutSolidCube(1);

	glPopMatrix();
	//Drawing the body
	for (int i = 0; i<snakeSize; i++) {//Loop throw the size and draw spheres representing the body
		glPushMatrix();
		glTranslatef(snakeBodyPos[0][i], 0, snakeBodyPos[1][i]);//this will locate the spheres
		glColor3f(1.0, 1.0, 0.6);//Color Red
		glutSolidCube(1);
		glPopMatrix();
	}
}

void Snake::ResetSnake()
{
	snakeXPos = 5;
	snakeYPos = 10;
	direction = 0;
	snakeSize = 0;
}
void Snake::SaveSnakePosition() {
	for (int i = 0; i<snakeSize; i++) {// Save the positions of the body parts
		lastSnakeXPos[0] = lastSnakeXPos[1];
		lastSnakeYPos[0] = lastSnakeYPos[1];
		lastSnakeXPos[1] = snakeBodyPos[0][i];
		lastSnakeYPos[1] = snakeBodyPos[1][i];
		snakeBodyPos[0][i] = lastSnakeXPos[0];
		snakeBodyPos[1][i] = lastSnakeYPos[0];
	}
}
#pragma endregion