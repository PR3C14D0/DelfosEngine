#include "Engine/Scene/Camera.h"

class EditorCamera : public Camera {
public:
	// EditorCamera() = default;
	EditorCamera(string name);
	void Update(float deltaTime) override;

	float speed;
};