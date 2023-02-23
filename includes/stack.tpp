namespace ft{

//---------------------------------constructor----------------------------------
// A container adaptor keeps internally a container object as data. This container 
//object is a copy of the ctnr argument passed to the constructor, if any, 
//otherwise it is an empty container.
template <class T, class Container>
stack<T, Container>::stack ( const container_type& ctnr )
{
	_c = ctnr;
}

template <class T, class Container>
stack<T, Container>::stack( const stack &other)
{
	_c = other._c;
}

template <class T, class Container>
stack<T, Container> &stack<T, Container>::operator=( const stack &other)
{
	_c = other._c;
	return *this;
}

template <class T, class Container>
stack<T, Container>::~stack( void ){}

//--------------------------------fct member------------------------------------
template <class T, class Container>
bool stack<T, Container>::empty( void ) const
{
	return (_c.empty());
}

template <class T, class Container>
typename stack<T, Container>::size_type stack<T, Container>::size( void ) const
{
	return (_c.size());
}

template <class T, class Container>
typename stack<T, Container>::value_type &stack<T, Container>::top( void )
{
	return (_c.back());
}

template <class T, class Container>
const typename stack<T, Container>::value_type &stack<T, Container>::top( void ) const
{
	return (_c.back());
}

template <class T, class Container>
void stack<T, Container>::push( const value_type &val )
{
	_c.push_back(val);
}

template <class T, class Container>
void stack<T, Container>::pop( void )
{
	_c.pop_back();
}

//------------------------------------non_member-------------------------------
template< class T, class Container >
inline bool operator==( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
{
	return lhs.c == rhs.c;
}

template< class T, class Container >
inline bool operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
{
	return !(lhs == rhs);
}

template< class T, class Container >
inline bool operator<( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
{
	return lhs.c < rhs.c;
}

template< class T, class Container >
inline bool operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
{
	return !(rhs < lhs);
}

template< class T, class Container >
inline bool operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
{
	return rhs < lhs;
}

template< class T, class Container >
inline bool operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs )
{
	return !(lhs < rhs);
}



}// ft