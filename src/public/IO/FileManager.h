#pragma once
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct FileManager {
public:
	FileManager() {};
	string LoadFile(const char* fileName);
};