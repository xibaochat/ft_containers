#ifndef CONST_ITERATOR
# define CONST_ITERATOR

#include "iterator.hpp"
#include "Vector.hpp"

namespace ft
{
	template <typename T>
	class const_iterator : public VectorIterator<T>
	{
	private:
		typedef const T*      const_pointer;
		typedef VectorIterator<const T> _Self;
		typedef const T& const_reference;
		const_pointer m_ptr;
	public:
		const_iterator(): VectorIterator<T>(){}
		const_iterator(const_pointer ptr): VectorIterator<T>(ptr)
		{}
		_Self &operator=(const _Self &src)
		{
			// if (this != &src)
			// 	VectorIterator<T>::operator=(src);
			this->_m_ptr = src._m_ptr;
			return (*this);
		}


	};


}



#endif
