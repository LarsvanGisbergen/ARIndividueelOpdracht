#include "ModelFactory.h"
#include <iostream>


ModelFactory::ModelFactory()
{
	_modelFileReader = new ModelFileReader();
}

void ModelFactory::makeModel(glm::vec3 position, int size, ModelType type)
{
	std::string data = "";
	switch (type) {
	
	case SHIP:
		//file io
		data = _modelFileReader->getStringData(SHIP);
		setModel(new Model(new ObjModel(data)));
		break;

	case CAR:
		//file io
		data = _modelFileReader->getStringData(CAR);
		setModel(new Model(new ObjModel(data)));
		break;	
	}
}

void ModelFactory::setModel(Model* model)
{
	_model = model;
}

void ModelFactory::updateModel() {
	if (_model) {
		//get deltas from gravitybuddy if exists
		std::vector<double> deltas = _gravityBuddy->getDeltas(_model);
		_model->setDeltaX(deltas[0]);
		_model->setDeltaY(deltas[1]);
		_model->update();
	}
}

void ModelFactory::drawModel()
{	
	if (_model)
	_model->draw();	
}

void ModelFactory::setGravityBuddy(GravityBuddy* gravityBuddy)
{
	_gravityBuddy = gravityBuddy;
}
