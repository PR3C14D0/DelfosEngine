#pragma once

#include <iostream>
#include <ImGUI/imgui.h>
#include <ImGUI/backends/imgui_impl_opengl3.h>
#include <ImGUI/backends/imgui_impl_sdl.h>
#include <SDL/SDL.h>
#include <map>
#include <Windows.h>
#include <SDL/SDL.h>
#include <string>
#include <format>
#include <vector>
#include "Engine/GameObject/GameObject.h"

using namespace std;

class Editor {
private:
	SDL_Window* window;

	void FileMenu();
	void BuildMenu();

	void CreateItemMenu();

	map<string, bool> OpenMenus;

	void EnableMenu(string name);
	void DisableMenu(string name);
	string projName;

	GameObject* selectedGo;
	vector<GameObject*>* pGo;
	vector<GameObject*> go;

	char creatingItemName[16] = "Object name";
	char creatingItemMeshPath[MAX_PATH] = "";
public:
	Editor(SDL_Window* window, string projName);

	void Update(float deltaTime, vector<GameObject*>* pGo);
};