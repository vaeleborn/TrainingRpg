#include "Logger.h"

void Logger::Log(std::string log, bool toFile, bool autoName, std::string fileName)
{
	if (!toFile) {
		std::cout << log << std::endl << std::endl;
	} 
	else {
		if (!autoName) {
			std::ofstream fileOut;
			fileOut.open(fileName);
			fileOut << log << std::endl << std::endl;
			fileOut.close();
		}
		else {
			std::time_t now = std::time(nullptr);
			std::tm ltm;
			localtime_s(&ltm, &now);

			std::stringstream temp;
			temp << "Debug_Log_" << std::put_time(&ltm, "%m-%d-%Y_%H:%M") << ".txt";
			fileName = temp.str();
			std::ofstream fileOut;
			fileOut.open(fileName);
			fileOut << log << std::endl << std::endl;
			fileOut.close();
		}
	}
}