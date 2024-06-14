#pragma once
#include <GLFW/glfw3.h>
#include <iostream>
// Base class
class Object {
public:
    virtual void OnCollisionEnter(Object& other) {
    }
};

// Derived classes
class Player : public Object {
public:
    void OnCollisionEnter(Object& other) override {
    }
    void Render() {
        // 빨간색 정사각형 (50cm x 50cm) 및 3cm 두께 테두리 렌더링
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // 빨강
        glVertex2f(-0.25f, -0.25f); // 왼쪽 아래
        glVertex2f(0.25f, -0.25f); // 오른쪽 아래
        glVertex2f(0.25f, 0.25f); // 오른쪽 위
        glVertex2f(-0.25f, 0.25f); // 왼쪽 위
        glEnd();

        // 테두리 렌더링 (검정색, 3cm 두께)
        glBegin(GL_LINE_LOOP);
        glLineWidth(3.0f);
        glColor3f(0.0f, 0.0f, 0.0f); // 검정색
        glVertex2f(-0.28f, -0.28f);
        glVertex2f(0.28f, -0.28f);
        glVertex2f(0.28f, 0.28f);
        glVertex2f(-0.28f, 0.28f);
        glEnd();
    }
};

class EnemyBlock : public Object {
public:
    void OnCollisionEnter(Object& other) override {
    }
    void Render(float x, float y, float height) {
        // 주어진 위치 (x, y) 및 높이(height)로 적 블록 렌더링 (파란색, 50cm x height)
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 1.0f); // 파란색
        glVertex2f(x - 0.25f, y);
        glVertex2f(x + 0.25f, y);
        glVertex2f(x + 0.25f, y + height);
        glVertex2f(x - 0.25f, y + height);
        glEnd();
    }
};

class Floor : public Object {
public:
    void OnCollisionEnter(Object& other) override {
    }
    void Render() {
        // 노란색 바닥 렌더링 (800cm x 100cm)
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.8f, 0.6f); // 노란색
        glVertex2f(-400.0f, -100.0f);
        glVertex2f(400.0f, -100.0f);
        glVertex2f(400.0f, 0.0f);
        glVertex2f(-400.0f, 0.0f);
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