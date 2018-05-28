#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include <../../GLM/glm/gtc/matrix_transform.hpp>
#include <../../GLM/glm/gtx/transform.hpp>

#include <stdio.h>
#include "../headerFiles/Food.h"
#include "../headerFiles/FloorGeneration.h"
#include "../headerFiles/Snake.h"
#include "../headerFiles/MapBoundary.h"
#include "../headerFiles//Score.h"


GLFWwindow* window;

#define UP 1
#define Down 2
#define LEFT 3
#define RIGHT 4

unsigned char camera = 'r';
int Width = 800;      // window width (pixels)
int Height = 800;     // window height (pixels)


int main(int argc, char **argv)
{
	GLFWwindow* window;

	/* Initialize the library */
	if (!glfwInit())
		return -1;

	/* Create a windowed mode window and its OpenGL context */
	window = glfwCreateWindow(Width, Height, "Snaze3D", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);

	if (glewInit() != GLEW_OK)
		return -1;

	/* Loop until the user closes the window */
	while (!glfwWindowShouldClose(window))
	{

		/* Render here */
		glClear(GL_COLOR_BUFFER_BIT);



		/* Swap front and back buffers */
		glfwSwapBuffers(window);

		/* Poll for and process events */
		glfwPollEvents();
	}

	glfwTerminate();
}
