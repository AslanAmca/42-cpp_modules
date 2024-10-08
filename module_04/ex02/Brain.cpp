/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 22:44:37 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/30 16:15:38 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void)
{
	std::cout << "Brain - Default constructor called" << std::endl;
}

Brain::Brain(const Brain &other)
{
	std::cout << "Brain - Copy constructor called" << std::endl;

	for (int i = 0; i < 100; i++)
		ideas[i] = other.ideas[i];
}

Brain &Brain::operator=(const Brain &other)
{
	std::cout << "Brain - Copy assignment operator called" << std::endl;

	if (this != &other)
	{
		for (int i = 0; i < 100; i++)
			ideas[i] = other.ideas[i];
	}

	return *this;
}

Brain::~Brain(void)
{
	std::cout << "Brain - Destructor called" << std::endl;
}
