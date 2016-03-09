
#include <GL/glew.h>
#include <gs/utils.h>
#include "gl.h"

using namespace gs;

namespace gl
{
	bool loadFunctions ()
	{
		glewExperimental = GL_TRUE;
		GLenum err = glewInit ();
	
		if (err != GLEW_OK) {
			errLog << "GLEW error: " << glewGetErrorString (err) << nl;
			return false;
		}
		
		return true;
	}
}

