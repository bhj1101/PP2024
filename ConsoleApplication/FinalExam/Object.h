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
        // ������ ���簢�� (50cm x 50cm) �� 3cm �β� �׵θ� ������
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.0f, 0.0f); // ����
        glVertex2f(-0.25f, -0.25f); // ���� �Ʒ�
        glVertex2f(0.25f, -0.25f); // ������ �Ʒ�
        glVertex2f(0.25f, 0.25f); // ������ ��
        glVertex2f(-0.25f, 0.25f); // ���� ��
        glEnd();

        // �׵θ� ������ (������, 3cm �β�)
        glBegin(GL_LINE_LOOP);
        glLineWidth(3.0f);
        glColor3f(0.0f, 0.0f, 0.0f); // ������
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
        // �־��� ��ġ (x, y) �� ����(height)�� �� ��� ������ (�Ķ���, 50cm x height)
        glBegin(GL_QUADS);
        glColor3f(0.0f, 0.0f, 1.0f); // �Ķ���
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
        // ����� �ٴ� ������ (800cm x 100cm)
        glBegin(GL_QUADS);
        glColor3f(1.0f, 0.8f, 0.6f); // �����
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