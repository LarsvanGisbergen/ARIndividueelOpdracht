#include "ModelFileReader.h"
#include "ModelFactory.h"
#include <iostream>
#include <string>
#include "enums.h"



ModelFileReader::ModelFileReader()
{
}

std::string ModelFileReader::getStringData(ModelType type)
{
	std::ifstream stream = std::ifstream();
	stream.open(_fileName); //model data textfile
	char* line = new char[50]{""};
	int length;
	std::string stringData = "";
	if (stream.is_open())
	{
		while (stream.getline(line,50))
		{
			length = strlen(line);			
			if (length != 0) {
				if (line[0] - 48 == type) {
					for (int i = 2; i < length; i++)
					{
						stringData += line[i];
					}
				}
			}
		}
		stream.close();
	}
	
	// TODO: insert return statement 
	std::cout << "stringdata: " << stringData << '\n' << std::endl;
	return stringData;
}


