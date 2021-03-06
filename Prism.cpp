#include "Prism.h"
#include <glm\ext\matrix_transform.hpp>

Prism::Prism(glm::vec3 position, glm::vec4 color, int size)
{
	_position = position;
	_color = color;
	_rotation = 0.0f;
	_size = size;
	_canIncreaseColor = true;
}

void Prism::update()
{
	if (_canIncreaseColor) {
		_color[0] += 0.001;
		if (_color[0] >= 1) {
			_canIncreaseColor = !_canIncreaseColor;
		}
	}
	else {
		_color[0] -= 0.001;
		if (_color[0] <= 0) {
			_canIncreaseColor = !_canIncreaseColor;
		}
	}
}

void Prism::draw()
{
	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, _position);
	model = glm::rotate(model, (float)_rotation, glm::vec3(0, 1, 0));
	model = glm::scale(model, glm::vec3((float)_size, (float)_size, (float)_size));
	tigl::shader->setModelMatrix(model);
	tigl::begin(GL_POLYGON);
	// Draw the First from square,Square 1.
	tigl::addVertex(Vertex::PCN(glm::vec3(-0.5, -1, 1.5), _color, glm::vec3(1, 1, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(0.5, -1, 1.5), _color, glm::vec3(-1, 1, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(0.5, 1, 1.5), _color, glm::vec3(1, 1, -1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(0.5, 1, 1.5), _color, glm::vec3(1, 1, -1)));
	//tigl::end();

	
	//tigl::begin(GL_POLYGON);// Draw the right from the front the square.
	tigl::addVertex(Vertex::PCN(glm::vec3(0.5, -1, 1.5), _color, glm::vec3(-1, 1, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(1, -1, 0.5), _color, glm::vec3(-1, 1, 0)));
	tigl::addVertex(Vertex::PCN(glm::vec3(1, 1, 0.5), _color, glm::vec3(-1, 1, 0)));
	tigl::addVertex(Vertex::PCN(glm::vec3(0.5, 1, 1.5), _color, glm::vec3(1, 1, -1)));
	//tigl::end();


	//tigl::begin(GL_POLYGON);// Draw the straight square from right.
	tigl::addVertex(Vertex::PCN(glm::vec3(1, -1, 0.5), _color, glm::vec3(1, 1, 0)));
	tigl::addVertex(Vertex::PCN(glm::vec3(1, -1, -0.5), _color, glm::vec3(1, 1, 0)));
	tigl::addVertex(Vertex::PCN(glm::vec3(1, 1, -0.5), _color, glm::vec3(1, -1, 0)));
	tigl::addVertex(Vertex::PCN(glm::vec3(1, 1, 0.5), _color, glm::vec3(1, -1, 0)));
	//tigl::end();


	//tigl::begin(GL_POLYGON);
	tigl::addVertex(Vertex::PCN(glm::vec3(1, -1, -0.5), _color, glm::vec3(1, 1, 0)));
	tigl::addVertex(Vertex::PCN(glm::vec3(0.5, -1, -1.5), _color, glm::vec3(1, -1, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(0.5, 1, -1.5), _color, glm::vec3(1, 1, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(1, 1, -0.5), _color, glm::vec3(1, -1, 0)));
	//tigl::end();


	//tigl::begin(GL_POLYGON);// Draw the behind square.
	tigl::addVertex(Vertex::PCN(glm::vec3(0.5, -1, -1.5), _color, glm::vec3(1, -1, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(-0.5, -1, -1.5), _color, glm::vec3(-1, -1, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(-0.5, 1, -1.5), _color, glm::vec3(-1, 1, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(0.5, 1, -1.5), _color, glm::vec3(1, 1, 1)));
	//tigl::end();


	//tigl::begin(GL_POLYGON);//draw the left suare.
	tigl::addVertex(Vertex::PCN(glm::vec3(-0.5, -1, -1.5), _color, glm::vec3(-1, -1, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(-1, -1, -0.5), _color, glm::vec3(1, -1, 0)));
	tigl::addVertex(Vertex::PCN(glm::vec3(-1, 1, -0.5), _color, glm::vec3(1, 1, 0)));
	tigl::addVertex(Vertex::PCN(glm::vec3(-0.5, 1, -1.5), _color, glm::vec3(-1, 1, 1)));
	//tigl::end();

	//tigl::begin(GL_POLYGON);// Draw the square next to the left.
	tigl::addVertex(Vertex::PCN(glm::vec3(-1, -1, -0.5), _color, glm::vec3(1, -1, 0)));
	tigl::addVertex(Vertex::PCN(glm::vec3(-1, -1, 0.5), _color, glm::vec3(1, -1, 0)));
	tigl::addVertex(Vertex::PCN(glm::vec3(-1, 1, 0.5), _color, glm::vec3(1, 1, 0)));
	tigl::addVertex(Vertex::PCN(glm::vec3(-1, 1, -0.5), _color, glm::vec3(1, 1, 0)));
	//tigl::end();


	//tigl::begin(GL_POLYGON);// Draw the square next to the left.
	tigl::addVertex(Vertex::PCN(glm::vec3(-1, -1, 0.5), _color, glm::vec3(1, -1, 0)));
	tigl::addVertex(Vertex::PCN(glm::vec3(-0.5, -1, 1.5), _color, glm::vec3(1, 1, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(-0.5, 1, 1.5), _color, glm::vec3(1, -1, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(-1, 1, 0.5), _color, glm::vec3(1, -1, 0)));
	tigl::end();
	

}
