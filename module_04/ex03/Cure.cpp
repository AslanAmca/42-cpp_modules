/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cure.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/31 18:25:47 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/31 18:35:15 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cure.hpp"
#include "ICharacter.hpp"

Cure::Cure(void)
{
	type = "cure";
}

Cure::~Cure(void)
{
}

Cure::Cure(const Cure &other) : AMateria(other)
{
	this->type = other.type;
}

Cure &Cure::operator=(const Cure &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}

	return *this;
}

AMateria *Cure::clone(void) const
{
	return new Cure();
}

void Cure::use(ICharacter &target)
{
	std::cout << "* heals " << target.getName() << "’s wounds *" << std::endl;
}
