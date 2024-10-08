/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:22:57 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/30 16:12:37 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog - Default constructor called" << std::endl;

	type = "Dog";
}

Dog::~Dog(void)
{
	std::cout << "Dog - Destructor called" << std::endl;
}

Dog::Dog(const Dog &other) : Animal(other)
{
	std::cout << "Dog - Copy constructor called" << std::endl;

	type = other.type;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog - Copy assignment operator called" << std::endl;

	if (this != &other)
	{
		type = other.type;
	}

	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Dog - Woof Woof" << std::endl;
}
