#pragma once
#include <iostream>
#include <vector>
#include <map>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <GL/glm/glm.hpp>
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
	glm::vec2 delta = glm::vec2(0.f);
	glm::vec2 oldPosition;

	void SetKeyState(KeyboardInput key, char value);
	void SetButtonState(MouseInput input);
	Input();
	bool cursorMoved;
	float pitch = 0.f;

	void RemoveReleased();
	static Input* input;

	int w, h;
	float relX, relY;
public:
	static Input* GetInstance();
	void BeginFrame();
	bool GetButton(MouseInput type);
	bool GetKey(KeyboardInput type, char key);
	float GetAxis(string axis);
	void UpdateAxis(float x, float y, float relx, float rely);
	void SetScreenSize(int width, int height);
	void HideCursor(bool b);
};