/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.spiderp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:33:41 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/26 22:33:41 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "DiamondTrap.hpp"

int main(void)
{
	DiamondTrap diamondTrap;
	diamondTrap.attack("troll");
	diamondTrap.guardGate();
	diamondTrap.takeDamage(20);
	diamondTrap.highFivesGuys();
	diamondTrap.beRepaired(10);
	diamondTrap.takeDamage(100);
	diamondTrap.whoAmI();

	std::cout << "\n----------------------------------------\n"
			  << std::endl;

	DiamondTrap diamondTrap2("ali");
	diamondTrap2.attack("troll");
	diamondTrap2.guardGate();
	diamondTrap2.takeDamage(20);
	diamondTrap2.highFivesGuys();
	diamondTrap2.beRepaired(10);
	diamondTrap2.takeDamage(100);
	diamondTrap2.whoAmI();

	return (0);
}
