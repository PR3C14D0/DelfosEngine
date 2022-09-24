#include "Math/Transform/Transform.h"

Transform::Transform(Vector3 Location, Vector3 Rotation, Vector3 Scale) {
	this->Location = Location;
	this->Rotation = Rotation;
	this->Scale = Scale;
}

void Transform::translate(float x, float y, float z) {
	this->Location.x += x;
	this->Location.y += y;
	this->Location.z += z;
	this->Location.z += z;
}