
namespace gl
{
	template<typename T>
	Buffer<T>::Buffer () :
		buffer(0), count(0), data(0), usage(STREAM_DRAW)
	{
	}

	template<typename T>
	void Buffer<T>::create ()
	{
		glGenBuffers (1, &buffer);
	}

	template<typename T>
	void Buffer<T>::enable ()
	{
		glBindBuffer (GL_ARRAY_BUFFER, buffer);
	}

	template<typename T>
	void Buffer<T>::enableIndices ()
	{
		glBindBuffer (GL_ELEMENT_ARRAY_BUFFER, buffer);
	}

	template<typename T>
	void Buffer<T>::allocate (int _count, T *_data, BufferUsage _usage)
	{
		count = _count;
		data = _data;
		usage = _usage;
		enable ();
		glBufferData (GL_ARRAY_BUFFER, sizeof(T)*count, data, usage);
	}

	template<typename T>
	void Buffer<T>::allocate (int _count, BufferUsage _usage)
	{
		allocate (_count, new T[_count], _usage);
	}

	template<typename T>
	void Buffer<T>::update ()
	{
		enable ();
		glBufferSubData (GL_ARRAY_BUFFER, 0, sizeof(T)*count, data);
	}
}

