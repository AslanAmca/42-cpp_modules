/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:12:13 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/30 16:12:04 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void)
{
	std::cout << "Animal - Default constructor called" << std::endl;

	type = "Animal";
}

Animal::Animal(const Animal &other)
{
	std::cout << "Animal - Copy constructor called" << std::endl;

	type = other.type;
}

Animal &Animal::operator=(const Animal &other)
{
	std::cout << "Animal - Copy assignment operator called" << std::endl;

	if (this != &other)
	{
		type = other.type;
	}

	return *this;
}

Animal::~Animal(void)
{
	std::cout << "Animal - Destructor called" << std::endl;
}

void Animal::makeSound(void) const
{
	std::cout << "Animal - makeSound function called" << std::endl;
}

const std::string Animal::getType(void) const
{
	return type;
}
