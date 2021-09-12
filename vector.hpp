#ifndef VECTOR_HPP
# define VECTOR_HPP

#include <iostream>
#include <vector>
#include <memory>
#include <algorithm>
#include <list>
#include <sstream>
#include <stdexcept>
#include "iterator.hpp"
#include "const_iterator.hpp"
#include "reverse_iterator.hpp"
#include "Utility.hpp"
#include "enable_if.hpp"
#include "is_integral.hpp"

namespace ft
{
	template< class T, class Allocator = std::allocator<T> >
	class vector
	{
	public:
		typedef T                                   value_type;
		typedef Allocator                           allocator_type;
		typedef size_t                              size_type;
		typedef std::ptrdiff_t                      difference_type;
		typedef T&                                  reference;
		typedef const T&                            const_reference;
		typedef T*                                  pointer;
		typedef const T*                            const_pointer;
		typedef ft::VectorIterator<T>                   iterator;
		typedef ft::Const_VectorIterator<T>             const_iterator;
		typedef ft::reverse_iterator<iterator>          reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>    const_reverse_iterator;

	private:
		typedef vector<T> _Self;
		allocator_type _alloc;
		size_type _len;
		size_type _cap;
		pointer _arr;
	public:
		explicit vector (const allocator_type& alloc = allocator_type()):\
			_arr(NULL), _len(0), _cap(0), _alloc(alloc)
			{
				std::cout << "default construct\n";
			}
		//remplir
		explicit vector (size_type n, const value_type& val = value_type(),
						 allocator_type const & alloc = allocator_type()):
			_arr(NULL), _len(0), _cap(0), _alloc(alloc)
			{
				std::cout << "constructor remplir with n and val\n";
				insert(this->begin(), n, val);
			}
			//range
		template <class InputIterator>
		vector (InputIterator first, InputIterator last, \
		  		const allocator_type& alloc = allocator_type(),
				typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL):
		 	_arr(NULL), _len(0), _cap(0),_alloc(alloc)
		{
			std::cout << "range with input iterator\n";
			/*other insert*/
			insert(this->begin(), first, last);
		}

		vector (const vector& x):_arr(NULL), _len(0), _cap(0), _alloc(x._alloc)
		{
			std::cout << "copy construct\n";
			this->insert(begin(), x.begin(), x.end());
		}

		~vector(){this->clear();}

		_Self &operator=(const _Self &src)
		{
			this->clear();
			this->insert(begin(), src.begin(), src.end());
			return *this;
		}

		iterator begin(){return iterator(_arr);}

		const_iterator begin() const
		{
			return const_iterator(_arr);
		}

		iterator end(){return iterator(_arr + _len);}

		const_iterator end() const
		{
			return const_iterator(_arr + _len);
		}
		size_type size() const
		{
			return (this->_len);
		}
		size_type max_size() const
		{
			return (Allocator().max_size());
		}
		void resize (size_type n, T val = T())
		{
			if (n < _len)
				erase(begin() + n, end());
			else
				insert(end(), n - _len, val);
		}

		reference operator[] (size_type n){return _arr[n];}
		const_reference operator[] (size_type n) const{return _arr[n];}


		bool empty() const {return !_len;}
		size_type capacity() const{return _cap;}
		reference at (size_type n)
		{
			if (n >= _len)
			{
				std::stringstream ss;
				ss << "vector::_M_range_check: __n which is " << n << " = this->size() which is " << _len;
				throw std::out_of_range(ss.str());
			}
			else
				return _arr[n];
		}

		const_reference at (size_type n) const
			{
				if (n >= _len)
				{
					std::stringstream ss;
					ss << "vector::_M_range_check: __n which is " << n << " = this->size() which is " << _len;
					throw std::out_of_range(ss.str());
				}
				else
					return _arr[n];
			}

		reference front(){return _arr[0];}
		const_reference front() const{return _arr[0];}

		reference back(){return _arr[_len - 1];}
		/*if it is empty, it will cause undefined behavior*/
		const_reference back() const{return _arr[_len - 1];}
		void pop_back()
		{
			_alloc.destroy(&back());
			_len--;
		}
		void clear()
		{
			for(size_type i=0; i < _len; i++)
			{
				_alloc.destroy(_arr + i);
			}
			_alloc.deallocate(_arr, _cap);
			_len = 0;
			_cap = 0;
			_arr = NULL;
		}

