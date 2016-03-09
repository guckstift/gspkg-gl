
#pragma once

#include <GL/glew.h>

namespace gl
{
	enum ShaderType {
		VERTEX = GL_VERTEX_SHADER,
		FRAGMENT = GL_FRAGMENT_SHADER
	};
	
	struct Shader
	{
		Shader ();
		void create (ShaderType _type = VERTEX);
		void setSource (char *_source);
		bool compile ();
	
		GLuint shader;
		ShaderType type;
		char *source;
	};
}

