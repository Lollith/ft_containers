/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:40:32 by agouet            #+#    #+#             */
/*   Updated: 2023/01/30 18:09:22 by agouet           ###   ########.fr       */
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
	
	delete_tree( _root );
	if (_root == _leaf )
		std::cout << "Tree Successfully Deleted"<< std::endl;
	delete _leaf;
	// _leaf = NULL;
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
		_leaf = rhs._leaf;
		_root = rhs._leaf;

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

// newnode = RED,  childs du newnode = NULL
// find = depart de root => descend  vers leaf
// check if the three is empty (find is NULL?) 
//oui : insert newNode comme Roor et color en Noir
//sinon : compare newkey avec rootkey => traverse larbre a droite / a gauche
//le parent de leaf devient le parent de newnode
//compare leafkey avec newkey =>  newnode devient right oou left child
// reequilibrage = fix larbre

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

// si le node supprime est noir => viole les proprietes => reequilibage
// graft = greffon (partie qui va etre transplntee a la place du node supprime), sauvegarde
// https://www.programiz.com/dsa/binary-search-tree : principe de deletion de larbre binaire
template< class Key, class T, class Compare, class Allocator >
void RBT<Key, T, Compare, Allocator>::delete_helper( pt_node nodeToDelete, int key )
{
	pt_node 	to_find = _leaf;
    pt_node		graft; 
	pt_node		successor;

	//cherche la position ds l arbre du node a supprimer => devient to_find
	// sinon return
    while (nodeToDelete != _leaf) 
	{
     	if (nodeToDelete->_pair_data.first == key) 
      		to_find = nodeToDelete;
    	if (nodeToDelete->_pair_data.first <= key) 
	  		nodeToDelete = nodeToDelete->_right;
		else
        	nodeToDelete = nodeToDelete->_left;
	}
	if (to_find == _leaf) {
      std::cout << "Key not found in the tree" << std::endl;
      return;
    }

	//sauvegarde de la couleur du node a supprimer (car si noire => reequilibage)
	// In case I, the node to be deleted is the leaf node. In such a case, 
	// simply delete the node from the tree.
	// si l enfant_gauche de mon node a suprimer = leaf, j assigne lenfant _droit a x 
	//et transplant x a la place de mon node a supprimer ( remonte ma leaf a la place)
	//case III:	the node to be deleted has two children. In such a case follow the steps below:
	//- Get the inorder successor of that node.(copy)
	//- Replace the node with the inorder successor.
	//- Remove the inorder successor from its original position.
	
	// y prend l valeur de l enfant  le + petit de la sous partie droite de larbre en dessous de mon node a suprimer
	
	//case I : repositionne la _leaf  sur le paarent de mon tofind 
	successor = to_find;
    int successor_original_color = successor->_color;
    if (to_find->_left == _leaf) 
	{
      graft = to_find->_right;
      rbTransplant(to_find, to_find->_right); 
    } 
	else if (to_find->_right == _leaf) 
	{
      graft = to_find->_left;
      rbTransplant(to_find, to_find->_left);
    } 
	//case III
	else 
	{
      successor = minimum(to_find->_right);
      successor_original_color = successor->_color;
      graft = successor->_right;
      if (successor->_parent == to_find)
		graft->_parent = successor;
	  else 
	  {
        rbTransplant(successor, successor->_right);
        successor->_right = to_find->_right;
        successor->_right->_parent = successor;
      }	
	  
	  rbTransplant(to_find, successor);
      successor->_left = to_find->_left;
	  successor->_left->_parent = successor;
      successor->_color = to_find->_color;
    }
    delete (to_find);
    // if (successor_original_color == 0) {
    //   deleteFix(graft);  // A FAIRE
    // }
}




//raccroche l enfant de mon node a supprimer au parent du node
//node->_parent = remonte le prent , _parent->_left => ancienne place de mon node , colle mon child
template< class Key, class T, class Compare, class Allocator >
void RBT<Key, T, Compare, Allocator>::rbTransplant( pt_node node, pt_node child )
{
	if (node->_parent == _leaf) 
      _root = child;
	else if (node == node->_parent->_left) 
      node->_parent->_left = child;
	else 
      node->_parent->_right = child;
	//reassocie mon pointeur parent
    child->_parent = node->_parent;
}

//cherche la Key minimum ( branche la + a guche)
template< class Key, class T, class Compare, class Allocator >
typename RBT<Key, T, Compare, Allocator>::pt_node RBT<Key, T, Compare, Allocator>::minimum( pt_node node_min )
{
	while (node_min->left != _leaf)
		node_min = node_min->_left;
	return (node_min);
}

//---------------------------------------------tools----------------------------
template< class Key, class T, class Compare, class Allocator >
void RBT<Key, T, Compare, Allocator>::delete_tree(pt_node root)
{
    if (root == _leaf) 
		return;
	// if (root->_left)
   	delete_tree(root->_left);
	// if (root->_right)
 	delete_tree(root->_right);
    delete root;
    // root = _leaf;
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

// Le parcours en profondeur d’un arbre binaire non vide consiste à le parcourir 
// récursivement : on parcourt son sous-arbre gauche, puis son sous-arbre droit,
//  sa racine pouvant être traitée au début, entre les deux parcours ou à la fin.


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
