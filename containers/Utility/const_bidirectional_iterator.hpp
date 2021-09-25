#ifndef CONST_BIDIRECTIONAL_ITERATOR_HPP
# define CONST_BIDIRECTIONAL_ITERATOR_HPP

#include "main.hpp"

namespace ft
{
	template <typename Node, typename P>
	class bidirectional_iterator;
	template <typename Node, typename P>
	class Const_Bidirectional_iterator
	{
	public:
		typedef size_t size_type;
		typedef std::ptrdiff_t difference_type;
		typedef const P value_type;
		typedef const P& reference;
		typedef P* pointer;
		typedef std::bidirectional_iterator_tag iterator_category;
	private:
		typedef Const_Bidirectional_iterator<Node, P> _Self;
		typedef Node _node;
		const _node*       _n;
	public:
		Const_Bidirectional_iterator():_n(NULL){}
		Const_Bidirectional_iterator(const _node* ptr):_n(ptr){}/*node is const*/
		Const_Bidirectional_iterator(const _Self &obj):_n(obj._n){}
		Const_Bidirectional_iterator(bidirectional_iterator<Node, P> obj)
		{
			_n = obj._n;
		}
		~Const_Bidirectional_iterator(){}
		_Self &operator=(const _Self &src)
		{
			_n = src._n;
			return *this;
		}
		_Self &operator=(bidirectional_iterator<Node, P> obj)
		{
			_n = obj._n;
			return *this;
		}

		reference operator*() const {return _n->value;}
		P* operator->(){return &_n->value;}

		friend bool operator==(const _Self& a, const _Self& b){return (a._n == b._n);}
		friend bool operator!=(const _Self& a, const _Self& b){return !(a._n == b._n);}

		_Self& operator++()
		{
			if (_n->right)
			{
				_n = _n->right;
				while (_n->left)
					_n = _n->left;
			}
			else
			{
				while (_n->parent && _n == _n->parent->right)
					_n = _n->parent;
				_n = _n->parent;
			}
			return *this;
		}
		_Self operator++(int)
		{
			_Self tmp(*this);
			this->operator++();
			return (tmp);
		}

		_Self& operator--()
		{
			if (_n->left)
			{
				_n = _n->left;
				while (_n->right)
					_n = _n->right;
			}
			else
			{
				while (_n->parent && _n == _n->parent->left)
					_n = _n->parent;
				_n = _n->parent;
			}
			return *this;
		}
		_Self operator--(int)
		{
			_Self tmp = *this;
			operator--();
			return (tmp);
		}
	};

}


#endif

/*1)T*  A non-const iterator to a non-const element. Corresponds to std::vector<T>::iterator
2)T* const A const iterator to a non-const element. Corresponds to const std::vector<T>::iterator
3)const T*  A non-const iterator to a const element. Corresponds to std::vector<T>::const_iterator */
