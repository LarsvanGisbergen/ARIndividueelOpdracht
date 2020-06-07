#include "ModelFactory.h"
#include <iostream>


ModelFactory::ModelFactory(GLFWwindow* window)
{
	_modelFileReader = new ModelFileReader();
	_window = window;
	camIsActive = false;
	
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
		_model->setDeltaZ(deltas[1]);

		if (camIsActive) {
			//manually interact with model
			if (glfwGetKey(_window, GLFW_KEY_LEFT) == GLFW_PRESS)
				_model->setRotation(_model->getRotation() - 0.1);
			if (glfwGetKey(_window, GLFW_KEY_RIGHT) == GLFW_PRESS)
				_model->setRotation(_model->getRotation() + 0.1);
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

		float x = xpos +(10 * glm::cos(glm::pi<float>() / 180 * _model->getRotation()));
		float z = zpos +(10 * glm::sin(glm::pi<float>() / 180 * _model->getRotation()));

		_modelCameraView = glm::lookAt(glm::vec3(x, ypos + 5, z),
			glm::vec3(xpos, ypos + 3,zpos),
			glm::vec3(0, 1, 0));
	}
}

void ModelFactory::setGravityBuddy(GravityBuddy* gravityBuddy)
{
	_gravityBuddy = gravityBuddy;
}
