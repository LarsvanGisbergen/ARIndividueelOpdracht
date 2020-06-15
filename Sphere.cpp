#include "Sphere.h"
#include <corecrt_math_defines.h>

#include <iostream>
Sphere::Sphere(glm::vec3 position, glm::vec4 color, int size)
{
	_position = position;
	_color = color;
	_rotation = 0.0f;
	_size = size;
	isGrowing = true;
}

void Sphere::update()
{
	if (isGrowing && _size > 6.5) {
		isGrowing = !isGrowing;
	}
	else if (!isGrowing && _size < 5.5) {
		isGrowing = !isGrowing;
	}

	if (isGrowing) {
		_size += 0.005;
	}
	else if (!isGrowing) {
		_size -= 0.005;
	}
}

void Sphere::draw()
{
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, _position);
	model = glm::rotate(model, (float)_rotation, glm::vec3(0, 1, 0));
	//model = glm::scale(model, glm::vec3((float)_size, (float)_size, (float)_size));
	tigl::shader->setModelMatrix(model);

	double r = _size / 2;
	int lats = 25;
	int longs = 25;
	 
	for (int i = 0; i <= lats; i++) {
		double lat0 = M_PI * (-0.5 + (double)(i-1) / lats);
		double z0 = sin(lat0);
		double zr0 = cos(lat0);

		double lat1 = M_PI * (-0.5 + (double)i / lats);
		double z1 = sin(lat1);
		double zr1 = cos(lat1);

		tigl::begin(GL_QUAD_STRIP);
		for (int j = 0; j <= longs; j++) {
			double lng = 2 * M_PI * (double)(j-1) / longs;
			double x = cos(lng);
			double y = sin(lng);
			
			tigl::addVertex(Vertex::PC(glm::vec3(r * x * zr0, r * y * zr0, r * z0), _color));
			glVertex3f(r * x * zr0, r * y * zr0, r * z0);

			tigl::addVertex(Vertex::PC(glm::vec3(r * x * zr1, r * y * zr1, r * z1), _color));
			glVertex3f(r * x * zr1, r * y * zr1, r * z1);
		}
		tigl::end();
	}
}

glm::vec3 Sphere::getPosition()
{
	return _position;
}

glm::vec4 Sphere::getColor()
{
	return _color;
}

double Sphere::getSize()
{
	return _size;
}


