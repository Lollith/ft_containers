/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_iterator.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:17:50 by agouet            #+#    #+#             */
/*   Updated: 2023/02/24 16:38:45 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


namespace ft{


template < class Key, class T >
RBT_iterator< Key, T >::RBT_iterator() : _current() {
}


template < class Key, class T >
RBT_iterator< Key, T >::RBT_iterator( pt_node input ): _current( input ){

}


template < class Key, class T >
RBT_iterator< Key, T>::RBT_iterator( const RBT_iterator &cpy ) { 
	_current = cpy.base();
}
		
template < class Key, class T >
RBT_iterator< Key, T> &RBT_iterator< Key, T >::operator=( const RBT_iterator &other )
{
	_current = other.base();
	return *this;
}


template < class Key, class T >
RBT_iterator< Key, T>::~RBT_iterator ( void ){}


template < class Key, class T >
typename RBT_iterator< Key, T>::pt_node RBT_iterator< Key, T>::base() const
{
	return _current;
}
	
//---------------------------------------operator---------------------------
template < class Key, class T >
typename RBT_iterator< Key, T>::reference RBT_iterator< Key, T>::operator*() const
{
	// return (*_current->&_pair_data); // recoit la copie
	return (*_current->value_ptr()); // recoit l adresse de la copie
}

template < class Key, class T >
typename RBT_iterator< Key, T>::pointer RBT_iterator< Key, T>::operator->() const
{
	return &(operator*());
}

template < class Key, class T >
typename RBT_iterator< Key, T>::iterator &RBT_iterator< Key, T>::operator++()
{
	_current = rb_tree_increment(_current);
	return *this;
}

template < class Key, class T >
typename RBT_iterator< Key, T>::iterator RBT_iterator< Key, T>::operator++(int)
{
	iterator tmp = *this;
	_current = rb_tree_increment(_current);
	return tmp;
}

template < class Key, class T >
typename RBT_iterator< Key, T>::iterator &RBT_iterator< Key, T>::operator--()
{
	_current = rb_tree_decrement(_current);
	return *this;
}

template < class Key, class T >
typename RBT_iterator< Key, T>::iterator RBT_iterator< Key, T>::operator--(int)
{
	iterator tmp = *this;
	_current = rb_tree_decrement(_current);
	return tmp;
}

template < class Key, class T >
typename RBT_iterator< Key, T>::iterator RBT_iterator< Key, T>::operator+( difference_type n ) const
{
	iterator tmp(base());

	for (difference_type i = 0; i != n; ++i)
		tmp++;
	return (tmp);
}

template < class Key, class T >
typename RBT_iterator< Key, T>::iterator RBT_iterator< Key, T>::operator-( difference_type n ) const
{
	iterator tmp(base());

	for (difference_type i = 0; i != n; ++i)
		--tmp;
		
	return (tmp);
}

template < class Key, class T >
bool operator==(const RBT_iterator< Key, T> &lhs, 
	const RBT_iterator< Key, T> &rhs)
{
	if (lhs.base()->_is_leaf && rhs.base()->_is_leaf)
		return true;
	return lhs.base() == rhs.base();
}

template < class Key, class T >
bool operator==( const RBT_iterator< Key, T> &lhs, 
	const RBT_const_iterator< Key, T> &rhs )
{
	if (lhs.base()->_is_leaf && rhs.base()->_is_leaf)
		return true;
	return lhs.base() == rhs.base();
}

template < class Key, class T >
bool operator!=( const RBT_iterator< Key, T> &lhs, 
	const RBT_iterator< Key, T> &rhs )
{
	return !(lhs == rhs);
}

template < class Key, class T >
bool operator!=( const RBT_iterator< Key, T> &lhs, 
	const RBT_const_iterator< Key, T> &rhs )
{
	return !(lhs == rhs);
}

//------------------------------------------------------------------------------
//-------------------------- red-black tree const iterator------------------

template < class Key, class T >
RBT_const_iterator< Key, T>::RBT_const_iterator() : _current() {}

template < class Key, class T >
RBT_const_iterator< Key, T>::RBT_const_iterator( pt_node input): _current(input){}

template < class Key, class T >
RBT_const_iterator< Key, T>::RBT_const_iterator(const RBT_const_iterator &cpy) 
{ 
	_current = cpy.base();
}

template < class Key, class T >
RBT_const_iterator<Key, T> &RBT_const_iterator< Key, T>::operator=( const RBT_const_iterator &other )
{
	_current = other.base();
	return (*this);
}

template < class Key, class T >
RBT_const_iterator< Key, T>::~RBT_const_iterator ( void ){}

template < class Key, class T >
typename RBT_const_iterator< Key, T>::pt_node RBT_const_iterator< Key, T>::base( void ) const
{
	return (_current);
}

//---------------------------------------operator---------------------------
template < class Key, class T >
typename RBT_const_iterator< Key, T>::reference RBT_const_iterator< Key, T>::operator*() const
{
	// return (static_cast<pt_node>(_current)->value_ptr());

	// return ( *(this->_current->value_ptr())); // recoit l adresse de la copie
	// return ((*_current)._pair_data);
	// return (*(_current)->_pair_data); // recoit l adresse de la copie
	// return *_current;
	return(*_current->value_ptr());
}

template < class Key, class T >
typename RBT_const_iterator< Key, T>::pointer RBT_const_iterator< Key, T>::operator->() const
{
	// return (static_cast<pt_node>(_current)->value_ptr());
	// return( (_current)->value_ptr());

	// return _current->value_ptr();	
	return &(operator*());

}

template < class Key, class T >
typename RBT_const_iterator< Key, T>::const_iterator &RBT_const_iterator< Key, T>::operator++()
{
	_current = rb_tree_increment(_current);
	return *this;
}

template < class Key, class T >
typename RBT_const_iterator< Key, T>::const_iterator RBT_const_iterator< Key, T>::operator++(int)
{
	const_iterator tmp = *this;
	_current = rb_tree_increment(_current);
	return tmp;
}

template < class Key, class T >
typename RBT_const_iterator< Key, T>::const_iterator &RBT_const_iterator< Key, T>::operator--()
{
	_current = rb_tree_decrement(_current);
	return *this;
}

template < class Key, class T >
typename RBT_const_iterator< Key, T>::const_iterator RBT_const_iterator< Key, T>::operator--(int)
{
	const_iterator tmp = *this;
	_current = rb_tree_decrement(_current);
	return tmp;
}

template < class Key, class T >
typename RBT_const_iterator< Key, T>::const_iterator RBT_const_iterator< Key, T>::operator+( difference_type n ) const
{
	iterator tmp(base());

	for (difference_type i = 0; i != n; ++i)
		tmp++;
	return (tmp);
}

template < class Key, class T >
typename RBT_const_iterator< Key, T>::const_iterator RBT_const_iterator< Key, T>::operator-( difference_type n ) const
{
	const_iterator tmp(base());

	for (difference_type i = 0; i != n; ++i)
		--tmp;
		
	return (tmp);
}

template < class Key, class T >
bool operator==( const RBT_const_iterator< Key, T> &lhs,
	const RBT_const_iterator< Key, T> &rhs )
{
	if (lhs.base()->_is_leaf && rhs.base()->_is_leaf)
		return true;
	return lhs._current == rhs._current;
}

template < class Key, class T >
bool operator==( const RBT_const_iterator< Key, T> &lhs, 
	const  RBT_iterator< Key, T> &rhs )
{
	if (lhs.base()->_is_leaf && rhs.base()->_is_leaf)
		return true;
	return lhs._current == rhs._current;
}

template < class Key, class T >
bool operator!=( const RBT_const_iterator< Key, T> &lhs, 
	const RBT_const_iterator< Key, T> &rhs )
{
	return !(lhs == rhs);
}

template < class Key, class T >
bool operator!=( const RBT_const_iterator< Key, T> &lhs, 
	const RBT_iterator< Key, T> &rhs )
{
	return !(lhs == rhs);
}



//------------------------------------------------------------------------------
//-------------------------------------no member:helper-------------------------
template < class Key, class T >
RBT_node< Key, T >* helper_rb_tree_increment( RBT_node< Key, T > *node_ptr){
	
	RBT_node<Key, T> *initial_node = node_ptr;
		
		// do nothing if a leaf is atteigned
		if (node_ptr->_is_leaf)
		{
			if (node_ptr->_parent)
				return node_ptr->_parent;
			return node_ptr;
		}
		
		if (!node_ptr->_right->_is_leaf)
		{
			node_ptr = node_ptr->_right;
			while (!node_ptr->_left->_is_leaf)
				node_ptr = node_ptr->_left;
			return node_ptr;
		}
		else
		{
			RBT_node<Key, T> *tmp_node = node_ptr->_parent;
			while (tmp_node &&
				!tmp_node->_is_leaf && 
				node_ptr == tmp_node->_right)
			{
				node_ptr = tmp_node;
				tmp_node = tmp_node->_parent;
			}
			if (tmp_node == NULL)
				return initial_node->_right;
			return tmp_node;
		}
}

template <class Key, class T>
RBT_node<Key, T> *rb_tree_increment( RBT_node<Key, T> *pt_node )
{
	return helper_rb_tree_increment( pt_node );
}

template <class Key, class T>
RBT_node<Key, T> *rb_tree_increment( const RBT_node<Key, T> *pt_node )
{
	return helper_rb_tree_increment( const_cast<RBT_node<Key, T> *>(pt_node) );
}
	


template <class Key, class T>
RBT_node< Key, T>* helper_rb_tree_decrement( RBT_node<Key, T> *current)
{
	RBT_node<Key, T> *initial_node = current;

		// do nothing if a leaf is atteigned, except for end
		if (current->_is_leaf)
		{
			if (current->_parent)
				return current->_parent;
			return current;
		}
		
		if (!current->_left->_is_leaf)
		{
			current = current->_left;
			while (!current->_right->_is_leaf)
				current = current->_right;
			return current;
		}
		else
		{
			RBT_node<Key, T> *tmp_node = current->_parent;
			while (tmp_node && !tmp_node->_is_leaf && current == tmp_node->_left)
			{
				current = tmp_node;
				tmp_node = tmp_node->_parent;
			}
			if (tmp_node == NULL)
				return initial_node->_left;
			return tmp_node;
		}
}

template <class Key, class T>
RBT_node<Key, T> *rb_tree_decrement( RBT_node<Key, T> *pt_node )
{
	return helper_rb_tree_decrement( pt_node );
}

template <class Key, class T>
RBT_node<Key, T> *rb_tree_decrement( const RBT_node<Key, T> *pt_node )
{
	return helper_rb_tree_decrement( const_cast<RBT_node<Key, T> *>(pt_node) );
}


}; // ft