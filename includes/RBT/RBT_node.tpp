/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT_node.tpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lollith <lollith@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 14:16:54 by agouet            #+#    #+#             */
/*   Updated: 2023/02/10 15:44:29 by lollith          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft{

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
	_is_leaf = true;
}

// template < class Key, class T >
// RBT_node< Key, T >::RBT_node( RBT_node *parent ){
//     _pair_data = ft::make_pair(Key(), T());
// 	_color = BLACK;
// 	_left = NULL;
// 	_right = NULL;
// 	_parent = parent;
// 	// _leaf = true;
	
// }


// template < class Key, class T >
// RBT_node< Key, T >::RBT_node( t_color color, RBT_node *parent, RBT_node *left, RBT_node *right, value_type pair_data ){
// 	_pair_data = pair_data;
// 	_color = color;
// 	_left = left;
// 	_right = right;
// 	_parent = parent;
// }

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
	}
	return (*this);
}

template < class Key, class T >
typename RBT_node< Key, T>::value_type *RBT_node< Key, T>::value_ptr()
{
	value_type *tmp;
	tmp = &_pair_data;
	return (tmp); // fait une copie de l adresse => pointe vers le meme objet
}

template < class Key, class T >
const typename RBT_node< Key, T>::value_type *RBT_node< Key, T>::value_ptr() const
{
	return &(_pair_data);
}




}//ft 