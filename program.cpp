
#include <iostream>
#include "program.h"
#include "shader.h"
#include "buffer.h"
#include "gl.h"
#include "../gs/utils.h"

using namespace std;
using namespace gs;

namespace gl
{
	Program::Program () :
		program(0)
	{
	}

	void Program::create ()
	{
		loadFunctions ();
		program = glCreateProgram ();
	}

	void Program::enable ()
	{
		glUseProgram (program);
	}

	void Program::attachShader (Shader& shader)
	{
		shaders.push_back (&shader);
		glAttachShader (program, shader.shader);
	}

	bool Program::link ()
	{
		glLinkProgram (program);
		GLint status;
		glGetProgramiv (program, GL_LINK_STATUS, &status);
		if (status == GL_FALSE) {
			GLint infoLogLen;
			glGetProgramiv (program, GL_INFO_LOG_LENGTH, &infoLogLen);
			GLchar *infoLog = new GLchar [infoLogLen];
			glGetProgramInfoLog (program, infoLogLen, 0, infoLog);
			errLog << "OpenGL Shader link error:" << nl << infoLog << nl;
			return false;
		}
		
		return true;
	}

	int Program::getUniformLocation (char *name)
	{
		return glGetUniformLocation (program, name);
	}

	int Program::getAttributeLocation (char *name)
	{
		return glGetAttribLocation (program, name);
	}

	void Program::setUniform (int location, vec3 &val)
	{
		enable ();
		glUniform2fv (location, 1, (GLfloat*)&val);
	}

	void Program::setUniform (int location, mat4 &val)
	{
		enable ();
		glUniformMatrix4fv (location, 1, GL_FALSE, (GLfloat*)&val);
	}

	void Program::setAttributeArray (int location, Buffer<vec3> *buffer)
	{
		buffer->enable ();
		glVertexAttribPointer (location, 3, GL_FLOAT, GL_FALSE, 0, 0);
		glEnableVertexAttribArray (location);
	}

	void Program::setAttributeArray (int location, Buffer<dvec3> *buffer)
	{
		buffer->enable ();
		glVertexAttribPointer (location, 3, GL_DOUBLE, GL_FALSE, 0, 0);
		glEnableVertexAttribArray (location);
	}
}

