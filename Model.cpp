#include "Model.h"
#include <glm\ext\matrix_transform.hpp>
#include <glm\ext\matrix_transform.hpp>
#include "tigl.h"
#include <iostream>

Model::Model(ObjModel* objModel) {
	_position = glm::vec3{ 0,0,0 };
	_size = 0.1; //standard size
	_objModel = objModel;
}


void Model::draw() {
	setModelMatrix();
	_objModel->draw();
}

void Model::update() {
	_position[0] += _deltaX;
	_position[2] += _deltaY;
	std::cout << _position[0] << " : " << _position[2] << std::endl;
}

void Model::setDeltaX(double dx)
{
	_deltaX = dx;
}

void Model::setDeltaY(double dy)
{
	_deltaY = dy;
}

glm::vec3 Model::getPosition()
{
	return _position;
}

void Model::setModelMatrix() {
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::rotate(model, (float)glm::radians(0.0f), glm::vec3(0, 1, 0)); //achter radians is rotation
	model = glm::translate(model, _position);
	model = glm::scale(model, glm::vec3(_size, _size, _size)); // in vec3 is size
	tigl::shader->setModelMatrix(model);
}


