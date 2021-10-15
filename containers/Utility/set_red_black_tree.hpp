#ifndef SET_RED_BLACK_TREE_HPP
# define SET_RED_BLACK_TREE_HPP

#include "main.hpp"

namespace ft
{
	template <class Key,
			  class Node = ft::Node<Key>,
			  class Compare = ft::less<Key> >
	class set_red_black_tree
	{
	public:
		typedef Key                                      key_type;
		typedef key_type  value_type;
		typedef Compare                                  key_compare;
		typedef ft::set_it<Node>         iterator;
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
		typedef set_red_black_tree<Key, Node, Compare>    _Self;
	public:
		/***************** CONSTRUCTOR && DESTRUCTOR ******************/
		/*                                                            */
		/**************************************************************/
		explicit set_red_black_tree (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()):_root(NULL), _nil(NULL), _size(0), _comp(comp), _alloc(alloc)
		{
			_root = _alloc.allocate(1);
			_alloc.construct(_root, Node(value_type(), NULL, NULL, NULL, black));
			_nil = _root;
		}
		template <class InputIterator>
		set_red_black_tree (InputIterator first, InputIterator last,
						const key_compare& comp = key_compare(),
						const allocator_type& alloc = allocator_type())
			:_root(NULL), _nil(NULL), _size(0), _comp(comp), _alloc(alloc)
			{
				_root = _alloc.allocate(1);
				_alloc.construct(_root, Node(value_type(), NULL, NULL, NULL, black));
				_nil = _root;
				insert(first, last);
			}

