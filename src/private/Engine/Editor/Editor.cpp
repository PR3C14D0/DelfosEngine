#include "Engine/Editor/Editor.h"

Editor::Editor(SDL_Window* window, string projName) {
	this->window = window;
	this->projName = projName;
	this->OpenMenus["File"] = false;
	this->OpenMenus["Build"] = false;
}

void Editor::Update(float deltaTime) {
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame(this->window);
	ImGui::NewFrame();

	ImGui::BeginMainMenuBar();
	if (ImGui::MenuItem("File")) {
		if (this->OpenMenus["File"])
			DisableMenu("File");
		else
			EnableMenu("File");
	}

	if (ImGui::MenuItem("Build"))
		EnableMenu("Build");

	if(this->OpenMenus["File"])
		FileMenu();

	if (this->OpenMenus["Build"])
		BuildMenu();

	ImGui::EndMainMenuBar();
}

void Editor::FileMenu() {
	ImGui::Begin("File", NULL, ImGuiWindowFlags_NoTitleBar);

	if (ImGui::Button("Open project")) {
		OPENFILENAME ofn;
		ZeroMemory(&ofn, sizeof(OPENFILENAME));

		char projFile[MAX_PATH] = { 0 };

		ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.lpstrFilter = "Delfos Project (*.dproj)\0*.dproj\0All files(*.*)\0*.*\0";
		ofn.lpstrFile = projFile;
		ofn.Flags = OFN_EXPLORER | OFN_HIDEREADONLY | OFN_FILEMUSTEXIST;
		ofn.nMaxFile = MAX_PATH;

		GetOpenFileName(&ofn);
	}

	ImGui::Button("Save");
	if (ImGui::Button("Save as")) {
		OPENFILENAME ofn;
		ZeroMemory(&ofn, sizeof(OPENFILENAME));
		string projFile = this->projName + ".dproj";
		char* cProjName = new char[MAX_PATH];
		cProjName = (char*)projFile.c_str();

		ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.lpstrFilter = "Delfos Project (*.dproj)\0*.dproj\0";
		ofn.lpstrFile = cProjName;
		ofn.nMaxFile = MAX_PATH;
		ofn.Flags = OFN_EXPLORER | OFN_HIDEREADONLY;

		if (GetSaveFileName(&ofn)) {
			
		}

	}

	if (ImGui::Button("Close"))
		DisableMenu("File");

	ImGui::End();
}

void Editor::BuildMenu() {
	ImGui::Begin("Build", NULL, ImGuiWindowFlags_NoTitleBar);
	ImGui::Text("Available soon...");
	if (ImGui::Button("Close"))
		DisableMenu("Build");
	ImGui::End();
}

void Editor::EnableMenu(string name) {
	this->OpenMenus[name] = true;
}

void Editor::DisableMenu(string name) {
	this->OpenMenus[name] = false;
}