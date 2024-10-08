/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Ice.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:25:47 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/31 23:07:49 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Ice.hpp"
#include "ICharacter.hpp"

Ice::Ice(void)
{
	type = "ice";
}

Ice::~Ice(void)
{
}

Ice::Ice(const Ice &other) : AMateria(other)
{
	this->type = other.type;
}

Ice &Ice::operator=(const Ice &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}

	return *this;
}

AMateria *Ice::clone(void) const
{
	return new Ice();
}

void Ice::use(ICharacter &target)
{
	std::cout << "* shoots an ice bolt at " << target.getName() << " *" << std::endl;
}
