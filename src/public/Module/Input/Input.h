#pragma once
#include <iostream>
#include <vector>

using namespace std;

enum MouseInput {
	LCLICK_DOWN,
	LCLICK_UP,
	RCLICK_DOWN,
	RCLICK_UP
};

enum KeyboardInput {
	KEY_PRESSED,
	KEY_RELEASED
};

struct InputKeyValue {
	friend class Input;
private:
	KeyboardInput key;
	char value;
public:
	InputKeyValue(KeyboardInput key, char value);
};

class Input {
	friend class Core;
private:
	vector<MouseInput> buttons;
	vector<InputKeyValue*> keys;

	void SetKeyState(KeyboardInput key, char value);
	void SetButtonState(MouseInput input);
	Input() = default;

	void RemoveReleased();
	static Input* input;
public:
	static Input* GetInstance();
	bool GetButton(MouseInput type);
	bool GetKey(KeyboardInput type, char key);
};