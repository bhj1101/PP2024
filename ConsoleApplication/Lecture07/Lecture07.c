#pragma comment(lib, "Opengl32.lib")

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <GLFW/glfw3.h>

#define NUM_STARS 5000

typedef struct Star
{
	float scale;
	float x, y;
	float r, g, b;
}Star;

int draw() {
	srand(time(NULL));

	Star* stars = malloc(sizeof(Star)) * NUM_STARS);
	if (!stars) {
		printf("Failed");
	}

	for (int i = 0; i < NUM_STARS; ++i)
	{
		stars[i].x = -1.0f + 2.0f * (rand() / (RAND_MAX + 1.0f));
		stars[i].y = -1.0f + 2.0f * (rand() / (RAND_MAX + 1.0f));
		stars[i].scale = 0.1f + 0.2f * (rand() / (RAND_MAX + 1.0f));
		stars[i].r = rand() / (RAND_MAX + 1.0f);
		stars[i].g = rand() / (RAND_MAX + 1.0f);
		stars[i].b = rand() / (RAND_MAX + 1.0f);
	}
	return 0;
}

void errorCallback(int error, const char* description)
{
	printf("GLFW Error : %s\n", description);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

int initialize() 
{
	return 0;
}

int release(Star*stars)
{
	free(stars);
}

int update()
{
	return 0;
}

int render(Star*stars)
{
	glClearColor(0.1f, 0.2f, 0.5f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	for (int i = 0;i < NUM_STARS;++i)
	{
		glPushMatrix();
		glTranslatef(stars[i].x, stars[i].y, 0.0f);
		glScalef(stars[i].scale, stars[i].scale, 1.0f);

		glBegin(GL_TRIANGLES);

		glColor3f(stars[i].r, stars[i].g, stars[i].b);
		glVertex2f(0.0f, 0.5f);
		glColor3f(stars[i].r, stars[i].g, stars[i].b);
		glVertex2f(-0.2f, 0.0f);
		glColor3f(stars[i].r, stars[i].g, stars[i].b);
		glVertex2f(0.0f, -0.5f);

		glColor3f(stars[i].r, stars[i].g, stars[i].b);
		glVertex2f(0.0f, -0.5f);
		glColor3f(stars[i].r, stars[i].g, stars[i].b);
		glVertex2f(0.2f, 0.0f);
		glColor3f(stars[i].r, stars[i].g, stars[i].b);
		glVertex2f(0.0f, 0.5f);

		glEnd();

		glPopMatrix();
	}
}

int main(void)
{
	//glfw라이브러리 초기화
	if (!glfwInit())
		return -1;

	GLFWwindow* window;
	window = glfwCreateWindow(1280, 768, "MuSoeunEngine", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallback);
	glfwSetKeyCallback(window, keyCallback);

	Star* stars = NULL;
	if (initialize(&stars) != 0)
	{
		release(stars);
		glfwTerminate();
		return -1;
	}
	initialize();

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		update();
		render(stars);
		glfwSwapBuffers(window);
	}

	release(stars);

	glfwTerminate();
	return 0;

}