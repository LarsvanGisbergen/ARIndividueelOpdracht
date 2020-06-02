#include "Cube.h"



float rotation;

Cube::Cube(glm::vec3 position, glm::vec4 color, int size) {
	position[0] *= size;
	_position = position;
	_color = color;
	rotation = 0.0f;
	_size = size;
}

void Cube::update() {

	if (rotation >= 2 * 3.14) {
		rotation = 0.0f;
	}
	rotation += 0.001f;
	printf("current rotation: %f \n", rotation);
}

void Cube::draw() {

	glm::mat4 model = glm::mat4(1.0f);
	model = glm::translate(model, _position);
	model = glm::rotate(model, (float)rotation, glm::vec3(0, 1, 0));
	model = glm::scale(model, glm::vec3((float)_size, (float)_size, (float)_size));
	tigl::shader->setModelMatrix(model);
	tigl::begin(GL_QUADS);

	//front face
	tigl::addVertex(Vertex::PC(glm::vec3(-1, 1, 1), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(1, 1, 1), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(1, -1, 1), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, 1), _color));

	//left face
	tigl::addVertex(Vertex::PC(glm::vec3(-1, 1, 1), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(-1, 1, -1), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, -1), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, 1), _color));

	//right face
	tigl::addVertex(Vertex::PC(glm::vec3(1, 1, 1), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(1, 1, -1), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(1, -1, -1), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(1, -1, 1), _color));

	//top face
	tigl::addVertex(Vertex::PC(glm::vec3(-1, 1, 1), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(-1, 1, -1), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(1, 1, -1), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(1, 1, 1), _color));

	//bottom face
	tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, 1), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, -1), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(1, -1, -1), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(1, -1, 1), _color));

	//back face
	tigl::addVertex(Vertex::PC(glm::vec3(-1, 1, -1), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(1, 1, -1), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(1, -1, -1), _color));
	tigl::addVertex(Vertex::PC(glm::vec3(-1, -1, -1), _color));

	tigl::end();
}



//getters


glm::vec3 Cube::getPosition() {
	return _position;
}

glm::vec4 Cube::getColor() {
	return _color;
}

