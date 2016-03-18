
#include <iostream>
#include "shader.h"
#include "gl.h"
#include "../gs/utils.h"

using namespace std;
using namespace gs;

namespace gl
{
	Shader::Shader () :
		shader(0), type(VERTEX), source(0)
	{
	}

	void Shader::create (ShaderType _type)
	{
		loadFunctions ();
		type = _type;
		shader = glCreateShader (type);
	}

	void Shader::setSource (char *_source)
	{
		source = _source;
		glShaderSource (shader, 1, &source, 0);
	}

	bool Shader::compile ()
	{
		glCompileShader (shader);
		GLint status;
		glGetShaderiv (shader, GL_COMPILE_STATUS, &status);
		if (status == GL_FALSE) {
			GLint infoLogLen;
			glGetShaderiv (shader, GL_INFO_LOG_LENGTH, &infoLogLen);
			GLchar *infoLog = new GLchar [infoLogLen];
			glGetShaderInfoLog (shader, infoLogLen, 0, infoLog);
			errLog << "OpenGL Shader compile error:" << nl << infoLog << nl;
			return false;
		}
		
		return true;
	}
}

