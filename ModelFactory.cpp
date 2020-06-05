#include "ModelFactory.h"
#include <iostream>


ModelFactory::ModelFactory()
{
	
}

void ModelFactory::makeModel(glm::vec3 position, int size, ModelType type)
{
	switch (type) {
	
	case SHIP:
		//file io
		std::cout << "making a ship" << std::endl;
		//setModel(new Model(new ObjModel()));
		break;

	case CAR:
		//file io
		std::cout << "making a car" << std::endl;
		//setModel(new Model(new ObjModel()));
		break;
	
	}
}

void ModelFactory::setModel(Model* model)
{
	_model = model;
}

void ModelFactory::updateModel() {
	if(_model != NULL)
	_model->update();
}

void ModelFactory::drawModel()
{	
	if (_model != NULL)
	_model->draw();	
}