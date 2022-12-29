/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_vector.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agouet <agouet@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 14:43:17 by agouet            #+#    #+#             */
/*   Updated: 2022/12/29 17:35:48 by agouet           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <Vector.hpp>

int main() 
{
	
	ft::vector <int> v; //constructeur vide
	std::cout << "empty constructor , size = "<< v.size() << std::endl;

	ft::vector <int> v_fill(3);
	std::cout << "fill constructor , size = "<< v_fill.size() << std::endl;
	
	return (0);
}