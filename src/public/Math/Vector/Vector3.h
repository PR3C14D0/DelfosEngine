#pragma once
#include <GL/glm/glm.hpp>
#include <GL/glm/ext.hpp>

struct Vector3 {
public:
	float x;
	float y;
	float z;
	Vector3() {};
	Vector3(float x, float y, float z);

	glm::vec3 toGLMVec3();
};