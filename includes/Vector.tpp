/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Vector.tpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/19 13:31:53 by agouet            #+#    #+#             */
/*   Updated: 2022/12/29 18:34:54 by agouet           ###   ########.fr       */
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
template < typename T, typename Allocator>// si pas de precision Alloc va compiler comme type T de la classe std::allocator
vector<T, Allocator>::vector( const Allocator &alloc ) : // = Allocator , permet dappeler le template int seul et sans avoir a demander le template Alloc qui est aors appele par default
		_data(NULL), _size(0), _capacity(0), _alloc(Allocator())// appel le constructeur allocator qui sert a allouer de la memoire
{
	return;
}

template < typename T, typename Allocator>
vector<T, Allocator>::vector( size_type count, const T& value, const Allocator& alloc ):
		_data(NULL), _size(0), _capacity(0), _alloc(Allocator())
	{
		assign(count, value);
	}



//---------------------------------------------members fct----------------------
//allocator::destroy = detruit le pointeur sur lobjet, ne desaloue pas le stockage pour liberer l place
//allocator::deallocate = libere le block de stckage alloue, non detruit
template < typename T, typename Allocator>
size_t vector<T, Allocator>::size( void ) const{ //size_type marche pas?
	return(this->_size);
}

//clear = remove all element s , destroyed(pointer), size =0
template < typename T, typename Allocator>
void vector<T, Allocator>::clear( void ){
	while(this->size())
		_alloc.destroy(_data);
	// this->_size = 0;
}

// template < typename T, typename Allocator>
// void assign(size_type count, const T &val){
// 	this->_size = count;
// }// a refaire

}// namespace ft