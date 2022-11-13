#include "Engine/Scene/Scene.h"

Scene::Scene(SDL_Window* window, string name) {
	this->name = name;
	this->window = window;
	this->editorCamera = new EditorCamera("Editor Camera");
	this->ActualCamera = this->editorCamera;

	this->editor = new Editor(this->window, "DelfosTest");
}

void Scene::AddObject(GameObject* pGo) {
	go.push_back(pGo);

	return;
}

void Scene::Update(float deltaTime) {;
	this->totalTime += (deltaTime);
	this->ActualCamera->Update(deltaTime);
	editor->Update(deltaTime);
}

void Scene::Render(int width, int height) {
	glClearDepth(1.f);
	glClearColor(0.f, 0.f, 0.f, 0.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_DEBUG_OUTPUT);

	this->model = glm::translate(glm::mat4(1.f), glm::vec3(0.f, 0.f, 0.f));
	this->ActualCamera->UpdateSize(width, height);

	glm::mat4 mvp = this->ActualCamera->Perspective * this->ActualCamera->View * model;

	for (GameObject* g : go) {
		g->PrepareRender();
		g->Draw(mvp);
	}

	ImGui::Render();
	ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());
	SDL_GL_SwapWindow(window);
}