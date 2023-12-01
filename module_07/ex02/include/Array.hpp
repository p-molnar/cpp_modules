#ifndef ARRAY__HPP
#define ARRAY__HPP

#include <exception>

template <typename T>
class Array
{
private:
	T *elements;
	unsigned int arr_size;

public:
	Array(void) : elements(NULL), arr_size(0){};

	Array(unsigned int n) : elements(new T[n]), arr_size(n){};

	Array<T> &operator=(const Array<T> &obj)
	{
		if (this != &obj)
		{
			delete[] elements;

			arr_size = obj.size();
			elements = new T[arr_size];
			if (obj.elements)
			{
				for (unsigned int i = 0; i < arr_size; i++)
					elements[i] = obj.elements[i];
			}
		}
		return *this;
	}

	Array<T>(const Array<T> &obj) : arr_size(obj.arr_size)
	{
		elements = new T[arr_size];
		if (obj.elements)
		{
			for (unsigned int i = 0; i < arr_size; i++)
				elements[i] = obj.elements[i];
		}
	}

	~Array<T>(void)
	{
		delete[] elements;
	};

public:
	unsigned int size(void) const { return arr_size; };

	T &operator[](int index)
	{
		if (index < 0 || index >= static_cast<int>(arr_size))
			throw(std::exception());
		return elements[index];
	}
};

#endif
