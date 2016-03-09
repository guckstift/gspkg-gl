
#pragma once

#include <GL/glew.h>

namespace gl
{
	enum BufferUsage {
		STREAM_DRAW = GL_STREAM_DRAW,
		STREAM_READ = GL_STREAM_READ,
		STREAM_COPY = GL_STREAM_COPY,
		STATIC_DRAW = GL_STATIC_DRAW,
		STATIC_READ = GL_STATIC_READ,
		STATIC_COPY = GL_STATIC_COPY,
		DYNAMIC_DRAW = GL_DYNAMIC_DRAW,
		DYNAMIC_READ = GL_DYNAMIC_READ,
		DYNAMIC_COPY = GL_DYNAMIC_COPY,
	};

	template<typename T>
	struct Buffer
	{
		Buffer ();
		void create ();
		void enable ();
		void enableIndices ();
		void allocate (int _count, T *_data, BufferUsage _usage);
		void allocate (int _count, BufferUsage _usage);
		void update ();
	
		GLuint buffer;
		int count;
		T *data;
		BufferUsage usage;
	};
}

#include "buffer.cxx"

