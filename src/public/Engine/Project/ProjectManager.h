#pragma once
#include <JSON/json.hpp>
#include <iostream>
#include <fstream>

using namespace std;
using json = nlohmann::json;

struct ProjectManager {
public:
	ProjectManager();
	void CreateProject(string name, string path);
};