#include "Module/Input/Input.h"

Input* Input::input;

Input::Input() {
	this->cursorMoved = false;
	this->delta = glm::vec2(0.f, 0.f);
	this->w = 0;
	this->h = 0;
	this->relX = 0.f;
	this->relY = 0.f;
}

InputKeyValue::InputKeyValue(KeyboardInput key, char value) {
	this->key = key;
	this->value = value;
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
	for (InputKeyValue* pI : this->keys) {
		InputKeyValue i = *pI;
		if (i.value == key) {
			if (i.key == type) {
				found = true;
				break;
			}
		}
		else
			break;
	}
	return found;
}

void Input::SetKeyState(KeyboardInput key, char value) {
	if (this->keys.size() == 0) {
		InputKeyValue* pI = new InputKeyValue(key, value);
		this->keys.push_back(pI);
		return;
	}

	for (InputKeyValue* pI : this->keys) {
		InputKeyValue i = *pI;
		if (i.value == value) {
			if (i.key != key) {
				pI->key = key;
				return;
			}
			else
				return;
			break;
		}
		else {
			InputKeyValue* pI = new InputKeyValue(key, value);
			this->keys.push_back(pI);
		}
	}
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

void Input::RemoveReleased() {
	for (int i = 0; i < this->buttons.size(); i++) {
		if (this->buttons[i] == LCLICK_UP || this->buttons[i] == RCLICK_UP) {
			this->buttons.erase(this->buttons.begin() + i);
		}
	}
	
	for (int i = 0; i < this->keys.size(); i++) {
		InputKeyValue* pI = this->keys[i];
		InputKeyValue in = *pI;
		if (in.key == KeyboardInput::KEY_RELEASED) {
			this->keys.erase(this->keys.begin() + i);
		}
	}

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