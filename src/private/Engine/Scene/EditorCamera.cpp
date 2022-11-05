#include "Engine/Scene/EditorCamera.h"

EditorCamera::EditorCamera(string name) : Camera::Camera(name) {
	this->speed = .5f;
}

void EditorCamera::Update(float deltaTime) {
	Camera::Update(deltaTime);

	if (this->input->GetButton(MouseInput::RCLICK_DOWN)) {
		float relY = input->GetAxis("Up");
		float relX = input->GetAxis("Right");
		this->input->HideCursor(true);

		float angleX = relY / this->h;
		float angleY = relX / this->w;

		this->transform->rotate(deltaTime * -angleX * 50.f, 0.f, 0.f);
		this->transform->rotate(0.f, deltaTime * -angleY * 50.f, 0.f);

		if (this->transform->Rotation.x > 89.f) {
			this->transform->Rotation.x = 89.f;
			return;
		}
		if (this->transform->Rotation.x < -89.f) {
			this->transform->Rotation.x = -89.f;
			return;
		}

		if (input->GetKey(KeyboardInput::KEY_PRESSED, 'w')) {
			this->transform->translate(0.f, 0.f, /*deltaTime **/ -speed * this->transform->Forward());
		}
		if (input->GetKey(KeyboardInput::KEY_PRESSED, 's')) {
			this->transform->translate(0.f, 0.f, deltaTime * speed);
		}
		if (input->GetKey(KeyboardInput::KEY_PRESSED, 'd')) {
			this->transform->translate(deltaTime * speed, 0.f, 0.f);
		}
		if (input->GetKey(KeyboardInput::KEY_PRESSED, 'a')) {
			this->transform->translate(deltaTime * -speed, 0.f, 0.f);
		}
	}
	else {
		this->input->HideCursor(false);
	}
}