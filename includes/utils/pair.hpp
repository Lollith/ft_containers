/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pair.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 11:10:39 by agouet            #+#    #+#             */
/*   Updated: 2023/01/24 16:03:57 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//This class couples together a pair of values, which may be of different types 
//(T1 and T2). The individual values can be accessed through its public members 
//first and second.
// Pairs are a particular case of tuple:
// A tuple is an object capable to hold a collection of elements. 
// Each element can be of a different type.

#ifndef PAIR_HPP
# define PAIR_HPP

namespace ft{

	template <class T1, class T2> 
	struct pair{ // struc car pas besoin de declarer de private, ms class marche
		typedef	T1		first_type;
		typedef	T2		second_type;

		first_type 		first;
		second_type 	second;
		
	//(1)
	pair() : first(first_type()), second(second_type()){ };
	
	//(2) copy / move constructor (and implicit conversion)
	template<class U, class V>
	pair (const pair<U,V>& pr): first(pr.first), second(pr.second){ }

	//(3) initialization constructor
	pair(const first_type a, const second_type b): first(a), second(b){ };
	

	~pair(){ };
	
	
	pair& operator=( const pair& pr )
	{
		if( this != &pr )
		{
			this->first = pr.first;
			this->second = pr.second;
		}
		return (*this);
	}
	
	};



	//-------------------------relational operators (pair)----------------------
template <class T1, class T2>
bool operator==( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ){ 
	return (lhs.first == rhs.first && lhs.second == rhs.second); 
}

template <class T1, class T2>
bool operator!=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ){
	return (!(lhs == rhs)); 
}

template <class T1, class T2>
bool operator<( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ){ 
	return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second)); 
}

template <class T1, class T2>
bool operator<=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ){
	return (!(rhs < lhs)); 
}

template <class T1, class T2>
bool operator>( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ){
	return ( rhs < lhs);
}

template <class T1, class T2>
bool operator>=( const pair<T1,T2>& lhs, const pair<T1,T2>& rhs ){
return (!(lhs<rhs)); 
}

	
} // ft

#endif