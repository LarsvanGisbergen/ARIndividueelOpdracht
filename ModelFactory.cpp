#include "ModelFactory.h"
#include <iostream>


ModelFactory::ModelFactory(GLFWwindow* window)
{
	_modelFileReader = new ModelFileReader();
	_window = window;
	camIsActive = false;
	
}

ModelFactory::~ModelFactory()
{
	delete _modelFileReader;
}

void ModelFactory::makeModel(glm::vec3 position, int size, ModelType type)
{
	std::string data = "";
	ModelFileWriter* writer = new ModelFileWriter();
	
		//file io
		data = _modelFileReader->getStringData(type);
		setModel(new Model(new ObjModel(data)));	
		writer->saveModelType(type);
		delete writer;
}

void ModelFactory::setModel(Model* model)
{
	_model = model;
}

void ModelFactory::updateModel() {
	if (_model) {
		//get deltas from gravitybuddy if exists
		if (_gravityBuddy) {
			std::vector<double> deltas = _gravityBuddy->getDeltas(_model);
			_model->setDeltaX(deltas[0]);
			_model->setDeltaZ(deltas[1]);
		}

		if (camIsActive) {
			//manually interact with model
			if (glfwGetKey(_window, GLFW_KEY_LEFT) == GLFW_PRESS)
				_model->setRotation(_model->getRotation() + 0.1);
			if (glfwGetKey(_window, GLFW_KEY_RIGHT) == GLFW_PRESS)
				_model->setRotation(_model->getRotation() - 0.1);
			if (glfwGetKey(_window, GLFW_KEY_UP) == GLFW_PRESS)
				_model->setInputVelocityX((_model->_inputVelocityX + 0.0001));
			if (glfwGetKey(_window, GLFW_KEY_DOWN) == GLFW_PRESS)
				_model->setInputVelocityX((_model->_inputVelocityX - 0.0001));
			
		}
		_model->update();
	}
}

void ModelFactory::drawModel()
{	
	if (_model) {
		_model->draw();
	}
	if (camIsActive) {
		
		float xpos = _model->getPosition().x;
		float ypos = _model->getPosition().y;
		float zpos = _model->getPosition().z;

		//float x = xpos +(10 * glm::cos(glm::pi<float>() / 180 * _model->getRotation()));
		//float z = zpos +(10 * glm::sin(glm::pi<float>() / 180 * _model->getRotation()));

		_modelCameraView = glm::lookAt(glm::vec3(xpos + 5, ypos + 5, zpos + 5),
			glm::vec3(xpos, ypos,zpos),
			glm::vec3(0, 1, 0));
	}
}

void ModelFactory::setGravityBuddy(GravityBuddy* gravityBuddy)
{
	_gravityBuddy = gravityBuddy;
}

