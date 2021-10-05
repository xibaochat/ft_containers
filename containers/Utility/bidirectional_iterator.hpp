#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

#include "main.hpp"
namespace ft
{
	template <typename Node_type>/*node type is ft::Node*/
	class bidirectional_iterator
	{
		template<typename U>
		friend class Const_Bidirectional_iterator;
		template<class Key, class E, class Node,class Compare>
		friend class red_black_tree;
	public:
		typedef size_t                          size_type;
		typedef Node_type                       value_type;
		typedef typename Node_type::value_type  pair;
		typedef pair&                           reference;
		typedef pair*                           pointer;
		typedef std::ptrdiff_t                  difference_type;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef Node_type                               _node;
		_node *_n;
		_node *_nil;
		_node *_root;
	private:
		typedef bidirectional_iterator<Node_type>       _Self;



	public:
		/*******************************************
		 *****           Construct              *****
		 *******************************************/
		bidirectional_iterator():_n(NULL), _nil(NULL), _root(NULL){}
		bidirectional_iterator(_node *n, _node *root, _node* nil):_n(n), _root(root), _nil(nil){}
		bidirectional_iterator(const _Self &obj):_n(obj._n), _root(obj._root), _nil(obj._nil){}
		~bidirectional_iterator(){}
		_Self &operator=(const _Self &src)
		{
			_n = src._n;
			_root = src._root;
			_nil = src._nil;
			return *this;
		}
		/*******************************************
		 *****          dereferenced           *****
		 *******************************************/
		reference operator*() const{return this->_n->value;}
		pointer operator->() {return &_n->value;}
		/*******************************************
		 *****       Operator Arithmetics       *****
		 *****             ++ | --              *****
		 *******************************************/
		_Self& operator++()
		{
			if (_n->right && _n->right != _nil)
			{
				_n = _n->right;
				while (_n->left && _n->left != _nil)
					_n = _n->left;
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
				_node* tmp = _root;
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

		/*******************************************
		 *****         Operator Boolean         *****
		 *****            == | !=               *****
		 *******************************************/
		friend bool operator==(const _Self& a, const _Self& b){return (a._n == b._n);}
		friend bool operator!=(const _Self& a, const _Self& b){return !(a._n == b._n);}

	};
}





#endif
