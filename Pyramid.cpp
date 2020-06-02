#include "Pyramid.h"


Pyramid::Pyramid(glm::vec3 position, glm::vec4 color, int size) {
	_position = position;
	_color = color;
	_size = size;
}

void Pyramid::update()
{
}

void Pyramid::draw()
{
}

glm::vec3 Pyramid::getPosition()
{
	return _position;
}

glm::vec4 Pyramid::getColor()
{
	return _color;
}
