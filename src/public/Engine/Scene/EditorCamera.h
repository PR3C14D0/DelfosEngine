#include "Engine/Scene/Camera.h"

#define PI 3.14159265359f

class EditorCamera : public Camera {
public:
	// EditorCamera() = default;
	EditorCamera(string name);
	void Update(float deltaTime) override;

	float speed;
};