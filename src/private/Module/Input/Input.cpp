#include "Module/Input/Input.h"

Input* Input::input;

Input::Input() {
	this->relX = 0.f;
	this->relY = 0.f;
	this->w = 0;
	this->h = 0;
}

bool Input::GetButton(MouseInput type) {
	bool found = false;
	for (MouseInput i : this->buttons) {
		if (i == type) {
			found = true;
			break;
		}
	}

	return found;
}

bool Input::GetKey(KeyboardInput type, char key) {
	bool found = false;

	this->keys = SDL_GetKeyboardState(NULL);

	if (type == KEY_PRESSED) {
		if (keys[SDL_GetScancodeFromKey(key)]) {
			found = true;
		}
	}

	if (type == KEY_RELEASED) {
		if (!keys[SDL_GetScancodeFromKey(key)]) {
			found = true;
		}
	}

	return found;
}

void Input::SetButtonState(MouseInput input) {
	if (input == MouseInput::LCLICK_UP) {
		for (int i = 0; i < this->buttons.size(); i++) {
			if (this->buttons[i] == LCLICK_DOWN)
				this->buttons[i] = LCLICK_UP;
			return;
			break;
		}
	}

	if (input == MouseInput::RCLICK_UP) {
		for (int i = 0; i < this->buttons.size(); i++) {
			if (this->buttons[i] == RCLICK_DOWN)
				this->buttons[i] = RCLICK_UP;
			return;
			break;
		}
	}

	this->buttons.push_back(input);
	return;
}

Input* Input::GetInstance() {
	if (!input)
		input = new Input;
	return input;
}

float Input::GetAxis(string axis) {
	if (axis == "Up") {
		return this->relY;
	} else if (axis == "Right") {
		return this->relX;
	}
	else {
		cout << "[ERROR] Invalid axis provided: " << axis << endl;
		return 0.f;
	}
}

void Input::UpdateAxis(float x, float y, float relx, float rely) {
	this->relX = relx;
	this->relY = rely;
}

void Input::SetScreenSize(int width, int height) {
	this->w = width;
	this->h = height;
}

void Input::BeginFrame() {
	this->relX = 0.f;
	this->relY = 0.f;

	for (int i = 0; i < this->buttons.size(); i++) {
		if (this->buttons[i] == LCLICK_UP || this->buttons[i] == RCLICK_UP) {
			this->buttons.erase(this->buttons.begin() + i);
		}
	}
}

void Input::HideCursor(bool b) {
	if (b) {
		if(!SDL_GetRelativeMouseMode())
			SDL_SetRelativeMouseMode((SDL_bool)b);
		return;
	}
	else {
		if(SDL_GetRelativeMouseMode())
			SDL_SetRelativeMouseMode((SDL_bool)b);
		return;
	}
}