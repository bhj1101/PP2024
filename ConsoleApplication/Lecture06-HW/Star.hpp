#include "MObject.h"
#include <GLFW/glfw3.h>

class Star : public MObject {
public:
    float scale = 0.02f;
    float xOffset = 0.0f;
    float yOffset = 0.0f;
    float red = 1.0f;
    float green = 1.0f;
    float blue = 1.0f;

    void update() {}

    void render() {
        glMatrixMode(GL_MODELVIEW);
        glLoadIdentity();
        glTranslatef(xOffset, yOffset, 0.0f);
        glScalef(scale, scale, 1.0f);

        glBegin(GL_TRIANGLES);
        // Point 1
        glColor3f(red, green, blue);
        glVertex2f(0.0f, 1.0f);

        // Point 2
        glColor3f(red, green, blue);
        glVertex2f(0.61f, -1.0f);

        // Point 3
        glColor3f(red, green, blue);
        glVertex2f(-0.38f, -0.24f);
        glEnd();

        glBegin(GL_TRIANGLES);
        // Point 1
        glColor3f(red, green, blue);
        glVertex2f(0.0f, 1.0f);

        // Point 2
        glColor3f(red, green, blue);
        glVertex2f(-0.61f, -1.0f);

        // Point 3
        glColor3f(red, green, blue);
        glVertex2f(0.38f, -0.24f);
        glEnd();

        glBegin(GL_TRIANGLES);
        // Point 1
        glColor3f(red, green, blue);
        glVertex2f(-1.0f, 0.23f);

        // Point 2
        glColor3f(red, green, blue);
        glVertex2f(0.0f, -0.53f);

        // Point 3
        glColor3f(red, green, blue);
        glVertex2f(1.0f, 0.23f);
        glEnd();
    }
};
