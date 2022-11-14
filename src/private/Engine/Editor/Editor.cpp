#include "Engine/Editor/Editor.h"

Editor::Editor(SDL_Window* window, string projName) {
	this->window = window;
	this->projName = projName;
	this->selectedGo = nullptr;

	this->OpenMenus["File"] = false;
	this->OpenMenus["Build"] = false;
	this->OpenMenus["CreateItem"] = false;
	this->OpenMenus["Analytics"] = false;

	ImGuiStyle& style = ImGui::GetStyle();
	style.FrameRounding = 3.0f;
	style.WindowRounding = 5.f;
	style.Colors[ImGuiCol_Text] = ImVec4(.8f, .8f, .8f, 1.f);
	style.Colors[ImGuiCol_Button] = ImVec4(0.f, 0.16f, 0.17f, 1.f);
	style.Colors[ImGuiCol_ButtonHovered] = ImVec4(.09f, 0.58f, 0.62f, 1.f);
	style.Colors[ImGuiCol_ButtonActive] = ImVec4(.05f, 0.4f, 0.5f, 1.f);
	style.Colors[ImGuiCol_TitleBg] = ImVec4(.05f, .05f, .05f, 1.f);
	style.Colors[ImGuiCol_TitleBgActive] = ImVec4(.1f, .1f, .1f, 1.f);
}

void Editor::Update(float deltaTime, vector<GameObject*>* pGo) {
	this->pGo = pGo;
	this->go = *this->pGo;
	ImGui_ImplOpenGL3_NewFrame();
	ImGui_ImplSDL2_NewFrame(this->window);
	ImGui::NewFrame();

	string fps(to_string((int)(1.f/deltaTime)));

	if (this->OpenMenus["Analytics"]) {
		ImGui::SetNextWindowSize({ 100.0f, 50.0f });
		ImGui::Begin("Analytics", NULL, ImGuiWindowFlags_NoResize);
		ImGui::Text(("FPS: " + fps).c_str());
		ImGui::End();
	}

	ImGui::SetNextWindowSize({ 200.0f, 600.0f });
	ImGui::Begin("Scene");
	for (GameObject* g : go) {
		if (ImGui::Button(g->name.c_str())) {
			this->selectedGo = g;
		}
	}
	if (ImGui::Button("Add object", ImVec2(ImGui::GetWindowSize().x * .75f, 30.f)))
		EnableMenu("CreateItem");
	if (ImGui::Button("Load Scripts")) {
		typedef void (*FNPTR)(vector<GameObject*>*);
		HMODULE scripts = LoadLibrary("DelfosScripts.dll");
		FNPTR SetupScripts = (FNPTR)GetProcAddress(scripts, "SetupScripts");
		SetupScripts(this->pGo);
	}
	ImGui::End();

	ImGui::SetNextWindowSize({ 200.0f, 600.0f });
	ImGui::Begin("Properties");
	if (this->selectedGo == nullptr) 
		ImGui::Text("First select an object");
	else {
		ImGui::Text(("Name: " + this->selectedGo->name).c_str());
		ImGui::Text("Location");
		ImGui::Text("X: ");
		ImGui::SameLine();
		ImGui::InputFloat("##XCoord", &this->selectedGo->transform->Location.x, .5f, 1.f, "%.2f");
		ImGui::Text("Y: ");
		ImGui::SameLine();
		ImGui::InputFloat("##YCoord", &this->selectedGo->transform->Location.y, .5f, 1.f, "%.2f");
		ImGui::Text("Z: ");
		ImGui::SameLine();
		ImGui::InputFloat("##ZCoord", &this->selectedGo->transform->Location.z, .5f, 1.f, "%.2f");
		if (ImGui::Button("Load another model")) {
			OPENFILENAME ofn;
			ZeroMemory(&ofn, sizeof(OPENFILENAME));

			ofn.lStructSize = sizeof(OPENFILENAME);
			ofn.lpstrFilter = "Wavefront OBJ (*.obj)\0*.obj\0";
			ofn.lpstrFile = creatingItemMeshPath;
			ofn.Flags = OFN_EXPLORER | OFN_HIDEREADONLY | OFN_FILEMUSTEXIST;
			ofn.nMaxFile = MAX_PATH;
			GetOpenFileName(&ofn);

			this->selectedGo->LoadModel(this->creatingItemMeshPath);
		}

		if (ImGui::Button("Remove mesh")) {
			this->selectedGo->ClearVertexArrays();
			this->selectedGo->ClearBuffers();
		}

	}
	ImGui::End();

	ImGui::BeginMainMenuBar();
	if (ImGui::MenuItem("File")) {
		if (this->OpenMenus["File"])
			DisableMenu("File");
		else
			EnableMenu("File");
	}

	if (ImGui::MenuItem("Build"))
		EnableMenu("Build");

	if (ImGui::MenuItem("Analytics")) {
		if (this->OpenMenus["Analytics"])
			DisableMenu("Analytics");
		else
			EnableMenu("Analytics");
	}

	if(this->OpenMenus["File"])
		FileMenu();

	if (this->OpenMenus["Build"])
		BuildMenu();

	if (this->OpenMenus["CreateItem"])
		CreateItemMenu();

	ImGui::EndMainMenuBar();
}

void Editor::FileMenu() {
	ImGui::SetNextWindowSize({ 200.0f, 150.0f });
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

		if (GetOpenFileName(&ofn)) {
			
		}
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

void Editor::CreateItemMenu() {
	ImGui::SetNextWindowSize({ 250.0f, 600.0f });
	ImGui::Begin("Create item");

	ImGui::Text("Object name: ");
	ImGui::SameLine();
	ImGui::InputText("##NameInput", this->creatingItemName, 16);
	ImGui::Text("Model: ");
	ImGui::SameLine();
	ImGui::InputText("##ModelPath", this->creatingItemMeshPath, MAX_PATH);
	ImGui::SameLine();
	if (ImGui::Button("Search...")) {
		OPENFILENAME ofn;
		ZeroMemory(&ofn, sizeof(OPENFILENAME));

		ofn.lStructSize = sizeof(OPENFILENAME);
		ofn.lpstrFilter = "Wavefront OBJ (*.obj)\0*.obj\0";
		ofn.lpstrFile = creatingItemMeshPath;
		ofn.Flags = OFN_EXPLORER | OFN_HIDEREADONLY | OFN_FILEMUSTEXIST;
		ofn.nMaxFile = MAX_PATH;
		GetOpenFileName(&ofn);
	}

	if (ImGui::Button("Add")) {
		string name(this->creatingItemName);
		GameObject* obj = new GameObject(name);
		obj->LoadModel(this->creatingItemMeshPath);
		this->pGo->push_back(obj);
		DisableMenu("CreateItem");
	}

	ImGui::End();
}