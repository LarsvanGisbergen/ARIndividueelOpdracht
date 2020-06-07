#pragma once
#include "Model.h"
#include "ModelFileReader.h"
#include "enums.h"
#include "GravityBuddy.h"
#include "ModelFileWriter.h"
class ModelFactory
{
public:
	
	//atts
	Model* _model;
	GLFWwindow* _window;
	ModelFileReader* _modelFileReader;
	glm::mat4 _modelCameraView;
	bool camIsActive;
	//funcs
	ModelFactory(GLFWwindow* window);
	void makeModel(glm::vec3 position, int size, ModelType type);
	void updateModel();
	void drawModel();
	void setGravityBuddy(GravityBuddy* gravityBuddy);
	GravityBuddy* _gravityBuddy;

private:
	void setModel(Model* shape);

};

