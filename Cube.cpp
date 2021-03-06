#include "Cube.h"




Cube::Cube(glm::vec3 position, glm::vec4 color, int size) {
	_position = position;
	_color = color;
	_rotation = 0.0f;
	_size = size;
	
}

void Cube::update() {

	if (_rotation >= 2 * 3.14) {
		_rotation = 0.0f;
	}
	_rotation += 0.001f;
}

void Cube::draw() {

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, _position);
	model = glm::rotate(model, (float)_rotation, glm::vec3(0, 1, 0));
	model = glm::scale(model, glm::vec3((float)_size, (float)_size, (float)_size));
	tigl::shader->setModelMatrix(model);
	tigl::begin(GL_QUADS);
	
	
	//front face
	tigl::addVertex(Vertex::PCN(glm::vec3(-1, 1, 1), _color, glm::vec3(1, 0, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(1, 1, 1), _color, glm::vec3(-1, 0, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(1, -1, 1), _color, glm::vec3(-1, 0, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(-1, -1, 1), _color, glm::vec3(1, 0, 1)));

	//left face
	tigl::addVertex(Vertex::PCN(glm::vec3(-1, 1, 1), _color, glm::vec3(1, 0, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(-1, 1, -1), _color, glm::vec3(-1, 0, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(-1, -1, -1), _color, glm::vec3(-1, 0, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(-1, -1, 1), _color, glm::vec3(1, 0, 1)));

	//right face
	tigl::addVertex(Vertex::PCN(glm::vec3(1, 1, 1), _color, glm::vec3(-1, 0, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(1, 1, -1), _color, glm::vec3(1, 0, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(1, -1, -1), _color, glm::vec3(1, 0, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(1, -1, 1), _color, glm::vec3(-1, 0, 1)));

	//top face
	tigl::addVertex(Vertex::PCN(glm::vec3(-1, 1, 1), _color, glm::vec3(1, 0, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(-1, 1, -1), _color, glm::vec3(-1, 0, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(1, 1, -1), _color, glm::vec3(1, 0, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(1, 1, 1), _color, glm::vec3(-1, 0, 1)));

	//bottom face
	tigl::addVertex(Vertex::PCN(glm::vec3(-1, -1, 1), _color, glm::vec3(1, 0, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(-1, -1, -1), _color, glm::vec3(-1, 0, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(1, -1, -1), _color, glm::vec3(1, 0, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(1, -1, 1), _color, glm::vec3(-1, 0, 1)));

	//back face
	tigl::addVertex(Vertex::PCN(glm::vec3(-1, 1, -1), _color, glm::vec3(-1, 0, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(1, 1, -1), _color, glm::vec3(1, 0, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(1, -1, -1), _color, glm::vec3(1, 0, 1)));
	tigl::addVertex(Vertex::PCN(glm::vec3(-1, -1, -1), _color, glm::vec3(-1, 0, 1)));

	tigl::end();
}



//getters


glm::vec3 Cube::getPosition() {
	return _position;
}

glm::vec4 Cube::getColor() {
	return _color;
}


