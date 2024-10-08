/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 14:03:50 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/29 17:21:51 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>

int main(void)
{
	std::string string = "HI THIS IS BRAIN";
	std::string *stringPTR = &string;
	std::string &stringREF = string;

	std::cout << "Memory Address (string)     : " << &string << std::endl;
	std::cout << "Memory Address (*stringPTR) : " << stringPTR << std::endl;
	std::cout << "Memory Address (&stringREF) : " << &stringREF << std::endl;

	std::cout << std::endl;

	std::cout << "Value (string)     : " << string << std::endl;
	std::cout << "Value (*stringPTR) : " << *stringPTR << std::endl;
	std::cout << "Value (&stringREF) : " << stringREF << std::endl;

	return 0;
}
