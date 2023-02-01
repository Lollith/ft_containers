/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:39:39 by agouet            #+#    #+#             */
/*   Updated: 2023/02/01 17:20:01 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft{

//---------------------------constructor// destructor---------------------------
// Constructs an empty container, with no elements.
template < typename K, typename T, typename C, typename A >
map<K, T, C, A>::map(const key_compare& comp, const allocator_type& alloc):_tree(){
	this->_comp = comp;
	this->_alloc = alloc;
}

// Constructs a container with as many elements as the range [first,last), with 
// each element constructed from its corresponding element in that range.
template < typename K, typename T, typename C, typename A >
template < class InputIterator >  
map<K, T, C, A>::map(typename ft::enable_if< !ft::is_integral< InputIterator> ::value, 
	InputIterator>::type first, InputIterator last, const key_compare& comp, 
	const allocator_type& alloc){

		(void) first;
		(void) last;



		//utilisation RBT ici




	this->_comp = comp;
	this->_alloc = alloc;

}


// Constructs a container with a copy of each of the elements in x.
template < typename K, typename T, typename C, typename A >
map<K, T, C, A>::map( const map &copy )
{
	*this = copy;
}

// This destroys all container elements, and deallocates all the storage capacity 
// allocated by the map container using its allocator.
template < typename K, typename T, typename C, typename A >
map< K, T, C, A >::~map( void )
{// ???????????????????????????????
	// clear
	//deallocate
}


//------------------------------operator=---------------------------

template < typename K, typename T, typename C, typename A >
map< K, T, C, A> &map< K, T, C, A>::operator=( const map &rhs ){
	if (this != &rhs)
	{
		// clear()//The elements stored in the container before the call are either assigned to or destroyed.
		this->_alloc= rhs._alloc;
		this->_comp = rhs._comp;
		// iterator????????????????????
		//  insert(other.begin(), other.end());
	}
	return (*this);
}

//----------------------------------------access--------------------------------

// T& operator[](const key_type& x);


}//ft