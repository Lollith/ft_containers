/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Reverse_Iterator.hpp                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/30 13:26:25 by agouet            #+#    #+#             */
/*   Updated: 2023/01/09 15:13:19 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef REVERSE_ITERATOR_HPP
 #define REVERSE_ITERATOR_HPP

# include "iterator_traits.hpp"
#include <iterator>
 
namespace ft {
template <class Iterator>
class reverse_iterator : public std::iterator <typename iterator_traits<Iterator>::iterator_category,
											typename iterator_traits<Iterator>::value_type,
											typename iterator_traits<Iterator>::difference_type,
											typename iterator_traits<Iterator>::pointer,
											typename iterator_traits<Iterator>::reference> 
{
	protected:
		Iterator _current;

	public:
		typedef Iterator											iterator_type;
		typedef typename iterator_traits<Iterator>::difference_type	difference_type;
		typedef typename iterator_traits<Iterator>::reference		reference;
		typedef typename iterator_traits<Iterator>::pointer			pointer;

//----------------------------------------constructor---------------------------	
		reverse_iterator();
		explicit reverse_iterator(Iterator it);
		template < class U > reverse_iterator(const reverse_iterator<U>& u);
		template < class U > reverse_iterator &operator=( const reverse_iterator<U> &other);
		
//----------------------------------------mber----------------------------------	
		Iterator base() const; // explicit
		reference operator*() const;
		pointer operator->() const;
		reverse_iterator& operator++();
		reverse_iterator operator++(int);
		reverse_iterator& operator--();
		reverse_iterator operator--(int);
		reverse_iterator operator+(difference_type n) const;
		reverse_iterator& operator+=(difference_type n);
		reverse_iterator operator-(difference_type n) const;
		reverse_iterator& operator-=(difference_type n);
		reference operator[](difference_type n) const;
};

//----------------------------------------non mber------------------------------	
	template <class Iterator>
	bool operator==(const reverse_iterator<Iterator>& x, 
		const reverse_iterator<Iterator>& y);
	
	template <class Iterator>
	bool operator<(const reverse_iterator<Iterator>& x, 
		const reverse_iterator<Iterator>& y);
	
	template <class Iterator>
	bool operator!=( const reverse_iterator<Iterator>& x, 
		const reverse_iterator<Iterator>& y);
	
	template <class Iterator>
	bool operator>(const reverse_iterator<Iterator>& x, 
		const reverse_iterator<Iterator>& y);

	template <class Iterator>
	bool operator>=(const reverse_iterator<Iterator>& x, 
		const reverse_iterator<Iterator>& y);

	template <class Iterator>
	bool operator<=(const reverse_iterator<Iterator>& x, 
		const reverse_iterator<Iterator>& y);

	template <class Iterator>
	typename reverse_iterator<Iterator>::difference_type operator-(const reverse_iterator<Iterator>& x, 
		const reverse_iterator<Iterator>& y);

	template <class Iterator>
	reverse_iterator<Iterator> operator+(typename reverse_iterator<Iterator>::difference_type n, 
		const reverse_iterator<Iterator>& x);

	
} // ft

#include "Reverse_Iterator.tpp"

#endif