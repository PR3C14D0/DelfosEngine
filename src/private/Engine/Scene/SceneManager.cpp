#include "Engine/Scene/SceneManager.h"

SceneManager::SceneManager(SDL_Window* window, int& width, int& height) {
	this->width = width;
	this->height = height;
	this->window = window;

	this->defScene = Scene(window, "DefaultScene");

	GameObject* asd = new GameObject("F16");

	this->defScene.AddObject(asd);
	asd->LoadModel("./f16.obj");
	this->actualScene = defScene;
}

void SceneManager::Render(float deltaTime) {
	this->actualScene.Update(deltaTime);
	this->actualScene.Render(this->width, this->height);
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