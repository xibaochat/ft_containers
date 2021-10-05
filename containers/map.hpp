#ifndef MAP_HPP
# define MAP_HPP

#include "Utility/main.hpp"
namespace ft
{
	//           key_type	, mapped_type,  key_compare
 	template<class Key, class T, class Compare = ft::less<Key>,
			 class Allocator = std::allocator<ft ::pair<const Key,T > > >
	class map
	{
	public:
		typedef Key                                       key_type;
		typedef T                                         mapped_type;
		typedef ft::pair<const Key, T>                    value_type;
		typedef Compare                                   key_compare;
		typedef value_type&                               reference;
		typedef const value_type&                         const_reference;
		typedef value_type*                               pointer;
		typedef const value_type*                         const_pointer;
		typedef std::size_t                               size_type;
		typedef std::ptrdiff_t                            difference_type;
		typedef Allocator                                 allocator_type;
	private:
		typedef red_black_tree<Key, value_type, ft::Node<value_type>, Compare> _tree_type;
		typedef map<Key, T, Compare, Allocator> _Self;
		_tree_type     _tree;
		allocator_type _alloc;
	public:
		typedef typename _tree_type::iterator         iterator;
		typedef typename _tree_type::const_iterator   const_iterator;
		typedef typename _tree_type::reverse_iterator reverse_iterator;
		typedef typename _tree_type::const_reverse_iterator const_reverse_iterator;

		key_compare key_comp() const
		{
			return Compare();
		}
//		template <class Key, class T, class Compare, class Alloc>
		class value_compare: std::binary_function<value_type,value_type,bool>
		{
			friend class map;
		protected:
			Compare comp;//obj from std::less
			value_compare (Compare c) : comp(c) {}  // constructed with map's comparison object
		public:
			bool operator() (const value_type& x, const value_type& y) const
     		{
				return comp(x.first, y.first);
  			}
		};

		value_compare value_comp() const
		{
			return value_comp(Compare());
		}
		map (const key_compare& comp = key_compare(),const allocator_type& alloc = allocator_type()):_tree(comp, alloc){}
		template <class InputIt>
		map (InputIt first, InputIt last,
			 const key_compare& comp = key_compare(),
			 const allocator_type& alloc = allocator_type()): _tree(first, last, comp, alloc){}
		map (const map& x):_tree(x._tree){}
		~map(){_tree.clear();}
		_Self &operator=(const _Self &src)
		{
			this->_tree = src._tree;
			return (*this);
		}
		iterator begin()
		{
			return _tree.begin();
		}
		const_iterator begin() const
		{
			return _tree.begin();
		}

		iterator end()
		{
			return _tree.end();
		}

		const_iterator end() const
		{
			return _tree.end();
		}

		reverse_iterator rbegin()
		{
			return _tree.rbegin();
		}

		const_reverse_iterator rbegin() const
		{
			return _tree.rbegin();
		}
		reverse_iterator rend()
		{
			return _tree.rend();
		}

		const_reverse_iterator rend() const
		{
			return _tree.rend();
		}
		bool empty() const
		{
			return _tree.empty();
		}

		size_type size() const
		{
			return _tree.size();
		}
		size_type max_size() const
		{
			return _tree.max_size();
		}
		mapped_type& operator[] (const key_type& k)
		{
			return (*((this->insert(make_pair(k,mapped_type()))).first)).second;
		}
		pair<iterator, bool> insert(const value_type &val)
		{
			return _tree.insert(val);
		}

		iterator insert(iterator hint, const value_type &val)
		{
			return _tree.insert(hint, val).first;
		}

		template <typename InputIt>
		void insert(InputIt first, InputIt last)
		{
			_tree.insert(first, last);
		}

		void erase(iterator position)
		{
			_tree.erase(position);
		}

		size_type erase(const key_type &k)
		{
			return _tree.erase(k);
		}
		void erase(iterator first, iterator last)
		{
			_tree.erase(first, last);
		}
		void swap (_Self& x)
		{
			_tree.swap(x._tree);
		}
		void clear()
		{
			_tree.clear();
		}
		size_type count (const key_type& k) const
		{
			return _tree.count(k);
		}
		ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			return _tree.equal_range(k);
		}
		ft::pair<iterator,iterator> equal_range (const key_type& k)
		{
			return _tree.equal_range(k);
		}
		iterator find (const key_type& k)
		{
			return _tree.find(k);
		}
		const_iterator find (const key_type& k) const
		{
			return _tree.find(k);
		}
		iterator lower_bound (const key_type& k)
		{
			return _tree.lower_bound(k);
		}
		const_iterator lower_bound (const key_type& k) const
		{
			return _tree.lower_bound(k);
		}
		iterator upper_bound (const key_type& k)
		{
			return _tree.upper_bound(k);
		}
		const_iterator upper_bound (const key_type& k) const
		{
			return _tree.upper_bound(k);
		}
		allocator_type get_allocator() const
		{
			return _alloc;
		}
	};
	template <class Key, class T, class Compare, class Alloc>
	bool operator== ( const map<Key,T,Compare,Alloc>& lhs, const map<Key,T,Compare,Alloc>& rhs )
	{
		if (lhs.size() != rhs.size())
			return (false);
		return equal(lhs.begin(), lhs.end(), rhs.begin());
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator!= ( const map<Key,T,Compare,Alloc>& lhs,
					  const map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs == rhs);
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator<  ( const map<Key,T,Compare,Alloc>& lhs,
					  const map<Key,T,Compare,Alloc>& rhs )
	{
		return lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator<= ( const map<Key,T,Compare,Alloc>& lhs,
					  const map<Key,T,Compare,Alloc>& rhs )
	{
		return !(rhs < lhs);
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator>  ( const map<Key,T,Compare,Alloc>& lhs,
					  const map<Key,T,Compare,Alloc>& rhs )
	{
		return rhs < lhs;
	}
	template <class Key, class T, class Compare, class Alloc>
	bool operator>= ( const map<Key,T,Compare,Alloc>& lhs,
					  const map<Key,T,Compare,Alloc>& rhs )
	{
		return !(lhs < rhs);
	}
	template <class Key, class T, class Compare, class Alloc>
	void swap (map<Key,T,Compare,Alloc>& x, map<Key,T,Compare,Alloc>& y)
	{
		x.swap(y);
	}





}

#endif
//https://stackoverflow.com/questions/21476869/constant-pointer-vs-pointer-to-constant
