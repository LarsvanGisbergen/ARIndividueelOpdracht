#pragma once
#include <glm\ext\vector_float3.hpp>
#include "ObjModel.h"
class Model
{
private:
	//att
	ObjModel* _objModel;

	glm::vec3 _position;
	double _size;
	//func
	void setModelMatrix();
public:
	//ctor
	Model(ObjModel* objModel);

	void draw();
	void update();
};

