/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:40:32 by agouet            #+#    #+#             */
/*   Updated: 2023/01/26 18:05:48 by agouet           ###   ########.fr       */
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

	_leaf = new node_type();
	_root = _leaf;
	
//...	
	return ;
}
	
template< class Key, class T, class Compare, class Allocator >
RBT<Key, T, Compare, Allocator>::~RBT( void ){
    pt_node find = this->_root;

		
	//parcourir l arbre pour delete // A FAIRE	

	
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
//----------------------------------------search -------------------------------
template< class Key, class T, class Compare, class Allocator >
typename RBT<Key, T, Compare, Allocator>::pt_node RBT<Key, T, Compare, Allocator>::searchTree(Key k) {
    return searchTreeHelper(this->_root, k);
  }


template< class Key, class T, class Compare, class Allocator >
typename RBT<Key, T, Compare, Allocator>::pt_node RBT<Key, T, Compare, Allocator>::searchTreeHelper(pt_node node, Key k) {
    if (node == _leaf || k == node->_pair_data.first) {
      return node;
    }

    if (k < node->_pair_data.first) {
      return searchTreeHelper(node->_left, k);
    }
    return searchTreeHelper(node->_right, k);
  }


//--------------------------------------- operations -----------------------------
// inserting a red node does not violate the depth property of a red-black tree.
template< class Key, class T, class Compare, class Allocator >
void RBT<Key, T, Compare, Allocator>::insert( value_type pair_data ){
	pt_node new_node = new node_type(RED, NULL, _leaf, _leaf, pair_data);
	pt_node parent = _leaf;
    pt_node find = this->_root;
// find decend de root tant quil nest pas a leaf et trouve le parent 
	while (find != _leaf) 
	{
    	parent = find;
    	if (new_node->_pair_data.first < find->_pair_data.first) 
    		find = find->_left;
      	else 
        	find = find->_right;
    }
//place le newnode apres le parent
    new_node->_parent = parent;
    if (parent == _leaf) 
	{
		_root = new_node;
		_root->_color = BLACK; //modif ici
    } 
	else if (new_node->_pair_data.first < parent->_pair_data.first) {
      parent->_left = new_node;
    } 
	else {
      parent->_right = new_node;
    }

	if (new_node->_parent->_parent == _leaf)
		return;
	
	// insertFix(new_node); // a faire
}

//----------------------------------------affichage ------------------------

// template< class Key, class T, class Compare, class Allocator >
// void RBT<Key,T, Compare, Allocator>::preOrderHelper	(pt_node node){
// 	if	(node != _null)
// 	{
// 		std::cout << node->_pair_data.first<< " ";
// 		preOrderHelper(node->_left);
// 		preOrderHelper(node->_right);
// 	}
// }



template< class Key, class T, class Compare, class Allocator >
void RBT<Key, T, Compare, Allocator>::display_helper(pt_node &root, std::string indent, bool last)
{
	if(root != _leaf)
	{
		std::cout << indent;
		if(last) 
		{
			std::cout << "R----";
			indent += "    ";
		}
		else
		{
			std::cout << "L----";
			indent += "|    ";
		}
		
		std::string sColor = root->_color ? "RED" : "BLACK";
		std::cout << root->_pair_data.first << "(" << sColor << ")" << std::endl;
		display_helper(root->_left, indent, false);
		display_helper(root->_right, indent, true);
	}
}

template< class Key, class T, class Compare, class Allocator >
void RBT<Key, T, Compare, Allocator>::display( void )
{
	if(_root)
		display_helper(_root, "", true);	
}

}// ft
