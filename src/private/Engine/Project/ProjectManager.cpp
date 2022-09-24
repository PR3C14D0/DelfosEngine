#include "Engine/Project/ProjectManager.h"

ProjectManager::ProjectManager() {

}

void ProjectManager::CreateProject(string name, string path) {
	ofstream Project(name + ".dproj");
	string projectData = "{\"name\": \"" + name + "\"}";
	Project << projectData;
	string fullPathName = path + "\\" + name;
}