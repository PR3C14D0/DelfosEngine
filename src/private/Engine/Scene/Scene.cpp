#include "Engine/Scene/Scene.h"

Scene::Scene(string name) {
	this->name = name;
}

void Scene::AddObject(GameObject* pGo) {
	sceneGo.push_back(pGo);
	return;
}

void Scene::Render(SDL_Window* window, int width, int height) {
	glClearDepth(1.f);
	glClearColor(0.f, 0.f, 0.f, 0.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.f, ((float)width / (float)height), .1f, 300.f);
	
	for (GameObject* pGo : sceneGo) {
		GameObject go = *pGo;
		go.Update();
		glMatrixMode(GL_MODELVIEW);
		glLoadIdentity();
		glTranslatef(go.transform->Location.x, go.transform->Location.y, go.transform->Location.z);
		glRotatef(go.transform->Rotation.x, 1, 0, 0);
		glRotatef(go.transform->Rotation.y, 0, 1, 0);
		glRotatef(go.transform->Rotation.z, 0, 0, 1);
		for (vector<Vector3> vertices : go.faces) {
			
			glBegin(GL_POLYGON);
			glColor3f(vertices.back().x, vertices.back().y, vertices.back().z);
			for (int i = 0; i < (vertices.size() - 1); i++) {
				Vector3 vertex = vertices[i];
				glVertex3f(vertex.x, vertex.y, vertex.z);
			}
			glEnd();
		}
	}

	SDL_GL_SwapWindow(window);
}