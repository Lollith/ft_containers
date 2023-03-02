/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:05:27 by agouet            #+#    #+#             */
/*   Updated: 2023/03/02 18:20:03 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


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
typedef T										value_type;
typedef Container								container_type;
typedef std::size_t								size_type;
typedef	typename Container::reference			reference;
typedef	typename Container::const_reference		const_reference;	

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

// friend permet d acceder aux attributs protected ou private, 
//attention pour eviter "shadowing" les class doivent etre renomee (Tx par ex)
// et les fct deviennent membres
template <class Tx, class Containerx>  
friend bool operator==( const stack<Tx,Containerx>& lhs, const stack<Tx,Containerx>& rhs );

template <class Tx, class Containerx> 
friend bool operator<( const stack<Tx,Containerx>& lhs, const stack<Tx,Containerx>& rhs );

};

 //------------------------------------non_member-------------------------------
//pas besoin dutilisee l attribut => peuvent rester non membres
template <class T, class Container> 
bool operator!=( const stack<T,Container>& lhs, const stack<T,Container>& rhs );
	
template <class T, class Container>  
bool operator<=( const stack<T,Container>& lhs, const stack<T,Container>& rhs );

template <class T, class Container>  
bool operator>( const stack<T,Container>& lhs, const stack<T,Container>& rhs );

template <class T, class Container>  
bool operator>=( const stack<T,Container>& lhs, const stack<T,Container>& rhs );


}//ft

#include "stack.tpp"

#endif