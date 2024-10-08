/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 22:12:02 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/29 22:12:03 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void)
{
	std::cout << "WrongAnimal - Default constructor called" << std::endl;

	type = "WrongAnimal";
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << "WrongAnimal - Destructor called" << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &other)
{
	std::cout << "WrongAnimal - Copy constructor called" << std::endl;

	*this = other;
}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &other)
{
	std::cout << "WrongAnimal - Copy assignment operator called" << std::endl;

	if (this != &other)
	{
		type = other.type;
	}

	return *this;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "WrongAnimal - makeSound function called" << std::endl;
}

const std::string WrongAnimal::getType(void) const
{
	return type;
}
