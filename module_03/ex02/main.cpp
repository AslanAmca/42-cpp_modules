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

#include "ScavTrap.hpp"
#include "FragTrap.hpp"

int main(void)
{
	FragTrap defaultFragTrap;
	defaultFragTrap.attack("FlagTrapDefaultEnemy");
	defaultFragTrap.beRepaired(13);
	defaultFragTrap.takeDamage(1337);
	defaultFragTrap.highFivesGuys();

	std::cout << "\n=====================\n\n";

	FragTrap fragTrap;
	fragTrap.attack("FlagTrapEnemy");
	fragTrap.beRepaired(13);
	fragTrap.highFivesGuys();
	fragTrap.takeDamage(1337);

	std::cout << "\n=====================\n\n";

	ScavTrap defaultScavTrap;
	defaultScavTrap.attack("ScavTrapDefaultEnemy");
	defaultScavTrap.beRepaired(13);
	defaultScavTrap.takeDamage(1337);
	defaultScavTrap.guardGate();

	std::cout << "\n=====================\n\n";

	ScavTrap scavTrap;
	scavTrap.attack("ScavTrapEnemy");
	scavTrap.beRepaired(13);
	scavTrap.guardGate();
	scavTrap.takeDamage(1337);

	std::cout << "\n=====================\n\n";

	ClapTrap defaultClapTrap;
	defaultClapTrap.attack("ClapTrapDefaultEnemy");
	defaultClapTrap.beRepaired(5);
	defaultClapTrap.takeDamage(10);

	std::cout << "\n=====================\n\n";

	ClapTrap spider("Spider");
	spider.attack("Enemy");
	spider.beRepaired(5);
	spider.takeDamage(10);

	std::cout << "\n=====================\n\n";
	return (0);
}
