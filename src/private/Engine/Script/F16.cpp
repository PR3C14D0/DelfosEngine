#include "F16.h"

F16::F16(string name) : GameObject::GameObject(name) {

}

void F16::Update(float deltaTime) {
	GameObject::Update(deltaTime);

	cout << "name" << endl;
}