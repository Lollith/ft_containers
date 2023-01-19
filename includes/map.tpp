namespace ft{

//---------------------------constructor// destructor---------------------------
// Constructs an empty container, with no elements.
template < typename K, typename T, typename C, typename A >
explicit map<K, T, C, A>::map(const key_compare& comp, const allocator_type& alloc){
	this->_comp = comp;
	this->_alloc = alloc;
}
// Constructs a container with as many elements as the range [first,last), with 
// each element constructed from its corresponding element in that range.
template < typename K, typename T, typename C, typename A >
template < class InputIterator >  
map<K, T, C, A>::map(typename enable_if< !ft::is_integral< InputIterator> ::value, 
	InputIterator>::type first, InputIterator last, const key_compare& comp, 
	const allocator_type& alloc){



		//utilisation RBT ici




	this->_comp = comp;
	this->_alloc = alloc;

}


// Constructs a container with a copy of each of the elements in x.
template < typename K, typename T, typename C, typename A >
map<K, T, C, A>::map(const map &copy)
{
	*this = copy;
}

// This destroys all container elements, and deallocates all the storage capacity 
// allocated by the map container using its allocator.
template < typename K, typename T, typename C, typename A >
map< K, T, C, A >::~map( void )
(
	// ???????????????????????????????
	// clear
	//deallocate
)


//------------------------------operator=---------------------------

template < typename K, typename T, typename C, typename A >
map< K, T, C, A>::map& operator=( const map &rhs ){
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



}//ft