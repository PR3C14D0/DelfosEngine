#version 330 core
layout (location = 0) in vec3 aPos;
layout (location = 1) in vec2 aUV;

uniform mat4 MVP;
out vec2 UV;

void main() {
	gl_Position = MVP * vec4(aPos, 1.0);
	UV = aUV;
}