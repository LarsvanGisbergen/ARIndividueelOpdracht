#pragma once
#include "Model.h"
class ModelFactory
{
public:
	enum ModelType { SHIP, CAR };
	ModelFactory();
	void makeModel(glm::vec3 position, int size, ModelType type);
	Model* _model;
	void updateModel();
	void drawModel();
private:
	void setModel(Model* shape);

};

