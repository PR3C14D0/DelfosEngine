#include "Engine/Scene/Scene.h"

Scene::Scene(string name) {
	this->name = name;
	EditorCamera = new Camera("Editor Camera");
}

void Scene::AddObject(GameObject* pGo) {
	go.push_back(pGo);

	return;
}

void Scene::Update(float deltaTime) {;
	this->totalTime += (deltaTime);
	this->EditorCamera->Update(deltaTime);
}

void Scene::Render(SDL_Window* window, int width, int height) {
	glClearDepth(1.f);
	glClearColor(0.f, 0.f, 0.f, 0.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_TEXTURE);
	glEnable(GL_COLOR);
	glEnable(GL_DEBUG_OUTPUT);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	this->proj = glm::perspective(glm::radians(90.f), ((float)width / (float)height), .1f, 300.f);

	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	this->view = glm::lookAt(
		glm::vec3(0.f, 0.f, -1.f),
		glm::vec3(0.f, 0.f, 0.f),
		glm::vec3(0.0f, 1.0f, 0.0f));

	this->model = glm::translate(glm::mat4(1.f), glm::vec3(0.f, 0.f, 0.f));

	glm::mat4 mvp = proj * view * model;

	for (GameObject* g : go) {
		g->PrepareRender();
		g->Draw(mvp);
	}

	SDL_GL_SwapWindow(window);
}