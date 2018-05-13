#include "../headerFiles/Snake.h"

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