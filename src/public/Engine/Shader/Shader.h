#pragma once
#include <iostream>
#include <GL/glew.h>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <gl/GL.h>
#include <gl/GLU.h>
#include <vector>
#include "IO/FileManager.h"

using namespace std;

class Shader {
public:
	Shader();
	GLuint id;
	FileManager* fileMgr;
	void LoadShader(const char* vertFile, const char* fragFile);
};