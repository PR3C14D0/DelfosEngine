#include "Engine/Shader/Shader.h"

Shader::Shader() {
	this->id = 0;
	this->fileMgr = new FileManager();
}

void Shader::LoadShader(const char* vertFile, const char* fragFile) {
	GLuint VertexID = glCreateShader(GL_VERTEX_SHADER);
	GLuint FragmentID = glCreateShader(GL_FRAGMENT_SHADER);
	GLint compiled;

	FileManager f = *this->fileMgr;
	string vertex = f.LoadFile(vertFile);
	string fragment = f.LoadFile(fragFile);

	const char* vert = vertex.c_str();
	const char* frag = fragment.c_str();

	cout << vert << endl;

	glShaderSource(VertexID, 1, &vert, NULL);
	glCompileShader(VertexID);
	glGetShaderiv(VertexID, GL_COMPILE_STATUS, &compiled);

	if (!compiled) {
		GLint maxLength = 0;
		glGetShaderiv(VertexID, GL_INFO_LOG_LENGTH, &maxLength);

		vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(VertexID, maxLength, &maxLength, &errorLog[0]);

		string message;
		for (GLchar c : errorLog) {
			message += c;
		}
		cout << "[ERROR]" << message << endl;
		return;
	}

	glShaderSource(FragmentID, 1, &frag, NULL);
	glCompileShader(FragmentID);

	glGetShaderiv(FragmentID, GL_COMPILE_STATUS, &compiled);

	if (!compiled) {
		GLint maxLength = 0;
		glGetShaderiv(FragmentID, GL_INFO_LOG_LENGTH, &maxLength);

		vector<GLchar> errorLog(maxLength);
		glGetShaderInfoLog(FragmentID, maxLength, &maxLength, &errorLog[0]);

		string message;
		for (GLchar c : errorLog) {
			message += c;
		}
		cout << "[ERROR] " << message << endl;
		return;
	}

	this->id = glCreateProgram();

	glAttachShader(this->id, VertexID);
	glAttachShader(this->id, FragmentID);
	glLinkProgram(this->id);

	glUseProgram(this->id);

	glDeleteShader(VertexID);
	glDeleteShader(FragmentID);

	return;
}