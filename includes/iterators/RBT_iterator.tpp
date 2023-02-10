/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_iterator.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:17:50 by agouet            #+#    #+#             */
/*   Updated: 2023/02/10 16:14:51 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


namespace ft{


template < class Key, class T >
RBT_iterator< Key, T >::RBT_iterator() : _current() {}


template < class Key, class T >
RBT_iterator< Key, T >::RBT_iterator( pt_node input ): _current( input ){}


template < class Key, class T >
RBT_iterator< Key, T>::RBT_iterator( const RBT_iterator &cpy ) { 
	*this = cpy; 
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



//-------------------------- red-black tree const iterator------------------

template < class Key, class T >
RBT_const_iterator< Key, T>::RBT_const_iterator() : _current() {}

template < class Key, class T >
RBT_const_iterator< Key, T>::RBT_const_iterator( pt_node input): _current(input){}

template < class Key, class T >
RBT_const_iterator< Key, T>::RBT_const_iterator(const RBT_const_iterator &cpy) 
{ 
	*this = cpy; 
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
	return (*_current->value_ptr());
}

template < class Key, class T >
typename RBT_const_iterator< Key, T>::pointer RBT_const_iterator< Key, T>::operator->() const
{
	return &(operator*());
}


}; // ft