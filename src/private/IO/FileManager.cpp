#include "IO/FileManager.h"

string FileManager::LoadFile(const char* fileName) {
	ifstream file;
	file.open(fileName);

	if (!file.is_open()) {
		return "";
	}
	
	string content;
	string line;
	while (!file.eof()) {
		getline(file, line);
		content.append(line + "\n");
	}

	return content;
}