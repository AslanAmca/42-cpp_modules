/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AMateria.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 19:55:56 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/31 23:03:55 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AMateria.hpp"
#include "ICharacter.hpp"

AMateria::AMateria(void)
{
}


AMateria::~AMateria(void)
{
}

AMateria::AMateria(const AMateria &other)
{
	this->type = other.type;
}

AMateria &AMateria::operator=(const AMateria &other)
{
	if (this != &other)
	{
		this->type = other.type;
	}

	return *this;
}

AMateria::AMateria(std::string const &type)
{
	this->type = type;
}

std::string const &AMateria::getType() const
{
	return this->type;
}

void AMateria::use(ICharacter &target)
{
	std::cout << "AMateria.use() function called for " << target.getName() << '\n';
}
