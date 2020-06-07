#include "ShapeFactory.h"

ShapeFactory::ShapeFactory()
{

}



void ShapeFactory::makeShape(glm::vec3 position, glm::vec4 color, int size, ShapeType type)
{
	switch (type) {
		case DEFAULT:
			addShape(new Shape());			
		case CUBE:
			addShape(new Cube(position, color, size));
			break;
		case SPHERE:
			addShape(new Sphere(position, color, size));
			break;
		case PYRAMID:
			addShape(new Pyramid(position, color, size));
			break;
		case PRISM:
			addShape(new Prism(position, color, size));
			break;
	}
}

void ShapeFactory::addShape(Shape* shape)
{
	_shapes.push_back(shape);
}

void ShapeFactory::updateShapes() {
	for (auto& shape : _shapes) {
		shape->update();
	}
}

void ShapeFactory::drawShapes()
{
	for (auto& shape : _shapes) {
		shape->draw();
	}
}

std::vector<Sphere> ShapeFactory::getSpheres()
{
	std::vector<Sphere> spheres;
	for (auto& shape : _shapes) {
		if (typeid(*shape) == typeid(Sphere)) {
			Sphere sphere = dynamic_cast<Sphere&>(*shape);
			spheres.push_back(sphere);
		}
	}
	
	return spheres;
}
