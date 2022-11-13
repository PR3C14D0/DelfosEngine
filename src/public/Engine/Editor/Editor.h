#include <iostream>
#include <ImGUI/imgui.h>
#include <ImGUI/backends/imgui_impl_opengl3.h>
#include <ImGUI/backends/imgui_impl_sdl.h>
#include <SDL/SDL.h>
#include <map>
#include <Windows.h>
#include <SDL/SDL.h>

using namespace std;

class Editor {
private:
	SDL_Window* window;

	void FileMenu();
	void BuildMenu();

	map<string, bool> OpenMenus;

	void EnableMenu(string name);
	void DisableMenu(string name);
	string projName;
public:
	Editor(SDL_Window* window, string projName);

	void Update(float deltaTime);
};