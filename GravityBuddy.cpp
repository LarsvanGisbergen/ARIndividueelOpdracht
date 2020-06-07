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
		glm::vec3 tempCoords{0};
		
		double distanceX = modelPosition.x - currentCoords.x;
		
		double distanceZ = modelPosition.z - currentCoords.z;
		if ((int)distanceX == 0 && (int)distanceZ == 0) {
			return deltas;
		}
		else if (distanceX == (int)0) {
			tempCoords.z += ((double)sphere.getSize() / distanceZ);
		}
		else if (distanceZ == (int)0) {
			tempCoords.x += ((double)sphere.getSize() / distanceX);
		}
		else {
	
			tempCoords.z += ((double)sphere.getSize() / distanceZ);
			tempCoords.x += ((double)sphere.getSize() / distanceX);
		}
			
			coords.push_back(tempCoords);
		
		//vector now has values based on size and distance
	}
	if (size(coords) == 0) {
		return deltas;
	}
	
	double dz = 0;
	double dx = 0;
	for (int i = 0; i < size(coords); i++)
	{
		//make one vector out of all others
		dx += -coords.at(i).x;
		dz += -coords.at(i).z;
	}

	//set deltas to resultant vector values
	deltas[0] = dx /100;
	deltas[1] = dz /100;
	
	return deltas;
}