#pragma once
#include "Model.h"
#include "ModelFileReader.h"
#include "enums.h"
class ModelFactory
{
public:
	
	//atts
	Model* _model;
	ModelFileReader* _modelFileReader;
	//funcs
	ModelFactory();
	void makeModel(glm::vec3 position, int size, ModelType type);
	void updateModel();
	void drawModel();

private:
	void setModel(Model* shape);

};

