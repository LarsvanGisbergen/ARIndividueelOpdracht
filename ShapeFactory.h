#pragma once
#include "Shapes.h"

class ShapeFactory
{
public:
	ShapeFactory();
	std::vector<Shape*> _shapes;
	enum ShapeType { DEFAULT, SPHERE, CUBE, PYRAMID };
	void makeShape(glm::vec3 position, glm::vec4 color, int size, ShapeType type);
	void updateShapes();
	void drawShapes();
private:
	void addShape(Shape* shape);
	
};

