/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   random_access_iterator.tpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:55:03 by agouet            #+#    #+#             */
/*   Updated: 2023/01/03 18:00:32 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <iostream>

namespace ft {
//---------------------------------------------constructor----------------------

template < class It >
random_access_iterator<It>::random_access_iterator(void):_current(pointer()){
	std::cout << "empty random it constructor "<< std::endl;
	return;
}

template < class It >
random_access_iterator<It>::random_access_iterator(pointer pt){
	_current = pt;
	return;
}

template< class It>
	template< class U >
random_access_iterator<It>::random_access_iterator( const random_access_iterator<U> &other){
	_current = other.current;
}

template < class It >
random_access_iterator<It>::~random_access_iterator( void ){}


//-------------------------------members----------------------------------------
template < class It >
	template< class U >
random_access_iterator<It> &random_access_iterator<It>::operator=(const random_access_iterator<U> &other){
	_current = other.base();
	return(*this);
}

template < class It >
typename random_access_iterator<It>::pointer random_access_iterator<It>::base() const{
	return (_current);	
}

template < class It >
typename random_access_iterator<It>::reference random_access_iterator<It>::operator*() const{
	return (*this->_current);
}

template < class It >
typename random_access_iterator<It>::pointer random_access_iterator<It>::operator->() const{
	return (&(operator*()));
}

template < class It >
typename random_access_iterator<It>::reference random_access_iterator<It>::operator[]( difference_type n){
	return (_current[n]);
}


template < class It >
random_access_iterator<It> &random_access_iterator<It>::operator++(){
	++_current;
	return(*this);
}

template < class It >
random_access_iterator<It> &random_access_iterator<It>::operator--(){
	--_current;
	return(*this);
}

template < class It >
random_access_iterator<It> random_access_iterator<It>::operator++( int ){
	return(random_access_iterator<It> (++*this));
}

template < class It >
random_access_iterator<It> random_access_iterator<It>::operator--( int ){
	return(random_access_iterator<It> (--*this));
}

template < class It >
random_access_iterator<It> random_access_iterator<It>::operator+( difference_type n ) const{
	return(random_access_iterator<It> (base() + n));
}

template < class It >
random_access_iterator<It> random_access_iterator<It>::operator-( difference_type n ) const{
	return(random_access_iterator<It> (base() - n));
}

template < class It >
random_access_iterator<It> &random_access_iterator<It>::operator+=( difference_type n ) {
	_current += n;
	return(*this);
}

template < class It >
random_access_iterator<It> &random_access_iterator<It>::operator-=( difference_type n ) {
	_current -= n;
	return(*this);
}



}//namesapceft