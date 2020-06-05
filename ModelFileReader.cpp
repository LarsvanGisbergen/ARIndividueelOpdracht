#include "ModelFileReader.h"
#include "ModelFactory.h"
#include <iostream>
#include <string>
char* ModelFileReader::getStringData(ModelFactory::ModelType type)
{
	std::ifstream stream = std::ifstream();
	stream.open(_fileName); //model data textfile
	
	char* line = new char[10]{""};
	if (stream.is_open())
	{
		while (stream.getline(line,10))
		{
			std::cout << line << '\n' << std::endl;
		}
		stream.close();
	}
	
	// TODO: insert return statement 
	
	return line;
}


