#include "Engine/Scene/Scene.h"

Scene::Scene(string name) {
	this->name = name;
	this->root = new Node;
}

void Scene::AddObject(GameObject* pGo) {
	Node* newNode = new Node;
	newNode->obj = pGo;
	root->AddChild(newNode);
	return;
}

void Scene::Update(float deltaTime) {
	this->totalTime += (deltaTime / 1000.f);
}

void Scene::Render(SDL_Window* window, int width, int height) {
	glClearDepth(1.f);
	glClearColor(0.f, 0.f, 0.f, 0.f);
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
	glEnable(GL_DEPTH_TEST);

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluPerspective(90.f, ((float)width / (float)height), .1f, 300.f);


	glMatrixMode(GL_MODELVIEW);
	glLoadIdentity();

	gluLookAt(0.f, 0.f, 10.f, 0.0, 0.0, 0.0, 0.0, 1.0, 0.0);
	glColor3f(1.f, 0.f, 0.f);

	GLuint VBO;

	static const GLfloat vertices[] = {
	   1.f, 1.f, 1.f,
	   -1.f, 1.f, 1.f,
	   1.f, -1.f, 1.f,

	   1.f, -1.f, 1.f,
	   -1.f, 1.f, 1.f,
	   -1.f, -1.f, 1.f
	};
	

	glGenBuffers(1, &VBO);

	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(vertices), vertices, GL_STATIC_DRAW);

	glEnableVertexAttribArray(0);
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_NONE, 0, (void*)0);
	glDrawArrays(GL_TRIANGLES, 0, 6);
	glDisableVertexAttribArray(0);

	SDL_GL_SwapWindow(window);
}

void Node::AddChild(Node* node) {
	this->childrens.push_back(node);
	return;
}

Node* Node::GetChild(int index) {
	return this->childrens[index];
}

void Node::RemoveChild(int index) {
	this->childrens.erase(this->childrens.begin() + index);
}