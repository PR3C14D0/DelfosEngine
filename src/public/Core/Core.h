#pragma once
#include <iostream>
#include <Windows.h>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <GL/GLU.h>

class Core {
private:
	SDL_Window* window;
	SDL_Event event;
	SDL_GLContext context;

	void MainLoop();

	int width = 1600;
	int height = 800;
public:
	Core();
};