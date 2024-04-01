//과제물 프로젝트명: Lecture04_HW
//idle : 화면색 검정색으로 clear
//마우스 오른쪽 KeyDown하면 : 빨간색
//마우스 오른쪽 KeyUp하면 : 원상복구
//마우스 왼쪽 KeyDown하면 : 녹색
//마우스 왼쪽 KeyUp하면 : 원상복구
//마우스 오른쪽 KeyDown하고 드래그 중이면 : 파랑색
//마우스 왼쪽 KeyDown하고 드래그 중이면 : 마젠타색

//https://www.glfw.org/docs/latest/topics.html

#pragma comment(lib, "Opengl32.lib")
#include <GLFW/glfw3.h>
#include <iostream>

enum Color {
	Black,
	Red,
	Green,
	Blue,
	Magenta
};
Color currentColor = Black;

bool isLeftButtonDown = false;
bool isRightButtonDown = false;
bool isDragging = false;

void errorCallback(int error, const char* description)
{
	std::cerr << "GLFW Error: " << description << std::endl;
}

void keyCallback(GLFWwindow* window, int key, int scancode, int action, int mods)
{
	if (key == GLFW_KEY_ESCAPE && action == GLFW_PRESS)
	{
		glfwSetWindowShouldClose(window, GLFW_TRUE);
	}
}

void mouseCallback(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_LEFT) {
		if (action == GLFW_PRESS) {
			isLeftButtonDown = true;
			currentColor = Green;
		}
		else if (action == GLFW_RELEASE) {
			isLeftButtonDown = false;
			currentColor = Black;
			isDragging = false;
		}
	}
	else if (button == GLFW_MOUSE_BUTTON_RIGHT) {
		if (action == GLFW_PRESS) {
			isRightButtonDown = true;
			currentColor = Red;
		}
		else if (action == GLFW_RELEASE) {
			isRightButtonDown = false;
			currentColor = Black;
			isDragging = false;
		}
	}
}

void onCursorPos(GLFWwindow* window, double xpos, double ypos) {
	if ((isLeftButtonDown || isRightButtonDown) && !isDragging) {
		isDragging = true;
		if (currentColor == Green) {
			currentColor = Magenta;
		}
		else if (currentColor == Red) {
			currentColor = Blue;
		}
	}
	else if (!(isLeftButtonDown || isRightButtonDown)) {
		isDragging = false;
	}
}

void onRender(GLFWwindow* window) {
	switch (currentColor) {
	case Black:
		glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
		break;
	case Red:
		glClearColor(1.0f, 0.0f, 0.0f, 1.0f);
		break;
	case Green:
		glClearColor(0.0f, 1.0f, 0.0f, 1.0f);
		break;
	case Blue:
		glClearColor(0.0f, 0.0f, 1.0f, 1.0f);
		break;
	case Magenta:
		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
		break;
	}

	glClear(GL_COLOR_BUFFER_BIT);

	glfwSwapBuffers(window);
}

int main(void)
{
	if (!glfwInit())
		return -1;

	GLFWwindow* window;
	window = glfwCreateWindow(1280, 768, "Hohoho", NULL, NULL);

	if (!window)
	{
		glfwTerminate();
		return -1;
	}

	glfwMakeContextCurrent(window);
	glfwSetErrorCallback(errorCallback);
	glfwSetKeyCallback(window, keyCallback);
	glfwSetMouseButtonCallback(window, mouseCallback);
	glfwSetCursorPosCallback(window, onCursorPos);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		onRender(window);
	}

	glfwTerminate();
	return 0;

}