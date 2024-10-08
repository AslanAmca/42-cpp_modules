/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Character.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/30 23:15:37 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/31 23:23:29 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Character.hpp"
#include "AMateria.hpp"

Character::Character(void)
{
	name = "Character Default Name";

	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

// The Materias must be deleted when a Character is destroyed.
Character::~Character(void)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];
	}
}

// Any copy (using copy constructor or copy assignment operator) of a Character must be deep.
// During copy, the Materias of a Character must be deleted before the new ones are added to their inventory.
Character::Character(const Character &other)
{
	name = other.name;

	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] != NULL)
			delete inventory[i];

		if (other.inventory[i] != NULL)
			inventory[i] = other.inventory[i]->clone();
		else
			inventory[i] = NULL;
	}
}

// Any copy (using copy constructor or copy assignment operator) of a Character must be deep.
// During copy, the Materias of a Character must be deleted before the new ones are added to their inventory.
Character &Character::operator=(const Character &other)
{
	if (this != &other)
	{
		name = other.name;

		for (int i = 0; i < 4; i++)
		{
			if (inventory[i] != NULL)
				delete inventory[i];

			if (other.inventory[i] != NULL)
				inventory[i] = other.inventory[i]->clone();
			else
				inventory[i] = NULL;
		}
	}

	return *this;
}

// Your Character must have a constructor taking its name as a parameter.
Character::Character(std::string const &name)
{
	this->name = name;

	for (int i = 0; i < 4; i++)
		inventory[i] = NULL;
}

std::string const &Character::getName() const
{
	return name;
}

// They equip the Materias in the first empty slot they find.
// This means, in this order: from slot 0 to slot 3.
void Character::equip(AMateria *m)
{
	for (int i = 0; i < 4; i++)
	{
		if (inventory[i] == NULL)
		{
			inventory[i] = m;
			return;
		}
	}
}

// The unequip() member function must NOT delete the Materia!
void Character::unequip(int idx)
{
	if (idx >= 0 && idx <= 3 && inventory[idx] != NULL)
	{
		inventory[idx] = NULL;
	}
}

// The use(int, ICharacter&) member function will have to use the Materia at the
// slot[idx], and pass the target parameter to the AMateria::use function
void Character::use(int idx, ICharacter &target)
{
	if (idx >= 0 && idx <= 3 && inventory[idx] != NULL)
	{
		inventory[idx]->use(target);
	}
}
