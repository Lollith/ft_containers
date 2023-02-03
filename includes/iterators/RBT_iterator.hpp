#ifndef RBT_ITERATOR_HPP
#define RBT_ITERATOR_HPP

namespace ft{


template <class Key, class T>
struct RBT_const_iterator; // car present ds ma structure RBT_iterator => ne marche pas

template <class Key, class T>
	struct RBT_iterator
	{
		typedef pair<const Key, T> 							value_type;
		typedef value_type 									&reference;
		typedef value_type 									*pointer;

		typedef std::bidirectional_iterator_tag 			iterator_category;
		typedef std::ptrdiff_t 								difference_type;

		typedef RBT_iterator<Key, T>						iterator;
		typedef RBT_node<Key, T> 							*base_ptr;
		typedef const base_ptr								const_base_ptr;
		typedef RBT_const_iterator<Key, T> 					const_iterator;

		base_ptr node_ptr;

		RBT_iterator()
			: node_ptr() {}

		RBT_iterator(base_ptr node_ptr_input)
			: node_ptr(node_ptr_input) {}

		RBT_iterator(const RBT_iterator & other)
		{
			node_ptr = other.base();
		}

		RBT_iterator & operator=( const RBT_iterator & other )
		{
			node_ptr = other.base();
			return *this;
		}

		base_ptr
		base() const
		{
			return node_ptr;
		}

		// reference
		// operator*() const
		// {
		// 	return *static_cast<base_ptr>(node_ptr)->value_ptr();
		// }

		// pointer
		// operator->() const
		// {
		// 	return static_cast<base_ptr>(node_ptr)->value_ptr();
		// }

		// iterator &
		// operator++()
		// {
		// 	node_ptr = rb_tree_increment(node_ptr);
		// 	return *this;
		// }

		// iterator
		// operator++(int)
		// {
		// 	iterator tmp = *this;
		// 	node_ptr = rb_tree_increment(node_ptr);
		// 	return tmp;
		// }

		// iterator &
		// operator--()
		// {
		// 	node_ptr = rb_tree_decrement(node_ptr);
		// 	return *this;
		// }

		// iterator
		// operator--(int)
		// {
		// 	iterator tmp = *this;
		// 	node_ptr = rb_tree_decrement(node_ptr);
		// 	return tmp;
		// }

		iterator operator+( difference_type n ) const
		{
			iterator tmp(base());

			for (difference_type i = 0; i != n; ++i)
				++tmp;
				
			return (tmp);
		}

		iterator operator-( difference_type n ) const
		{
			iterator tmp(base());

			for (difference_type i = 0; i != n; ++i)
				--tmp;
				
			return (tmp);
		}

		friend bool
		operator==(const iterator &lhs, const iterator &rhs)
		{
			if (lhs.base()->is_nil && rhs.base()->is_nil)
				return true;
			return lhs.node_ptr == rhs.node_ptr;
		}

		friend bool
		operator==(const iterator &lhs, const const_iterator &rhs)
		{
			if (lhs.base()->is_nil && rhs.base()->is_nil)
				return true;
			return lhs.node_ptr == rhs.node_ptr;
		}

		friend bool
		operator!=(const iterator &lhs, const iterator &rhs)
		{
			return !(lhs == rhs);
		}

		friend bool
		operator!=(const iterator &lhs, const const_iterator &rhs)
		{
			return !(lhs == rhs);
		}
	};

	// red-black tree const iterator

	template <class Key, class T>
	struct RBT_const_iterator
	{
		typedef pair<const Key, T> value_type;
		typedef const value_type &reference;
		typedef const value_type *pointer;

		typedef RBT_iterator<Key, T> iterator;

		typedef std::bidirectional_iterator_tag iterator_category;
		typedef std::ptrdiff_t difference_type;

		typedef RBT_const_iterator<Key, T> const_iterator;
		typedef const RBT_node<Key, T> *base_ptr;

		base_ptr node_ptr;

		RBT_const_iterator()
			: node_ptr() {}

		RBT_const_iterator(base_ptr node_ptr_input)
			: node_ptr(node_ptr_input) {}

		RBT_const_iterator(const RBT_const_iterator & other)
			: node_ptr(other.node_ptr) {}

		const_iterator & operator=( const const_iterator & other )
		{
			node_ptr = other.base();
			return *this;
		}

		RBT_const_iterator(const iterator & other)
			: node_ptr(other.node_ptr) {}

		const_iterator & operator=( const iterator & other )
		{
			node_ptr = other.base();
			return *this;
		}

		base_ptr
		base() const
		{
			return node_ptr;
		}

		// reference
		// operator*() const
		// {
		// 	return *static_cast<base_ptr>(node_ptr)->value_ptr();
		// }

		// pointer
		// operator->() const
		// {
		// 	return static_cast<base_ptr>(node_ptr)->value_ptr();
		// }

		// const_iterator &
		// operator++()
		// {
		// 	node_ptr = rb_tree_increment(node_ptr);
		// 	return *this;
		// }

		// const_iterator
		// operator++(int)
		// {
		// 	const_iterator tmp = *this;
		// 	node_ptr = rb_tree_increment(node_ptr);
		// 	return tmp;
		// }

		// const_iterator &
		// operator--()
		// {
		// 	node_ptr = rb_tree_decrement(node_ptr);
		// 	return *this;
		// }

		// const_iterator
		// operator--(int)
		// {
		// 	const_iterator tmp = *this;
		// 	node_ptr = rb_tree_decrement(node_ptr);
		// 	return tmp;
		// }

		const_iterator operator+( difference_type n ) const
		{
			const_iterator tmp(base());

			for (difference_type i = 0; i != n; ++i)
				++tmp;
				
			return (tmp);
		}

		const_iterator operator-( difference_type n ) const
		{
			const_iterator tmp(base());

			for (difference_type i = 0; i != n; ++i)
				--tmp;
				
			return (tmp);
		}

		friend bool
		operator==(const const_iterator &lhs, const const_iterator &rhs)
		{
			if (lhs.base()->is_nil && rhs.base()->is_nil)
				return true;
			return lhs.node_ptr == rhs.node_ptr;
		}

		friend bool
		operator==(const const_iterator &lhs, const iterator &rhs)
		{
			if (lhs.base()->is_nil && rhs.base()->is_nil)
				return true;
			return lhs.node_ptr == rhs.node_ptr;
		}

		friend bool
		operator!=(const const_iterator &lhs, const const_iterator &rhs)
		{
			return !(lhs == rhs);
		}

		friend bool
		operator!=(const const_iterator &lhs, const iterator &rhs)
		{
			return !(lhs == rhs);
		}

		
	};






}//ft
#include "RBT_iterator.tpp"
#endif
