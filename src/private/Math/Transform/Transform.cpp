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

void Transform::translate(Vector3 vec) {
	this->Location = this->Location + vec;
}

void Transform::rotate(Vector3 rot) {
	this->Rotation += rot;
}

void Transform::rotate(float x, float y, float z) {
	this->Rotation.x += x;
	this->Rotation.y += y;
	this->Rotation.z += z;
}

void Transform::rescale(Vector3 Scale) {
	this->Scale = Scale;
}

Vector3 Transform::Forward() {
	return this->RotatePoint(Vector3{ 0.f, 0.f, 1.f });
}

Vector3 Transform::Right() {
	return this->RotatePoint(Vector3 {1.f, 0.f, 0.f});
}

Vector3 Transform::Up() {
	return this->RotatePoint(Vector3{ 0.f, 1.f, 0.f });
}

Vector3 Transform::RotatePoint(const Vector3 v) {
	glm::mat4 rot = glm::mat4(1.f);
	rot = glm::rotate(rot, this->Rotation.toGLMVec3().y, glm::vec3(0, 1, 0));
	rot = glm::rotate(rot, this->Rotation.toGLMVec3().x, glm::vec3(1, 0, 0));
	rot = glm::rotate(rot, this->Rotation.toGLMVec3().z, glm::vec3(0, 0, 1));

	glm::vec3 res = glm::vec3(rot * glm::vec4(v.x, v.y, v.z, 1.f));
	Vector3 vRes = Vector3{ res.x, res.y, res.z };
	return vRes;
}