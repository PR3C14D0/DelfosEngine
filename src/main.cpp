#include "Core/Core.h"

using namespace std;

void EnableDebugger();

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
#ifndef NDEBUG
	EnableDebugger();
#endif

	string version = "v0.0.1";

	cout << "DelfosEngine " << version << " (Debug mode)" << endl;

	Core core;

	return 0;
}

void EnableDebugger() {
	AllocConsole();
	FILE* f;
	freopen_s(&f, "CONOUT$", "w", stdout);
}