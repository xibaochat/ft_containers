#ifndef SET_HPP
# define SET_HPP

#include "Utility/main.hpp"

namespace ft
{

	template < class T,  class Compare = ft::less<T>,
			   class Alloc = std::allocator<T> >
	class set //: public set_red_black_tree<T, ft::Node<T>, Compare >
	{
	public:
		typedef T               key_type;
		typedef T               value_type;
		typedef Compare         key_compare;
		typedef Compare         value_compare;
		typedef Alloc           allocator_type;
		typedef value_type&     reference;
		typedef const value_type& const_reference;
		typedef value_type*       pointer;
		typedef const value_type* const_pointer;
		typedef std::size_t                               size_type;
        typedef std::ptrdiff_t                            difference_type;
	private:
//		typedef ft::pair<T, T> E;
		typedef set_red_black_tree<T, ft::Node<T>, Compare> _tree_type;
		typedef set<T, Compare, allocator_type> _Self;
		_tree_type _tree;
		allocator_type _alloc;
	public:
		typedef typename _tree_type::iterator         iterator;
		typedef typename _tree_type::const_iterator   const_iterator;
		typedef typename _tree_type::reverse_iterator reverse_iterator;
		typedef typename _tree_type::const_reverse_iterator const_reverse_iterator;

		explicit set (const key_compare& comp = key_compare(),
					  const allocator_type& alloc = allocator_type()):_tree(comp, alloc){}
		template <class InputIterator>
		set (InputIterator first, InputIterator last,
			 const key_compare& comp = key_compare(),
			 const allocator_type& alloc = allocator_type()):_tree(first, last, comp, alloc){}
		set (const set& x):_tree(x._tree){}
		_Self& operator= (const _Self& x)
		{
			this->_tree = x._tree;
			return (*this);
		}
		~set(){}
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
		pair<iterator, bool> insert(const value_type &val)
        {
            return _tree.insert(val);
        }

		iterator insert(iterator hint, const value_type &val)
			{
				return _tree.insert(hint, val);
			}

        template <typename InputIt>
        void insert(InputIt first, InputIt last)
        {
            _tree.insert(first, last);
        }
		void erase (iterator position)
			{
				_tree.erase(position);
			}
		size_type erase (const value_type& val)
		{
			return _tree.erase(val);
		}
		void erase (iterator first, iterator last)
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
		key_compare key_comp() const
		{
			return Compare();
		}
		value_compare value_comp() const
		{
			return this->key_comp();
		}
		iterator find (const value_type& val)
		{
			return _tree.find(val);
		}
		const_iterator find (const value_type& val) const
		{
			return _tree.find(val);
		}
		size_type count (const value_type& val) const
		{
			return _tree.count(val);
		}
		iterator lower_bound (const value_type& val)
		{
			return _tree.lower_bound(val);
		}
		const_iterator lower_bound (const value_type& val) const
		{
			return _tree.lower_bound(val);
		}
		iterator upper_bound (const value_type& val)
		{
			return _tree.upper_bound(val);
		}
		const_iterator upper_bound (const value_type& val) const
		{
			return _tree.upper_bound(val);
		}
		ft::pair<const_iterator,const_iterator> equal_range (const key_type& k) const
		{
			return _tree.equal_range(k);
		}
		ft::pair<iterator,iterator> equal_range (const key_type& val)
		{
			return _tree.equal_range(val);

		}
		allocator_type get_allocator() const
		{
			return _alloc;
		}
	};

		template<class T, class Compare, class Alloc>
	bool
	operator==(set<T, Compare, Alloc> const& lhs, set<T, Compare, Alloc> const& rhs)
	{
		if (lhs.size() != rhs.size())
			return false;

		return equal(lhs.begin(), lhs.end(), rhs.begin());
	}

	template<class T, class Compare, class Alloc>
	bool
	operator!=(set<T, Compare, Alloc> const& lhs, set<T, Compare, Alloc> const& rhs)
	{
		return !(lhs == rhs);
	}

	template<class T, class Compare, class Alloc>
	bool
	operator<(set<T, Compare, Alloc> const& lhs, set<T, Compare, Alloc> const& rhs)
	{
		return lexicographical_compare(lhs.begin(),
										lhs.end(),
										rhs.begin(),
										rhs.end());
	}

	template<class T, class Compare, class Alloc>
	bool
	operator<=(set<T, Compare, Alloc> const& lhs, set<T, Compare, Alloc> const& rhs)
	{
		return !(rhs < lhs);
	}

	template<class T, class Compare, class Alloc>
	bool
	operator>(set<T, Compare, Alloc> const& lhs, set<T, Compare, Alloc> const& rhs)
	{
		return rhs < lhs;
	}

	template<class T, class Compare, class Alloc>
	bool
	operator>=(set<T, Compare, Alloc> const& lhs, set<T, Compare, Alloc> const& rhs)
	{
		return !(lhs < rhs);
	}

/*                                  Swap                                      */

	template<class T, class Compare, class Alloc>
	void
	swap(ft::set<T, Compare, Alloc>& lhs, ft::set<T, Compare, Alloc>& rhs)
	{
		lhs.swap(rhs);
	}
}























#endif
