#pragma once

#include <GL/glm/glm.hpp>
#include <GL/glm/ext.hpp>
#include <GL/glm/gtc/quaternion.hpp>
#include <GL/glm/gtx/quaternion.hpp>
#include "Math/Vector/Vector3.h"

struct Quaternion {
	friend class Transform;
private:
	glm::quat quaternion;
	Quaternion(glm::quat rot);
public:
	Quaternion();
	Quaternion(Vector3& EulerAngles);
	Quaternion(float x, float y, float z);
	Quaternion operator * (const Quaternion& quat);
	glm::quat& toGLMQua();
};