/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:31:04 by agouet            #+#    #+#             */
/*   Updated: 2022/12/29 18:27:04 by agouet           ###   ########.fr       */
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
	//iterators??
//---------------------------------------------constructor----------------------
//(1)empty
// Vector();
 		explicit vector( const Allocator &alloc = Allocator() );

//(2)fill count element , initialized with a Value val
		explicit vector( size_type count, const T& value = T(), const Allocator& alloc = Allocator() ); // appel class T par default et class Allocator par defaut

// Vector( size_t n );
// //(3)range
// Vector ( T first, T last);
// //(4)copy
// Vector (Vector const &copy);
// //destructeur
// ~Vector( void );
//operator=

//---------------------------------------------members fct----------------------
//capacity
		size_type	size( void ) const;

// modifier
		void clear( void );
		void assign(size_type count, const T &value);
		
//---------------------------------------------overloards-----------------------

//---------------------------------------------non member fct-------------------

//---------------------------------------------iterators------------------------

		
	
		//The container keeps an internal copy of alloc, which is used to allocate storage throughout its lifetime.
		private:
		
			value_type		*_data;// Un pointeur sur un tableau de valeurs de type générique T. Cela représentera notre espace de stockage pour les éléments du vecteur.
			size_type		_size;//Un entier size qui indiquera le nombre d'éléments actuellement contenus dans le vecteur.
			size_type		_capacity;// indique la capacité actuelle de l'espace de stockage alloué pour le vecteur.
			allocator_type	_alloc;
	
	};

}

#include "Vector.tpp"

#endif