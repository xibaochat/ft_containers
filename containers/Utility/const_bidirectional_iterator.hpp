#ifndef CONST_BIDIRECTIONAL_ITERATOR_HPP
# define CONST_BIDIRECTIONAL_ITERATOR_HPP

#include "main.hpp"

namespace ft
{
	template <typename Node>
	class bidirectional_iterator;
	template <typename Node>
	class set_it;
	template <typename Node>
	class Const_Bidirectional_iterator
	{
	public:
		typedef size_t size_type;
		typedef Node                       value_type;
		typedef std::ptrdiff_t difference_type;
		typedef typename Node::value_type  pair;
		typedef const pair& reference;
		typedef const pair* pointer;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef value_type _node;
		const _node*       _n;
		const _node*       _nil;
		const _node*       _root;
	private:
		typedef Const_Bidirectional_iterator<Node> _Self;


	public:
		Const_Bidirectional_iterator():_n(NULL), _nil(NULL){}
		Const_Bidirectional_iterator(const _node* ptr, const _node* root, const _node* sentinel):_n(ptr),_nil(sentinel), _root(root){
}/*node is const*/
		Const_Bidirectional_iterator(const _Self &obj):_n(obj._n),_nil(obj._nil), _root(obj._root){}
		Const_Bidirectional_iterator(bidirectional_iterator<Node> obj)
		{
			_n = obj._n;
			_nil = obj._nil;
			_root = obj._root;
		}

		// here is for set because The value of the elements in a set cannot be modified once in the container
		Const_Bidirectional_iterator(set_it<Node> obj)
		{
			_n = obj._n;
			_nil = obj._nil;
			_root = obj._root;
		}

		_Self &operator=(set_it<Node> obj)
		{
			_n = obj._n;
			_nil = obj._nil;
			_root = obj._root;
			return *this;
		}
		~Const_Bidirectional_iterator(){}
		_Self &operator=(const _Self &src)
		{
			_n = src._n;
			_nil = src._nil;
			 _root = src._root;
			return *this;
		}
		_Self &operator=(bidirectional_iterator<Node> obj)
		{
			_n = obj._n;
			_nil = obj._nil;
			_root = obj._root;
			return *this;
		}

		reference operator*() const {return _n->value;}
		pointer operator->() const
		{
			return &(_n->value);
		}

		friend bool operator==(const _Self& a, const _Self& b){return (a._n == b._n);}
		friend bool operator!=(const _Self& a, const _Self& b){return !(a._n == b._n);}
		_Self& operator++()
		{
			if (_n->right && _n->right != _nil)
			{
				_n = _n->right;
				while (_n->left && _n->left != _nil)
				{
					_n = _n->left;
				}
			}
			else
			{
				while (_n->parent && _n == _n->parent->right)
					_n = _n->parent;
				_n = _n->parent;
				if (!_n)
					_n = _nil;
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
			if (_n && _n == _nil)
            {
                const _node* tmp = _root;
                while (tmp && tmp->right != _nil)
                    tmp = tmp->right;
                _n = tmp;
            }
			else if (_n->left && _n->left != _nil)
			{
				_n = _n->left;
				while (_n->right && _n->right != _nil)
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