		set_red_black_tree (const set_red_black_tree& x):_root(NULL), _nil(NULL), _size(0), _comp(x._comp),_alloc(x._alloc)
			{
				_root = _alloc.allocate(1);
				_alloc.construct(_root, Node(value_type(), NULL, NULL, NULL, black));
				_nil = _root;
				insert(x.begin(), x.end());
			}
		~set_red_black_tree()
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
			while (t && t->left && t->left != _nil)
			{
				t = t->left;
			}
			return iterator(t, _root, _nil);
		}
		const_iterator begin() const
		{
			node_pointer t = _root;
			while (t && t->left && t->left != _nil)
			{
				t = t->left;
			}
			return const_iterator(t, _root, _nil);
		}
		iterator end()
		{
			if (!_size)
				return begin();
			return iterator(_nil, _root, _nil);
		}
		const_iterator end() const
		{
			if (!_size)
				return begin();
			return const_iterator(_nil, _root, _nil);
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
			iterator it = find(val);
			if (it != end())
			{
				return ft::make_pair(it, false);
			}
			else
			{
				node_pointer node = _alloc.allocate(1);
				_alloc.construct(node, Node(val, NULL, _nil, _nil, red));
				insert_new_node(_root, node);
				_size++;
				return ft::make_pair(iterator(node, _root, _nil), true);
			}
		}
		iterator insert (iterator position, const value_type& val)
		{
			if (find(val) != end())
                return find(val);
			node_pointer node = _alloc.allocate(1);
			_alloc.construct(node, Node(val, NULL, _nil, _nil, red));
			if (_comp(*position, val) == 0)
				insert_new_node(position._n, node);
			else
				insert_new_node(_root, node);
			_size++;
			return iterator(node, _root, _nil);
		}
		template <class InputIterator>
		void insert (InputIterator first, InputIterator last)
		{
			 for (; first != last; ++first)
                insert(*first);
		}
		iterator find (const value_type& val)
		{
			node_pointer node;
			node = _root;
			while (node && node != _nil)
			{
				bool a = _comp(val, node->value);
				bool b = _comp(node->value, val);
				if (!a && !b)
					return iterator(node, _root, _nil);
				if (a == true)
					node = node->left;
				else
					node = node->right;
			}
			return end();
		}
		const_iterator find (const value_type& k) const
		{
			node_pointer node;
			node = _root;
			while (node && node != _nil)
			{
				bool a = _comp(k, node->value);
				bool b = _comp(node->value, k);
				if (!a && !b)
					return const_iterator(node, _root, _nil);
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
			node_pointer tmp;

			if (position == end())
			{
				return ;
			}
			else if (!n->parent)
			{
				_root = deleteNode(n);
				_root->parent = NULL;
				_root->color = black;
				_alloc.destroy(n);
				_alloc.deallocate(n, 1);
				_size--;
				return ;
			}//no child
			else if (n && n->left == _nil
					 && n->right == _nil)
			{
				if (n->parent->left == n)
					n->parent->left = _nil;
				else
					n->parent->right = _nil;
				_alloc.destroy(n);
				_alloc.deallocate(n, 1);
				_size--;
				return ;
			}
			else if (n->parent->left == n)
			{
				tmp = deleteNode(n);
				n->parent->left = tmp;
				tmp->parent = n->parent;
			}
			else
			{
				tmp = deleteNode(n);
				n->parent->right = tmp;
				tmp->parent = n->parent;
			}
			//add balanced part
			if (n->color == black)
			{
				if (tmp->color == red)
					tmp->color = black;
				else if (n->right == _nil)
					delete_case(n);
				else
				{
					delete_case(tmp);
				}
			}
			//till ici
			_alloc.destroy(n);
			_alloc.deallocate(n, 1);
			_size--;
		}
		size_type erase (const value_type& k)
		{
			iterator it = find(k);
			if (it._n == _nil)
				return (0);
			else
			{
				erase(it);
				return (1);
			}
		}

		iterator get_next(iterator it)
		{
			return (++it);
		}

		void erase (iterator first, iterator last)
		{
			while (first != last)
			{
				iterator tmp = get_next(first);
				erase(first);
				first = tmp;
			}
		}
		void swap (_Self& x)
		{
			std::swap(this->_root, x._root);
			std::swap(this->_size, x._size);
			std::swap(this->_nil, x._nil);
		}
		void clear()
		{
			_size = 0;
			if (_nil && _nil != _root)
				deleteTree(_root);
			_nil->parent = NULL;
			_nil->left = NULL;
			_nil->right = NULL;
			_root = _nil;
		}
		void deleteTree(node_pointer node)
		{
			if (node == _nil)
				return ;
			if (node->left)
				deleteTree(node->left);
			if (node->right)
				deleteTree(node->right);
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
		}
		size_type count (const value_type& k) const
		{
			return (find(k) != end());
		}
		iterator lower_bound (const value_type& k)
		{
			iterator it = begin();
			while (it != end())
			{
				if (!_comp(*it, k))
					return (it);
				it++;
			}
			return (end());
		}
		const_iterator lower_bound (const value_type& k) const
		{
			const_iterator it = begin();
			while (it != end())
			{
				if (!_comp(*it, k))//k is not go before
					return (it);
				it++;
			}
			return (end());
		}
		iterator upper_bound (const value_type& k)
		{
			iterator it = begin();
			while (it != end())
			{
				if (_comp(k, *it))
					return (it);
				it++;
			}
			return (end());
		}
		const_iterator upper_bound (const value_type& k) const
		{
			const_iterator it = begin();
			while (it != end())
			{
				if (_comp(k, *it))
					return (it);
				it++;
			}
			return (end());
		}
		ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			return (ft::make_pair<const_iterator,const_iterator>(lower_bound(k), upper_bound(k)));
		}
		ft::pair<iterator, iterator> equal_range (const key_type& k)
			{
				return (ft::make_pair<iterator,iterator>(lower_bound(k), upper_bound(k)));
			}


	private:
		node_pointer deleteNode(node_pointer node)
			{
				if (node->right == _nil)
					return node->left;
				node_pointer x = node->right;
				while(x && x->left != _nil)
					x = x->left;
				if (node->left != _nil)
				{
					x->left = node->left;
					node->left->parent = x;
				}
				return node->right;
			}
		void insert_new_node(node_pointer hint, node_pointer new_node)
		{
			node_pointer x = hint;
			node_pointer xParent = _nil;

			while (x != _nil)
			{
				xParent = x;
				if (_comp(new_node->value, x->value) == true)
					x = x->left;
				else
					x = x->right;
			}
			new_node->parent = xParent;
			if (xParent == _nil)
			{
				_root = new_node;
				_root->parent = NULL;
				_root->color = black;
			}
			else
			{
				if (_comp(new_node->value, xParent->value) == true)
					xParent->left = new_node;
				else
					xParent->right = new_node;
			}
			rb_insert_fixup(new_node);
		}
		void rotate_left(node_pointer n)
		{
			if (n->parent == NULL)
			{
				_root = n;
				return ;
			}
			node_pointer grandparent = n->grandparent();
			node_pointer parent = n->parent;
			node_pointer y = n->left;
			parent->right = y;
			if (y != _nil)
				y->parent = parent;
			n->left = parent;
			parent->parent = n;
			if (_root == parent)
				_root = n;
			n->parent = grandparent;
			if (grandparent != NULL)
			{
				if (grandparent->left == parent)
					grandparent->left = n;
				else
					grandparent->right = n;
			}
		}
		void rotate_right(node_pointer n)
		{
			node_pointer grandparent = n->grandparent();
			node_pointer parent = n->parent;
			node_pointer y = n->right;
			parent->left = y;
			if (y != _nil)
				y->parent = parent;
			n->right = parent;
			parent->parent = n;
			if (_root == parent)
				_root = n;
			n->parent = grandparent;
			if (grandparent != NULL)
			{
				if (grandparent->left == parent)
					grandparent->left = n;
				else
					grandparent->right = n;
			}
		}

