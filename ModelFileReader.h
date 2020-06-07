#pragma once
#include <fstream>
#include "enums.h"

class ModelFileReader
{
public:
	//ctor
	ModelFileReader();
	
	std::string getStringData(ModelType type);

private:
	const std::string& _fileName = "model_data.txt";

};



