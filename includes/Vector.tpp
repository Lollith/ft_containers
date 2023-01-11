/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:31:53 by agouet            #+#    #+#             */
/*   Updated: 2023/01/11 15:13:25 by agouet           ###   ########.fr       */
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

//initialise lhs = copie construite // rhs : ce que je copie
template < typename T, typename Allocator>
vector<T, Allocator>::vector( vector const &copy ){
	_start = NULL;
	_size = 0;
	_capacity = 0;
	*this = copy;
}

template < typename T, typename Allocator>
vector<T, Allocator> &vector<T, Allocator>::operator=( vector<T, Allocator> const& rhs ){
		if ( this != &rhs )
		{
			this->reserve(rhs._size);
			this->clear();
			for (size_type i = 0; i < rhs._size; i++)
				_alloc.construct(this->_start + i, *(rhs._start + i));
			this->_size = rhs._size;
			this->_capacity = rhs._capacity;
		}
		return (*this);
	}


template < typename T, typename Allocator>
vector<T, Allocator>::~vector( void )
{
		clear();
	_alloc.deallocate(_start, sizeof(value_type) * _capacity); // libere
}
		

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

template < typename T, typename Allocator>
void vector<T, Allocator>::resize (size_type n, value_type val){
	if (n < _size)
		_alloc.destroy(_start);
	else if (n > _size && n > _capacity * 2)
	{
		reserve(n);
		for (size_type i = _size; i < n; i++)
			_alloc.construct(_start + i, val);
	}
	else if (n > _size)
	{
		reserve(n);
		for (size_type i = _size; i < n; i++)
			_alloc.construct(_start + i, val);
	}
	this->_size = n;
}

template < typename T, typename Allocator>
typename vector<T, Allocator>::size_type vector<T, Allocator>::capacity( void ) const{
	return (_capacity);
}

template < typename T, typename Allocator>
bool vector<T, Allocator>::empty( void ) const{
	if (_size > 0 )
		return ( false );
	return ( true );
}
//reserve: Requests that the vector capacity be at least enough to contain n elements.
// If n is greater than the current vector capacity, the function causes the 
//container to reallocate its storage increasing its capacity to n (or greater).
// In all other cases, the function call does not cause a reallocation and the 
//vector capacity is not affected.
// This function has no effect on the vector size and cannot alter its elements.

// alloc.construc => n alloue pas, cnstruit lobjet value  au niveau du pointer
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
		_alloc.destroy(_start + i); //  l objet est detruit // ne libere pas
	}
	if (_capacity != 0)
		_alloc.deallocate(_start, sizeof(value_type) * _capacity); // libere le pointeur
	_start = new_stock;
	_capacity = n;
}


//-------------------------------------members fct modifier---------------------
//clear = remove all element s , destroyed the objet( not the pointer), size =0
template < typename T, typename Allocator>
void vector<T, Allocator>::clear( void ){
	for(size_type i = 0; i < _size; i++)
		_alloc.destroy(_start + i);
	this->_size = 0;
}


//assign new values to the vector elements by replacing old ones. 
//It modifies size of vector if necessary.
template < typename T, typename Allocator>
void vector<T, Allocator>::assign(size_type n, const T &val){
	clear();
	reserve(n);
	this->_size = n;
	for (size_type i = 0; i < _size; i++)
		_alloc.construct(_start + i, val);
}


template < typename T, typename Allocator>
void vector<T, Allocator>::push_back(const value_type &val){
	if (_capacity == 0)
		reserve(1);
	else if (_size + 1 > _capacity)
		reserve(_capacity * 2);
	_alloc.construct(_start + _size, val);
	_size++;
}

template < typename T, typename Allocator>
void vector<T, Allocator>::pop_back( void ){	
	_alloc.destroy(_start + _size - 1);
	if (_size == 0)
		throw std::overflow_error("size < 0");
	this->_size --;
}

template < typename T, typename Allocator>
void vector<T, Allocator>::swap(vector& x){
	pointer tmp;
	
	tmp = this->_start;
	this->_start = x._start;
	x._start = tmp;
	std::swap(_size, x._size); // meme chose que ligne prcedente
	std::swap(_capacity, x._capacity);
	std::swap(_alloc, x._alloc);
}

//Removes from the vector either a single element (position) 
//or a range of elements ([first,last)).
template < typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::erase(iterator position){
	for (size_type i = 1; position + i != end(); i++)
	{
		_alloc.destroy(position + i - 1);
		_alloc.construct(position + i - 1, *(position + i));
	}
	_alloc.destroy(end() - 1);
	_size--;
	return (position);
}

template < typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::erase(iterator first, iterator last){
	for (iterator it = first; it < last ; it++)
	{
		_alloc.destroy(it);
		_size--;
	}
	for (iterator it = first; it != end() ; it++)
	{
		_alloc.construct(it, *(last)); // met a case davant ds la case suivante
		_alloc.destroy(last);
		last++;
	}
	
	return (first);
}

//nserting new elements before the element at the specified position,
// calcl la nouvelle pos ds new tableau de capacite *2 ou 1;
template < typename T, typename Allocator>
typename vector<T, Allocator>::iterator	vector<T, Allocator>::insert (iterator position, const value_type& val){

	size_type dist_before_res = position - _start;
	if (_capacity == 0)
		reserve(1);
	if (_size + 1 > _capacity)
		reserve(_capacity * 2);
	iterator new_pos = _start + dist_before_res;
			
	for (iterator it = end(); it != new_pos; it--)
	{
		_alloc.construct(it, *(it - 1)); // met a case davant ds la case suivante
		_alloc.destroy(it - 1);
			
	}
		_alloc.construct(new_pos, val);
		_size++;
		return (new_pos);
}

template < typename T, typename Allocator>
void	vector<T,Allocator>::insert (iterator position, size_type n, const value_type& val){
	
	if (n <= 0)
		return ;
	size_type dist_sp = (position - _start);
	size_type new_size = _size + n;
	if (_capacity == 0)
		reserve(1);
	if (new_size > _capacity)
	{
		if (new_size > _size * 2)
			reserve(new_size);
		else
			reserve(_size * 2);
	}
	position = _start + dist_sp;
	
	iterator new_pos = (end() - 1) + n;
	for (iterator it = end() - 1; it != (position - 1); it--) 
	{
		_alloc.construct(new_pos, *it);
		_alloc.destroy(it);
		new_pos--;
	}
	new_pos++;
	for (;position != new_pos; position++)
		_alloc.construct(position, val);
	_size = _size + n;
}



//-------------------------------------members fct iterator---------------------

template < typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::begin(){
	return (_start);
}

template < typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::begin() const{
	return (_start);
}

template < typename T, typename Allocator>
typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rbegin(){
	return (reverse_iterator(_start + _size));
}

template < typename T, typename Allocator>
typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rbegin() const{
	return (const_reverse_iterator(_start + _size));
}

template < typename T, typename Allocator>
typename vector<T, Allocator>::iterator vector<T, Allocator>::end(){
	return (_start + _size);
}

template < typename T, typename Allocator>
typename vector<T, Allocator>::const_iterator vector<T, Allocator>::end() const{
	return (_start + _size);
}

template < typename T, typename Allocator>
typename vector<T, Allocator>::reverse_iterator vector<T, Allocator>::rend(){
	return (reverse_iterator(_start));
}

template < typename T, typename Allocator>
typename vector<T, Allocator>::const_reverse_iterator vector<T, Allocator>::rend() const{
	return (const_reverse_iterator(_start));
}

//---------------------------------------------get_allocator------------------------

template < typename T, typename Allocator>
typename vector<T, Allocator>::allocator_type vector<T, Allocator>::get_allocator() const{
	return (allocator_type (_alloc));
}

//---------------------------------------------access---------------------------

template < typename T, typename Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::operator[] (size_type n){
	return (_start[n]);
}

template < typename T, typename Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::operator[] (size_type n) const{
	return (_start[n]);
}

template < typename T, typename Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::at (size_type n){
	if (n >= _size)
		throw std::out_of_range("vector::at");
	return (_start[n]);
}

template < typename T, typename Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::at (size_type n) const{
	if (n >= _size)
		throw std::out_of_range("vector::at");
	return (_start[n]);
}

template < typename T, typename Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::front(){
	return (*_start);
}

template < typename T, typename Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::front() const{
	return (*_start);
}

template < typename T, typename Allocator>
typename vector<T, Allocator>::reference vector<T, Allocator>::back(){
	return (*(end() - 1));
}

template < typename T, typename Allocator>
typename vector<T, Allocator>::const_reference vector<T, Allocator>::back() const{
	return (*(end() - 1));
}
//-----------------------------------------------------en plus-----------------//
// template < typename T, typename Allocator>
// std::ostream& operator<<(std::ostream& o, vector<T, Allocator> const &instance){
// 	o << instance.size();
// 	return (o);
// }

//---------------------------------------------non member fct-------------------

template < typename T, typename Allocator>
void swap(vector<T, Allocator> &lhs, vector<T, Allocator> &rhs){
	lhs.swap(rhs);	
}


}// namespace ft