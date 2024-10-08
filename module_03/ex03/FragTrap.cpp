/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/26 22:14:26 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/29 19:56:27 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(void) : ClapTrap()
{
	name = "Unknown";
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;

	std::cout << "FragTrap - Default constructor called for " << name << std::endl;
}

FragTrap::FragTrap(std::string nameValue) : ClapTrap(nameValue)
{
	name = nameValue;
	hitPoints = 100;
	energyPoints = 100;
	attackDamage = 30;

	std::cout << "FragTrap - Name constructor called for " << name << std::endl;
}

FragTrap::FragTrap(const FragTrap &other) : ClapTrap(other)
{
	std::cout << "FragTrap - Copy constructor called for " << name << std::endl;

	*this = other;
}

FragTrap &FragTrap::operator=(const FragTrap &other)
{
	std::cout << "FragTrap - Copy assignment operator called for " << name << std::endl;

	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}

	return *this;
}

FragTrap::~FragTrap(void)
{
	std::cout << "FragTrap - Destructor called for " << name << std::endl;
}

void FragTrap::highFivesGuys(void)
{
	if (hitPoints <= 0)
		std::cout << "FragTrap - " << name << " cannot high five"
				  << " because he is dead!" << std::endl;
	else
		std::cout << "FragTrap - " << name << " wants to give you high fives!" << std::endl;
}
