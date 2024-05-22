#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>
#include <cmath>

float moveFactor = 0.0f;
float scaleFactor = 1.0f;

void errorCallback(int error, const char* description)
{
	std::cerr << "GLFW Error: " << description << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
	if (key == GLFW_KEY_UP && action == GLFW_PRESS)
	{
		moveFactor += 0.01f;
	}
	if (key == GLFW_KEY_RIGHT && action == GLFW_PRESS)
	{
		scaleFactor += 0.1f;
	}
}

int setVertexRotation(float x, float y, float angle_degree)
{
	glVertex2f(x * cos(angle_degree) - (y * sin(angle_degree)), x * sin(angle_degree) + (y * cos(angle_degree)));
	return 0;
}
float angle = 0;

int render()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glRotatef(angle, 0.0, 0.0, 1.0f);
	angle = angle + 0.1;

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.851f, 0.4f);
	for (float angle = 0.0f; angle < 2 * 3.14; angle += 0.01f) {
		glVertex2f(cos(angle) * 0.4f, sin(angle) * 0.4f);
	}
	glEnd();

	glLineWidth(2.0f);
	glBegin(GL_LINE_LOOP);
	glColor3f(0.773f, 0.353f, 0.067f);
	for (float angle = 0.0f; angle < 2 * 3.14; angle += 0.01f) {
		glVertex2f(cos(angle) * 0.4f, sin(angle) * 0.4f);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.902f, 0.6f);
	for (float angle = 0.0f; angle < 2 * 3.14; angle += 0.01f) {
		glVertex2f(-0.19f+cos(angle) * 0.2f, sin(angle) * 0.2f);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.753f, 0.0f);
	float cosTheta = cos(45.0f * 3.14 / 180.0f);
	float sinTheta = sin(45.0f * 3.14 / 180.0f);

	for (float angle = 0.0f; angle < 2 * 3.14; angle += 0.01f) {
		float x = 0.00f + cos(angle) * 0.2f;
		float y = -0.33f + sin(angle) * 0.05f;

		float newX = x * cosTheta - y * sinTheta;
		float newY = x * sinTheta + y * cosTheta;

		glVertex2f(newX, newY);
	}
	glEnd();

	glBegin(GL_TRIANGLE_FAN);
	glColor3f(1.0f, 0.902f, 0.6f);
	for (float angle = 0.0f; angle < 2 * 3.14; angle += 0.01f) {
		glVertex2f(0.5f + cos(angle) * 0.2f, sin(angle) * 0.2f);
	}
	glEnd();


	return 0;
}


int main(void)
{
	
	//glfw라이브러리 초기화
	if (!glfwInit())
		return -1;

	GLFWwindow* window;
	window = glfwCreateWindow(800, 800, "태양계", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallback);
	glfwSetKeyCallback(window, keyCallback);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		render();

		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;

}