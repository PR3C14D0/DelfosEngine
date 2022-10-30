#include "Engine/Scene/Scene.h"
#include <GL/glm/glm.hpp>

class SceneManager {
private:
	SDL_Window* window;
	int width, height;

	Scene defScene;
	Scene actualScene;
	vector<Scene> projectScenes;
public:
	SceneManager() {};
	SceneManager(SDL_Window* window, int& width, int& height);
	void Render(float deltaTime);
	void ChangeScene(string name);
};