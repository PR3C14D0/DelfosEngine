#pragma once
#include "Math/Vector/Vector3.h"

struct Transform {
private:
	Vector3 Scale;
	glm::vec3 forward;
	glm::vec3 direction;
public:
	Vector3 Location;
	Vector3 Rotation;
	Vector3 Forward();
	Vector3 Right();
	Vector3 Up();

	Vector3 RotatePoint(const Vector3 v);
	
	Transform() {};
	Transform(Vector3 Location, Vector3 Rotation, Vector3 Scale);
	void translate(float x, float y, float z);
	void translate(Vector3 vec);
	void rotate(float x, float y, float z);
	void rotate(Vector3 rot);
	void rescale(Vector3 Scale);
};