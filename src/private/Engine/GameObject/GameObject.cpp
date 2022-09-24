#include "Engine/GameObject/GameObject.h"

void GameObject::OnCreate() {

}

void GameObject::Update() {

}

GameObject::GameObject(string name) {
	this->name = name;
	this->transform = Transform { Vector3 {0.f, 0.f, 0.f},Vector3 {0.f, 0.f, 0.f}, Vector3 {0.f, 0.f, 0.f} };
}