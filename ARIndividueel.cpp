#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Shapes.h"
#include "ShapeFactory.h"
#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")

#include <iostream>
//functions
void update();
void init();
void draw();
void cameraInit();
//attributes
GLFWwindow* window;
Shape* test;
glm::mat4 view;
ShapeFactory* factory;

int width, height;
int zoom, horizontal, vertical;

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
	

	factory = new ShapeFactory();
	factory->makeShape(glm::vec3(5, 0, 0), glm::vec4(0.1, 0.1, 0.1, 0.3), 3, ShapeFactory::CUBE);
	
	
	

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
	cameraInit();
}


void update()
{
	factory->updateShapes();
}

void draw()
{
	glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1400/(float)800, 0.1f, 100.0f);
	view = glm::lookAt(glm::vec3(horizontal, 5, zoom), glm::vec3(horizontal, vertical, 0), glm::vec3(0, 1, 0));
	tigl::shader->setProjectionMatrix(projection);
	tigl::shader->setViewMatrix(view);
	glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	tigl::shader->enableColor(true);

	factory->drawShapes();
}


void cameraInit() {
	bool rotationMode = false;
	zoom = 10;
	horizontal = 10;
	glEnable(GL_DEPTH_TEST);
	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			if (key == GLFW_KEY_S) {
				zoom += 1;
			}
			if (key == GLFW_KEY_W) {
				zoom -= 1;
			}
			if (key == GLFW_KEY_ESCAPE)
				glfwSetWindowShouldClose(window, true);
			if (key == GLFW_KEY_UP)
				vertical += 1;
			if (key == GLFW_KEY_DOWN)
				vertical -= 1;
			if (key == GLFW_KEY_LEFT)
				horizontal -= 1;
			if (key == GLFW_KEY_RIGHT)
				horizontal += 1;
		});

	glfwGetWindowSize(window, &width, &height);
}