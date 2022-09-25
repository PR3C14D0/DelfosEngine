#pragma once
#include "Engine/GameObject/GameObject.h"
#include <vector>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <gl/GLU.h>

using namespace std;

class Scene {
protected:
	vector<GameObject*> sceneGo;
	string name;
public:
	Scene() {};
	Scene(string name);
	void AddObject(GameObject* pGo);
	void Render(SDL_Window* window, int width, int height);
};