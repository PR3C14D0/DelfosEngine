#pragma once
#include "Math/Vector/Vector3.h"

struct Transform {
private:
	Vector3 Location;
	Vector3 Rotation;
	Vector3 Scale;
public:
	Transform() {};
	Transform(Vector3 Location, Vector3 Rotation, Vector3 Scale);
	void translate(float x, float y, float z);
};