#pragma once
#include <GLFW/glfw3.h>
#include <iostream>

// Base class
class Object {
public:
    virtual void OnCollisionEnter(Object& other) {
    }
};


float xPixel = 400.0f;
float yPixel = 300.0f;


// Derived classes
class Player : public Object {
public:
    void OnCollisionEnter(Object& other) override {
    }
    void Render() {
        // 빨간색 정사각형 (50cm x 50cm) 및 3cm 두께 테두리 렌더링
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, 0.0f);
        glScalef(1.0f, 1.0f, 1.0f);

        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // 빨강색
        glVertex2f(-25.0f / xPixel, -25.0f / yPixel);
        glVertex2f(25.0f / xPixel, -25.0f / yPixel);
        glVertex2f(25.0f / xPixel, 25.0f / yPixel);
        glVertex2f(-25.0f / xPixel, 25.0f / yPixel);
        glEnd();

        // 테두리 렌더링 (검정색, 3cm 두께)
        glBegin(GL_LINE_LOOP);
        glLineWidth(3.0f);
        glColor3f(0.0f, 0.0f, 0.0f); // 검정색
        glVertex2f(-25.0f / xPixel, -25.0f / yPixel);
        glVertex2f(25.0f / xPixel, -25.0f / yPixel);
        glVertex2f(25.0f / xPixel, 25.0f / yPixel);
        glVertex2f(-25.0f / xPixel, 25.0f / yPixel);
        glEnd();
    }
};

class EnemyBlock : public Object {
public:
    void OnCollisionEnter(Object& other) override {
    }
    void Render(float x, float height) {
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, 0.0f);
        glScalef(1.0f, 1.0f, 1.0f);

        glBegin(GL_QUADS);
        glColor3f(0.0f, 1.0f, 0.0f); // 녹색
        glVertex2f((25.0f + x) / xPixel, -200.0f / yPixel);
        glVertex2f((75.0f + x) / xPixel, -200.0f / yPixel);
        glVertex2f((75.0f + x) / xPixel, (-200.0f + height) / yPixel);
        glVertex2f((25.0f + x) / xPixel, (-200.0f + height) / yPixel);
        glEnd();
    }
};

class Floor : public Object {
public:
    void OnCollisionEnter(Object& other) override {
    }
    void Render() {
        // 바닥 렌더링 (800cm x 100cm)
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(0.0f, 0.0f, 0.0f);
        glScalef(1.0f, 1.0f, 1.0f);

        glBegin(GL_QUADS);
        glColor3f(1.0f, 200/255.0f, 15/255.0f); // 황색
        glVertex2f(-400.0f / xPixel, -300.0f / yPixel);
        glVertex2f(400.0f / xPixel, -300.0f / yPixel);
        glVertex2f(400.0f / xPixel, -200.0f / yPixel);
        glVertex2f(-400.0f / xPixel, -200.0f / yPixel);
        glEnd();
    }
};

class Star : public Object {
public:
    void OnCollisionEnter(Object& other) override {
    }
    void Render() {
        
    }
};


int PhysicsAABB(Object A, Object B)
{
    return 0;
}