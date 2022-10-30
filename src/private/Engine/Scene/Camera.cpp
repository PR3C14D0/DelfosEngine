#include "Engine/Scene/Camera.h"

Camera::Camera(string name) {
	this->name = name;
	this->input = Input::GetInstance();
	transform = new Transform(Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f), Vector3(0.f, 0.f, 0.f));
}

void Camera::Update(float deltaTime) {

}