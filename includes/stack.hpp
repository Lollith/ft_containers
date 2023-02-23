
// Stacks are a type of container adaptor, specifically designed to operate in a
// LIFO context (last-in first-out), where elements are inserted and extracted only 
// from one end of the container.

// stacks are implemented as container adaptors, which are classes that use an 
// encapsulated object of a specific container class as its underlying container,
//  providing a specific set of member functions to access its elements. 
//  Elements are pushed/popped from the "back" of the specific container, which is
//   known as the top of the stack

#ifndef STACK_HPP
# define STACK_HPP

#include "vector.hpp"


namespace ft {

template <class T, class Container = ft::vector<T> >
class stack{
	
	
	public:
typedef T								value_type;
typedef Container						container_type;
typedef std::size_t						size_type;
	
	protected:
container_type 							_c;

	public:

// typedef	typename Container::value_type		value_type;
// typedef	typename Container::size_type		size_type;

//---------------------------------constructor----------------------------------
explicit stack (const container_type& ctnr = container_type());
stack( const stack &other);
stack &operator=( const stack &other);
~stack( void );

//--------------------------------fct member------------------------------------
	bool 				empty( void ) const;
	size_type			size( void ) const;
	
	value_type			&top( void );
	const value_type	&top( void ) const;

	void 				push( const value_type& val );
	void		 		pop( void );


};

 //------------------------------------non_member-------------------------------
template <class T, class Container>  
bool operator==( const stack<T,Container>& lhs, const stack<T,Container>& rhs );

template <class T, class Container> 
bool operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs );
	
template <class T, class Container> 
bool operator<( const stack<T,Container>& lhs, const stack<T,Container>& rhs );

template <class T, class Container>  
bool operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs );

template <class T, class Container>  
bool operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs );

template <class T, class Container>  
bool operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs );


}//ft

#include "stack.tpp"

#endif