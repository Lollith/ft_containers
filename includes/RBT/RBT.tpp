/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:40:32 by agouet            #+#    #+#             */
/*   Updated: 2023/02/02 18:46:40 by agouet           ###   ########.fr       */
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
	// _leaf = new node_type(); // ne pas utiliser new cf REBIND , +delete a revoir
  _leaf = _node_alloc.allocate(sizeof(node_type));
  _node_alloc = node_allocator();
  
	_root = _leaf;
	
	return ;
}
	
template< class Key, class T, class Compare, class Allocator >
RBT<Key, T, Compare, Allocator>::~RBT( void ){

	delete_tree( this->_root );           //desalouer et nno dilete
	// delete _leaf;                      /// desalouer et non delete
  _node_alloc.deallocate(_leaf, sizeof(node_type));
	return;
}


template< class Key, class T, class Compare, class Allocator >
RBT<Key, T, Compare, Allocator>::RBT( const RBT &copy ){
	*this = copy;
}

template< class Key, class T, class Compare, class Allocator >
RBT<Key, T, Compare, Allocator> &RBT<Key, T, Compare, Allocator>::operator=( const RBT &rhs )
{
	if ( this != &rhs )
	{
		_comp = rhs._comp;
		_alloc = rhs._alloc;
		// _leaf = new node_type(); // ne pas utiliser NEW  +> cf rebind
  _leaf = _node_alloc.allocate(sizeof(node_type));
  _node_alloc = node_allocator();
		_root = _leaf;
		copy_tree(rhs._root, *this);
	}
	return (*this);
}

//-------------------------------- capacity-----------------------------
		
template< class Key, class T, class Compare, class Allocator >
bool		RBT<Key, T, Compare, Allocator>::empty( void )  const
{
  if (_root == _leaf)
    return (true);
  return (false);
}

template< class Key, class T, class Compare, class Allocator >
void RBT<Key, T, Compare, Allocator>::size_helper( pt_node node, size_t *i ) const
{
    if (node == _leaf)
      return;
    size_helper( node->_left, i);
    size_helper( node->_right, i);
    (*i)++;
}

template< class Key, class T, class Compare, class Allocator >
typename RBT<Key, T, Compare, Allocator>::size_type RBT< Key, T, Compare, Allocator >::size( void ) const
{
    size_type i = 0;
    
	  size_helper( _root, &i);
    return (i);
}


//----------------------------------------search -------------------------------
template< class Key, class T, class Compare, class Allocator >
typename RBT<Key, T, Compare, Allocator>::pt_node RBT<Key, T, Compare, Allocator>::searchTree(Key k) 
{
    return searchTreeHelper(this->_root, k);
}


template< class Key, class T, class Compare, class Allocator >
typename RBT<Key, T, Compare, Allocator>::pt_node RBT<Key, T, Compare, Allocator>::searchTreeHelper(pt_node node, Key k) 
{
    if (node == _leaf || k == node->_pair_data.first)
      return node;
    if (k < node->_pair_data.first)
		  return searchTreeHelper(node->_left, k);
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
void RBT<Key, T, Compare, Allocator>::insert( value_type pair_data )
{
  
	// pt_node new_node = new node_type(RED, NULL, _leaf, _leaf, pair_data) ;/// NEW => rebind
	
	pt_node new_node = _node_alloc.allocate(sizeof(node_type));
  node_alloc.construct(new_node, pair_data);
  new_node->_parent = NULL;
  new_node->_left = _leaf;
  new_node->_right = _leaf;
  new_node->_color = RED;
  
  
  
  
  
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
	
	insert_balancing(new_node);
}

// 1. a fire jusauq ce que le parent du nouveau noeud soit RED
template< class Key, class T, class Compare, class Allocator >
void RBT<Key, T, Compare, Allocator>::insert_balancing(pt_node new_node) 
{
    pt_node u;

    while (new_node->_parent->_color == RED) 
	{
      if (new_node->_parent == new_node->_parent->_parent->_right) 
	  {
        u = new_node->_parent->_parent->_left;
        if (u->_color == RED) 
		{
          u->_color = BLACK;
          new_node->_parent->_color = BLACK;
          new_node->_parent->_parent->_color = RED;
          new_node = new_node->_parent->_parent;
        } 
		else 
		{
          if (new_node == new_node->_parent->_left) {
            new_node = new_node->_parent;
            rightRotate(new_node);
          }
          new_node->_parent->_color = BLACK;
          new_node->_parent->_parent->_color = RED;
          leftRotate(new_node->_parent->_parent);
        }
      }
	   else
	   {
        u = new_node->_parent->_parent->_right;
        if (u->_color == RED) 
		{
          u->_color = BLACK;
          new_node->_parent->_color = BLACK;
          new_node->_parent->_parent->_color = RED;
          new_node = new_node->_parent->_parent;
        } 
		else 
		{
          if (new_node == new_node->_parent->_right) 
		  {
            new_node = new_node->_parent;
            leftRotate(new_node);
          }
          new_node->_parent->_color = BLACK;
          new_node->_parent->_parent->_color = RED;
          rightRotate(new_node->_parent->_parent);
        }
      }
      if (new_node == _root) {
        break;
      }
    }
    _root->_color = BLACK;
}






// si le node supprime est noir => viole les proprietes => reequilibage
// graft = greffon (partie qui va etre transplntee a la place du node supprime), sauvegarde
// https://www.programiz.com/dsa/binary-search-tree : principe de deletion de larbre binaire
template< class Key, class T, class Compare, class Allocator >
void RBT<Key, T, Compare, Allocator>::delete_helper( pt_node nodeToDelete, key_type key )
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
    // delete (to_find);
    _node_alloc.deallocate(to_find, sizeof(node_type));
    if (successor_original_color == 0) 
	{
      delete_balancing(graft);
    }
}