		void rb_insert_fixup(node_pointer p)
		{
			//if p is node, just modify color
			if (p->parent == NULL)
			{
				_root = p;
				p->color = black;
				return ;
			}
			if (p->parent->color == red)//if father and unclue both are red, change them + grandpa
			{
				if (p->uncle()->color == red)
				{
					p->parent->color = black;
					p->uncle()->color = black;
					p->grandparent()->color = red;
					rb_insert_fixup(p->grandparent());
				}
				else //if parent is red, uncle is black, there are 2 form
				{
					if (p->parent->right == p && p->grandparent()->left == p->parent)
					{
						rotate_left(p);
						p->color = black;
						p->parent->color = red;
						rotate_right(p);
					}
					else if (p->parent->left == p && p->grandparent()->right == p->parent)
					{
						rotate_right(p);
						p->color = black;
						p->parent->color = red;
						rotate_left(p);
					}
					else if (p->parent->left == p && p->grandparent()->left == p->parent)
					{
						p->parent->color = black;
						p->grandparent()->color = red;
						rotate_right(p->parent);
					}
					else if (p->parent->right == p && p->grandparent()->right == p->parent)
					{
						p->parent->color = black;
						p->grandparent()->color = red;
						rotate_left(p->parent);
					}
				}
			}
		}
		void delete_case(node_pointer tmp)
		{
			if (tmp->parent == NULL)
			{
				tmp->color = black;
				return;
			}
			if (tmp->sibling()->color == red)
			{
				tmp->parent->color = red;
				tmp->sibling()->color = black;
				if (tmp == tmp->parent->left)
					rotate_left(tmp->parent);
				else
					rotate_right(tmp->parent);
			}
			if(tmp->parent->color == black
			   && tmp->sibling()->color == black
               && tmp->sibling()->left->color == black
			   && tmp->sibling()->right->color == black)
			{
				tmp->sibling()->color = red;
				delete_case(tmp->parent);
			}
			else if(tmp->parent->color == red
					&& tmp->sibling()->color == black
					&& tmp->sibling()->left->color == black
					&& tmp->sibling()->right->color == black)
			{
				tmp->sibling()->color = red;
				tmp->parent->color = black;
			}
			else
			{
				if(tmp->sibling()->color == black)
				{
					if(tmp == tmp->parent->left
					   && tmp->sibling()->left->color == red
					   && tmp->sibling()->right->color == black)
					{
						tmp->sibling()->color = red;
						tmp->sibling()->left->color = black;
						rotate_right(tmp->sibling()->left);
					}
					else if(tmp == tmp->parent->right
							&& tmp->sibling()->left->color == black
							&& tmp->sibling()->right->color == red)
					{
						tmp->sibling()->color = red;
						tmp->sibling()->right->color = black;
						rotate_left(tmp->sibling()->right);
					}
				}
				tmp->sibling()->color = tmp->parent->color;
				tmp->parent->color = black;
				if(tmp == tmp->parent->left)
				{
					tmp->sibling()->right->color = black;
					rotate_left(tmp->sibling());
				}
				else
				{
					tmp->sibling()->left->color = black;
					rotate_right(tmp->sibling());
				}
			}
		}
	};

}

#endif
//https://www.tutorialspoint.com/delete-node-in-a-bst-in-cplusplus
//https://zh.wikipedia.org/wiki/%E7%BA%A2%E9%BB%91%E6%A0%91
