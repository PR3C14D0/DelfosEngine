#pragma once

#define GL_GLEXT_PROTOTYPES
#include "Engine/GameObject/GameObject.h"
#include <GL/glew.h>
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <gl/GLU.h>

using namespace std;

struct Node {
	friend class Scene;
protected:
	GameObject* obj;
public:
	vector<Node*> childrens;
	void AddChild(Node* node);
	Node* GetChild(int index);
	void RemoveChild(int index);
};

class Scene {
	friend class SceneManager;
protected:
	string name;
	Node* root;
	float totalTime;
public:
	Scene() {};
	Scene(string name);
	void AddObject(GameObject* pGo);
	void Render(SDL_Window* window, int width, int height);
	void Update(float deltaTime);
};