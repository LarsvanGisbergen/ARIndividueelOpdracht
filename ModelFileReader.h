#pragma once
#include <fstream>
#include "ModelFactory.h"

static class ModelFileReader
{
public:
	char* getStringData(ModelFactory::ModelType type);

private:
	const std::string& _fileName = "model_data.txt";
};



