#include "Engine/Scene/Camera.h"

Camera::Camera(string name) {
	this->name = name;
	this->input = Input::GetInstance();
	transform = new Transform(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f));
	this->transform->Location.z = 2.f;
}

void Camera::UpdateSize(int w, int h) {
	this->w = w;
	this->h = h;
}

void Camera::Update(float deltaTime) {
	glm::mat4 cameraView = glm::mat4(1.f);
	cameraView = glm::translate(cameraView, this->transform->Location.toGLMVec3());
	cameraView = glm::rotate(cameraView, this->transform->Rotation.x, glm::vec3(1, 0, 0));
	cameraView = glm::rotate(cameraView, this->transform->Rotation.y, glm::vec3(0, 1, 0));
	cameraView = glm::rotate(cameraView, this->transform->Rotation.z, glm::vec3(0, 0, 1));
	cameraView = glm::affineInverse(cameraView);

	this->View = cameraView;
	this->Perspective = glm::perspective(glm::radians(90.f), ((float)this->w / (float)this->h), .1f, 300.f);
}