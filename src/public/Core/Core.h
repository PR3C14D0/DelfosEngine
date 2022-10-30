#pragma once
#include <iostream>
#include <Windows.h>
#include <GL/glew.h>

#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>

#include <GL/GL.h>
#include <GL/GLU.h>
#include "Engine/Scene/SceneManager.h"
#include "Module/Input/Input.h"

class Core {
private:
	SDL_Window* window;
	SDL_Event event;
	SDL_GLContext context;

	void MainLoop();

	int width = 1600;
	int height = 800;
	SceneManager sceneMgr;

public:
	Core();
	Input* input;
};