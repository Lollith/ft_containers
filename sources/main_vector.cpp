/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:43:17 by agouet            #+#    #+#             */
/*   Updated: 2022/12/30 18:25:00 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Vector.hpp"
#include "iterators/random_access_iterator.hpp"
#include <vector>

int main() 
{
	
	ft::vector <int> v; //constructeur vide
	std::cout << "empty constructor , size = "<< v.size() << std::endl;

	// ft::vector <int> v_fill(3);
	// std::cout << "fill constructor , size = "<< v_fill.size() << std::endl;
	
	return (0);
}