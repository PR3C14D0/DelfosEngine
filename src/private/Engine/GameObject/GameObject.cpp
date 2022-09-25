#include "Engine/GameObject/GameObject.h"

void GameObject::OnCreate() {

}

void GameObject::Update() {
	this->transform->rotate(1.f, 1.f, 0.f);
}

GameObject::GameObject(string name) {
	this->name = name;
	this->transform = new Transform(  Vector3 (0.f, 0.f, 0.f),  Vector3 (0.f, 0.f, 0.f),  Vector3 (0.f, 0.f, 0.f) );
}

