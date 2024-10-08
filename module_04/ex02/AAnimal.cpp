/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:12:42 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/30 19:12:43 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AAnimal.hpp"

AAnimal::AAnimal(void)
{
	std::cout << "AAnimal - Default constructor called" << std::endl;

	type = "AAnimal";
}

AAnimal::AAnimal(const AAnimal &other)
{
	std::cout << "AAnimal - Copy constructor called" << std::endl;

	type = other.type;
}

AAnimal &AAnimal::operator=(const AAnimal &other)
{
	std::cout << "AAnimal - Copy assignment operator called" << std::endl;

	if (this != &other)
	{
		type = other.type;
	}

	return *this;
}

AAnimal::~AAnimal(void)
{
	std::cout << "AAnimal - Destructor called" << std::endl;
}

const std::string AAnimal::getType(void) const
{
	return type;
}
