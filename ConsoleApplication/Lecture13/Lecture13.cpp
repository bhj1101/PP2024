#include <iostream>
#include <GLFW/glfw3.h>

struct BoxCollider {
	float x, y, width, height;

	BoxCollider(float x, float y, float width, float height) :
		x(x), y(y), width(width), height(height){}
};

void renderBoxCollider(const BoxCollider& collider){

	glBegin(GL_LINE_LOOP);
	glVertex2f(collider.x, collider.y);
	glVertex2f(collider.x + collider.width, collider.y);
	glVertex2f(collider.x + collider.width, collider.y + collider.height);
	glVertex2f(collider.x, collider.y + collider.height);
	glEnd();
}


bool isColliding(const BoxCollider& collider1, const BoxCollider& collider2) {
	return(
		collider1.x <= collider2.x + collider2.width &&
		collider1.x + collider1.width > collider2.x &&
		collider1.y<collider2.y + collider2.height &&
		collider1.y + collider1.height>collider2.y
		);
}

int main(void)
{

	//glfw라이브러리 초기화
	if (!glfwInit())
		return -1;

	GLFWwindow* window;
	window = glfwCreateWindow(800, 800, "Lecture13", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	/* Make the window's context current */
	glfwMakeContextCurrent(window);
	//glfwSetErrorCallback(errorCallback);
	//glfwSetKeyCallback(window, keyCallback);


	BoxCollider collider1(10, 10, 10, 10);
	BoxCollider collider2(10, 20, 100, 10);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		renderBoxCollider(collider1);
		renderBoxCollider(collider2);

		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;

}