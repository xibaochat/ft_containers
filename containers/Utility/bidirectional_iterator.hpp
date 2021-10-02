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
	private:
		typedef bidirectional_iterator<Node_type>       _Self;
		typedef Node_type                               _node;

		_node *_n;
	public:
		/*******************************************
		 *****           Construct              *****
		 *******************************************/
		bidirectional_iterator():_n(NULL){}
		bidirectional_iterator(_node *n):_n(n){}
		bidirectional_iterator(const _Self &obj):_n(obj._n){}
		~bidirectional_iterator(){}
		_Self &operator=(const _Self &src)
		{
			_n = src._n;
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

		/*******************************************
		 *****         Operator Boolean         *****
		 *****            == | !=               *****
		 *******************************************/
		friend bool operator==(const _Self& a, const _Self& b){return (a._n == b._n);}
		friend bool operator!=(const _Self& a, const _Self& b){return !(a._n == b._n);}

	};
}





#endif
