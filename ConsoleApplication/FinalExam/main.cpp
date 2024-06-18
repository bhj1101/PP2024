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
#include "Transform.h"

Player player;
EnemyBlock enemyBlocks1, enemyBlocks2;
Floor land; 
Star star;
bool isJumping = false;
float jumpVelocity = 0.0f;
const float gravity = -1.0f; // 1N의 중력 가속도
const float jumpForce = 5.0f; // 점프력 5m/s

void errorCallback(int error, const char* description)
{
	printf("GLFW Error: %s", description);
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_SPACE && action == GLFW_PRESS && !isJumping) {
		isJumping = true;
		jumpVelocity = jumpForce;
	}
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
}


int Render()
{
	player.Render();
	land.Render();
	enemyBlocks1.Render(100.0f, 100.0f);
	enemyBlocks2.Render(300.0f, 300.0f);
	star.Render();
	return 0;
}

int m(void)
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
	int screenWidth, screenHeight;
	glfwGetWindowSize(window, &screenWidth, &screenHeight);

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