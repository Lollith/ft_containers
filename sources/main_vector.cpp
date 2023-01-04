/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:43:17 by agouet            #+#    #+#             */
/*   Updated: 2023/01/04 17:39:09 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Vector.hpp"
#include <vector>

#ifdef FT
	#include <Vector.hpp>
	// #include <map.hpp>
	// #include <stack.hpp>
	namespace NAME_USE = ft;
#else
	// #include <map>
// 	// #include <stack>
	#include <vector>
	namespace NAME_USE = std;
#endif

template <typename T>
static void display(NAME_USE::vector<T> vect)
{
// 	for (typename NAME_USE::vector<T>::iterator it = vect.begin(); it != vect.end(); it++)
// 		std::cout << *it << std::endl;
	std::cout << "size: " << vect.size() << std::endl;
	std::cout << "max_size: " << vect.max_size() << std::endl;
	std::cout << "capacity: " << vect.capacity() << std::endl;
	std::cout << "empty: " << vect.empty() << std::endl;
	std::cout <<  std::endl;
}

namespace ft{
	std::string s = "ft";
}
namespace std{
	std::string s = "std";
}

//make vector
int main() 
{
	std::cout <<"\e[1;33m"<< "Test: "<< NAME_USE::s << "\e[0m"<< std::endl;
	
	NAME_USE::vector <int> v; //constructeur vide
	display(v);
	
	v.reserve(10);
	display(v);

	// v.assign(5, 0);
	// std::cout << "empty constructor , size = "<< v.size() << std::endl;

	// ft::vector <int> v1(5,1); // constructeur 2 + assign() + clear() + reserve()
	// std::cout << "fill constructor , size = "<< v1.size() << std::endl;
	
	// printVector(v);
	return (0);
}