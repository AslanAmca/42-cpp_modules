/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 17:22:53 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/29 19:55:06 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

ClapTrap::ClapTrap(void)
{
	name = "Unknown";
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;

	std::cout << "ClapTrap - Default constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(std::string nameValue)
{
	name = nameValue;
	hitPoints = 10;
	energyPoints = 10;
	attackDamage = 0;

	std::cout << "ClapTrap - Name constructor called for " << name << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &other)
{
	std::cout << "ClapTrap - Copy constructor called for " << name << std::endl;

	*this = other;
}

ClapTrap &ClapTrap::operator=(const ClapTrap &other)
{
	std::cout << "ClapTrap - Copy assignment operator called for " << name << std::endl;

	if (this != &other)
	{
		name = other.name;
		hitPoints = other.hitPoints;
		energyPoints = other.energyPoints;
		attackDamage = other.attackDamage;
	}

	return *this;
}

ClapTrap::~ClapTrap(void)
{
	std::cout << "ClapTrap - Destructor called for " << name << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap - " << name << " cannot attack because is dead!" << std::endl;
		return;
	}

	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap - " << name << " cannot attack because it has no energy!" << std::endl;
		return;
	}

	energyPoints--;

	std::cout << "ClapTrap - " << name << " attacks " << target << ", causing " << attackDamage << " points of damage!" << std::endl;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap - " << name << " is already dead!" << std::endl;
		return;
	}

	hitPoints -= amount;

	std::cout << "ClapTrap - " << name << " takes damage of " << amount << ", causing healt drop to " << hitPoints << ". ";

	if (hitPoints <= 0)
		std::cout << name << " has taken critical amount of damage and is dead!" << std::endl;
	else
		std::cout << "\n";
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (hitPoints <= 0)
	{
		std::cout << "ClapTrap - " << name << " cannot be repaired because because is dead!" << std::endl;
		return;
	}

	if (energyPoints <= 0)
	{
		std::cout << "ClapTrap - " << name << " cannot be repaired because there is no energy!" << std::endl;
		return;
	}

	energyPoints--;
	hitPoints += amount;

	std::cout << "ClapTrap - " << name << " has been repaired"
			  << ", causing his health increase by " << amount
			  << ". new health : " << hitPoints << std::endl;
}
