﻿#pragma comment(lib, "Opengl32.lib")

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

// Global variables
Player player;
EnemyBlock enemyBlocks1, enemyBlocks2;
Floor land;
Star star;
bool isJumping = false;
float jumpVelocity = 0.0f;
const float gravity = -0.00098f; // 1N의 중력 가속도, 약 0.098 m/s^2
const float jumpForce = 0.05f; // 점프력 5m/s

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

int Physics(GLFWwindow* window)
{
    // Apply gravity
    if (isJumping) {
        player.y += jumpVelocity;
        jumpVelocity += gravity; // Apply gravity
        //player.rotation -= 1.0f;

        // Collision with ground
        if (player.y < 0) {
            player.y = 0;
            isJumping = false;
            jumpVelocity = 0;
            player.rotation = 0.0f; // Reset rotation
        }
    }

    // Collision detection
    if (PhysicsAABB(player, enemyBlocks1) || PhysicsAABB(player, enemyBlocks2)) {
        printf("Game Over\n");
        glfwSetWindowShouldClose(window, GLFW_TRUE);
    }

    return 0;
}

int Initialize()
{
    player.y = 0;
    enemyBlocks1.x = 1; // Start outside the right edge of the screen
    enemyBlocks1.y = 100.0f;
    enemyBlocks2.x = 2; // Start outside the right edge of the screen
    enemyBlocks2.y = 300.0f;
    return 0;
}

int Update()
{
    // Move enemies from right to left
    enemyBlocks1.x -= 0.01f; // Move left by 5cm per frame
    enemyBlocks2.x -= 0.01f; // Move left by 5cm per frame

    // Recycle enemies
    if (enemyBlocks1.x < -1.2f) enemyBlocks1.x = 1.0f;
    if (enemyBlocks2.x < -1.2f) enemyBlocks2.x = 1.0f;

    return 0;
}

int Render()
{
    player.Render();
    land.Render();
    enemyBlocks1.Render();
    enemyBlocks2.Render();
    star.Render();
    return 0;
}

int main(void)
{
    _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

    if (!glfwInit())
        return -1;

    GLFWwindow* window = glfwCreateWindow(800, 600, "Google Dino Run Copy Game", NULL, NULL);

    if (!window)
    {
        glfwTerminate();
        return -1;
    }
    glfwMakeContextCurrent(window);
    glfwSetErrorCallback(errorCallback);
    glfwSetKeyCallback(window, keyCallback);

    Initialize();

    glClearColor(0.0f, 30 / 255.0f, 100 / 255.0f, 1.0f);


    while (!glfwWindowShouldClose(window))
    {
        glfwPollEvents();
        glClear(GL_COLOR_BUFFER_BIT);
        Physics(window);
        Update();
        Render();
        Pixel(window);
        glfwSwapBuffers(window);
    }

    glfwTerminate();
    return 0;
}
