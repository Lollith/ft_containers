/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/24 13:05:36 by agouet            #+#    #+#             */
/*   Updated: 2023/02/24 13:05:37 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

namespace ft{

//---------------------------------constructor----------------------------------
// A container adaptor keeps internally a container object as data. This container 
//object is a copy of the ctnr argument passed to the constructor, if any, 
//otherwise it is an empty container.
template <class T, class Container>
stack<T, Container>::stack ( const container_type& ctnr )
{
	c = ctnr;
}

template <class T, class Container>
stack<T, Container>::stack( const stack &other)
{
	c = other.c;
}

template <class T, class Container>
stack<T, Container> &stack<T, Container>::operator=( const stack &other)
{
	c = other.c;
	return *this;
}

template <class T, class Container>
stack<T, Container>::~stack( void ){}

//--------------------------------fct member------------------------------------
template <class T, class Container>
bool stack<T, Container>::empty( void ) const
{
	return (c.empty());
}

template <class T, class Container>
typename stack<T, Container>::size_type stack<T, Container>::size( void ) const
{
	return (c.size());
}

template <class T, class Container>
typename stack<T, Container>::value_type &stack<T, Container>::top( void )
{
	return (c.back());
}

template <class T, class Container>
const typename stack<T, Container>::value_type &stack<T, Container>::top( void ) const
{
	return (c.back());
}

template <class T, class Container>
void stack<T, Container>::push( const value_type &val )
{
	c.push_back(val);
}

template <class T, class Container>
void stack<T, Container>::pop( void )
{
	c.pop_back();
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