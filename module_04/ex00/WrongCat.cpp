/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 22:23:13 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/30 16:12:51 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	std::cout << "WrongCat - Default constructor called" << std::endl;

	type = "WrongCat";
}

WrongCat::~WrongCat(void)
{
	std::cout << "WrongCat - Destructor called" << std::endl;
}

WrongCat::WrongCat(const WrongCat &other) : WrongAnimal(other)
{
	std::cout << "WrongCat - Copy constructor called" << std::endl;

	type = other.type;
}

WrongCat &WrongCat::operator=(const WrongCat &other)
{
	std::cout << "WrongCat - Copy assignment operator called" << std::endl;

	if (this != &other)
	{
		type = other.type;
	}

	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "WrongCat - Meow" << std::endl;
}
