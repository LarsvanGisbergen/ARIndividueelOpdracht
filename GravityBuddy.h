#pragma once
#include <vector>
#include <glm\detail\type_vec3.hpp>
#include "Shapes.h"
#include "Model.h"

class GravityBuddy
{
public:
	//ctor
	GravityBuddy(std::vector<Sphere> blackHoles);
	//func
	std::vector<double> getDeltas(Model* model);
	
	
private:
	std::vector<Sphere> _blackHoles;
};

