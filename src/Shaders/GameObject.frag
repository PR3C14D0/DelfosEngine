#version 330 core
out vec4 FragColor;

in vec2 UV;

uniform sampler2D tex;

void main() {
	FragColor = texture(tex, vec2(UV.x, 1 - UV.y));
}