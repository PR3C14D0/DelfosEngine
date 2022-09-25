#pragma once
#include "Math/Vector/Vector3.h"

struct Transform {
private:
	Vector3 Scale;
public:
	Vector3 Location;
	Vector3 Rotation;
	Transform() {};
	Transform(Vector3 Location, Vector3 Rotation, Vector3 Scale);
	void translate(float x, float y, float z);
	void rotate(float x, float y, float z);
	void rescale(Vector3 Scale);
};