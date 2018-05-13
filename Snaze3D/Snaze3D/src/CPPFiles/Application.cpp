#include <glut.h>
#include <stdio.h>
#include "../headerFiles/Food.h"
#include "../headerFiles/FloorGeneration.h"
#include "../headerFiles/Snake.h"
#include "../headerFiles/MapBoundary.h"

#define UP 1
#define Down 2
#define LEFT 3
#define RIGHT 4

GLbyte  gameOver = false;
unsigned char camera = 'r';
int Width = 800;      // window width (pixels)
int Height = 800;     // window height (pixels)
GLbyte  EnableLight = true;

MapBoundary mapBoundary;
Food food;
Snake snake;
FloorGeneration floorGeneration;


#pragma region SnakeFoodCollision
//try without all the different or statement
void CheckFoodColiision() {
	if ((snake.snakeXPos == food.foodXPosition && snake.snakeYPos == food.foodYPosition) ||
		((snake.snakeXPos >= food.foodXPosition) && (snake.snakeXPos <= food.foodXPosition + 1) && (snake.snakeYPos >= food.foodYPosition) && (snake.snakeYPos <= food.foodYPosition + 1)) ||
		((snake.snakeXPos <= food.foodXPosition) && (snake.snakeXPos >= food.foodXPosition - 1) && (snake.snakeYPos <= food.foodYPosition) && (snake.snakeYPos >= food.foodYPosition - 1)) ||
		((snake.snakeXPos <= food.foodXPosition) && (snake.snakeXPos >= food.foodXPosition - 1) && (snake.snakeYPos >= food.foodYPosition) && (snake.snakeYPos <= food.foodYPosition + 1)) ||
		((snake.snakeXPos >= food.foodXPosition) && (snake.snakeXPos <= food.foodXPosition + 1) && (snake.snakeYPos <= food.foodYPosition) && (snake.snakeYPos >= food.foodYPosition - 1))) {
		snake.snakeSize++;
		food.NewFood(mapBoundary.leftBound, mapBoundary.botBound);
	}
}
#pragma endregion
#pragma region SnakeMovement
void MoveSnake(int value) {
	snake.lastSnakeXPos[1] = snake.snakeXPos;
	snake.lastSnakeYPos[1] = snake.snakeYPos;

	switch (snake.direction) {
	case RIGHT:
		snake.snakeXPos += 1;
		if (snake.snakeXPos > mapBoundary.rightBound) snake.snakeXPos = mapBoundary.leftBound;//This will check if the snake is going into the border so it will appear on the other side
		break;
	case LEFT:
		snake.snakeXPos -= 1;
		if (snake.snakeXPos < mapBoundary.leftBound) snake.snakeXPos = mapBoundary.rightBound;//This will check if the snake is going into the border so it will appear on the other side
		break;
	case UP:
		snake.snakeYPos += 1;
		if (snake.snakeYPos > mapBoundary.upBound) snake.snakeYPos = mapBoundary.botBound;//This will check if the snake is going into the border so it will appear on the other side
		break;
	case Down:
		snake.snakeYPos -= 1;
		if (snake.snakeYPos < mapBoundary.botBound) snake.snakeYPos = mapBoundary.upBound;//This will check if the snake is going into the border so it will appear on the other side
		break;
	}


	CheckFoodColiision();
	snake.SaveSnakePosition();

	//Set the Timer
	glutTimerFunc(126, MoveSnake, 0);
}

//variables are here because they need to be
void ChangeDirection(int key, int x, int y) {
	switch (key) {
	case GLUT_KEY_RIGHT:
		if (snake.direction != LEFT)
			snake.direction = RIGHT;
		break;
	case GLUT_KEY_LEFT:
		if (snake.direction != RIGHT)
			snake.direction = LEFT;
		break;
	case GLUT_KEY_UP:
		if (snake.direction != UP)
			snake.direction = Down;
		break;
	case GLUT_KEY_DOWN:
		if (snake.direction != Down)
			snake.direction = UP;
		break;
	}
}

#pragma endregion


void keyboardCallback(unsigned char c, int x, int y) {
	switch (c) {
	case 'q':
		exit(0);
		break;
	}
	glutPostRedisplay();
}

void Initialize(void) {
	glEnable(GL_DEPTH_TEST);
	glClearColor(0.0f, 0.0f, 0.0f, 1.0f); //Change the background to black
	if (EnableLight) {
		glEnable(GL_COLOR_MATERIAL);
		glEnable(GL_LIGHTING);
		glEnable(GL_LIGHT0);
		glEnable(GL_LIGHT1);
		glEnable(GL_NORMALIZE);
	}
}

void displayCallback()
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	//Camera
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(45, 1.0, 0.1, 200.0);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0, 30, 40, 0, 0, 0, 0, 1, 0);

	if (!gameOver)
	{
		// draw after the opaque objects, since it is translucent
		floorGeneration.drawFloor();
		glTranslatef(0, 0.5, 0);

		//draw snake
		snake.DrawSnake();
		food.DrawFood();
	}
	else {
	}


	// draw the buffer to the screen
	glutPostRedisplay();
	glutSwapBuffers();

	GLenum error = glGetError();
}

int main(int argc, char **argv)
{
	// create window and rendering context
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DEPTH | GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowSize(Width, Height);
	glutCreateWindow("Snaze3D");

	// register display callback

	glutSpecialFunc(ChangeDirection);
	glutKeyboardFunc(keyboardCallback);
	glutDisplayFunc(displayCallback);

	glViewport(0, 0, Width, Height);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	// Turn on blending (for floor).
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	MoveSnake(0);
	Initialize();
	// pass control over to GLUT
	glutMainLoop();
}