template< class Key, class T, class Compare, class Allocator >
void RBT<Key, T, Compare, Allocator>::delete_balancing(pt_node x) 
{
    pt_node s;
    while (x != _root && x->_color == BLACK) {
      if (x == x->_parent->_left) {
        s = x->_parent->_right;
        if (s->_color == RED) 
		{
          s->_color = BLACK;
          x->_parent->_color = RED;
          leftRotate(x->_parent);
          s = x->_parent->_right;
        }
        if (s->_left->_color == BLACK && s->_right->_color == BLACK) 
		{
          s->_color = RED;
          x = x->_parent;
        } 
		else 
		{
          if (s->_right->_color == BLACK) 
		  {
            s->_left->_color = BLACK;
            s->_color = RED;
            rightRotate(s);
            s = x->_parent->_right;
          }
          s->_color = x->_parent->_color;
          x->_parent->_color = BLACK;
          s->_right->_color = BLACK;
          leftRotate(x->_parent);
          x = _root;
        }
      } 
	  else 
	  {
        s = x->_parent->_left;
        if (s->_color == RED) 
		{
          s->_color = BLACK;
          x->_parent->_color = RED;
          rightRotate(x->_parent);
          s = x->_parent->_left;
        }

        if (s->_right->_color == BLACK && s->_right->_color == BLACK) 
		{
          s->_color = RED;
          x = x->_parent;
        } 
		else 
		{
          if (s->_left->_color == BLACK) {
            s->_right->_color = BLACK;
            s->_color = RED;
            leftRotate(s);
            s = x->_parent->_left;
          }

          s->_color = x->_parent->_color;
          x->_parent->_color = BLACK;
          s->_left->_color = BLACK;
          rightRotate(x->_parent);
          x = _root;
        }
      }
    }
    x->_color = BLACK;
  }




//---------------------------------------------tools----------------------------
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
	while (node_min->_left != _leaf)
		node_min = node_min->_left;
	return (node_min);
}


template< class Key, class T, class Compare, class Allocator >
void RBT<Key, T, Compare, Allocator>::delete_tree(pt_node root)
{
    if (root == _leaf) 
		return;
   	delete_tree(root->_left);
  	delete_tree(root->_right);
    // delete root;
    _node_alloc.deallocate(_leaf, sizeof(node_type));
    root = _leaf;
}

template< class Key, class T, class Compare, class Allocator >
void RBT<Key, T, Compare, Allocator>::copy_tree(pt_node old_root, RBT &new_rbt )
{
    if (old_root == _leaf || !old_root->_left ) 
		return;
   	copy_tree(old_root->_left, new_rbt);
 	copy_tree(old_root->_right, new_rbt);
	new_rbt.insert(old_root->_pair_data);
}

// In right-rotation, the arrangement of the nodes on the left x is transformed into
//  the arrangements on the right node y.
template< class Key, class T, class Compare, class Allocator >
void RBT<Key, T, Compare, Allocator>::rightRotate(pt_node x) 
{
    pt_node y = x->_left;
    x->_left = y->_right;

    if (y->_right != _leaf) 
		y->_right->_parent = x;
    y->_parent = x->_parent;
    if (x->_parent == _leaf)
    	this->_root = y;
	else if (x == x->_parent->_right)
    	x->_parent->_right = y;
	else
    	x->_parent->_left = y;
    y->_right = x;
    x->_parent = y;
}

template< class Key, class T, class Compare, class Allocator >
void RBT<Key, T, Compare, Allocator>::leftRotate(pt_node x)
{
    pt_node y = x->_right;
    x->_right = y->_left;
    if (y->_left != _leaf)
    	y->_left->_parent = x;
    y->_parent = x->_parent;
    if (x->_parent == _leaf)
		this->_root = y;
    else if (x == x->_parent->_left)
    	x->_parent->_left = y;
    else
    	x->_parent->_right = y;
    y->_left = x;
    x->_parent = y;
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

//----------------------------------------getter--------------------------------
template< class Key, class T, class Compare, class Allocator >
void RBT<Key, T, Compare, Allocator>::display( void )
{
	if(_root)
		display_helper(_root, "", true);	
}


template< class Key, class T, class Compare, class Allocator >
void RBT<Key, T, Compare, Allocator>::delete_node( key_type key )
{
	delete_helper( this->_root, key);
}


}// ft
