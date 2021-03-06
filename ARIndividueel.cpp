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
#include "ModelFileWriter.h"
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

//model 
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
	modelFactory = new ModelFactory(window);
	
	modelFactory->makeModel(glm::vec3(0, 0, 0), 0.1, SHIP);
	
	shapeFactory->makeShape(glm::vec3(-25,0, 10), glm::vec4(0.1, 0.1, 0.1, 1), 5, PRISM);
	shapeFactory->makeShape(glm::vec3(-5, 0, 10), glm::vec4(0.8, 0.2, 0, 1), 5, CUBE);
	shapeFactory->makeShape(glm::vec3(10, 0, 10), glm::vec4(0, 0.3, 0.9, 1), 5, SPHERE);
	shapeFactory->makeShape(glm::vec3(25, 0, 10), glm::vec4(0.1, 0.8, 0.1, 1), 5, PYRAMID);
	//gravityBuddy = new GravityBuddy(shapeFactory->getSpheres());
	//modelFactory->setGravityBuddy(gravityBuddy);
	
	


	while (!glfwWindowShouldClose(window))
	{
		update();
		draw();
		glfwSwapBuffers(window);
		glfwPollEvents();
	}

	glfwTerminate();
	// delete all pointers before closing application
	delete shapeFactory, modelFactory, objModel, model, reader, gravityBuddy;

	return 0;
}

void init()
{
	tigl::init();
	//light
	tigl::shader->enableLighting(true);
	tigl::shader->setLightCount(1);
	tigl::shader->setLightDirectional(0, false);
	tigl::shader->setLightAmbient(0, glm::vec3(0.5f, 0.5f, 0.75f));
	tigl::shader->setLightDiffuse(0, glm::vec3(0.5f, 0.5f, 0.5f));
	tigl::shader->setLightSpecular(0, glm::vec3(0.5, 0.5, 0.5));
	tigl::shader->setShinyness(32.0f);
	//shader
	tigl::shader->enableTexture(true);
	cameraInit();
}


void update()
{
	shapeFactory->updateShapes();
	modelFactory->updateModel();
	tigl::shader->setLightPosition(0, glm::vec3(0, 10, 0));
	//tigl::shader->setLightPosition(0, glm::vec3(modelFactory->_model->getPosition().x, modelFactory->_model->getPosition().y + 2, modelFactory->_model->getPosition().z));
}

void draw()
{
	if (camIsFree) {
		//camera
		glm::mat4 projection = glm::perspective(glm::radians(45.0f), 1400 / (float)800, 0.1f, 100.0f);
		freeCameraView = glm::lookAt(glm::vec3(horizontal, 5, zoom), glm::vec3(horizontal, vertical, 0), glm::vec3(0, 1, 0));
		freeCameraView = glm::rotate(freeCameraView, (float)glm::radians(rotation), glm::vec3(0, 1, 0));
		tigl::shader->setProjectionMatrix(projection);
		tigl::shader->setViewMatrix(freeCameraView);
		//fog
		tigl::shader->enableFog(true);
		tigl::shader->setFogExp(0.003);
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
	zoom = 10;
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