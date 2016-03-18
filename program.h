
#pragma once

#include <list>
#include <GL/glew.h>
#include <glm/fwd.hpp>

namespace gl
{
	using std::list;
	using glm::vec3;
	using glm::dvec3;
	using glm::mat4;
	
	struct Shader;
	template<typename T> struct Buffer;

	class Program
	{
	public:
		Program ();
		void create ();
		void enable ();
		void attachShader (Shader& shader);
		bool link ();
		int getUniformLocation (char *name);
		int getAttributeLocation (char *name);
		void setUniform (int location, vec3 &val);
		void setUniform (int location, mat4 &val);
		template<typename T>
		void setUniform (char *name, T &val)
		{
			setUniform (getUniformLocation (name), val);
		}
		void setAttributeArray (int location, Buffer<vec3> *buffer);
		void setAttributeArray (int location, Buffer<dvec3> *buffer);
		template<typename T>
		void setAttributeArray (char *name, Buffer<T> *buffer)
		{
			setAttributeArray (getAttributeLocation (name), buffer);
		}
	
		GLuint program;
		list<Shader*> shaders;
	};
}

