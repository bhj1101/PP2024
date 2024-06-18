#pragma once
#include <GLFW/glfw3.h>
#include <iostream>

float xPixel = 400.0f;
float yPixel = 300.0f;

void Pixel(GLFWwindow* window) {
    int screenWidth, screenHeight;
    glfwGetWindowSize(window, &screenWidth, &screenHeight);
    xPixel = screenWidth / 2;
    yPixel = screenHeight / 2;
}

// Base class
class Object {
public:
    float x, y;
    virtual void OnCollisionEnter(Object& other) {}
};

// Derived classes
class Player : public Object {
public:
    void OnCollisionEnter(Object& other) override {}
    void Render() {
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(x, y, 0.0f);
        glScalef(1.0f, 1.0f, 1.0f);

        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // 빨강
        glVertex2f(-200.0f / xPixel, -200.0f / yPixel);
        glVertex2f(-150.0f / xPixel, -200.0f / yPixel);
        glVertex2f(-150.0f / xPixel, -150.0f / yPixel);
        glVertex2f(-200.0f / xPixel, -150.0f / yPixel);
        glEnd();

        glBegin(GL_LINE_LOOP);
        glLineWidth(3.0f); // 3cm 두께 테두리
        glColor3f(0.0f, 0.0f, 0.0f); // 검정
        glVertex2f(-200.0f / xPixel, -200.0f / yPixel);
        glVertex2f(-150.0f / xPixel, -200.0f / yPixel);
        glVertex2f(-150.0f / xPixel, -150.0f / yPixel);
        glVertex2f(-200.0f / xPixel, -150.0f / yPixel);
        glEnd();
    }
};

class EnemyBlock : public Object {
public:
    void OnCollisionEnter(Object& other) override {}
    void Render(float pos, float height) {
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(x, y, 0.0f);
        glScalef(1.0f, 1.0f, 1.0f);

        glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 0.0f); // 녹색
        glVertex2f((25.0f + pos) / xPixel, -200.0f / yPixel);
        glVertex2f((75.0f + pos) / xPixel, -200.0f / yPixel);
        glVertex2f((75.0f + pos) / xPixel, (-200.0f + height) / yPixel);
        glVertex2f((25.0f + pos) / xPixel, (-200.0f + height) / yPixel);
        glEnd();
    }
};

class Floor : public Object {
public:
    void OnCollisionEnter(Object& other) override {}
    void Render() {
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, 0.0f); // 30cm below the center
        glScalef(1.0f, 1.0f, 1.0f);

        glBegin(GL_QUADS);
        glColor3f(1.0f, 200 / 255.0f, 15 / 255.0f); // 황색
        glVertex2f(-400.0f / xPixel, -300.0f / yPixel);
        glVertex2f(400.0f / xPixel, -300.0f / yPixel);
        glVertex2f(400.0f / xPixel, -200.0f / yPixel);
        glVertex2f(-400.0f / xPixel, -200.0f / yPixel);
        glEnd();
    }
};

class Star : public Object {
public:
    void OnCollisionEnter(Object& other) override {}
    void Render() {}
};

bool PhysicsAABB(Object& A, Object& B)
{
    float axMin = A.x - 25.0f / xPixel;
    float axMax = A.x + 25.0f / xPixel;
    float ayMin = A.y - 25.0f / yPixel;
    float ayMax = A.y + 25.0f / yPixel;

    float bxMin = B.x - 25.0f / xPixel;
    float bxMax = B.x + 25.0f / xPixel;
    float byMin = B.y - 50.0f / yPixel;
    float byMax = B.y + 50.0f / yPixel;

    return (axMin < bxMax && axMax > bxMin && ayMin < byMax && ayMax > byMin);
}
