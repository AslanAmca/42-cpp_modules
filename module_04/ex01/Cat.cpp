/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:24:29 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/30 17:56:29 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	std::cout << "Cat - Default constructor called" << std::endl;

	type = "Cat";
	brain = new Brain();
}

Cat::~Cat(void)
{
	std::cout << "Cat - Destructor called" << std::endl;

	delete brain;
}

Cat::Cat(const Cat &other) : Animal(other)
{
	std::cout << "Cat - Copy constructor called" << std::endl;

	type = other.type;

	// This is a Deep Copy.
	// Creates a new object with its own memory address.
	brain = new Brain(*other.brain);

	// This is a Shallow Copy.
	// It just copies the memory address. It does not create a new object.
	// brain = other.brain;
}

Cat &Cat::operator=(const Cat &other)
{
	std::cout << "Cat - Copy assignment operator called" << std::endl;

	if (this != &other)
	{
		type = other.type;

		// The object created by the constructor should be deleted to avoid memory leaks.
		delete brain;

		brain = new Brain(*other.brain);
	}

	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "Cat - Meow" << std::endl;
}

Brain *Cat::getBrain(void) const
{
	return brain;
}
