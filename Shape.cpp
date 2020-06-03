#include "Shape.h"
#include <iostream>


void Shape::update()
{
	std::cout << "I am a shape" << std::endl;
	
}

void Shape::draw()
{
	std::cout << "draw() in shape called" << std::endl;
}
