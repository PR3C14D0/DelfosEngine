#include "Math/Quaternion/Quaternion.h"

Quaternion::Quaternion() {
	this->quaternion = glm::quat(1.f, 0.f, 0.f, 0.f);
}

Quaternion Quaternion::operator * (const Quaternion& quat) {
	Quaternion retQuat = Quaternion{ quat.quaternion * this->quaternion };
	return retQuat;
}

Quaternion::Quaternion(Vector3& EulerAngles) {
	this->quaternion = glm::quat(EulerAngles.toGLMVec3());
}

Quaternion::Quaternion(glm::quat rot) {
	this->quaternion = rot;
}

Quaternion::Quaternion(float x, float y, float z) {
	this->quaternion = glm::quat(glm::vec3(x, y, z));
}

glm::quat& Quaternion::toGLMQua() {
	return quaternion;
}