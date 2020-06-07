#pragma comment(lib, "glfw3.lib")
#pragma comment(lib, "glew32s.lib")
#pragma comment(lib, "opengl32.lib")

#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Shapes.h"
#include "ShapeFactory.h"

#include "ObjModel.h"
#include "stb_image.h"
#include "Texture.h"
#include <iostream>
#include "Model.h"
#include "ModelFactory.h"
#include "ModelFileReader.h"
#include "enums.h"
#include "GravityBuddy.h"
#include "StopWatch.h"
//functions
void update();
void init();
void draw();
void cameraInit();
void switchCam();
//attributes
GLFWwindow* window;
Shape* test;
glm::mat4 freeCameraView;
StopWatch* watch;

bool camIsFree;

//factories
ShapeFactory* shapeFactory;
ModelFactory* modelFactory;

//model stuff
ObjModel* objModel;
Model* model;
ModelFileReader* reader;

//physics
GravityBuddy* gravityBuddy;

//values
int width, height;
int zoom, horizontal, vertical;
float rotation;

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

	
	init();
	
	camIsFree = true;
	watch = new StopWatch();
	shapeFactory = new ShapeFactory();
	modelFactory = new ModelFactory();
	modelFactory->makeModel(glm::vec3(0, 0, 5), 1, SHIP);
	
	shapeFactory->makeShape(glm::vec3(-10,0, 10), glm::vec4(0.1, 0.1, 0.1, 1), 3, SPHERE);
	shapeFactory->makeShape(glm::vec3(-10, 0, 0), glm::vec4(0.1, 0.1, 0.1, 1), 5, SPHERE);
	gravityBuddy = new GravityBuddy(shapeFactory->getSpheres());
	modelFactory->setGravityBuddy(gravityBuddy);
	
	


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
	tigl::init();
	tigl::shader->enableTexture(true);
	cameraInit();
}


void update()
{
	shapeFactory->updateShapes();
	modelFactory->updateModel();
}

void draw()
{
	if (camIsFree) {
		glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1400 / (float)800, 0.1f, 100.0f);
		freeCameraView = glm::lookAt(glm::vec3(horizontal, 5, zoom), glm::vec3(horizontal, vertical, 0), glm::vec3(0, 1, 0));
		freeCameraView = glm::rotate(freeCameraView, (float)glm::radians(rotation), glm::vec3(0, 1, 0));
		tigl::shader->setProjectionMatrix(projection);
		tigl::shader->setViewMatrix(freeCameraView);
	}
	else {
		tigl::shader->setViewMatrix(modelFactory->_modelCameraView);
	}

	
	glClearColor(0.3f, 0.4f, 0.6f, 1.0f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	tigl::shader->enableColor(true);

	shapeFactory->drawShapes();
	modelFactory->drawModel();
}


void cameraInit() {
	bool rotationMode = false;
	zoom = 50;
	horizontal = 10;
	rotation = 0.0f;
	glEnable(GL_DEPTH_TEST);
	glfwSetKeyCallback(window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
		{
			if (key == GLFW_KEY_TAB) {
				switchCam();
			}
			if (key == GLFW_KEY_S) {
				zoom += 1;
			}
			if (key == GLFW_KEY_W) {
				zoom -= 1;
			}
			if (key == GLFW_KEY_A) {
				rotation += 1;
			}
			if (key == GLFW_KEY_D) {
				rotation -= 1;
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

void switchCam()
{
	watch->stop();
	if (watch->getElapsedTime() > 1000) {
		camIsFree = !camIsFree;
		modelFactory->camIsActive = !modelFactory->camIsActive;
		watch->start();
	}


}