#include "Pyramid.h"


Pyramid::Pyramid(glm::vec3 position, glm::vec4 color, int size) {
	_position = position;
	_color = color;
	_rotation = 0.0f;
	_size = size;
}

void Pyramid::update()
{
	if (_rotation >= 2 * 3.14) {
		_rotation = 0.0f;
	}
	_rotation += 0.001f;
	printf("current rotation: %f \n", _rotation);
}

void Pyramid::draw()
{
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, _position);
	model = glm::rotate(model, (float)_rotation, glm::vec3(0, 1, 0));
	model = glm::scale(model, glm::vec3((float)_size, (float)_size, (float)_size));
	tigl::shader->setModelMatrix(model);

	glBegin(GL_TRIANGLES);
	glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(1.0f, -1.0f, 1.0f);

	glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(0.0f, -1.0f, -1.0f);

	glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(0.0f, 1.0f, 0.0f);
	glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(0.0f, -1.0f, -1.0f);
	glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(1.0f, -1.0f, 1.0f);

	glColor3f(1.0f, 0.0f, 0.0f); glVertex3f(-1.0f, -1.0f, 1.0f);
	glColor3f(0.0f, 1.0f, 0.0f); glVertex3f(0.0f, -1.0f, -1.0f);
	glColor3f(0.0f, 0.0f, 1.0f); glVertex3f(1.0f, -1.0f, 1.0f);

	glEnd();
}

glm::vec3 Pyramid::getPosition()
{
	return _position;
}

glm::vec4 Pyramid::getColor()
{
	return _color;
}
