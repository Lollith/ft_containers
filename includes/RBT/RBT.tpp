/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:40:32 by agouet            #+#    #+#             */
/*   Updated: 2023/01/25 18:12:47 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// If root == NULL 
//     return NULL;
// If number == root->data 
//     return root->data;
// If number < root->data 
//     return search(root->left)
// If number > root->data 
//     return search(root->right)


//std::less
// Objects of this class can be used on standard algorithms
// returning whether the first argument compares less than the second (x<y)
// class compare = std::less<key> => par deffaut va tier du plus petit au plus grand
// Compare: A binary predicate that takes two element keys as arguments and returns a bool.
//less transmit par map au RBT

namespace ft {
	
//-----------------------------------constructor--------------------------------

template< class Key, class T, class Compare, class Allocator >
RBT<Key, T, Compare, Allocator>::RBT( const Compare &comp, const allocator_type &alloc ){
	_alloc = alloc;
	_comp = comp;
	_null = new RBT_node;
	_root = _null;
	
//ICI
	//...
	
	return ;
}
	
template< class Key, class T, class Compare, class Allocator >
RBT<Key, T, Compare, Allocator>::~RBT( void ){
	return;
}


template< class Key, class T, class Compare, class Allocator >
RBT<Key, T, Compare, Allocator>::RBT( const RBT &copy ){
	*this = copy;
}

template< class Key, class T, class Compare, class Allocator >
RBT<Key, T, Compare, Allocator> &RBT<Key, T, Compare, Allocator>::operator=( const RBT &rhs ){
	if ( this != &rhs )
	{
		_comp = rhs._comp;
		_alloc = rhs._alloc;
		_root = rhs._root;

		//....
		
	}
	return (*this);
}	

//--------------------------------------- rotation -----------------------------


//----------------------------------------affichage ------------------------

template< class Key, class T, class Compare, class Allocator >
void RBT<Key,T, Compare, Allocator>::preOrderHelper	(pt_node node){
	if	(node != _null)
	{
		std::cout << node->_pair_data.first<< " ";
		preOrderHelper(node->_left);
		preOrderHelper(node->_right);
	}
}

}// ft
