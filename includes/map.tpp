/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.tpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 10:39:39 by agouet            #+#    #+#             */
/*   Updated: 2023/02/09 14:53:488 agouet           ###   ########.fr       */
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
	const allocator_type& alloc):_tree(){
std::cout <<"constructor range"<< std::endl;
	this->_comp = comp;
	this->_alloc = alloc;
	for(; first != last; first++)
		_tree.insert_node(*first);


}


// Constructs a container with a copy of each of the elements in x.
template < typename K, typename T, typename C, typename A >
map<K, T, C, A>::map( const map &copy )
{
				// this->insert(copy.begin(), copy.end());
	*this = copy;
	// for (const_iterator it = copy.begin(); it != copy.end(); ++it) 
				// _tree.insert_node(*it);
	// 		}
}

// This destroys all container elements, and deallocates all the storage capacity 
// allocated by the map container using its allocator.
template < typename K, typename T, typename C, typename A >
map< K, T, C, A >::~map( void )
{
	clear();
	//deallocate
}

//------------------------------operator=---------------------------

template < typename K, typename T, typename C, typename A >
map< K, T, C, A> &map< K, T, C, A>::operator=( const map &rhs ){
	if (this != &rhs)
	{
		std::cout << "operator="<<std::endl;
		// std::cout << rhs.begin()._current->_pair_data.first<<std::endl;
		// clear();//The elements stored in the container before the call are either assigned to or destroyed.
		for (const_iterator it = rhs.begin(); it != rhs.end(); ++it) 
			_tree.insert_node(it._current->_pair_data);
			// _tree.insert_node(*it);
		this->_alloc= rhs._alloc;
		this->_comp = rhs._comp;
		// map(rhs.begin(), rhs.end());
		// this->insert(rhs.begin(), rhs.end());
		// _tree.insert_node(rhs.begin());
	}
	return (*this);
}

//-------------------------------------iterators--------------------------------
template < typename K, typename T, typename C, typename A >
typename map< K, T, C, A>::iterator map< K, T, C, A>::begin( void )
{
	return (_tree.begin());
}

template < typename K, typename T, typename C, typename A >
typename map< K, T, C, A>::const_iterator map< K, T, C, A>::begin( void ) const
{
	return (_tree.begin());
}

template < typename K, typename T, typename C, typename A >
typename map< K, T, C, A>::iterator map< K, T, C, A>::end( void )
{
	return (_tree.end());
}

template < typename K, typename T, typename C, typename A >
typename map< K, T, C, A>::const_iterator map< K, T, C, A>::end( void ) const
{
	return (_tree.end());
}

template < typename K, typename T, typename C, typename A >
typename map< K, T, C, A>::reverse_iterator map< K, T, C, A>::rbegin( void )
{
	return ( _tree.rbegin());
}

template < typename K, typename T, typename C, typename A >
typename map< K, T, C, A>::const_reverse_iterator map< K, T, C, A>::rbegin( void ) const
{
	return ( _tree.rbegin());
}

template < typename K, typename T, typename C, typename A >
typename map< K, T, C, A>::reverse_iterator map< K, T, C, A>::rend( void )
{
	return ( _tree.rend());
}

template < typename K, typename T, typename C, typename A >
typename map< K, T, C, A>::const_reverse_iterator map< K, T, C, A>::rend( void ) const
{
	return (_tree.rend());
}


//----------------------------capacity------------------------------
		
template < typename K, typename T, typename C, typename A >
bool map< K, T, C, A >::empty( void ) const{
	return( _tree.empty() );	
}

template < typename K, typename T, typename C, typename A >
typename map< K, T, C, A >::size_type map< K, T, C, A>::size( void ) const
{
	return ( _tree.size() );
}
		
template < typename K, typename T, typename C, typename A >
typename map< K, T, C, A >::size_type map< K, T, C, A>::max_size( void ) const
{
	return ( _tree.max_size() );
}

//----------------------------------------access--------------------------------
// if k matches the key of an element in the container, the function returns a 
//reference to its mapped value.
// If k does not match the key of any element in the container, the function 
//inserts a new element with that key and returns a reference to its mapped value.
// Notice that this always increases the container size by one, even if no mapped 
//value is assigned to the element (the element is constructed using its default constructor).

// A similar member function, map::at, has the same behavior when an element 
//with the key exists, but throws an exception when it does not.

