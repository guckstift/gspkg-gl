
#include <GL/glew.h>
#include <gs/utils.h>
#include "gl.h"

using namespace gs;

static bool isLoaded = false;

namespace gl
{
	bool loadFunctions ()
	{
		if (!isLoaded)
		{
			glewExperimental = GL_TRUE;
			GLenum err = glewInit ();
			
			if (err != GLEW_OK) {
				errLog << "GLEW error: " << glewGetErrorString (err) << nl;
				return false;
			}
		}
		
		isLoaded = true;
		
		return true;
	}
}

