#pragma once
#include "Math/Transform/Transform.h"
#include <iostream>

using namespace std;

class GameObject {
protected:
	Transform transform;
public:
	virtual void OnCreate();
	virtual void Update();
	string name;
	GameObject(string name);
};