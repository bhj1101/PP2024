#pragma comment(lib, "Opengl32.lib")

#define _CRTDBG_MAP_ALLOC
#include <crtdbg.h>

#ifdef _DEBUG
#define DBG_NEW new ( _NORMAL_BLOCK , __FILE__ , __LINE__ )
#else
#define DBG_NEW new
#endif

#include <GLFW/glfw3.h>
#include <stdio.h>
#include <chrono>
#include <thread>
#include <cmath>
#include "Object.h"

Player player;
EnemyBlock enemyBlocks[2] = { EnemyBlock(), EnemyBlock() };
//Floor floor; 
Star star;

float enemyBlockXPositions[2] = { -200.0f, 200.0f }; // 적 블록 X 위치
float enemyBlockHeights[2] = { 100.0f, 300.0f }; // 적 블록 높이

void errorCallback(int error, const char* description)
{
	printf("GLFW Error: %s", description);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{

}

int Physics()
{
	return 0;
}

int Initialize()
{
	return 0;
}

int Update()
{
	return 0;

	float red = 1.0f;
	float green = 1.0f;
	float blue = 1.0f;

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(0.0f, 0.0f, 0.0f);
	glScalef(0.02f, 0.02f, 1.0f);

	glBegin(GL_TRIANGLES);
	glColor3f(red, green, blue);
	glVertex2f(0.0f, 1.0f);

	glColor3f(red, green, blue);
	glVertex2f(0.61f, -1.0f);

	glColor3f(red, green, blue);
	glVertex2f(-0.38f, -0.24f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(red, green, blue);
	glVertex2f(0.0f, 1.0f);

	glColor3f(red, green, blue);
	glVertex2f(-0.61f, -1.0f);

	glColor3f(red, green, blue);
	glVertex2f(0.38f, -0.24f);
	glEnd();

	glBegin(GL_TRIANGLES);
	glColor3f(red, green, blue);
	glVertex2f(-1.0f, 0.23f);

	glColor3f(red, green, blue);
	glVertex2f(0.0f, -0.53f);

	glColor3f(red, green, blue);
	glVertex2f(1.0f, 0.23f);
	glEnd();
}


int Render()
{
	player.Render();
	enemyBlocks[0].Render(enemyBlockXPositions[0], -1.0f, enemyBlockHeights[0]);
	enemyBlocks[1].Render(enemyBlockXPositions[1], -1.0f, enemyBlockHeights[1]);
	//floor.Render();
	star.Render();
	return 0;
}

int main(void)
{
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);


	//glfw라이브러리 초기화
	if (!glfwInit())
		return -1;

	
	GLFWwindow* window;
	window = glfwCreateWindow(800, 600, "Google Dino Run Copy Game", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}
	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallback);
	glfwSetKeyCallback(window, keyCallback);

	Initialize();

	glClearColor(0.0f, 30/255.0f, 100/255.0f, 1.0f);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClear(GL_COLOR_BUFFER_BIT);
		Physics();
		Update();
		Render();
		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;

}