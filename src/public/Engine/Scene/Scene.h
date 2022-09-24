#pragma once
#include <iostream>
#include <fstream>
#include <JSON/json.hpp>
#include "Engine/GameObject/GameObject.h"
#include <vector>

using namespace std;

class Scene {
protected:
	vector<GameObject> sceneGo;
public:
	Scene(string name);
	GameObject GetObjectByName(string name);
};