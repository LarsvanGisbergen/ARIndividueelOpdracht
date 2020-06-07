#include "GravityBuddy.h"

GravityBuddy::GravityBuddy(std::vector<Sphere> blackHoles)
{
	_blackHoles = blackHoles;
}

std::vector<double> GravityBuddy::getDeltas(Model* model) {
	glm::vec3 modelPosition = model->getPosition();
	std::vector<double> deltas {0.0, 0.0}; // default no change in deltas
	std::vector<glm::vec3> coords;
	for (Sphere sphere : _blackHoles) {
		//translate coords to force of attraction based on size
		glm::vec3 currentCoords = sphere.getPosition();
		
		double distance = std::sqrt(std::pow((modelPosition[0] - currentCoords[0]), 2) + std::pow((modelPosition[2] - currentCoords[2]), 2));
		currentCoords[0] *= (sphere.getSize()/distance);
		currentCoords[2] *= (sphere.getSize()/distance);
		coords.push_back(currentCoords);
		//vector now has values based on size and distance
	}
	if (size(coords) == 0) {
		return deltas;
	}
	int c = size(coords);
	double dz = 0;
	double dx = 0;
	for (int i = 0; i < size(coords); i++)
	{
		//make one vector out of all others
		dx += coords[i][0];
		dz += coords[i][2];
	}

	//set deltas to resultant vector values
	deltas[0] = dx;
	deltas[1] = dz;
	
	return deltas;
}