#include "Engine/GameObject/GameObject.h"

class F16 : public GameObject {
public:
	F16(string name);
	void Update(float deltaTime) override;
};