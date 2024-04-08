#pragma comment(lib, "Opengl32.lib")

#include <GLFW/glfw3.h>
#include <iostream>

//1. 삼각형으로 별을 그리시오
//2. 마우스 좌클릭 후에 드래그해서 드래그한만큼 별을 이동해주세요
//3. 우클릭하고 우측으로 드래그한만큼 확대 좌측으로 드래그한만큼 축소를 해주세요.
//   (별의 중점을 기준으로 확대/축소가 돼야합니다.)

float scale = 1.0f;
float xOffset = 0.0f;
float yOffset = 0.0f;
bool isMouseDown = false;
float dragStartX = 0.0f;
float dragStartY = 0.0f;

void onMouseButton(GLFWwindow* window, int button, int action, int mods) {
	if (button == GLFW_MOUSE_BUTTON_LEFT) {
		if (action == GLFW_PRESS) {
			isMouseDown = true;
			//좌클릭 드래그 시작 위치 저장
			double xpos, ypos;
			glfwGetCursorPos(window, &xpos, &ypos);
			dragStartX = static_cast<float>(xpos);
			dragStartY = static_cast<float>(ypos);
		}
		else if (action == GLFW_RELEASE) {
			isMouseDown = false;
		}
		else if (button == GLFW_MOUSE_BUTTON_RIGHT) {
			if (action == GLFW_PRESS) {
				isMouseDown = true;
				//우클릭 드래그 시작 위치 저장
				double xpos, ypos;
				glfwGetCursorPos(window, &xpos, &ypos);
				dragStartX = static_cast<float>(xpos);
				dragStartY = static_cast<float>(ypos);
			}
			else if (action == GLFW_RELEASE) {
				isMouseDown = false;
			}
		}
	}
}


void onMouseMove(GLFWwindow* window, double xpos, double ypos) {
	if (isMouseDown) {
		//마우스 좌클릭 드래그 중일 때 삼각형 위치 업데이트
		float deltaX = xpos - dragStartX;
		float deltaY = ypos - dragStartY;
		xOffset += deltaX / 500;
		yOffset -= deltaY / 500;
		//드래그 시작 위치 재설정
		dragStartX = xpos;
		dragStartY = ypos;
	}
	else if (glfwGetMouseButton(window, GLFW_MOUSE_BUTTON_RIGHT) == GLFW_PRESS) {
		//마우스 우클릭 드래그 중일 때 삼각형 확대/축소
		float deltaX = xpos - dragStartX;
		//삼각형 중점을 기준으로 확대/축소
		float scaleFactor = 1.0f + (deltaX / 1000.0f);
		scale *= scaleFactor;
		//드래그 시작 위치 재설정
		dragStartX = xpos;
	}
}

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

int render()
{
	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();
	glTranslatef(xOffset, yOffset, 0.0f);
	glScalef(scale, scale, 1.0f);

	glBegin(GL_TRIANGLES);
	//점1
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.0f, 1.0f);
	//점2
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.62f, -1.0f);
	//점3
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.4f, -0.24f);
	glEnd();

	glBegin(GL_TRIANGLES);
	//점1
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.0f, 1.0f);
	//점2
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-0.62f, -1.0f);
	//점3
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.4f, -0.24f);
	glEnd();

	glBegin(GL_TRIANGLES);
	//점1
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(-1.0f, 0.23f);
	//점2
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(0.0f, -0.55f);
	//점3
	glColor3f(1.0f, 1.0f, 1.0f);
	glVertex2f(1.0f, 0.23f);
	glEnd();

	return 0;
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
	glfwSetMouseButtonCallback(window, onMouseButton);
	glfwSetCursorPosCallback(window, onMouseMove);

	while (!glfwWindowShouldClose(window))
	{
		glfwPollEvents();
		glClearColor(1.0f, 0.0f, 1.0f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT);

		render();

		glfwSwapBuffers(window);
	}

	glfwTerminate();
	return 0;

}