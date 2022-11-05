#pragma once
#include <iostream>
#include "Math/Transform/Transform.h"
#include <GL/glew.h>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <GL/glm/glm.hpp>
#include <GL/glm/vec3.hpp>
#include <GL/glm/ext.hpp>
#include "Module/Input/Input.h"

using namespace std;

class Camera {
	friend class Scene;
private:
	SDL_Event event;
protected:
	int w, h;
	Input* input;
public:
	// Camera() = default;
	explicit Camera(string name);
	Transform* transform;
	string name;
	glm::mat4 View;
	glm::mat4 Perspective;
	void UpdateSize(int w, int h);
	virtual void Update(float deltaTime);
};