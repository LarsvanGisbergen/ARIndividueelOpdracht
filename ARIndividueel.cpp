#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Cube.h"
#include "Shape.h"
#include "Pyramid.h"
#include "Sphere.h"
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

int width, height;
int zoom, horizontal;

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
	init();
	

	test = new Sphere(glm::vec3(5, 0, 0), glm::vec4(0.5, 1, 0, 1), 3);
	
	

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
	zoom = 10;
	horizontal = 10;
	glEnable(GL_DEPTH_TEST);
	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			if (key == GLFW_KEY_ESCAPE)
				glfwSetWindowShouldClose(window, true);
			if (key == GLFW_KEY_UP)
				zoom -= 1;
			if (key == GLFW_KEY_DOWN)
				zoom += 1;
			if (key == GLFW_KEY_LEFT)
				horizontal -= 1;
			if (key == GLFW_KEY_RIGHT)
				horizontal += 1;
		});

	glfwGetWindowSize(window, &width, &height);
}


void update()
{
	test->update();
}

void draw()
{
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1400/(float)800, 0.1f, 100.0f);
	view = glm::lookAt(glm::vec3(horizontal, 5, zoom), glm::vec3(horizontal, 0, 0), glm::vec3(0, 1, 0));
	tigl::shader->setProjectionMatrix(projection);
	tigl::shader->setViewMatrix(view);
	glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	tigl::shader->enableColor(true);

	test->draw();
}