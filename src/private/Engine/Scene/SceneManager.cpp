#include "Engine/Scene/SceneManager.h"

SceneManager::SceneManager(SDL_Window* window, int& width, int& height) {
	this->width = width;
	this->height = height;
	this->window = window;

	this->defScene = Scene("DefaultScene");
	
	GameObject* sampleCube = new GameObject("Cube");
	sampleCube->faces = {
		{
			Vector3(1.f, 1.f, 1.f),
			Vector3(-1.f, 1.f, 1.f),
			Vector3(-1.f, -1.f, 1.f),
			Vector3(1.f, -1.f, 1.f),
			Vector3(1.f, 0.f, 0.f)
		},
		{
			Vector3(1.f, -1.f, -1.f),
			Vector3(1.f, 1.f, -1.f),
			Vector3(1.f, 1.f, 1.f),
			Vector3(1.f, -1.f, 1.f),
			Vector3(0.f, 1.f, 0.f)
		},
		{
			Vector3(1.f, -1.f, 1.f),
			Vector3(-1.f, -1.f, 1.f),
			Vector3(-1.f, -1.f, -1.f),
			Vector3(1.f, -1.f, -1.f),
			Vector3(1.f, 1.f, 0.f)
		},
		{
			Vector3(1.f, -1.f, -1.f),
			Vector3(1.f, 1.f, -1.f),
			Vector3(-1.f, 1.f, -1.f),
			Vector3(-1.f, -1.f, -1.f),
			Vector3(0.f, 0.f, 1.f)
		},
		{
			Vector3(-1.f, 1.f, -1.f),
			Vector3(-1.f, 1.f, 1.f),
			Vector3(-1.f, -1.f, 1.f),
			Vector3(-1.f, -1.f, -1.f),
			Vector3(1.f, 0.f, 1.f)
		},
		{
			Vector3(1.f, 1.f, 1.f),
			Vector3(-1.f, 1.f, 1.f),
			Vector3(-1.f, 1.f, -1.f),
			Vector3(1.f, 1.f, -1.f),
			Vector3(1.f, 1.f, 1.f)
		}
	};
	this->defScene.AddObject(sampleCube);
	sampleCube->transform->translate(0.f, 0.f, -10.f);
	this->actualScene = defScene;
}

void SceneManager::LoadScene() {
	this->actualScene.Render(this->window, this->width, this->height);
}