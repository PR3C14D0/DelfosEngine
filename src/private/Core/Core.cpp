#include "Core/Core.h"

Core::Core() {
	this->input = Input::GetInstance();
	SDL_Init(SDL_INIT_EVERYTHING);
	SDL_DisplayMode dm;
	SDL_GetDesktopDisplayMode(0, &dm);
	this->width = dm.w - 100;
	this->height = dm.h -100;
	this->window = SDL_CreateWindow("Delfos engine", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, this->width, this->height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
	this->context = SDL_GL_CreateContext(this->window);
	SDL_GL_SetAttribute(SDL_GL_DOUBLEBUFFER, 1);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_ES);
	SDL_GL_SetAttribute(SDL_GL_DEPTH_SIZE, 16);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLEBUFFERS, 1);
	SDL_GL_SetAttribute(SDL_GL_MULTISAMPLESAMPLES, 8);
	SDL_SetHintWithPriority(SDL_HINT_MOUSE_RELATIVE_MODE_WARP, "1", SDL_HINT_OVERRIDE);
	SDL_GL_MakeCurrent(this->window, this->context);
	SDL_WarpMouseInWindow(NULL, this->width / 2, this->height / 2);

	glewInit();

	IMGUI_CHECKVERSION();
	ImGui::CreateContext();
	ImGuiIO& io = ImGui::GetIO(); (void)io;
	ImGui::StyleColorsDark();

	ImGui_ImplSDL2_InitForOpenGL(this->window, this->context);
	ImGui_ImplOpenGL3_Init();

	this->sceneMgr = SceneManager(this->window, this->width, this->height);

	MainLoop();
}

void Core::MainLoop() {
	bool quit = false;
	float currentTimeMs, deltaTimeMs, lastTimeMs = 0.f;
	while (!quit) {
		this->input->BeginFrame();
		currentTimeMs = SDL_GetTicks();
		deltaTimeMs = currentTimeMs - lastTimeMs;
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
			case SDL_MOUSEMOTION:
				input->UpdateAxis(event.motion.x, event.motion.y, event.motion.xrel, event.motion.yrel);
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
		input->SetScreenSize(this->width, this->height);

		this->sceneMgr.Render(deltaTimeMs / 1000.f);
		input->RemoveReleased();
		lastTimeMs = currentTimeMs;
	}
	SDL_Quit();
	return;
}