#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Cube.h"
#include "Shape.h"
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")

#include <iostream>
void update();
void init();
void draw();
GLFWwindow* window;
Shape* test;
glm::mat4 view;
int main()
{
	if (!glfwInit())
		throw "Could not initialize glwf";
	window = glfwCreateWindow(1400, 800, "Hello World", NULL, NULL);
	if (!window)
	{
		glfwTerminate();
		throw "Could not initialize glwf";
	}
	glfwMakeContextCurrent(window);

	tigl::init();

	

	test = new Cube(glm::vec3(5, 0, 0), glm::vec4(0.5, 1, 0, 1), 3);
	


	while (!glfwWindowShouldClose(window))
	{
		update();
		draw();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();


	return 0;
}

void init()
{
	

}


void update()
{
	test->update();
}

void draw()
{
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1400/(float)800, 0.1f, 100.0f);
	view = glm::lookAt(glm::vec3(0, 0, 50), glm::vec3(0, 0, 0), glm::vec3(0, 1, 0));
	tigl::shader->setProjectionMatrix(projection);
	tigl::shader->setViewMatrix(view);
	glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	tigl::shader->enableColor(true);

	test->draw();
}