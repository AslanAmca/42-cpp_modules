/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/27 16:44:25 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/29 19:56:19 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

DiamondTrap::DiamondTrap(void) : ClapTrap(), ScavTrap(), FragTrap()
{
	name = "Unknown";
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;

	std::cout << "DiamondTrap - Default constructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap(std::string nameValue) : ClapTrap(nameValue + "_clap_name"), ScavTrap(nameValue + "_clap_name"), FragTrap(nameValue + "_clap_name")
{
	name = nameValue;
	hitPoints = 100;
	energyPoints = 50;
	attackDamage = 30;

	std::cout << "DiamondTrap - Name constructor called for " << name << std::endl;
}

DiamondTrap::DiamondTrap(const DiamondTrap &other) : ClapTrap(other), ScavTrap(other), FragTrap(other)
{
	std::cout << "DiamondTrap - Copy constructor called for " << name << std::endl;

	*this = other;
}

DiamondTrap &DiamondTrap::operator=(const DiamondTrap &other)
{
	std::cout << "DiamondTrap - Copy assignment operator called for " << name << std::endl;

	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}

	return *this;
}

DiamondTrap::~DiamondTrap(void)
{
	std::cout << "DiamondTrap - Destructor called for " << name << std::endl;
}

void DiamondTrap::attack(const std::string &target)
{
	ScavTrap::attack(target);
}

void DiamondTrap::whoAmI(void)
{
	std::cout << "DiamondTrap - My name is " << name << std::endl;
	std::cout << "DiamondTrap - My ClapTrap name is " << ClapTrap::name << std::endl;
}
