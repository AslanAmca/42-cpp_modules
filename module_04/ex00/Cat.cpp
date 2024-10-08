/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:24:29 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/30 16:12:23 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat - Default constructor called" << std::endl;

	type = "Cat";
}

Cat::~Cat(void)
{
	std::cout << "Cat - Destructor called" << std::endl;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat - Copy constructor called" << std::endl;

	type = other.type;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat - Copy assignment operator called" << std::endl;

	if (this != &other)
	{
		type = other.type;
	}

	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Cat - Meow" << std::endl;
}
