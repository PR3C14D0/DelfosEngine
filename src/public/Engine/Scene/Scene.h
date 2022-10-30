#pragma once

#define GL_GLEXT_PROTOTYPES
#include "Engine/GameObject/GameObject.h"
#include <GL/glew.h>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <gl/GLU.h>
#include <GL/glm/glm.hpp>
#include <GL/glm/vec3.hpp>
#include <GL/glm/ext/matrix_transform.hpp>
#include "Module/Input/Input.h"
#include "Engine/Scene/Camera.h"

using namespace std;

class Scene {
	friend class SceneManager;
protected:
	string name;
	float totalTime;
	vector<GameObject*> go;
	glm::mat4 view;
	glm::mat4 proj;
	glm::mat4 model;
	Camera* EditorCamera;
public:
	Scene() {};
	Scene(string name);
	void AddObject(GameObject* pGo);
	void Render(SDL_Window* window, int width, int height);
	void Update(float deltaTime);
};