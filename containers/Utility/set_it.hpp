#ifndef SET_IT_HPP
# define SET_IT_HPP

#include "main.hpp"
namespace ft
{
	template <typename Node_type>/*node type is ft::Node*/
	class set_it
	{
		template<typename U>
		friend class Const_Bidirectional_iterator;
		template<class Key, class E, class Node,class Compare>
		friend class red_black_tree;
	public:
		typedef size_t                          size_type;
		typedef Node_type                       value_type;
		typedef typename Node_type::value_type  pair;
		typedef const pair&                           reference;
		typedef const pair*                           pointer;
		typedef std::ptrdiff_t                  difference_type;
		typedef std::bidirectional_iterator_tag iterator_category;
		typedef Node_type                               _node;
		_node *_n;
		_node *_nil;
		_node *_root;
	private:
		typedef set_it<Node_type>       _Self;
	public:
		/*******************************************
		 *****           Construct              *****
		 *******************************************/

		set_it():_n(NULL), _nil(NULL), _root(NULL){}
		set_it(_node *n, _node *root, _node* nil):_n(n), _nil(nil), _root(root){}
		set_it(const _Self &obj):_n(obj._n), _nil(obj._nil), _root(obj._root){}
		/*ici* I add */
		set_it(Const_Bidirectional_iterator<const Node_type> &obj):_n(obj._n), _nil(obj._nil), _root(obj._root){}
		~set_it(){}
		_Self &operator=(const _Self &src)
		{
			_n = src._n;
			_nil = src._nil;
			_root = src._root;
			return *this;
		}
		// set_it(Const_Bidirectional_iterator<Node_type> &src)
		// 	{
		// 		_Self a;
		// 		a._n = src._n;
		// 		a._nil = src._nil;
		// 		a._root = src._root;
		// 		*this = a;
		// 	//	return *this;
		// }
		/*******************************************
		 *****          dereferenced           *****
		 *******************************************/
		reference operator*() const {return this->_n->value;}
		pointer operator->()  const {return &(this->_n->value);}


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
		bool
        operator==(_Self const& rhs) const
        {
            return _n == rhs._n;
        }

        bool
        operator!=(_Self const& rhs) const
			{
            return _n != rhs._n;
			}
	};


}





#endif
