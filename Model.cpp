#include "Model.h"
#include <glm\ext\matrix_transform.hpp>
#include <glm\ext\matrix_transform.hpp>
#include "tigl.h"
#include <iostream>

Model::Model(ObjModel* objModel) {
	_position = glm::vec3{ 0,0,0 };
	_size = 0.1; //standard size
	_objModel = objModel;
	_rotation = 0.0f;
}


void Model::draw() {
	setModelMatrix();
	_objModel->draw();
}

void Model::update() {
	_position[0] += (_deltaX +_inputVelocityX);
	_position[2] += (_deltaZ + _inputVelocityZ);
	std::cout << _position[0] << " : " << _position[2] << std::endl;
	
}

void Model::setDeltaX(double dx)
{
	_deltaX = dx;
}

void Model::setDeltaZ(double dz)
{
	_deltaZ = dz;
}

glm::vec3 Model::getPosition()
{
	return _position;
}

void Model::setPosition(glm::vec3 position)
{
	_position = position;
}

float Model::getRotation()
{
	return _rotation;
}

void Model::setModelMatrix() {
	
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::rotate(model, (float)glm::radians(_rotation), glm::vec3(0, 1, 0)); //achter radians is rotation
	model = glm::translate(model, _position);
	model = glm::scale(model, glm::vec3(_size, _size, _size)); // in vec3 is size
	tigl::shader->setModelMatrix(model);
}


