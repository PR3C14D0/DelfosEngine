#include "Engine/Scene/Scene.h"

Scene::Scene(string name) {
	
}

GameObject Scene::GetObjectByName(string name) {
	for (GameObject obj : sceneGo) {
		if (obj.name == name)
			return obj;
	}

	return GameObject{"GameObject"};
}
