/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 12:15:32 by aaslan            #+#    #+#             */
/*   Updated: 2023/12/24 13:43:00 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "easyfind.hpp"

int main(void)
{
	std::vector<int> v1;
	v1.push_back(5);
	v1.push_back(-12);
	v1.push_back(10);
	v1.push_back(-20);
	v1.push_back(61);
	v1.push_back(42);

	try
	{
		std::vector<int>::iterator position = easyfind(v1, 61);
		std::cout << "Value Found : " << *position << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		std::vector<int>::iterator position = easyfind(v1, 41);
		std::cout << "Value Found : " << *position << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << e.what() << '\n';
	}

	return 0;
}