#pragma once
#include "Math/Transform/Transform.h"
#include <iostream>
#include <vector>

using namespace std;

class GameObject {
public:
	GameObject() {};
	virtual void OnCreate();
	virtual void Update();
	
	vector<vector<Vector3>> faces;

	string name;
	GameObject(string name);
	Transform* transform;
};