#include "Pyramid.h"
#include <iostream>


Pyramid::Pyramid(glm::vec3 position, glm::vec4 color, int size) {
	_position = position;
	_color = color;
	_rotation = 1.0f;
	_size = size;
	_isRotatingClockwise = true;
}

void Pyramid::update()
{
	if (_isRotatingClockwise) {
		if (_rotation <= 0) {
			_isRotatingClockwise = !_isRotatingClockwise;
		}
		_rotation -= 0.01;
	}
	else {
		if (_rotation >= 3) {
			_isRotatingClockwise = !_isRotatingClockwise;
		}
		_rotation += 0.01;
	}

}

void Pyramid::draw()
{
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, _position);
	model = glm::rotate(model, (float)_rotation, glm::vec3(0, 1, 0));
	model = glm::scale(model, glm::vec3((float)_size, (float)_size, (float)_size));
	tigl::shader->setModelMatrix(model);

	tigl::begin(GL_TRIANGLES);
	tigl::addVertex(Vertex::PC(glm::vec3(0, 1, 0), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, 1), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(1, -1, 1), _color));

	tigl::addVertex(Vertex::PC(glm::vec3(0, 1, 0), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, 1), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(0, -1, -1), _color));

	tigl::addVertex(Vertex::PC(glm::vec3(0, 1, 0), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(0, -1, -1), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(1, -1, 1), _color));

	tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, 1), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(0, -1, -1), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(1, -1, 1), _color));

	tigl::end();
}

glm::vec3 Pyramid::getPosition()
{
	return _position;
}

glm::vec4 Pyramid::getColor()
{
	return _color;
}
