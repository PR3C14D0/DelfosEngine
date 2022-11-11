#include "Math/Vector/Vector3.h"

Vector3::Vector3(float x, float y, float z) {
	this->x = x;
	this->y = y;
	this->z = z;
}

glm::vec3 Vector3::toGLMVec3() {
	glm::vec3 v = glm::vec3(this->x, this->y, this->z);
	return v;
}

Vector3 Vector3::operator * (float a) {
	Vector3 v = Vector3{ this->x * a, this->y * a, this->z * a };
	return v;
}

Vector3 Vector3::operator = (const Vector3& vec) {
	this->x = vec.x;
	this->y = vec.y;
	this->z = vec.z;
	return Vector3{ this->x, this->y, this->z };
}

Vector3 Vector3::operator += (const Vector3& vec) {
	this->x = this->x + vec.x;
	this->y = this->y + vec.y;
	this->z = this->z + vec.z;
	return Vector3{ this->x, this->y, this->z };
}

Vector3 Vector3::operator + (const Vector3& vec2) {
	Vector3 v = Vector3{ this->x + vec2.x, this->y + vec2.y, this->z + vec2.z };
	return v;
}

Vector3 operator - (Vector3& vec1, Vector3& vec2) {
	Vector3 v = Vector3{ vec1.x - vec2.x, vec1.y - vec2.y, vec1.z - vec2.z };
	return v;
}