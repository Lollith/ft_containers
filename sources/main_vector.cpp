/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:43:17 by agouet            #+#    #+#             */
/*   Updated: 2023/01/06 11:39:55 by agouet           ###   ########.fr       */
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

template <typename T, typename Allocator>
static void display(NAME_USE::vector<T, Allocator>& vect)
{
// 	for (typename NAME_USE::vector<T>::iterator it = vect.begin(); it != vect.end(); it++)
// 		std::cout << *it << std::endl;
	std::cout << "size: " << vect.size() << std::endl;
	std::cout << "max_size: " << vect.max_size() << std::endl;
	std::cout << "capacity: " << vect.capacity() << std::endl;
	std::cout << "empty: " << vect.empty() << std::endl;
	// std::cout << "empty: " << vect[] << std::endl;
	// std::cout << "empty: " << vect.at << std::endl;
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
	std::cout <<"\e[1;31m"<< "Constructor vide :"<< "\e[0m"<< std::endl;
	display(v);
	
	v.reserve(10);
	std::cout <<"\e[1;31m"<< "Reserve(10) :"<< "\e[0m"<< std::endl;
	display(v);


	v.assign(5, 0);
	std::cout <<"\e[1;31m"<< "assign(5, 0) :"<< "\e[0m"<< std::endl;
	display(v);

	NAME_USE::vector <int> v1(7,1); // constructeur 2 + assign() + clear() + reserve()
	std::cout <<"\e[1;31m"<< "constructor (2) :"<< "\e[0m"<< std::endl;
	display(v1);

	NAME_USE::vector <int> v2;
	v2 = v1;
	std::cout <<"\e[1;31m"<< "operator= :"<< "\e[0m"<< std::endl;
	display(v2);
	v2.assign(5, 4);
	std::cout <<"\e[1;31m"<< "assign :"<< "\e[0m"<< std::endl;
	display(v2);

	NAME_USE::vector <int> v3(v1);	
	std::cout <<"\e[1;31m"<< "constructor par copy :"<< "\e[0m"<< std::endl;
	display(v3);
	v3.resize(2,0);
	std::cout <<"\e[1;31m"<< "resize + petit :"<< "\e[0m"<< std::endl;
	display(v3);
	v3.resize(10,0);
	std::cout <<"\e[1;31m"<< "resize + grand:"<< "\e[0m"<< std::endl;
	display(v3);
	v3.resize(10,1);
	std::cout <<"\e[1;31m"<< "resize  egal :"<< "\e[0m"<< std::endl;
	display(v3);



	return (0);
}