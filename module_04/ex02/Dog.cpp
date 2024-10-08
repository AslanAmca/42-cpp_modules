/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 21:22:57 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/30 19:13:38 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	std::cout << "Dog - Default constructor called" << std::endl;

	type = "Dog";
	brain = new Brain();
}

Dog::~Dog(void)
{
	std::cout << "Dog - Destructor called" << std::endl;

	delete brain;
}

Dog::Dog(const Dog &other) : AAnimal(other)
{
	std::cout << "Dog - Copy constructor called" << std::endl;

	type = other.type;

	// This is a Deep Copy.
	// Creates a new object with its own memory address.
	brain = new Brain(*other.brain);

	// This is a Shallow Copy.
	// It just copies the memory address. It does not create a new object.
	// brain = other.brain;
}

Dog &Dog::operator=(const Dog &other)
{
	std::cout << "Dog - Copy assignment operator called" << std::endl;

	if (this != &other)
	{
		type = other.type;

		// The object created by the constructor should be deleted to avoid memory leaks.
		delete brain;

		brain = new Brain(*other.brain);
	}

	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "Dog - Woof Woof" << std::endl;
}

Brain* Dog::getBrain(void) const
{
	return brain;
}
