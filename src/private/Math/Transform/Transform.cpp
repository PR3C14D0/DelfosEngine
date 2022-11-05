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

float Transform::Forward() {
	glm::mat4 rot = glm::mat4(1.f);
	rot = glm::rotate(rot, this->Rotation.x, glm::vec3(1, 0, 0));
	rot = glm::rotate(rot, this->Rotation.y, glm::vec3(0, 1, 0));
	rot = glm::rotate(rot, this->Rotation.z, glm::vec3(0, 0, 1));

	glm::vec3 forward = glm::vec3(rot * glm::vec4(0.f, 0.f, -1.f, 1.f));
	return forward.x;
}