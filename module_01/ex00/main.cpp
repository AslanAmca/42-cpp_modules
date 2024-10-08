/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/25 13:20:39 by aaslan            #+#    #+#             */
/*   Updated: 2023/06/28 01:02:10 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

int main(void)
{
	Zombie *heapZombie = newZombie("Heap Zombie");
	heapZombie->announce();
	delete heapZombie;

	randomChump("Stack Zombie");
	
	return 0;
}
