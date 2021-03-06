#pragma once
#include <GL/glew.h>
#include <GLFW/glfw3.h>
#include "tigl.h"
#include <glm/gtc/matrix_transform.hpp>
#include "Shape.h"

using tigl::Vertex;
class Sphere : public Shape
{
private:

	glm::vec3 _position;
	glm::vec4 _color;
	double _size;
	float _rotation;
	bool isGrowing;

public:

	//constructor
	Sphere(glm::vec3 position, glm::vec4 color, int size);

	//methodes
	void update();
	void draw();
	glm::vec3 getPosition();
	glm::vec4 getColor();
	double getSize();
};