template < typename K, typename T, typename C, typename A >
typename map< K, T, C, A >::mapped_type &map< K, T, C, A >::operator[](const key_type& key){
	return(_tree.access_operator(key));
}


template < typename K, typename T, typename C, typename A >
typename map< K, T, C, A >::mapped_type &map< K, T, C, A >::at(const key_type& key){
	return(_tree.at(key));
}

template < typename K, typename T, typename C, typename A >
const typename map< K, T, C, A >::mapped_type &map< K, T, C, A >::at (const key_type& key) const{
	return(_tree.at(key));

}

//------------------------------------modifier----------------------------------

template < typename K, typename T, typename C, typename A >
void map< K, T, C, A >::clear( void )
{
	_tree.clear();
}

// Extends the container by inserting new elements, effectively increasing the 
// container size by the number of elements inserted.
// Because element keys in a map are unique, the insertion operation checks
// whether each inserted element has a key equivalent to the one of an element already in the container, and if so, the element is not inserted, returning an iterator to this existing element (if the function returns a value).
//1
template < typename K, typename T, typename C, typename A >
ft::pair<typename map< K,T ,C ,A >::iterator, bool> 
	map< K, T, C, A >::insert( const value_type &value )
{
	ft::pair<iterator, bool> ret;                                            
	iterator searched_key = find( value.first );
	// find return un iterator sur le 1er element

// 	// // if map is empty, insert the node
	if (empty())
	{
		ret.first = _tree.insert_node(value);
		ret.second = true;
	}
// 	// // key found -> no duplicate allowed
	else if (!searched_key.base()->_is_leaf)
	{
		ret.first = searched_key;
		ret.second = false;
	}
// 	// // no key found, proceed with inserting the node
	else
	{
		ret.first = _tree.insert_node(value);
		ret.second = true;
	}
	return ret;
}
// An alternative way to insert elements in a map is by using member function map::operator[].


template < typename K, typename T, typename C, typename A >
template <class InputIterator>
void map< K, T, C, A >::insert(InputIterator first, InputIterator last)
{
	for(;first != last; first++)
		_tree.insert_node(*first);
}

template < typename K, typename T, typename C, typename A >
typename map< K ,T ,C ,A >::iterator map< K ,T ,C ,A >::insert(iterator position, const value_type& value)
{
	iterator searched_key = find(value.first);
	if (empty())
		return (_tree.insert_node(value));
	else if (!searched_key.base()->_is_leaf)
		return (searched_key);
	else
		return (_tree.insert_node_pos(position, value));
}

template < typename Key, typename T, typename C, typename A >
void map< Key ,T ,C ,A >::swap(map<Key,T,C,A>&other)
{
	_tree.swap(other._tree);
}

//erase
// Removes from the map container either a single element or a range of elements ([first,last)).
// This effectively reduces the container size by the number of elements removed,
// which are destroyed.
template < typename Key, typename T, typename C, typename A >
void  map< Key ,T ,C ,A >::erase(iterator position)
{
	_tree.erase_node(position);
}

template < typename Key, typename T, typename C, typename A >
typename map< Key ,T ,C ,A >::size_type map< Key ,T ,C ,A >::erase(const key_type& key)
{
	iterator searched_key = find(key);
	if (empty())
		return (0);
	else if (!searched_key.base()->_is_leaf)
	{
		erase(searched_key);
		return(1);
	}
	else
		return 0;
}

template < typename Key, typename T, typename C, typename A >
void  map< Key ,T ,C ,A >::erase(iterator first, iterator last)
{
	iterator tmp;
	iterator it = first;

	while (it != last)
	{
		tmp = it + 1;
		erase (it);
		it = tmp;
	}
}



//-----------------------observers----------------------------------------------
template < typename Key, typename T, typename C, typename A >
typename map< Key ,T ,C ,A >::key_compare map< Key ,T ,C ,A >::key_comp() const
{
	return _tree.key_comp();
}

template < typename Key, typename T, typename C, typename A >
typename map< Key ,T ,C ,A >::value_compare	map< Key ,T ,C ,A >::value_comp() const
{
	return (value_compare(_tree.key_comp()));
}

//---------------------------------------------operations-----------------------
// Searches the container for an element with a key equivalent to k and returns an 
// iterator to it if found, otherwise it returns an iterator to map::end.

template < typename Key, typename T, typename C, typename A >
typename map< Key ,T ,C ,A >::iterator	map< Key, T, C, A >::find(const Key &k){
	return (_tree.find(k));
}

