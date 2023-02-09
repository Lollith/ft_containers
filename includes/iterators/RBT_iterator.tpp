/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_iterator.tpp                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 18:17:50 by agouet            #+#    #+#             */
/*   Updated: 2023/02/09 18:32:35 by agouet           ###   ########.fr       */
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
RBT_iterator< Key, T>::pt_node RBT_iterator< Key, T>::base() const
{
	return _current;
}



}; // ft