/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:31:04 by agouet            #+#    #+#             */
/*   Updated: 2023/01/04 17:38:19 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTOR_HPP
# define  VECTOR_HPP

# include <iostream>
# include <memory> //class Allocator

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
		
		typedef std::ptrdiff_t									diference_type;
		typedef std::size_t										size_type;

		typedef T*												iterator;
		typedef const T*										const_iterator;
		// typedef reverse_iterator<iterator>						reverse_iterator;
		// typedef reverse_iterator<const_iterator>				const_reverse_iterator;

	
		
//---------------------------------------------constructor----------------------
// un constructeur avec un plage d'iterateur a mettre a l'iterieur a l'initalisation


//(1)empty
// Vector();
 		explicit vector( const allocator_type &alloc = allocator_type() );

//(2)fill count element , initialized with a Value val
		explicit vector( size_type n, const T& value = T(), const Allocator& alloc = Allocator() ); // appel class T par default et class Allocator par defaut

// Vector( size_t n );
// //(3)range
// Vector ( T first, T last);
// //(4)copy
// Vector (Vector const &copy);
// //destructeur
		~vector( void );
//operator=

//---------------------------------------------iterators------------------------

		// iterator	begin(void);
		// this function returns a random access iterator pointing to it.


//---------------------------------------------members fct----------------------
//capacity
		size_type	size( void ) const;
		// void resize (size_type n, value_type val= value_type());
		size_type max_size ( void ) const;
		size_type capacity( void ) const;
		bool empty( void ) const;
		void reserve(size_type n);
		//shrink_to_fit

// modifier
		void assign(size_type n, const T &value);
		//pushback
		//insert
		//erase
		//swap
		//emplae
		//emplace_back
		void clear( void );
		void pop_back( void);

//access

//iterators
		
//---------------------------------------------overloards-----------------------

//---------------------------------------------non member fct-------------------


		
	
		//The container keeps an internal copy of alloc, which is used to allocate storage throughout its lifetime.
		private:
		
			pointer			_start;// Un pointeur sur un tableau de valeurs de type générique T. Cela représentera notre espace de stockage pour les éléments du vecteur.
			//pointer _end_capacity;
			size_type		_size;//Un entier size qui indiquera le nombre d'éléments actuellement contenus dans le vecteur.
			size_type		_capacity;// indique la capacité actuelle de l'espace de stockage alloué pour le vecteur.
			allocator_type	_alloc;

//capacity = ce que je donne en previsionnel = size a linitialisation 
//size = ce qui est demander par le main

	};
	// template < class T, class Allocator = std::allocator<T> >
	// std::ostream &	operator<<( std::ostream & o, const vector<T, Allocator> &rhs);

	

}

#include "Vector.tpp"

#endif