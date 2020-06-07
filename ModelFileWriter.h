#pragma once
#pragma warning(disable : 4996)
#include "enums.h"
#include <string>
class ModelFileWriter
{
public:
	//func
	ModelFileWriter();
	void saveModelType(ModelType type);
	//att
	const std::string& _fileName = "loaded_models.txt";
private:
	
};

