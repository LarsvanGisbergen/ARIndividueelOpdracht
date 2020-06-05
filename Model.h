#pragma once
#include <glm\ext\vector_float3.hpp>
#include "ObjModel.h"
class Model
{
private:
	//att
	glm::vec3 _position;
	ObjModel* _objModel;
	double _size;
	//func
	void setModelMatrix();
public:
	//ctor
	Model(ObjModel* objModel);

	void draw();
	void update();
};

