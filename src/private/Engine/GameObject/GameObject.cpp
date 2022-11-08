#include "Engine/GameObject/GameObject.h"

void GameObject::OnCreate() {

}

void GameObject::Update() {
	//this->transform->rotate(1.f, 1.f, 0.f);
}

void GameObject::PrepareRender() {
	if (!bufferUploaded) {
		/* Vertex */
		GLfloat* vertexArr = vertex.data();
		glGenVertexArrays(1, &VAO);
		glBindVertexArray(VAO);

		glGenBuffers(1, &vertexBuff);
		glBindBuffer(GL_ARRAY_BUFFER, vertexBuff);
	
		glBufferData(GL_ARRAY_BUFFER, (vertex.size() * sizeof(GLfloat)), vertexArr, GL_STATIC_DRAW);
		
		/* UV */

		GLfloat* uvArr = uv.data();

		glGenBuffers(1, &uvBuff);
		glBindBuffer(GL_ARRAY_BUFFER, uvBuff);

		glBufferData(GL_ARRAY_BUFFER, (uv.size() * sizeof(GLfloat)), uvArr, GL_STATIC_DRAW);

		GLfloat* texCoordArr = textureCoords.data();

		glGenBuffers(1, &texCoordBuff);
		glBindBuffer(GL_ARRAY_BUFFER, this->texCoordBuff);

		glBufferData(GL_ARRAY_BUFFER, (textureCoords.size() * sizeof(GLfloat)), texCoordArr, GL_STATIC_DRAW);

		if (this->hasTex) {
			glGenTextures(1, &texBuff);
			glBindTexture(GL_TEXTURE_2D, texBuff);
			glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, this->tex->w, this->tex->h, 0, GL_RGB, GL_UNSIGNED_BYTE, tex->pixels);
			glGenerateMipmap(GL_TEXTURE_2D);
		}

		this->bufferUploaded = true;
		//this->LoadShader("Assets/Shaders/GameObject.vert", "Assets/Shaders/GameObject.frag");
		this->shader->LoadShader("Assets/Shaders/GameObject.vert", "Assets/Shaders/GameObject.frag");
	}
}

void GameObject::LoadModel(string path) {
	Assimp::Importer importer;
	char fullPath[MAX_PATH];
	GetFullPathNameA(path.c_str(), MAX_PATH, fullPath, nullptr);
	const aiScene* scene = importer.ReadFile(fullPath, 0);
	if (!scene) {
		cout << importer.GetErrorString() << endl;
		return;
	}
	mesh = scene->mMeshes[0];
	mtl = scene->mMaterials[mesh->mMaterialIndex];

	aiString texturePath;
	if (this->mtl->GetTextureCount(aiTextureType_DIFFUSE) > 0 && this->mtl->GetTexture(aiTextureType_DIFFUSE, 0, &texturePath) == AI_SUCCESS) {
		cout << "Loading: " << fullPath << endl;
		this->hasTex = true;

		this->tex = IMG_Load(texturePath.C_Str());
	}

	for (int i = 0; i < mesh->mNumVertices; i++) {
		aiVector3D pos = mesh->mVertices[i];
		vertex.push_back(pos.x);
		vertex.push_back(pos.y);
		vertex.push_back(pos.z);
		
		if (mesh->HasTextureCoords(0)) {
			textureCoords.push_back(mesh->mTextureCoords[0][i].x);
			textureCoords.push_back(mesh->mTextureCoords[0][i].y);
		}
	}
}

void GameObject::Draw(glm::mat4 mvp) {
	glBindVertexArray(VAO);

	glUseProgram(this->shader->id);

	glBindTexture(GL_TEXTURE_2D, this->texBuff);
	glBindVertexArray(VAO);

	GLuint mvpLocation = glGetUniformLocation(this->shader->id, "MVP");
	glUniformMatrix4fv(mvpLocation, 1, GL_FALSE, &mvp[0][0]);

	glEnableVertexAttribArray(0);
	glEnableVertexAttribArray(1);
	glBindBuffer(GL_ARRAY_BUFFER, this->vertexBuff);

	glVertexAttribPointer(0, 3, GL_FLOAT, GL_NONE, 0, (void*)0);

	glBindBuffer(GL_ARRAY_BUFFER, this->texCoordBuff);
	glVertexAttribPointer(1, 2, GL_FLOAT, GL_NONE, 0, (void*)0);

	glDrawArrays(GL_TRIANGLES, 0, (vertex.size() / 3));

	glDisableVertexAttribArray(1);
	glDisableVertexAttribArray(0);

}


GameObject::GameObject(string name) {
	this->name = name;
	this->transform = new Transform(  Vector3 (0.f, 0.f, 0.f),  Vector3 (0.f, 0.f, 0.f),  Vector3 (0.f, 0.f, 0.f) );
	this->bufferUploaded = false;
	this->fileMgr = new FileManager();
	this->hasTex = false;
	this->shader = new Shader;
}