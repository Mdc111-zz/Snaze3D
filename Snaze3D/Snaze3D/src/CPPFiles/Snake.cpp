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
/*
#pragma region SnakeFoodCollision
//try without all the different or statement
void CheckFoodColiision() {
	if ((snake.snakeXPos == food.foodXPosition && snake.snakeYPos == food.foodYPosition) ||
		((snake.snakeXPos >= food.foodXPosition) && (snake.snakeXPos <= food.foodXPosition + 1) && (snake.snakeYPos >= food.foodYPosition) && (snake.snakeYPos <= food.foodYPosition + 1)) ||
		((snake.snakeXPos <= food.foodXPosition) && (snake.snakeXPos >= food.foodXPosition - 1) && (snake.snakeYPos <= food.foodYPosition) && (snake.snakeYPos >= food.foodYPosition - 1)) ||
		((snake.snakeXPos <= food.foodXPosition) && (snake.snakeXPos >= food.foodXPosition - 1) && (snake.snakeYPos >= food.foodYPosition) && (snake.snakeYPos <= food.foodYPosition + 1)) ||
		((snake.snakeXPos >= food.foodXPosition) && (snake.snakeXPos <= food.foodXPosition + 1) && (snake.snakeYPos <= food.foodYPosition) && (snake.snakeYPos >= food.foodYPosition - 1))) {
		score.points++;
		if (score.points < 100) snake.snakeSize++;
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

	//Checks for Collisoin if yes Game Over
	if (snake.CheckSelfCollision()) gameOver = true;

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
*/