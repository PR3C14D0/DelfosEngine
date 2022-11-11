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
	Vector3 operator * (float a);
	Vector3 operator + (const Vector3& vec2);
	Vector3 operator = (const Vector3& vec);
	Vector3 operator += (const Vector3& vec);

	glm::vec3 toGLMVec3();
};