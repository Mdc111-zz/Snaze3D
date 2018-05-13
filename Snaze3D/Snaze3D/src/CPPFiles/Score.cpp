#include <stdio.h>
#include <glut.h>
#include "../headerFiles/Score.h"

#pragma region Score
void Score::WriteToScreen(char *string) {//Write string on the screen
	while (*string)
		glutBitmapCharacter(GLUT_BITMAP_8_BY_13, *string++);
}

void Score::UpdateScore() {
	char pointScore[15];

	// Print the status of the game on the screen
	glColor3f(1, 1, 1);
	glRasterPos2f(0, 13);
	sprintf_s(pointScore, "Points: %d", points);
	WriteToScreen(pointScore);
}
#pragma endregion