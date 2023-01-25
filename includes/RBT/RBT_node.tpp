/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_node.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:16:54 by agouet            #+#    #+#             */
/*   Updated: 2023/01/25 17:50:36 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft{


// template < class T, class Allocator >
// RBT_node< T, Allocator >::RBT_node(const Allocator &alloc){

// 	_value = T();
// 	_color = BLACK;
// 	_left = NULL;
// 	_right = NULL;
// 	_parent = NULL;
// 	_alloc = alloc;
// }

// template < class T, class Allocator >
// RBT_node< T, Allocator >::~RBT_node( void )
// {
// 	_alloc.destroy(&_value);
// }


// template < class T, class Allocator >
// RBT_node< T, Allocator >::RBT_node(RBT_node const &copy)
// {
// 	*this = copy;
// }

// template < class T, class Allocator >
// RBT_node< T, Allocator> &RBT_node< T, Allocator >::operator=(const RBT_node &rhs){
// 	if (this != &rhs )
// 	{
// 		_alloc = rhs._alloc;
// 		_alloc.construct(&_value, rhs._value);
// 		this->_color = rhs._color;
// 		_left = rhs._left;
// 		_right = rhs._right;
// 		_parent = rhs._parent;
// 	}
// 	return (*this);
// }


// template < class T, class Allocator >
// RBT_node< T, Allocator>::RBT_node(const T &value, t_color color, RBT_node *left, RBT_node *right, 
// 	RBT_node *parent, const Allocator &alloc)
// {
// 	_alloc = alloc;
// 	_alloc.construct(&_value, value);
// 	_color = color;
// 	_left = left;
// 	_right = right;
// 	_parent = parent;
// }

//------------------------------------------------------------------------------

// template < class Key, class T >
// RBT_node< Key, T >::RBT_node( void ):_pair_data ( Key(), T()){
// }
//equivalent

template < class Key, class T >
RBT_node< Key, T >::RBT_node( void ){
    _pair_data = ft::make_pair(Key(), T());
	_color = BLACK;
	_left = NULL;
	_right = NULL;
	_parent = NULL;
	_leaf = true;
}

template < class Key, class T >
RBT_node< Key, T >::RBT_node( RBT_node *parent ){
    _pair_data = ft::make_pair(Key(), T());
	_color = BLACK;
	_left = NULL;
	_right = NULL;
	_parent = parent;
	_leaf = true;
	
}

template < class Key, class T >
RBT_node< Key, T >::RBT_node( value_type pair_init ){
	_pair_data = pair_init;
}

template < class Key, class T >
RBT_node< Key, T >::~RBT_node( void ){
}

template < class Key, class T >
RBT_node< Key, T >::RBT_node(RBT_node const &copy){
	*this = copy;
}

template < class Key, class T >
RBT_node< Key, T> &RBT_node< Key, T >::operator=(const RBT_node &rhs){
	if (this != &rhs )
	{
    	_pair_data = rhs._pair_data;
		this->_color = rhs._color;
		_left = rhs._left;
		_right = rhs._right;
		_parent = rhs._parent;
		_leaf = rhs._leaf;
	}
	return (*this);
}



}//ft 