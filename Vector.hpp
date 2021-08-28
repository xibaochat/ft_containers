#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <list>
#include "iterator.hpp"
#include "const_iterator.hpp"
#include "Utility.hpp"

namespace ft
{
	template<typename T,  class Allocator>
	class Vector;

	template< class T, class Allocator = std::allocator<T> >
	class Vector
	{
	public:
		typedef T                       value_type;
		typedef Allocator               allocator_type;
		typedef size_t                  size_type;
		typedef std::ptrdiff_t          difference_type;
		typedef T&                      reference;
		typedef const T&                const_reference;
		typedef T*                      pointer;
		typedef const T*                const_pointer;
		typedef VectorIterator<T>       iterator;
		typedef VectorIterator<const T> const_iterator;
	private:
		size_type _len;
		size_type _cap;
	public:
		pointer _arr;
		explicit Vector (const allocator_type& alloc = allocator_type()):_arr(NULL), _len(0), _cap(0){}

		explicit Vector (size_type n, const value_type& val = value_type(),
						 const allocator_type& alloc = allocator_type()):_arr(NULL), _len(0), _cap(0)
			{
//				insert(begin(), n, val);
			}

		template <class InputIterator>
		Vector (InputIterator first, InputIterator last, const allocator_type& alloc = allocator_type()){}

		//iterator begin(){return iterator(_arr);}
		iterator end(){return iterator(_arr + _len);}

		const_iterator begin() const
		{
			return const_iterator(_arr);
		}
		const_iterator end() const
		{
			return const_iterator(_arr + _len);
		}











		iterator insert (iterator position, const value_type& val)
		{
			insert(position, 1, val);
			return (position);
		}
		void insert (iterator position, size_type n, const value_type& val)
		{
			std::cout <<  "ICI\n";
			if (!n)
				return ;
			std::ptrdiff_t index = position.m_ptr - _arr;
			std::cout << index << "\n";
			size_type tmp = index;
			if (n + _len > _cap)
				reserve(_len + n);
			while (index < _len)
			{
				_arr[index + n] = _arr[index];
				index++;
			}
			index = tmp;
			while (n > 0)
			{
					_arr[index] = val;
					n--;
			}
			_len += n;
			for(int i=0; i < _len; i++)
				std::cout << " " << _arr[i] << "\n";
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last)
		{}

		void reserve (size_type n)
		{
			if (n > _cap)
			{
				allocator_type alloc;
				pointer new_arr = alloc.allocate(n);
				for(size_type i=0; i < _len; i++)
				{
					alloc.construct(new_arr + i, _arr[i]);
					alloc.destroy(_arr + i);
				}
				alloc.deallocate(_arr, _cap);
				_arr = new_arr;
				_cap = n;
			}
		}



	};

}





#endif
