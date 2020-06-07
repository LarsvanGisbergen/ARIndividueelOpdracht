#pragma once
#include "Shape.h"
#include "tigl.h"

using tigl::Vertex;
class Prism : public Shape
{
private:
	glm::vec3 _position;
	glm::vec4 _color;
	int _size;
	float _rotation;
	bool _canIncreaseColor;
public:
	Prism(glm::vec3 position, glm::vec4 color, int size);
	void update();
	void draw();
};


