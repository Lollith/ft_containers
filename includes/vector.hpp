/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:31:04 by agouet            #+#    #+#             */
/*   Updated: 2023/03/02 18:15:35 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define  VECTOR_HPP

# include <iostream>
# include <memory> //class Allocator
# include "iterators/iterator_traits.hpp"
# include "iterators/reverse_iterator.hpp"
# include "utils/is_integral.hpp"
# include "utils/enable_if.hpp"
# include "utils/equal.hpp"
# include "utils/lexicographical_compare.hpp"
# include "iterators/random_access_iterator.hpp"
// # include <iterator>

namespace ft {
	//allocator = class
	template < class T, class Allocator = std::allocator<T> >// si pas de precision Alloc va compiler comme type T de la classe std::allocator
	class vector{
		public:

//definitions - alias , remplace gauche par la droite
		typedef T 												value_type;
		typedef Allocator										allocator_type;// Member type allocator_type is the type of the allocator used by the container, 
		
		typedef typename allocator_type::reference				reference;
		typedef typename allocator_type::const_reference 		const_reference; //typename rappeler pour pas que le compilateur se perde // type def =alias ,evite les using 
		typedef typename allocator_type::pointer				pointer;
		typedef typename allocator_type::const_pointer			const_pointer;
		
		typedef std::ptrdiff_t									difference_type;
		typedef std::size_t										size_type;

		typedef random_access_iterator<pointer>					iterator;
		typedef random_access_iterator<const_pointer>			const_iterator;
		typedef ft::reverse_iterator<iterator>					reverse_iterator;
		typedef ft::reverse_iterator<const_iterator>			const_reverse_iterator;
		// typedef T*												iterator;
		// typedef T*												const_iterator;

	
		
//---------------------------------------------constructor----------------------
//(1)empty
// Vector();
 		explicit vector( const allocator_type &alloc = allocator_type() );

//(2)fill count element , initialized with a Value val
		explicit vector( size_type n, const T& value = T(), const Allocator& alloc = Allocator() ); // appel class T par default et class Allocator par defaut

//(3)range
		template< class InputIterator >
		vector(typename enable_if<!ft::is_integral< InputIterator >::value, 
			InputIterator >::type first, InputIterator last, const allocator_type& alloc = Allocator());
//(4)copy
		vector (vector const &copy);
		
//destructeur
		~vector( void );
//operator=
		vector &operator=( vector const& rhs );

//---------------------------------------------iterators------------------------

		iterator				begin( void );
		const_iterator			begin( void ) const;
		iterator				end( void );
		const_iterator			end( void ) const;
		reverse_iterator 		rbegin( void );
		const_reverse_iterator	rbegin( void ) const;
		reverse_iterator 		rend( void );
		const_reverse_iterator	rend( void ) const;

//---------------------------------------------members fct----------------------
//capacity
		size_type		size( void ) const;
		void 			resize( size_type n, value_type val = value_type() );
		size_type	 	max_size( void ) const;
		size_type		capacity( void ) const;
		bool			empty( void ) const;
		void			reserve( size_type n );

// modifier
		void			clear( void );
		void			assign( size_type n, const T &value );
		void			push_back( const value_type &val );
		void			pop_back( void );
		void			swap( vector& x);
		iterator		erase( iterator position );
		iterator 		erase( iterator first, iterator last );
		iterator		insert( iterator position, const value_type& val );
    	void			insert( iterator position, size_type n, const value_type& val );
		
		template <class InputIterator>    
		typename enable_if<!ft::is_integral< InputIterator >::value, void >::type
		insert(iterator pos, InputIterator first, InputIterator last);
			
		template <class InputIterator>
		void assign( InputIterator first, InputIterator last,
			typename enable_if<!ft::is_integral< InputIterator >::value, void* >::type* = NULL);


//access
  		reference 		operator[]( size_type n );
  		const_reference operator[]( size_type n ) const;

  		reference 		at( size_type n );
  		const_reference at( size_type n ) const;
  		reference 		front( void );
  		const_reference front( void ) const;
  		reference 		back( void );
  		const_reference back( void ) const;

//---------------------------------------------get_allocator------------------------

		allocator_type	get_allocator( void ) const;

//----------------------------------------------helper------------------------------	
		private:
			template<typename _InputIterator>
			void _insertHelper(iterator pos, _InputIterator first, 
				_InputIterator last, std::input_iterator_tag);

			template<typename _ForwardIterator>
			void _insertHelper(iterator pos, _ForwardIterator first, 
				_ForwardIterator last, std::forward_iterator_tag);

			template<typename _InputIterator>
			void _assignHelper(_InputIterator first, _InputIterator last, 
				std::input_iterator_tag);
				
			template<typename _ForwardIterator>
			void _assignHelper(_ForwardIterator first, _ForwardIterator last, 
				std::forward_iterator_tag);
		
//---------------------------------------------attributs------------------------
		//The container keeps an internal copy of alloc, which is used to allocate storage throughout its lifetime.

			pointer			_start;// Un pointeur sur un tableau de valeurs de type g??n??rique T. Cela repr??sentera notre espace de stockage pour les ??l??ments du vecteur.
			size_type		_size;//Un entier size qui indiquera le nombre d'??l??ments actuellement contenus dans le vecteur.
			size_type		_capacity;// indique la capacit?? actuelle de l'espace de stockage allou?? pour le vecteur.
			allocator_type	_alloc;

			//capacity = ce que je donne en previsionnel = size a linitialisation// capacite entre le first et le last 
			//size = ce qui est demander par le main

	};

//---------------------------------------------algo-----------------------------

template < typename T, typename Allocator >
inline void swap (vector<T, Allocator> &a, vector<T, Allocator> &b);

//-----------------------------------------relational operators-----------------
template < class T, class Allocator >  
bool operator==( const vector<T, Allocator >& lhs, const vector< T, Allocator >& rhs );

template < class T, class Allocator >
bool operator!=( const vector< T, Allocator >& lhs, const vector< T, Allocator >& rhs );

template < class T, class Allocator >  
bool operator<( const vector< T, Allocator >& lhs, const vector< T, Allocator >& rhs );

template < class T, class Allocator >
bool operator<=( const vector< T, Allocator >& lhs, const vector<T, Allocator >& rhs );

template < class T, class Allocator >
bool operator>( const vector< T, Allocator >& lhs, const vector< T, Allocator >& rhs );

template < class T, class Allocator >
bool operator>=( const vector< T, Allocator >& lhs, const vector< T, Allocator >& rhs );


} //ft

#include "vector.tpp"

#endif