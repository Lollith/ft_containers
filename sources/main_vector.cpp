/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:43:17 by agouet            #+#    #+#             */
/*   Updated: 2023/03/01 18:08:30 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "vector.hpp"
#include <vector>
#include <iterator>


#ifdef FT
	#include <vector.hpp>
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
	std::cout << "iterator :"<< std::endl;
	for (typename NAME_USE::vector<T>::iterator it = vect.begin(); it != vect.end(); it++)
		std::cout << *it << ", ";
	std::cout << std::endl;
	std::cout <<"reverse ite :" << std::endl;
	for (typename NAME_USE::vector<T>::reverse_iterator it2 = vect.rbegin(); it2 != vect.rend(); it2++)
		std::cout << *it2 << ", ";
	std::cout << std::endl;
	std::cout << "size: " << vect.size() << std::endl;
	std::cout << "max_size: " << vect.max_size() << std::endl;
	std::cout << "capacity: " << vect.capacity() << std::endl;
	std::cout << "empty: " << vect.empty() << std::endl;
	if (vect.size() > 0)
		std::cout << "vect[1]: " << vect[1] << std::endl;
	std::cout <<  std::endl;
}

namespace ft{
	std::string s = "ft";
}
namespace std{
	std::string s = "std";
}

// //make vector

void fonctions_principales(void)
{
	// NAME_USE::vector <int> v; //constructeur vide
	// std::cout <<"\e[1;31m"<< "Constructor vide :"<< "\e[0m"<< std::endl;
	// display(v);
	
	// v.reserve(10);
	// std::cout <<"\e[1;31m"<< "Reserve(10) :"<< "\e[0m"<< std::endl;
	// display(v);

	// v.assign(5, 0);
	// std::cout <<"\e[1;31m"<< "assign(5, 0) :"<< "\e[0m"<< std::endl;
	// display(v);

	// NAME_USE::vector <int> v1(7,1); // constructeur 2 
	// std::cout <<"\e[1;31m"<< "constructor (2):"<< "\e[0m"<< std::endl;
	// display(v1);
	
	NAME_USE::vector <int> v4(0,-1); // constructeur 2 
	std::cout <<"\e[1;31m"<< "(0 ,-1):"<< "\e[0m"<< std::endl;
	display(v4);

	// NAME_USE::vector <int> v2;
	// v2 = v1;
	// std::cout <<"\e[1;31m"<< "operator= :"<< "\e[0m"<< std::endl;
	// display(v2);

	// v2.assign(5, 4);
	// std::cout <<"\e[1;31m"<< "assign :"<< "\e[0m"<< std::endl;
	// display(v2);

	// NAME_USE::vector <int> v3(v1);	
	// std::cout <<"\e[1;31m"<< "constructor par copy :"<< "\e[0m"<< std::endl;
	// display(v3);

	// NAME_USE::vector <int> v5;	
	// std::cout <<"\e[1;31m"<< "swap :"<< "\e[0m"<< std::endl;
	// display(v5);
	// NAME_USE::swap(v5 , v2);
	// display(v5);
}

void resize_test(void)
{
	NAME_USE::vector <int> v3(7,1);	
	v3.resize(2,0);
	std::cout <<"\e[1;31m"<< "resize + petit :"<< "\e[0m"<< std::endl;
	display(v3);
	
	v3.resize(10,0);
	std::cout <<"\e[1;31m"<< "resize + grand:"<< "\e[0m"<< std::endl;
	display(v3);

	v3.resize(10,1);
	std::cout <<"\e[1;31m"<< "resize  egal :"<< "\e[0m"<< std::endl;
	display(v3);
}

void pushback_test(){
	 NAME_USE::vector <int> v4(3,1);	
	std::cout <<"\e[1;31m"<< "pushback :"<< "\e[0m"<< std::endl;
	display(v4);
	v4.push_back(5);
	display(v4);
	v4.push_back(5);
	display(v4);
}

void popback_test(){
	 NAME_USE::vector <int> v4(6,2);	
	std::cout <<"\e[1;31m"<< "popback :"<< "\e[0m"<< std::endl;
	v4.pop_back();
	display(v4);
	v4.pop_back();
	display(v4);
}

void erase_insert_test(){
	NAME_USE::vector <int> v6;
	std::cout <<"\e[1;31m"<< "insert :"<< "\e[0m"<< std::endl;
	display(v6);
	v6.insert(v6.begin(), 1);
	v6.insert(v6.begin() + 1, 2);
	v6.insert(v6.begin(), 0);
	v6.push_back(3);
	v6.push_back(4);
	v6.push_back(5);
	display(v6);
	std::cout <<"\e[1;31m"<< "erase [1]:"<< "\e[0m"<< std::endl;
	v6.erase(v6.begin()+1);
	display(v6);
	v6.insert(v6.begin()+1, 1);
	display(v6);
	std::cout <<"\e[1;31m"<< "erase [2-4[:"<< "\e[0m"<< std::endl;
	v6.erase(v6.begin() +2,v6.begin() +4);
	display(v6);
	std::cout <<"\e[1;31m"<< "insert (2):"<< "\e[0m"<< std::endl;
	v6.insert(v6.begin() + 3,5, 0);
	display(v6);
}

void retour_exeption_test(){

	try{
		NAME_USE::vector <int> v4;	
		v4.pop_back();
		display(v4);
		v4.push_back(5);
		display(v4);
	}
	catch(std::overflow_error const &e){
		std::cerr << "ERREUR: "<< e.what() << std::endl;
	}
	std::cout<<std::endl;



	try{
	NAME_USE::vector <int> v7;
	v7.insert(v7.begin(), 0);
	v7.insert(v7.begin(), 1);
	v7.push_back(2);
	v7.push_back(3);
	v7.push_back(4);
	std::cout <<"\e[1;31m"<< "at:"<< "\e[0m"<< std::endl;
	std::cout << "at(3): " << v7.at(1) << std::endl;
	std::cout<< "front(): "<< v7.front() << std::endl;
	std::cout<< "back(): "<< v7.back() << std::endl;
	std::cout << "at(10): " << v7.at(10) << std::endl;
	}

	catch(std::out_of_range const &e){
		std::cerr << "ERREUR: "<< e.what() << std::endl;
	}
	
}


int main() 
{
	std::cout <<"\e[1;33m"<< "Test: "<< NAME_USE::s << "\e[0m"<< std::endl;
	
	fonctions_principales();
	// resize_test();
	// pushback_test();
	// popback_test();
	// erase_insert_test();
	
	// retour_exeption_test(); //segfault sur la std
	
	// NAME_USE::vector < std::string> v1;
	// v1.assign(5, "0");
	// v1.assign(0, "jkjkl");

	return (0);

}