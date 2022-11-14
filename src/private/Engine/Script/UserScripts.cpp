#define EXPORT extern "C" __declspec(dllexport)
#include "F16.h"

EXPORT void SetupScripts(vector<GameObject*>* objs) {
	GameObject* f16 = new F16("ASd");
	objs->push_back(f16);
}
