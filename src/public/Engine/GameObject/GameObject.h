#pragma once
#include "Math/Transform/Transform.h"
#include <iostream>
#include <vector>
#include <GL/glew.h>
#include <SDL/SDL.h>
#include <SDL/SDL_opengl.h>
#include <SDL/SDL_image.h>
#include <GL/GL.h>
#include <GL/GLU.h>
#include <fstream>
#include <Windows.h>
#include <ASSIMP/Importer.hpp>
#include <ASSIMP/scene.h>
#include <ASSIMP/postprocess.h>
#include "IO/FileManager.h"
#include <GL/glm/glm.hpp>
#include <GL/glm/gtc/type_ptr.hpp>
#include <GL/glm/gtx/string_cast.hpp>
#include "Engine/Shader/Shader.h"

using namespace std;

class GameObject {
	friend class Scene;
protected:
	bool bufferUploaded;
	GLuint VAO;
	GLuint vertexBuff;
	GLuint texBuff;
	GLuint texCoordBuff;

	Vector3 ambient;
	Vector3 diffuse;
	Vector3 specular;

	const aiMesh* mesh;
	const aiMaterial* mtl;
	FileManager* fileMgr;
	SDL_Surface* tex;

	Shader* shader;

	GLuint program;
	
	bool hasTex;

	glm::mat4 modelMatrix;
public:
	GameObject() {};
	virtual void OnCreate();
	virtual void Update(float deltaTime);

	void PrepareRender();
	void Draw(glm::mat4 mvp);

	void LoadModel(string path);

	vector<GLfloat> vertex;
	vector<GLfloat> textureCoords;

	string name;
	GameObject(string name);
	Transform* transform;
};