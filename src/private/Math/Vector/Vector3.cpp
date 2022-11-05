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
