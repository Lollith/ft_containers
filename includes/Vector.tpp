/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:31:53 by agouet            #+#    #+#             */
/*   Updated: 2023/01/04 18:22:08 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// The container keeps an internal copy of alloc, which is used to allocate storage throughout its lifetime.
//Le constructeur a un paramètre, alloc, qui est une référence à un objet de type Allocateur.
//  mot-clé explicit indique que ce constructeur ne peut être utilisé pour créer un 
//objet vector que lorsqu'il est invoqué avec un argument de type Allocateur.

//La valeur par défaut de alloc est Allocator(), ce qui signifie que si vous ne 
//fournissez pas de valeur pour le paramètre alloc lors de l'appel de la fonction, 
//une instance par défaut de Allocator sera créée et utilisée à la place. 
//Cela signifie que vous pouvez appeler la fonction sans fournir de valeur pour le paramètre alloc,

# include <iostream>


//---------------------------------------------constructor----------------------
namespace ft {
	//size_type :: redefinir la class vector pour eppeler le size_type

template < typename T, typename Allocator>// si pas de precision Alloc va compiler comme type T de la classe std::allocator
vector<T, Allocator>::vector( const Allocator &alloc ) : // = Allocator , permet dappeler le template int seul et sans avoir a demander le template Alloc qui est aors appele par default
		_start(NULL), _size(0), _capacity(0), _alloc(alloc)// appel le constructeur allocator qui sert a allouer de la memoire
{
	return;
}

// un constructeur avec un taille de base, le deuxieme argument est la valeur a 
//de remplissage, si elle n'est as presente la valeur du constructeur par default est utilise
template < typename T, typename Allocator>
vector<T, Allocator>::vector( size_type n, const value_type& value, const allocator_type& alloc ): // appel class T par default et class Allocator par defaut
		_start(NULL), _size(0), _capacity(0), _alloc(alloc){
		assign( n, value);
	}


template < typename T, typename Allocator>
vector<T, Allocator>::~vector( void )
{
	// clear();
	if (_capacity != 0)
	{
		_alloc.deallocate(_start, sizeof(value_type) * _capacity); // libere
		// _capacity= 0;
	}
}
//---------------------------------------------iterators------------------------
// template < typename T, typename Allocator>
// typename vector<T,Allocator>::iterator vector<T, Allocator>::begin(void){
// 	return (_data);			
// }

//-------------------------------------members fct  capacity--------------------
//allocator::destroy = detruit le pointeur sur lobjet, ne desaloue pas le stockage pour liberer l place
//allocator::deallocate = libere le block de stckage alloue, non detruit
template < typename T, typename Allocator>
typename vector<T, Allocator>::size_type vector<T, Allocator>::size( void ) const
{ 
	return (this->_size);
}

template < typename T, typename Allocator>
typename vector<T, Allocator>::size_type vector<T, Allocator>::max_size( void ) const
{
	return (_alloc.max_size());
}

// template < typename T, typename Allocator>
// void vector<T, Allocator>::resize (size_type n, value_type val){
// 	// if(n < this->size())
// 	// {
// 	// 	_alloc.destroy(_data)
// 	// 	this->_size = n;
// 	// }
// }

template < typename T, typename Allocator>
typename vector<T, Allocator>::size_type vector<T, Allocator>::capacity( void ) const{
	return (_capacity);
}

template < typename T, typename Allocator>
bool vector<T, Allocator>::empty( void ) const{
	if (_size == 0 )
		return ( true );
	return ( false );
}
//reserve: Requests that the vector capacity be at least enough to contain n elements.
// If n is greater than the current vector capacity, the function causes the 
//container to reallocate its storage increasing its capacity to n (or greater).
// In all other cases, the function call does not cause a reallocation and the 
//vector capacity is not affected.
// This function has no effect on the vector size and cannot alter its elements.
template < typename T, typename Allocator>
void vector<T, Allocator>::reserve(size_type n)
{
	pointer new_stock;
	
	if (n <= _capacity)
		return;
	if (n > this->max_size())
		throw std::length_error("max size is exceeded");
	new_stock = _alloc.allocate(n);
	for (size_type i = 0; i < _size; i++)
	{
		_alloc.construct(new_stock + i, _start[i]);
		_alloc.destroy(_start+i); //  l objet est detruit // ne libere pas
	}
	if (_capacity != 0)
		_alloc.deallocate(_start, sizeof(value_type) * _capacity); // libere le pointeur
	_start = new_stock;
	_capacity = n;
}


//-------------------------------------members fct modifier---------------------
//clear = remove all element s , destroyed(pointer), size =0
template < typename T, typename Allocator>
void vector<T, Allocator>::clear( void ){
	for(size_type i = 0; i < _size; i++)
		_alloc.destroy(_start + i);
	this->_size = 0;
}

// template < typename T, typename Allocator>
// void vector<T, Allocator>::pop_back( void ){
// 	_alloc.destroy(_data[a remplir])
// 	this->_size --;
// }



//assign new values to the vector elements by replacing old ones. 
//It modifies size of vector if necessary.
template < typename T, typename Allocator>
void vector<T, Allocator>::assign(size_type n, const T &val){
	clear();
	// reserve(n);
	this->_size = n;
	for (size_type i = 0; i < _size; i++)
		_alloc.construct(_start + i, val);
	// _end = _start + _ size;
}
//-----------------------------------------------------en plus-----------------//
// template < typename T, typename Allocator>
// std::ostream& operator<<(std::ostream& o, vector<T, Allocator> const &instance){
// 	o << instance.size();
// 	return (o);
// }

}// namespace ft