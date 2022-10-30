#pragma once
#include <iostream>
#include "Math/Transform/Transform.h"
#include <GL/glew.h>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <gl/GLU.h>
#include <GL/glm/glm.hpp>
#include <GL/glm/vec3.hpp>
#include <GL/glm/ext/matrix_transform.hpp>
#include "Module/Input/Input.h"

using namespace std;

class Camera {
	friend class Scene;
private:
	SDL_Event event;
public:
	Camera(string name);
	Transform* transform;
	string name;
	virtual void Update(float deltaTime);
	Input* input;
};