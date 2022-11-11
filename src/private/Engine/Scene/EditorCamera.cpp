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

		float sensX = 0.6f;
		float sensY = 0.5f;

		this->transform->rotate(-angleX * sensY, 0.f,  0.f);
		this->transform->rotate(0.f, -angleY * sensX, 0.f);

		if (input->GetKey(KeyboardInput::KEY_PRESSED, 'w')) 
			this->transform->translate(this->transform->Forward() * (-speed * deltaTime));
		
		if (input->GetKey(KeyboardInput::KEY_PRESSED, 's')) 
			this->transform->translate(this->transform->Forward() * (speed * deltaTime));
		
		if (input->GetKey(KeyboardInput::KEY_PRESSED, 'd')) 
			this->transform->translate(this->transform->Right() * (speed * deltaTime));
		
		if (input->GetKey(KeyboardInput::KEY_PRESSED, 'a')) 
			this->transform->translate(this->transform->Right() * (-speed * deltaTime));
		
	}
	else {
		this->input->HideCursor(false);
	}
}