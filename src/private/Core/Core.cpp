#include "Core/Core.h"

Core::Core() {
	this->input = Input::GetInstance();
	SDL_Init(SDL_INIT_EVERYTHING);
	this->window = SDL_CreateWindow("Delfos engine", 100, 100, this->width, this->height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN);
	this->context = SDL_GL_CreateContext(this->window);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 8);
	SDL_GL_MakeCurrent(this->window, this->context);

	glewInit();

	this->sceneMgr = SceneManager(this->window, this->width, this->height);

	MainLoop();
}

void Core::MainLoop() {
	bool quit = false;
	float actualFps, deltaTime, oldFps = 0.f;
	while (!quit) {
		actualFps = SDL_GetTicks();
		deltaTime = actualFps - oldFps;
		while (SDL_PollEvent(&event)) {
			switch (event.type) {
			case SDL_MOUSEBUTTONDOWN:
				if (event.button.button == SDL_BUTTON_LEFT) {
					input->SetButtonState(MouseInput::LCLICK_DOWN);
				}
				if (event.button.button == SDL_BUTTON_RIGHT) {
					input->SetButtonState(MouseInput::RCLICK_DOWN);
				}
				break;
			case SDL_MOUSEBUTTONUP:
				if (event.button.button == SDL_BUTTON_LEFT) {
					input->SetButtonState(MouseInput::LCLICK_UP);
				}
				if (event.button.button == SDL_BUTTON_RIGHT) {
					input->SetButtonState(MouseInput::RCLICK_UP);
				}
				break;
			case SDL_KEYDOWN:
				input->SetKeyState(KeyboardInput::KEY_PRESSED, (char)SDL_GetKeyFromScancode(event.key.keysym.scancode));
				break;
			case SDL_KEYUP:
				input->SetKeyState(KeyboardInput::KEY_RELEASED, (char)SDL_GetKeyFromScancode(event.key.keysym.scancode));
				break;
			case SDL_QUIT:
				if (MessageBoxA(NULL, "Are you sure you want to close Delfos?", "Sure?", MB_OKCANCEL) == IDOK)
					quit = true;
				break;
			default:
				break;
			}
		}

		SDL_GetWindowSize(this->window, &width, &height);
		this->sceneMgr.Render(deltaTime / 1000.f);
		input->RemoveReleased();
		//cout << "FPS: " << (1000.f / deltaTime) << endl;
		oldFps = actualFps;
	}
	SDL_Quit();
	return;
}