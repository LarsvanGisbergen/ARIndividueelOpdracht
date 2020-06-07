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

	//additional info for update
	double _deltaX;
	double _deltaZ;

	

	float _rotation;
public:
	//ctor
	Model(ObjModel* objModel);

	void draw();
	void update();

	//extra
	void setDeltaX(double dx);
	void setDeltaZ(double dz);
	void setInputVelocityX(double vel);
	void setInputVelocityZ(double vel);
	glm::vec3 getPosition();
	void setRotation(float rot);
	float getRotation();
	//atts
	double _inputVelocityX;
	double _inputVelocityZ;
};

