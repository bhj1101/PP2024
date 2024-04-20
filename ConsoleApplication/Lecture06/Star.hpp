#include "MObject.h"
#include <GLFW/glfw3.h>

class Star : public MObject
{
	void update()
	{

	}
	void render()
	{
		glBegin(GL_TRIANGLES);
		//점1
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex2f(0.0f, 1.0f);
		//점2
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex2f(0.61f, -1.0f);
		//점3
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(-0.38f, -0.24f);
		glEnd();

		glBegin(GL_TRIANGLES);
		//점1
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex2f(0.0f, 1.0f);
		//점2
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(-0.61f, -1.0f);
		//점3
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex2f(0.38f, -0.24f);
		glEnd();

		glBegin(GL_TRIANGLES);
		//점1
		glColor3f(0.0f, 1.0f, 1.0f);
		glVertex2f(-1.0f, 0.23f);
		//점2
		glColor3f(1.0f, 1.0f, 0.0f);
		glVertex2f(0.0f, -0.53f);
		//점3
		glColor3f(1.0f, 0.0f, 1.0f);
		glVertex2f(1.0f, 0.23f);
		glEnd();
	}
};