#include <glut.h>
#include "../headerFiles/FloorGeneration.h"


GLbyte  gameOver = false; 
unsigned char camera = 'r';
int Width = 800;      // window width (pixels)
int Height = 800;     // window height (pixels)
GLbyte  EnableLight = true;

FloorGeneration floorGeneration;

void keyboardCallback(unsigned char c, int x, int y) {
	switch (c) {
		case 'q':
			exit(0);
			break;
		}
	glutPostRedisplay();
}

void Initialize(void){
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

	//glutSpecialFunc(ChangeDirection);
	glutKeyboardFunc(keyboardCallback);
	glutDisplayFunc(displayCallback);

	glViewport(0, 0, Width, Height);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_NORMALIZE);

	// Turn on blending (for floor).
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	Initialize();
	// pass control over to GLUT
	glutMainLoop();
}
