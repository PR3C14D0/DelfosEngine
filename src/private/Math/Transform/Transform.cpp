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
}

void Transform::rotate(float x, float y, float z) {
	this->Rotation.x += x;
	this->Rotation.y += y;
	this->Rotation.z += z;
}

void Transform::rescale(Vector3 Scale) {
	this->Scale = Scale;
}