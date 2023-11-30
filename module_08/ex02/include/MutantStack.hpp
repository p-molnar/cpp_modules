#ifndef MUTANTSTACK__HPP
#define MUTANTSTACK__HPP

#include <stack>
#include <iterator>
#include <cstddef>
#include <iostream>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	class iterator
	{
	public:
		typedef std::bidirectional_iterator_tag iterator_tag;
		typedef std::ptrdiff_t difference_type;
		typedef T value_type;
		typedef T *pointer;
		typedef T &reference;

	public:
		// iterator operators and arithmetics
		iterator(pointer ptr) : ptr(ptr) {}

		reference operator*(void)
		{
			return *ptr;
		}

		pointer operator->(void)
		{
			return ptr;
		}

		iterator &operator++(void)
		{
			ptr++;
			return *this;
		}

		iterator &operator++(T)
		{
			iterator tmp = *this;
			ptr++;
			return tmp;
		}

		iterator &operator--(void)
		{
			ptr--;
			return *this;
		}

		iterator &operator--(T)
		{
			iterator tmp = *this;
			ptr--;
			return tmp;
		}

		bool operator==(const iterator &rhs)
		{
			return ptr == rhs.ptr;
		}

		bool operator!=(const iterator &rhs)
		{
			return ptr != rhs.ptr;
		}

	private:
		pointer ptr;
	};

public:
	iterator begin(void)
	{
		return iterator(&this->c[0]);
	}

	iterator end(void)
	{
		return iterator(&this->c[0] + this->c.size());
	}
};

#endif
