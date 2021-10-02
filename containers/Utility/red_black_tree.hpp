#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

#include "main.hpp"

namespace ft
{
	enum Color { red, black };
	template <typename T> // T is pair
	struct Node
	{
		typedef T   value_type;
		T value;
		Node* parent;
		Node* left;
		Node* right;
		Color color;
		Node(const T &p, Node* parent_, Node* left_, Node* right_, enum Color color):
			value(p), parent(parent_), left(left_), right(right_), color(color){}
	};

	template <class Key, class E,
			  class Node = ft::Node<E>,
			  class Compare = std::less<Key> >
	class red_black_tree
	{
	public:
		typedef Key                                      key_type;
		//    ???  ---------------why?
		typedef Node                                     value_type;
		typedef Compare                                  key_compare;
		typedef ft::bidirectional_iterator<Node>         iterator;
		typedef ft::Const_Bidirectional_iterator<Node>   const_iterator;
		typedef ft::reverse_iterator<iterator>           reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>     const_reverse_iterator;
		typedef std::ptrdiff_t                           difference_type;
		typedef std::size_t                              size_type;
		typedef std::allocator<Node>      allocator_type;
	private:
		/*-----------------mark?*/
		typedef Node*                     node_pointer;
		node_pointer                      _root;
		node_pointer                      _nil;
		//a special Node object used to indicate an absent child or parent node
		size_type                         _size;
		key_compare                       _comp;
		allocator_type                    _alloc;
		typedef red_black_tree<Key, E, Node, Compare>    _Self;
	public:
		/***************** CONSTRUCTOR && DESTRUCTOR ******************/
		/*                                                            */
		/**************************************************************/
		explicit red_black_tree (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_root(NULL), _nil(NULL), _size(0), _comp(comp), _alloc(alloc)
		{
			_root = _alloc.allocate(1);
			_alloc.construct(_root, Node(E(), NULL, NULL, NULL, black));
			_nil = _root;
		}
		template <class InputIterator>
		red_black_tree (InputIterator first, InputIterator last,
						const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type())
			:_root(NULL), _nil(NULL), _size(0), _comp(comp), _alloc(alloc)
			{
				_root = _alloc.allocate(1);
				_alloc.construct(_root, Node(E(), NULL, NULL, NULL, black));
				_nil = _root;
				insert(first, last);
			}

		red_black_tree (const red_black_tree& x):_root(NULL), _nil(NULL), _size(0), _comp(x._comp),_alloc(x._alloc)
			{
				_root = _alloc.allocate(1);
				_alloc.construct(_root, Node(E(), NULL, NULL, NULL, black));
				_nil = _root;
				insert(x.begin(), x.end());
			}
		~red_black_tree()
		{
			clear();
			_alloc.destroy(_nil);
			_alloc.deallocate(_nil, 1);
		}

		_Self& operator= (const _Self& x)
		{
			if (this == &x)
				return *this;
			this->clear();
			insert(x.begin(), x.end());
			return *this;
		}
		iterator begin()
		{
			node_pointer t = _root;
			while (t && t->left)
				t = t->left;
			return iterator(t);
		}
		const_iterator begin() const
		{
			node_pointer t = _root;
			while (t && t->left)
				t = t->left;
			return const_iterator(t);
		}
		iterator end()
		{
			return iterator(_nil);
		}
		const_iterator end() const
		{
			return const_iterator(_nil);
		}
		reverse_iterator rbegin()
		{
			return reverse_iterator(end());
		}
		const_reverse_iterator rbegin() const
		{
			return const_reverse_iterator(end());
		}
		reverse_iterator rend()
		{
			return reverse_iterator(begin());
		}
		const_reverse_iterator rend() const
		{
			return const_reverse_iterator(begin());
		}
		bool empty() const
		{
			return _size==0;
		}
		size_type size() const
		{
			return _size;
		}
		size_type max_size() const
		{
			return _alloc.max_size();
		}
		ft::pair<iterator,bool> insert (const value_type& val)
		{
			if (find(val.first) != end())
			{
				return ft::make_pair(find(val.first), false);
			}
			else
			{
				node_pointer node = _alloc.allocate(1);
				_alloc.construct(node, Node(val, NULL, _nil, _nil, red));
				insert_new_node(_root, node);
				_size++;
				return ft::make_pair(iterator(node), true);
			}
		}
		iterator insert (iterator position, const value_type& val)
		{
			if (find(val.first) != end())
                return find(val.first);
			node_pointer node = _alloc.allocate(1);
			_alloc.construct(node, Node(val, NULL, _nil, _nil, red));
			if (_comp(*position.first, val.first))
				insert_new_node(position._n, node);
			else
				insert_new_node(_root, node);
			_size++;
			return iterator(node);
		}
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			 for (; first != last; ++first)
                insert(*first);
		}
		iterator find (const key_type& k)
		{
			node_pointer node;
			node = _root;
			while (node && node != _nil)
			{
				bool a = _comp(k, node->value.first);
				bool b = _comp(node->value.first, k);
				if (!a && !b)
					return iterator(node);
				if (a == true)
					node = node->left;
				else
					node = node->right;
			}
			return end();
		}
		const_iterator find (const key_type& k) const
		{
			node_pointer node;
			node = _root;
			while (node && node != _nil)
			{
				bool a = _comp(k, node->value.first);
				bool b = _comp(node->value.first, k);
				if (!a && !b)
					return const_iterator(node);
				if (a == true)
					node = node->left;
				else
					node = node->right;
			}
			return end();
		}
		void erase (iterator position)
		{
			node_pointer n = position._n;
			if (!n->parent)
				_root = deleteNode(n);
			else if (n->parent->left == n)
				n->parent->left = deleteNode(n);
			else
				n->parent->right = deleteNode(n);
			_alloc.destroy(n);
			_alloc.deallocate(n, 1);
			_size--;
		}
		size_type erase (const key_type& k)
		{
			iterator it = find(k);
			if (it == _nil)
				return (0);
			else
			{
				erase(it);
				return (1);
			}
		}
		void erase (iterator first, iterator last)
		{
			while (first != last)
				erase(first++);
		}
		void swap (_Self& x)
		{
			std::swap(this->_root, x._root);
			std::swap(this->_size, x._size);
			std::swap(this->_nil, x._nil);
		}
		void clear()
		{
			deleteTree(_root);
			_root = _nil;
		}
		void deleteTree(node_pointer node)
		{
			if (node == _nil)
				return ;
			deleteTree(node->left);
			deleteTree(node->right);
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
		}
		size_type count (const key_type& k) const
		{
			return (find(k) != end());
		}
		iterator lower_bound (const key_type& k)
		{
			iterator it = begin();
			while (it != end())
			{
				if (!_comp(*it.first, k))
					return (it);
				it++;
			}
			return (end());
		}
		const_iterator lower_bound (const key_type& k) const
		{
			const_iterator it = begin();
			while (it != end())
			{
				if (!_comp(*it.first, k))//k is not go before
					return (it);
				it++;
			}
			return (end());
		}
		iterator upper_bound (const key_type& k)
		{
			iterator it = begin();
			while (it != end())
			{
				if (_comp(*it.first, k))
					return (it);
				it++;
			}
			return (end());
		}
		const_iterator upper_bound (const key_type& k) const
		{
			const_iterator it = begin();
			while (it != end())
			{
				if (_comp(*it.first, k))
					return (it);
				it++;
			}
			return (end());
		}
		ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			return (ft::make_pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k)));
		}
		ft::pair<iterator,iterator> equal_range (const key_type& k)
		{
			return (ft::make_pair<iterator,iterator>(lower_bound(k), upper_bound(k)));
		}
		// allocator_type get_allocator() const
		// {
		// 	return _alloc;
		// }

	private:
		node_pointer deleteNode(node_pointer node)
			{
				if (node->right == _nil)
					return node->left;
				node_pointer x = node->right;
				while(x && x->left)
					x = x->left;
				x->left = node->left;
				return node->right;
			}
		void insert_new_node(node_pointer hint, node_pointer new_node)
		{
			node_pointer x = hint;
			node_pointer xParent = _nil;
			while (x != _nil)
			{
				xParent = x;
				if (_comp(new_node->value.first, x->value.first) == true)
					x = x->left;
				else
					x = x->right;
			}
			new_node->parent = xParent;
			if (xParent == _nil)
				_root = new_node;
			else
			{
				if (_comp(new_node->value.first, xParent->value.first) == true)
					xParent->left = new_node;
				else
					xParent->right = new_node;
			}
		}


	};

}

#endif
//https://www.tutorialspoint.com/delete-node-in-a-bst-in-cplusplus
