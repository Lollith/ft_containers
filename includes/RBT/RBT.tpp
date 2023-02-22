/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RBT.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 17:40:32 by agouet            #+#    #+#             */
/*   Updated: 2023/02/22 18:12:42 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// std::less
//  Objects of this class can be used on standard algorithms
//  returning whether the first argument compares less than the second (x<y)
//  class compare = std::less<key> => par deffaut va tier du plus petit au plus grand
//  Compare: A binary predicate that takes two element keys as arguments and returns a bool.
// less transmit par map au RBT

namespace ft
{

  //-----------------------------------constructor--------------------------------

  template <class Key, class T, class Compare, class Allocator>
  RBT<Key, T, Compare, Allocator>::RBT(const Compare &comp, const allocator_type &alloc)
{
	_alloc = alloc;
	_comp = comp;
	// _leaf = new node_type(); // ne pas utiliser new cf REBIND , +delete a revoir
	_leaf = _node_alloc.allocate(sizeof(node_type));
	_leaf_max = _node_alloc.allocate(sizeof(node_type));
	_leaf_min = _node_alloc.allocate(sizeof(node_type));

	_node_alloc.construct(_leaf, pair<Key, T>(0,0) );//????
	_node_alloc.construct(_leaf_min, pair<Key, T>(0,0) );//????
	_node_alloc.construct(_leaf_max, pair<Key, T>(0,0) );//????

	_node_alloc = node_allocator();

	_root = _leaf;

	// intialisation
	_leaf->_color = BLACK;
	_leaf->_left = NULL;
	_leaf->_right = NULL;
	_leaf->_parent = NULL;
	_leaf->_is_leaf = true;

	_leaf_max->_color = BLACK;
	_leaf_max->_left = NULL;
	_leaf_max->_right = NULL;
	_leaf_max->_parent = NULL;
	_leaf_max->_is_leaf = true;

	_leaf_min->_color = BLACK;
	_leaf_min->_left = NULL;
	_leaf_min->_right = NULL;
	_leaf_min->_parent = NULL;
	_leaf_min->_is_leaf = true;

	return;
  }

template <class Key, class T, class Compare, class Allocator>
RBT<Key, T, Compare, Allocator>::~RBT(void)
{
	delete_tree(this->_root); // desalouer et nno dilete
    // delete _leaf;                      /// desalouer et non delete
    _node_alloc.deallocate(_leaf, sizeof(node_type));
    _node_alloc.deallocate(_leaf_min, sizeof(node_type));
    _node_alloc.deallocate(_leaf_max, sizeof(node_type));
// desalooc min max??
	return;
}

template <class Key, class T, class Compare, class Allocator>
RBT<Key, T, Compare, Allocator>::RBT(const RBT &copy)
{
	*this = copy;
}

template <class Key, class T, class Compare, class Allocator>
RBT<Key, T, Compare, Allocator> &RBT<Key, T, Compare, Allocator>::operator=(const RBT &rhs)
{
	if (this != &rhs)
    {
		_comp = rhs._comp;
		_alloc = rhs._alloc;
      // _leaf = new node_type(); // ne pas utiliser NEW  +> cf rebind
		_leaf = _node_alloc.allocate(sizeof(node_type));
    	_leaf_max = _node_alloc.allocate(sizeof(node_type));
    	_leaf_min = _node_alloc.allocate(sizeof(node_type));
		_node_alloc = node_allocator();
		_root = _leaf;
      // intialisation car allocate a la place de new node
		_leaf_max->_color = BLACK;
		_leaf_max->_left = NULL;
		_leaf_max->_right = NULL;
		_leaf_max->_parent = NULL;
		_leaf_max->_is_leaf = true;

		_leaf_min->_color = BLACK;
		_leaf_min->_left = NULL;
		_leaf_min->_right = NULL;
		_leaf_min->_parent = NULL;
		_leaf_min->_is_leaf = true;

	    copy_tree(rhs._root, *this);
    }
    return (*this);
}

  //-------------------------------- capacity-----------------------------

template <class Key, class T, class Compare, class Allocator>
bool RBT<Key, T, Compare, Allocator>::empty(void) const
{
	if (_root->_is_leaf)
		return (true);
	return (false);
}

template <class Key, class T, class Compare, class Allocator>
void RBT<Key, T, Compare, Allocator>::size_helper(pt_node node, size_t *i) const
{
	if (node->_is_leaf)
		return;
	size_helper(node->_left, i);
	size_helper(node->_right, i);
	(*i)++;
}

template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::size_type RBT<Key, T, Compare, Allocator>::size(void) const
{
	size_type i = 0;

	size_helper(_root, &i);
	return (i);
}

template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::size_type RBT<Key, T, Compare, Allocator>::max_size(void) const
{
    return(_node_alloc.max_size()); // utilisation du rebind => allocator <node> a la place du pair
}

  //------------------------modifier----------------------------------

template <class Key, class T, class Compare, class Allocator>
void RBT<Key, T, Compare, Allocator>::clear(void)
{
    delete_tree(_root);
    _root = _leaf;
	_leaf_min->_parent = NULL;
	_leaf_max->_parent = NULL;
}
  
template <class Key, class T, class Compare, class Allocator>
void RBT<Key, T, Compare, Allocator>::swap(RBT & other)
{
	std::swap(_root, other._root);
	std::swap(_leaf, other._leaf);
	std::swap(_leaf_min, other._leaf_min);
	std::swap(_leaf_max, other._leaf_max);
	std::swap(_alloc, other._alloc);
	std::swap(_comp, other._comp);
}

  //----------------------------------------search -------------------------------
template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::pt_node 
RBT<Key, T, Compare, Allocator>::searchTree(Key k)
{
	return searchTreeHelper(this->_root, k);
}

template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::pt_node 
RBT<Key, T, Compare, Allocator>::searchTree(Key const k) const
{
	return searchTreeHelper(this->_root, k);
}

template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::pt_node 
RBT<Key, T, Compare, Allocator>::searchTreeHelper(pt_node node, Key k)
{
	if (node->_is_leaf || k == node->_pair_data.first)
		return (node);
	if (k < node->_pair_data.first)
		return searchTreeHelper(node->_left, k);
    return searchTreeHelper(node->_right, k);
}

template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::pt_node  // surcharge for count
RBT<Key, T, Compare, Allocator>::searchTreeHelper(pt_node node, Key const k) const
{
	if (node->_is_leaf)
		return (NULL); 
	if (k == node->_pair_data.first)
		return (node);
	if (k < node->_pair_data.first)
		return searchTreeHelper(node->_left, k);
    return searchTreeHelper(node->_right, k);
  }
  

template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::iterator 
	RBT<Key, T, Compare, Allocator>::find(const Key &key)
{
	pt_node node_to_find = searchTree(key);

	// std::cout << "find apres seach" << std::endl;
	// std::cout << node_to_find->_pair_data.first << std::endl;
	
	
	// if (node_to_find == _root)
	// {
	// 	return (_root);
	// }
	iterator ret(node_to_find); //creates a new object of type "iterator" and initializes it with the value of "node_to_find".
	return (ret);
}

template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::const_iterator 
	RBT<Key, T, Compare, Allocator>::find(const Key &key) const
{
	pt_node node_to_find = searchTree(key);

	// if (node_to_find == _leaf)
	// 	return (end());
	const_iterator ret(node_to_find);
	return (ret);
}

// Return iterator to lower bound
// Returns an iterator pointing to the first element in the container whose key 
// is not considered to go before k (i.e., either it is equivalent or goes after).
// if = =>return the element whereas upper_bound returns an iterator pointing to the next element.

template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::iterator 
	RBT<Key, T, Compare, Allocator>::lower_bound(const key_type &key)
{
	iterator it = begin();

	while (it._current!= end()._current)  // normale;emt compare it et end()
	{
		if (!_comp(it->first, key)) //?true si a < b
			return it;
		it++;
	}
	return end();
}

template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::const_iterator 
	RBT<Key, T, Compare, Allocator>::lower_bound(const key_type &key) const
{
	const_iterator it = begin();

	while (it._current != end().current)
	{
		if (!_comp(it->first, key)) //?true si a < b
			return it;
		it++;
	}
	return end();
}

template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::iterator 
	RBT<Key, T, Compare, Allocator>::upper_bound(const key_type &key)
{
	iterator it = begin();

	while (it._current!= end()._current)  // normale;emt compare it et end()
	{
		if (_comp(key, it->first)) //?true si a < b
			return it;
		it++;
	}
	return end();
}

template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::const_iterator 
	RBT<Key, T, Compare, Allocator>::upper_bound(const key_type &key) const
{
	const_iterator it = begin();

	while (it._current!= end()._current)  // normale;emt compare it et end()
	{
		if (_comp(key, it->first)) //?true si a < b
			return it;
		it++;
	}
	return end();
}



template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::mapped_type 
	&RBT<Key, T, Compare, Allocator>::access_operator(const key_type& key)
{	
	pt_node searched_node = searchTree(key);
	
	if(!searched_node->_is_leaf)
		return (searched_node->_pair_data.second);
	insert_node(value_type(key, mapped_type()));
	return (searchTree(key)->_pair_data.second);
}

template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::mapped_type& 
	RBT<Key, T, Compare, Allocator>::at (const key_type& key)
{
	pt_node searched_node = searchTree(key);

	if (searched_node->_is_leaf)
		throw std::out_of_range("map::at");
	else
		return searched_node->_pair_data.second;
}


template <class Key, class T, class Compare, class Allocator>
const typename RBT<Key, T, Compare, Allocator>::mapped_type& 
	RBT<Key, T, Compare, Allocator>::at (const key_type& key) const
{
	pt_node searched_node = searchTree(key);

	if (searched_node->_is_leaf)
		throw std::out_of_range("map::at");
	else
		return searched_node->_pair_data.second;
}

//-----------------------observers----------------------------------------------
template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::key_compare 
	RBT<Key, T, Compare, Allocator>::key_comp() const
{
	return (_comp);
}

template <class Key, class T, class Compare, class Allocator>
void RBT<Key, T, Compare, Allocator>::getAllocator( void )
{
	return _alloc;
}
  //--------------------------------------- operations -----------------------------
  // inserting a red node does not violate the depth property of a red-black tree.

  // newnode = RED,  childs du newnode = NULL
  // find = depart de root => descend  vers leaf
  // check if the three is empty (find is NULL?)
  // oui : insert newNode comme Roor et color en Noir
  // sinon : compare newkey avec rootkey => traverse larbre a droite / a gauche
  // le parent de leaf devient le parent de newnode
  // compare leafkey avec newkey =>  newnode devient right oou left child
  // reequilibrage = fix larbre

template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::pt_node 
	RBT<Key, T, Compare, Allocator>::insert_node(value_type pair_data)
{
    // pt_node new_node = new node_type(RED, NULL, _leaf, _leaf, pair_data) ;/// NEW => rebind
    pt_node new_node = _node_alloc.allocate(sizeof(node_type));
    // _node_alloc.construct(new_node, pair_data);
	new_node->_pair_data.first = pair_data.first;
	new_node->_pair_data.second = pair_data.second;
	new_node->_parent = NULL;
	new_node->_left = _leaf;
	new_node->_right = _leaf;
	new_node->_color = RED;
	new_node->_is_leaf = false;
	
	_leaf_max->_pair_data.first = size() + 1;
	_leaf_max->_pair_data.second = 0;
	_leaf_min->_pair_data.first = size() + 1; // defini le _leaf_min pour rend	
	_leaf_min->_pair_data.second = 0;
    
	pt_node parent = NULL;
    pt_node find = this->_root;
    // find decend de root tant quil nest pas a leaf et trouve le parent
    while (!find->_is_leaf)
    {
    	parent = find;
     	if (new_node->_pair_data.first < find->_pair_data.first)
    		find = find->_left;
    	else
      		find = find->_right;
    }
    // place le newnode apres le parent
    new_node->_parent = parent;
    if (parent == NULL)
    {
		_root = new_node;
    	_root->_color = BLACK; // modif ici
    }
    else if (new_node->_pair_data.first < parent->_pair_data.first)
    	parent->_left = new_node;
    else
      parent->_right = new_node;
	
	if (new_node->_parent == NULL)
	{
		new_node->_color = BLACK;
		replace_extremity();
		return new_node;
	}
	  
    if (new_node->_parent->_parent == NULL)
	{
		replace_extremity();
    	return (new_node);
	}
    insert_balancing(new_node);
	replace_extremity();
	return(new_node);
  }


template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::pt_node	
	RBT<Key, T, Compare, Allocator>::insert_node_position( value_type pair_data, iterator position )
{
		 // pt_node new_node = new node_type(RED, NULL, _leaf, _leaf, pair_data) ;/// NEW => rebind
    pt_node new_node = _node_alloc.allocate(sizeof(node_type));
    // _node_alloc.construct(new_node, pair_data);
    new_node->_pair_data.first = pair_data.first;
    new_node->_pair_data.second = pair_data.second;
    new_node->_parent = NULL;
    new_node->_left = _leaf;
    new_node->_right = _leaf;
    new_node->_color = RED;
	new_node->_is_leaf = false;
	_leaf_max->_pair_data.first = size() + 1;
	_leaf_max->_pair_data.second = 0;
	
	_leaf_min->_pair_data.first = size() + 1; // defini le _leaf_min pour rend
	_leaf_min->_pair_data.second = 0;

	iterator tmp = position + 1;
	while (!tmp.base()->_is_leaf && _comp(tmp.base()->_pair_data.first, pair_data.first))
	{
		++position;
		++tmp;
	}
	if (_comp(position.base()->_pair_data.first, pair_data.first))
		position = iterator(_root);
		
	pt_node parent = _leaf;
    pt_node find = this->_root;
    // find decend de root tant quil nest pas a leaf et trouve le parent
     while (!find->_is_leaf)
    {
    	parent = find;
     	if (new_node->_pair_data.first < find->_pair_data.first)
    		find = find->_left;
    	else
      		find = find->_right;
    }
    // place le newnode apres le parent
    new_node->_parent = parent;
    if (parent == NULL)
    {
		_root = new_node;
    	_root->_color = BLACK; // modif ici
    }
    else if (new_node->_pair_data.first < parent->_pair_data.first)
    	parent->_left = new_node;
    else
      parent->_right = new_node;
	
	if (new_node->_parent == NULL)
	{
		new_node->_color =BLACK;
		replace_extremity();
		return new_node;
	}
	  
    if (new_node->_parent->_parent == NULL)
	{
		replace_extremity();
    	return (new_node);
	}
    insert_balancing(new_node);
	replace_extremity();
	return(new_node);
}

template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::iterator 
	RBT<Key, T, Compare, Allocator>::insert_node_pos(iterator position, const value_type &value )
{
	pt_node node_inserted;
	node_inserted = insert_node_position(value, position);
	iterator ret(node_inserted);
	return ret;
}
	
  // 1. a fire jusauq ce que le parent du nouveau noeud soit RED
template <class Key, class T, class Compare, class Allocator>
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
    			if (new_node == new_node->_parent->_left)
    			{
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
      if (new_node == _root)
        break;
    }
    _root->_color = BLACK;
}
  
template <class Key, class T, class Compare, class Allocator>
void RBT<Key, T, Compare, Allocator>::delete_node(key_type key)
{
	delete_helper(this->_root, key);
}

  // si le node supprime est noir => viole les proprietes => reequilibage
  // graft = greffon (partie qui va etre transplntee a la place du node supprime), sauvegarde
  // https://www.programiz.com/dsa/binary-search-tree : principe de deletion de larbre binaire
template <class Key, class T, class Compare, class Allocator>
void RBT<Key, T, Compare, Allocator>::delete_helper(pt_node nodeToDelete, key_type key)
{
    pt_node to_find = _leaf;
    pt_node graft; //greffe
    pt_node successor;

    // cherche la position ds l arbre du node a supprimer => devient to_find
    //  sinon return
    while (!nodeToDelete->_is_leaf) // ou !nodeToDelete->is_leaf
    {
    	if (nodeToDelete->_pair_data.first == key)
        	to_find = nodeToDelete;
      	if (nodeToDelete->_pair_data.first <= key)
        	nodeToDelete = nodeToDelete->_right;
      	else
       		nodeToDelete = nodeToDelete->_left;
    }
    if (to_find->_is_leaf)
    {
    	std::cout << "Key not found in the tree" << std::endl;
    	return;
    }

    // sauvegarde de la couleur du node a supprimer (car si noire => reequilibage)
    //  In case I, the node to be deleted is the leaf node. In such a case,
    //  simply delete the node from the tree.
    //  si l enfant_gauche de mon node a suprimer = leaf, j assigne lenfant _droit a x
    // et transplant x a la place de mon node a supprimer ( remonte ma leaf a la place)
    // case III:	the node to be deleted has two children. In such a case follow the steps below:
    //- Get the inorder successor of that node.(copy)
    //- Replace the node with the inorder successor.
    //- Remove the inorder successor from its original position.

    // y prend l valeur de l enfant  le + petit de la sous partie droite de larbre en dessous de mon node a suprimer

    // case I : repositionne la _leaf  sur le paarent de mon tofind
    successor = to_find;
    int successor_original_color = successor->_color;
    if (to_find->_left == _leaf)
    {
    	graft = to_find->_right;
    	rbTransplant(to_find, to_find->_right);
    }
    else if (to_find->_right->_is_leaf)
    {
    	graft = to_find->_left;
    	rbTransplant(to_find, to_find->_left);
    }
    // case III
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
    if (successor_original_color == BLACK)
    	delete_balancing(graft);
}

template <class Key, class T, class Compare, class Allocator>
void RBT<Key, T, Compare, Allocator>::delete_balancing(pt_node x)
{
    pt_node s;
    while (x != _root && x->_color == BLACK)
    {
		if (x == x->_parent->_left)
		{
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
        		if (s->_left->_color == BLACK)
    		  	{
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

template <class Key, class T, class Compare, class Allocator>
void  RBT<Key, T, Compare, Allocator>::erase_node(iterator position)
{
	pt_node node_to_be_deleted = position._current;
	if (node_to_be_deleted->_left == _leaf_min)
		_leaf_min->_parent = NULL;
	if (node_to_be_deleted->_right == _leaf_max)
		_leaf_max->_parent = NULL;

	delete_node(node_to_be_deleted->_pair_data.first);
	replace_extremity();

			// --_node_count;
}
 
  //---------------------------------------------tools----------------------------
  // raccroche l enfant de mon node a supprimer au parent du node
  // node->_parent = remonte le prent , _parent->_left => ancienne place de mon node , colle mon child
template <class Key, class T, class Compare, class Allocator>
void RBT<Key, T, Compare, Allocator>::rbTransplant(pt_node node, pt_node child)
{
	if (node->_parent == NULL)
		_root = child;
	else if (node == node->_parent->_left)
    	node->_parent->_left = child;
    else
		node->_parent->_right = child;
    // reassocie mon pointeur parent
	child->_parent = node->_parent;
}

  // cherche la Key minimum ( branche la + a guche en fait , peut etre le max si compare est inverse)
template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::pt_node
  RBT<Key, T, Compare, Allocator>::minimum(pt_node node_min) const
{
	if (node_min->_is_leaf)
		return node_min;
	while (!node_min->_left->_is_leaf)
    	node_min = node_min->_left;
    return (node_min);
}
  
template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::pt_node
  RBT<Key, T, Compare, Allocator>::maximum(pt_node node_max) const
{
	if (node_max->_is_leaf)
		return node_max;
	while (!node_max->_right->_is_leaf)
		node_max = node_max->_right;
	return (node_max);
}

template <class Key, class T, class Compare, class Allocator>
void RBT<Key, T, Compare, Allocator>::delete_tree(pt_node root)
{
	if (root->_is_leaf)
    	return;
	delete_tree(root->_left);
	delete_tree(root->_right);
    // delete root;
	_node_alloc.deallocate(root, sizeof(node_type));
	root = _leaf;
}

template <class Key, class T, class Compare, class Allocator>
void RBT<Key, T, Compare, Allocator>::copy_tree(pt_node old_root, RBT &new_rbt)
{
	if (old_root->_is_leaf || !old_root->_left || !old_root->_right)
    	return;
    copy_tree(old_root->_left, new_rbt);
    copy_tree(old_root->_right, new_rbt);
    new_rbt.insert_node(old_root->_pair_data);
}

  // In right-rotation, the arrangement of the nodes on the left x is transformed into
  //  the arrangements on the right node y.
template <class Key, class T, class Compare, class Allocator>
void RBT<Key, T, Compare, Allocator>::rightRotate(pt_node x)
{
	pt_node y = x->_left;
	x->_left = y->_right;
	
	if (!y->_right->_is_leaf)
    	y->_right->_parent = x;
	y->_parent = x->_parent;
	if (x->_parent == NULL)
    	this->_root = y;
	else if (x == x->_parent->_right)
    	x->_parent->_right = y;
	else
    	x->_parent->_left = y;
	y->_right = x;
	x->_parent = y;
}

template <class Key, class T, class Compare, class Allocator>
void RBT<Key, T, Compare, Allocator>::leftRotate(pt_node x)
{
    pt_node y = x->_right;
    x->_right = y->_left;
   
	if (!y->_left->_is_leaf)
    	y->_left->_parent = x;
    y->_parent = x->_parent;
    if (x->_parent == NULL)
    	this->_root = y;
    else if (x == x->_parent->_left)
    	x->_parent->_left = y;
    else
    	x->_parent->_right = y;
    y->_left = x;
    x->_parent = y;
  }

template <class Key, class T, class Compare, class Allocator>
void RBT<Key, T, Compare, Allocator>::replace_extremity( void )
{
	pt_node tmp = minimum(_root);
	if (_leaf_min->_parent)
	{
		// std::cout << "here" << std::endl;
		if (_leaf_min->_parent->_left == _leaf_min)
			_leaf_min->_parent->_left = _leaf;
		// tmp->_left = _leaf_min;
		// _leaf_min->_parent = tmp;
	}
	// else
	// {
	tmp->_left = _leaf_min;
	_leaf_min->_parent = tmp;
	// }
	tmp = maximum(_root);
	if (_leaf_max->_parent)
	{
		if (_leaf_max->_parent->_right == _leaf_max)
			_leaf_max->_parent->_right = _leaf;
	// 	// tmp->_right = _leaf;
	// 	// _leaf_max->_parent = tmp;
	}
	// // else
	// // {
	tmp->_right = _leaf_max;
	_leaf_max->_parent = tmp;
	// // }
  }

  //----------------------------------iterator--------------------------------
  // begin:Returns an iterator referring to the first element in the map container.
  // Because map containers keep their elements ordered at all times, begin points
  // to the element that goes first following the container's sorting criterion.
  // If the container is empty, the returned iterator value shall not be dereferenced.
template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::iterator 
	RBT<Key, T, Compare, Allocator>::begin(void)
{
	pt_node node;

    if (this->empty())
		node = _leaf_min; // null? //-leaf??
	else	
		node = _leaf_min->_parent;
	// std::cout << node->_pair_data.first << std::endl;
	iterator ret(node);
	return ret;
}

template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::const_iterator 
	RBT<Key, T, Compare, Allocator>::begin(void) const
{
	
	pt_node node;
 
    if (this->empty())
		node = _leaf_min; // null? //-leaf??
	else	
		node = _leaf_min->_parent;
	const_iterator ret(node);
	return ret;
}


// Returns an iterator referring to the past-the-end element in the map container.
// The past-the-end element is the theoretical element that would follow the 
// last element in the map container. It does not point to any element, and thus 
//shall not be dereferenced.
// If the container is empty, this function returns the same as map::begin.

// pb : prendre, comme node de fin, le maximum(_root)->right = leaf = or une fois ds LA leaf => impossiblde de 
//remonter de 1 en utilisant les reverse iterator
// template <class Key, class T, class Compare, class Allocator>
// typename RBT<Key, T, Compare, Allocator>::iterator 
// 	RBT<Key, T, Compare, Allocator>::end(void)
// {
// 	pt_node node;

// 	if(_root == _leaf)
// 		return (begin());

// 	node = maximum(_root)->_right;
// 	iterator ret(node);
//     return (ret);			
// }

template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::iterator 
	RBT<Key, T, Compare, Allocator>::end(void)
{
			
	iterator ret(_leaf_max);
	return ret;
}


template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::const_iterator 
	RBT<Key, T, Compare, Allocator>::end(void) const
{
	const_iterator ret(_leaf_max);
    return (ret);			
}


template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::reverse_iterator 
	RBT<Key, T, Compare, Allocator>::rbegin(void)
{
	reverse_iterator ret(end()); // reverse iterator effectue le -1  lorsque dereference
	return (ret);
}

template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::const_reverse_iterator 
	RBT<Key, T, Compare, Allocator>::rbegin(void) const
{
	const_reverse_iterator ret(end());
	return (ret);
}

template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::reverse_iterator 
	RBT<Key, T, Compare, Allocator>::rend(void)
{
	reverse_iterator ret(begin());
	return (ret);
}
	
template <class Key, class T, class Compare, class Allocator>
typename RBT<Key, T, Compare, Allocator>::const_reverse_iterator 
	RBT<Key, T, Compare, Allocator>::rend(void) const
{
	const_reverse_iterator ret(begin());
	return (ret);
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

  template <class Key, class T, class Compare, class Allocator>
  void RBT<Key, T, Compare, Allocator>::display_helper(pt_node &root, std::string indent, bool last)
  {
    if (root != _leaf)
    {
      std::cout << indent;
      if (last)
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
  template <class Key, class T, class Compare, class Allocator>
  void RBT<Key, T, Compare, Allocator>::display(void)
  {
    if (_root)
      display_helper(_root, "", true);
  }


} // ft