		iterator insert (iterator position, const value_type& val)
		{
			size_type len = _len;
			difference_type index = position - this->begin();
			int n = 1;
			if (_len + n > _cap)
			{
				if (2 * _cap >= _len + n)
					reserve(2 * _cap);
				else
					reserve(_len + n);
			}
			/*can not move from left to right, to avoid override*/
			for(ptrdiff_t i = len - 1; i >= index; i--)
			{
				_alloc.construct(_arr + i + 1, _arr[i]);
				_alloc.destroy(_arr + i);
			}
			_alloc.construct(_arr + index, val);
			_len += 1;
			return (iterator(_arr + index));
		}
		void insert (iterator position, size_type n, const value_type& val)
		{
			std::cout << "in this insert\n";
			if (!n)
				return ;
			size_type len = _len;
			difference_type index = position - this->begin();
			if (_len + n > _cap)
			{
				if (2 * _cap >= _len + n)
					reserve(2 * _cap);
				else
					reserve(_len + n);
			}
			/*can not move from left to right, to avoid override*/
			for(ptrdiff_t i = len - 1; i >= index; i--)
			{
				_alloc.construct(_arr + i + n, _arr[i]);
				_alloc.destroy(_arr + i);
			}
			for(size_type i = index; i < index + n; i++)
			{
				_alloc.construct(_arr + i, val);
			}
			_len += n;
		}

		template <class InputIterator>
		void insert (iterator position, InputIterator first, InputIterator last
						  , typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)//it.begin() or array
		{
			std::cout << "in that insert\n";
			difference_type n;
			n = last - first;//nb to insert
			if (!n)
				 return ;
			pointer new_arr = _alloc.allocate(n);
			for(size_type i=0; first + i < last; i++)
				_alloc.construct(new_arr + i, *(first + i));
			difference_type index = position - this->begin();
			if (_len + n > _cap)
			{
				// if (2 * _cap >= _len + n)
				// 	reserve(2 * _cap);
				// else
				reserve(_len + n);
			}
			for(ptrdiff_t i = _len - 1; i >= index; i--)
			{
				_alloc.construct(_arr + i + n, _arr[i]);
				_alloc.destroy(_arr + i);
			}
// 			for(InputIterator it = first; it != last; it++)
// 			{
// //				_alloc.construct(_arr + index, *it);
// 				_alloc.construct(_arr + index, new_arr[index]);
// 				_alloc.destroy(new_arr + index);
// 				index++;
// 			}
			for(ptrdiff_t i = 0; i < n; i++)
			{
				_alloc.construct(_arr + index + i, new_arr[i]);
				_alloc.destroy(new_arr + i);
			}
			_alloc.deallocate(new_arr, n);
			_len += n;
		}

		void reserve (size_type n)
		{
			if (n > _cap)
			{
				pointer new_arr = _alloc.allocate(n);//Memory is allocated for n objects of type T but objects are not constructed
				for(size_type i=0; i < _len; i++)
				{
					_alloc.construct(new_arr + i, _arr[i]);
					_alloc.destroy(_arr + i);
				}
				_alloc.deallocate(_arr, _cap);
				_arr = new_arr;
				_cap = n;
			}
		}

		void push_back (const value_type& val)
		{
			if (empty())
				reserve(1);
			if (_len + 1 > _cap)
			 	reserve(2 * _cap);
			_alloc.construct(_arr + _len, val);
			_len++;
		}

		iterator erase (iterator pos)
		{
			return erase(pos, pos + 1);
		}

		iterator erase (iterator first, iterator last)
		{
			size_type n = last - first;
			if (n <= 0)
				return last;
			size_type index = first - this->begin();
			for(size_type i = index; i < index + n; i++)
				_alloc.destroy(_arr + i);
			for(size_type i = index + n; i < _len ; i++)
			{
				_alloc.construct(&_arr[i - n], _arr[i]);
				_alloc.destroy(_arr + i);
			}
			_len -= n;
			return first;
		}
		void swap (_Self& x)
		{
			std::swap(this->_arr, x._arr);
			std::swap(this->_len, x._len);
			std::swap(this->_cap, x._cap);
		}
		allocator_type get_allocator() const
		{
			return (this->_alloc);
		}

		template <class InputIterator>
		void assign (InputIterator first, InputIterator last, typename ft::enable_if<!ft::is_integral<InputIterator>::value, InputIterator>::type* = NULL)
		{
			this->clear();
			this->insert(begin(), first, last);
		}
		void assign (size_type n, const value_type& val)
		{
			this->clear();
			this->insert(begin(), n, val);
		}

		reverse_iterator rbegin()
		{
			return reverse_iterator(this->end());
		}

		const_reverse_iterator  rbegin() const
		{
			return reverse_iterator(this->end());
		}

		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}

	};

	//non member function
	template <class T, class Alloc>
	void swap (vector<T,Alloc>& x, vector<T,Alloc>& y)
	{
		x.swap(y);
	}

}


#endif
