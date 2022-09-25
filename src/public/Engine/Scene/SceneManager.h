#include "Engine/Scene/Scene.h"

class SceneManager {
private:
	SDL_Window* window;
	int width, height;

	Scene defScene;
	Scene actualScene;
public:
	SceneManager() {};
	SceneManager(SDL_Window* window, int& width, int& height);
	void LoadScene();
};