#pragma once
#define GL_GLEXT_PROTOTYPES 1
#include <iostream>
#include <Windows.h>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include "Engine/Scene/SceneManager.h"

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
};