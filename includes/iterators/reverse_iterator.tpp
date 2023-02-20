/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_iterator.tpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:26:42 by agouet            #+#    #+#             */
/*   Updated: 2023/02/20 15:02:06 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

//&*(reverse_iterator(i)) == &*(i - 1).

namespace ft {

//----------------------------------------constructor---------------------------	
template < typename Iterator >
reverse_iterator<Iterator>::reverse_iterator(): _current(){}

template < typename Iterator >
reverse_iterator<Iterator>::reverse_iterator(iterator_type it): _current(it.base()){}


template < typename Iterator >
template <class U> 
reverse_iterator<Iterator>::reverse_iterator(const reverse_iterator<U>& u): _current(u.base()){}

template < typename Iterator >
reverse_iterator<Iterator>::reverse_iterator( pointer ptr ): _current( ptr ) {}

template < typename Iterator >
template < class U > 
reverse_iterator<Iterator> &reverse_iterator<Iterator>::operator=( const reverse_iterator<U> &rhs ){
	this->_current = rhs.base();
	return (*this);
}

//----------------------------------------mber----------------------------------	

template < typename Iterator >
typename reverse_iterator<Iterator>::iterator_type reverse_iterator<Iterator>::base() const {
	return (_current);
}

template < typename Iterator >
typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator*() const{
	return (*(_current - 1));
}

template < typename Iterator >
typename reverse_iterator<Iterator>::pointer reverse_iterator<Iterator>::operator->() const{
	return (&(operator*()));
}

template < typename Iterator >
reverse_iterator<Iterator> &reverse_iterator<Iterator>::operator++(){
	--_current;
	return (*this);
}

template < typename Iterator >
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator++(int){
	reverse_iterator tmp = *this;
	--_current;
	return (tmp);
}

template < typename Iterator >
reverse_iterator<Iterator> &reverse_iterator<Iterator>::operator--(){
	++_current;
	return (*this);
}

template < typename Iterator >
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator--(int){
	reverse_iterator tmp = *this;
	++_current;
	return (tmp);
}

template < typename Iterator >
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator+(difference_type n) const{
	return (reverse_iterator (_current - n));
}

template < typename Iterator >
reverse_iterator<Iterator> &reverse_iterator<Iterator>::operator+=(difference_type n){
	_current -= n;
	return (*this);	
}

template < typename Iterator >
reverse_iterator<Iterator> reverse_iterator<Iterator>::operator-(difference_type n) const{
	return (reverse_iterator (_current + n));
}

template < typename Iterator >
reverse_iterator<Iterator> &reverse_iterator<Iterator>::operator-=(difference_type n){
	_current += n;
	return (*this);	
}

template < typename Iterator >
typename reverse_iterator<Iterator>::reference reverse_iterator<Iterator>::operator[](difference_type n) const{
	return (*(_current - 1 - n));
}

//----------------------------------------non mber------------------------------	
//Le mot clé inline indique au compilateur de substituer le code dans la définition 
//de fonction pour chaque instance d'un appel de fonction.
//L'utilisation des fonctions inline permet accélérer l'exécution de votre programme, 
//car celles-ci éliminent la surcharge associée aux appels de fonction

template < typename Iterator1, typename Iterator2 >
inline bool operator==(const reverse_iterator<Iterator1>& lhs, 
	const reverse_iterator<Iterator2>& rhs){
	return (lhs.base() == rhs.base());
}

template < typename Iterator1, typename Iterator2 >
inline bool operator<(const reverse_iterator<Iterator1>& lhs, 
	const reverse_iterator<Iterator2>& rhs){
	return (lhs.base() > rhs.base());
}

template < typename Iterator1, typename Iterator2 >
inline bool operator!=( const reverse_iterator<Iterator1>& x, 
	const reverse_iterator<Iterator2>& y){
	return (x.base() != y.base());
}

template < typename Iterator1, typename Iterator2 >
inline bool operator>(const reverse_iterator<Iterator1>& x, 
	const reverse_iterator<Iterator2>& y){
	return (x.base() < y.base());
}

template < typename Iterator1, typename Iterator2 >
inline bool operator>=(const reverse_iterator<Iterator1>& x, 
	const reverse_iterator<Iterator2>& y){
	return (x.base() <= y.base());
}

template < typename Iterator1, typename Iterator2 >
inline bool operator<=(const reverse_iterator<Iterator1>& x, 
	const reverse_iterator<Iterator2>& y){
	return (x.base() >= y.base());
}

template < typename Iterator1, typename Iterator2 >
typename reverse_iterator<Iterator1>::difference_type operator-(const reverse_iterator<Iterator1>& x, 
	const reverse_iterator<Iterator2>& y){
	return (y.base() - x.base());
}

template < typename Iterator >
reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, 
	const reverse_iterator<Iterator>& x){
	return(reverse_iterator<Iterator> (x.base() - n));	
}
	
}//ft
