#include "Engine/Scene/SceneManager.h"

SceneManager::SceneManager(SDL_Window* window, int& width, int& height) {
	this->width = width;
	this->height = height;
	this->window = window;

	this->defScene = Scene("DefaultScene");

	GameObject* asd = new GameObject("asd");

	this->defScene.AddObject(asd);
	asd->LoadModel("./f16.obj");
	/*asd->vertex = {
	0.f, 1.f, 0.0f,
	1.f, -1.f, 0.0f,
	-1.f,  -1.f, 0.0f
	};*/
	this->actualScene = defScene;
}

void SceneManager::Render(float deltaTime) {
	this->actualScene.Update(deltaTime);
	this->actualScene.Render(this->window, this->width, this->height);
}

void SceneManager::ChangeScene(string name) {
	for (Scene scene : projectScenes) {
		if (scene.name == name) {
			this->actualScene = scene;
			break;
		}
	}
	return;
}