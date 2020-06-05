#pragma once
#include <fstream>


static class ModelFileReader
{
public:
	const std::string& stringData getStringData();

private:
	const std::string& fileName = "model_data.txt";
	std::ifstream getInputFileStream();
};

