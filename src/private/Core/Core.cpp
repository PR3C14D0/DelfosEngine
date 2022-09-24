#include "Core/Core.h"

Core::Core() {
	SDL_Init(SDL_INIT_EVERYTHING);
	this->window = SDL_CreateWindow("Delfos engine", 100, 100, this->width, this->height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	this->context = SDL_GL_CreateContext(this->window);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_MakeCurrent(this->window, this->context);

	MainLoop();
}

void Core::MainLoop() {
	bool quit = false;
	while (!quit) {
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_QUIT:
				if (MessageBoxA(NULL, "Are you sure you want to close Delfos?", "Sure?", MB_OKCANCEL) == IDOK)
					quit = true;
				break;
			default:
				break;
			}
		}
		SDL_GetWindowSize(this->window, &width, &height);
	}
	SDL_Quit();
	return;
}