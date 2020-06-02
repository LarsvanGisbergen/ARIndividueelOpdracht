#include "Sphere.h"
#include <corecrt_math_defines.h>



Sphere::Sphere(glm::vec3 position, glm::vec4 color, int size)
{
	_position = position;
	_color = color;
	_rotation = 0.0f;
	_size = size;
}

void Sphere::update()
{
	
}

void Sphere::draw()
{
	double r = _size / 2;
	int lats = 25;
	int longs = 25;
	 

	for (int i = 0; i <= lats; i++) {
		double lat0 = M_PI * (-0.5 + (double)(i - 1) / lats);
		double z0 = sin(lat0);
		double zr0 = cos(lat0);

		double lat1 = M_PI * (-0.5 + (double)i / lats);
		double z1 = sin(lat1);
		double zr1 = cos(lat1);

		glBegin(GL_QUAD_STRIP);
		for (int j = 0; j <= longs; j++) {
			double lng = 2 * M_PI * (double)(j - 1) / longs;
			double x = cos(lng);
			double y = sin(lng);

			glNormal3f(x * zr0, y * zr0, z0);
			glVertex3f(r * x * zr0, r * y * zr0, r * z0);
			glNormal3f(x * zr1, y * zr1, z1);
			glVertex3f(r * x * zr1, r * y * zr1, r * z1);
		}
		glEnd();
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
