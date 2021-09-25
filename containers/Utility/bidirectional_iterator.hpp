#ifndef BIDIRECTIONAL_ITERATOR_HPP
# define BIDIRECTIONAL_ITERATOR_HPP

#include "main.hpp"
namespace ft
{
	enum Color { red, black };
	template <typename T> // T is pair
	struct Node
	{
		T value;
		Node* parent;
		Node* left;
		Node* right;
		Color color;
		Node(const T &p, Node* parent_, Node* left_, Node* right_):value(p), parent(parent_), left(left_), right(right_){}
	};

	template <typename Node, typename P>
	class bidirectional_iterator
	{
		template<typename U, typename T>
		friend class Const_Bidirectional_iterator;
	public:
		typedef size_t                          size_type;
		typedef P                               value_type;
		typedef P&                              reference;
		typedef P*                              pointer;
		typedef std::ptrdiff_t                  difference_type;
		typedef std::bidirectional_iterator_tag iterator_category;
	private:
		typedef bidirectional_iterator<Node,P>       _Self;
		typedef Node                               _node;

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
