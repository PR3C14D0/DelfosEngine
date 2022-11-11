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

class Input {
	friend class Core;
private:
	vector<MouseInput> buttons;
	const Uint8* keys;

	void SetButtonState(MouseInput input);
	Input();
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