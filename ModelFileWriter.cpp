#include "ModelFileWriter.h"
#include "ModelFactory.h"
#include <iostream>
#include <string>
#include "enums.h"
#include <ctime>

ModelFileWriter::ModelFileWriter()
{
}

void ModelFileWriter::saveModelType(ModelType type)
{
	std::ofstream outfile;
	outfile.open(_fileName, std::fstream::app);
	time_t curr_time;
	tm* curr_tm;
	char date_string[100];
	time(&curr_time);
	curr_tm = localtime(&curr_time);

	switch (type) {
	case CAR:	
		strftime(date_string, 50, "CAR added on: %B %d, %Y" , curr_tm);
		outfile << date_string << std::endl;
		break;

	case SHIP:	
		strftime(date_string, 50, "SHIP added on: %B %d, %Y", curr_tm);
		outfile << date_string << std::endl;
		break;

	default:
		std::cout << "tried to write unrecognised type to file" << std::endl;
		break;
	}
	outfile.close();
}
