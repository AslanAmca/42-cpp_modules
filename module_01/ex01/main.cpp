/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:52:18 by aaslan            #+#    #+#             */
/*   Updated: 2023/06/28 01:13:22 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *zombies = zombieHorde(5, "Zombie");
	for (int i = 0; i < 5; i++)
		zombies[i].announce();
	delete[] zombies;

	return 0;
}

