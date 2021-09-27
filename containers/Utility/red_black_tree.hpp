#ifndef RED_BLACK_TREE_HPP
# define RED_BLACK_TREE_HPP

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
		typedef E                                        value_type;
		typedef Compare                                  key_compare;
		typedef ft::bidirectional_iterator<Node>         iterator;
		typedef ft::Const_Bidirectional_iterator<Node>   const_iterator;
		typedef ft::reverse_iterator<iterator>           reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>     const_reverse_iterator;
		typedef std::ptrdiff_t                           difference_type;
		typedef std::size_t                              size_type;

	private:
		typedef std::allocator<Node>      allocator_type;
		typedef Node*                     node_pointer;
		node_pointer                      _root;
		node_pointer                      _nil;
		size_type                         _size;
		key_compare                       _comp;
		allocator_type                    _alloc;
		typedef red_black_tree<Key, E, Node, Compare>    _Self;


		explicit red_black_tree (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
		{

		}


















	};






}



















#endif
