#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Shape.h"

using tigl::Vertex;
class Pyramid : public Shape
{
private:

	glm::vec3 _position;
	glm::vec4 _color;
	int _size;
	float _rotation;
	bool _isRotatingClockwise;
public:
	//constructor
	Pyramid(glm::vec3 position, glm::vec4 color, int size);

	//methodes
	void update();
	void draw();
	glm::vec3 getPosition();
	glm::vec4 getColor();
};