template < typename Key, typename T, typename C, typename A >
typename map< Key ,T ,C ,A >::const_iterator map< Key, T, C, A >::find(const Key &k) const{
	return (_tree.find(k));
}
// Searches the container for elements with a key equivalent to k and returns 
//the number of matches.Because all elements in a map container are unique, the 
//function can only return 1 (if the element is found) or zero (otherwise).
// Two keys are considered equivalent if the container's comparison object returns 
// false reflexively (i.e., no matter the order in which the keys are passed as arguments).
template < typename Key, typename T, typename C, typename A >
typename map< Key ,T ,C ,A >::size_type map< Key ,T ,C ,A >::count(const Key& key) const
{
	if(_tree.searchTree(key))
		return 1;
	return 0;
}

template < typename Key, typename T, typename C, typename A >
typename map< Key ,T ,C ,A >::iterator map< Key ,T ,C ,A >::lower_bound(const key_type& key) 
{
	return _tree.lower_bound(key);
}

template < typename Key, typename T, typename C, typename A >
typename map< Key ,T ,C ,A >::const_iterator map< Key ,T ,C ,A >::lower_bound(const key_type& key) const 
{
	return _tree.lower_bound(key);
}


template < typename Key, typename T, typename C, typename A >
typename map< Key ,T ,C ,A >::iterator map< Key ,T ,C ,A >::upper_bound(const key_type& key)
{
	return _tree.upper_bound(key);
}

template < typename Key, typename T, typename C, typename A >
typename map< Key ,T ,C ,A >::const_iterator map< Key ,T ,C ,A >::upper_bound(const key_type&key) const
{
	return _tree.upper_bound(key);
}

	
template < typename Key, typename T, typename C, typename A >
ft::pair<typename  map< Key ,T ,C ,A >::iterator, typename  map< Key ,T ,C ,A >::iterator> 
	map< Key ,T ,C ,A >::equal_range(const key_type& key)
{
	pair<iterator,iterator> ret(lower_bound(key), upper_bound(key));
	return ret;
}

template < typename Key, typename T, typename C, typename A >
ft::pair<typename  map< Key ,T ,C ,A >::const_iterator, typename  map< Key ,T ,C ,A >::const_iterator> 
	map< Key ,T ,C ,A >::equal_range(const key_type& key) const
{
	pair<const_iterator,const_iterator> ret(lower_bound(key), upper_bound(key));
	return ret;
}

//--------------------------------allocator-------------------------
template< class Key, class T, class C, class A >
typename map< Key ,T ,C ,A >::allocator_type map< Key ,T ,C ,A >::get_allocator() const
{
	return _tree.getAllocator();
}

//-----------------------------------------operator-----------------------------
template< class Key, class T, class Compare, class Alloc >
inline bool operator==( const ft::map<Key,T,Compare,Alloc>& lhs, 
	const ft::map<Key,T,Compare,Alloc>& rhs)
{
	return !(rhs < lhs) && !(lhs < rhs);
}

template< class Key, class T, class Compare, class Alloc >
inline bool operator!=( const ft::map<Key,T,Compare,Alloc>& lhs, 
	const ft::map<Key,T,Compare,Alloc>& rhs)
{
	return !(lhs == rhs);
}

template< class Key, class T, class Compare, class Alloc >
inline bool operator<( const ft::map<Key,T,Compare,Alloc>& lhs, 
	const ft::map<Key,T,Compare,Alloc>& rhs)
{
	return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
}

template< class Key, class T, class Compare, class Alloc >
inline bool operator<=( const ft::map<Key,T,Compare,Alloc>& lhs, 
	const ft::map<Key,T,Compare,Alloc>& rhs)
{
	return !(rhs < lhs);
}

template< class Key, class T, class Compare, class Alloc >
inline bool operator>( const ft::map<Key,T,Compare,Alloc>& lhs, 
	const ft::map<Key,T,Compare,Alloc>& rhs)
{
	return rhs < lhs;
}

template< class Key, class T, class Compare, class Alloc >
inline bool operator>=( const ft::map<Key,T,Compare,Alloc>& lhs, 
	const ft::map<Key,T,Compare,Alloc>& rhs)
{
	return !(lhs < rhs);
}

template< class Key, class Compare, class Alloc >
void swap( ft::map<Key,Compare,Alloc>& lhs, ft::map<Key,Compare,Alloc>& rhs )
{
	lhs.swap(rhs);
}






}//ft