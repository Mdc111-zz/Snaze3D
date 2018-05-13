#include <glut.h>
#include <time.h>
#include "../headerFiles/Food.h"

#pragma region Food
void Food::DrawFood()
{
	//Draw the Sphere representing the Food for the snake
	glPushMatrix();
	glTranslatef(foodXPosition, 0, foodYPosition);
	glColor3f(0.8, 0.4, 0.4);
	glutSolidCube(1);
	glPopMatrix();
}
#pragma endregion