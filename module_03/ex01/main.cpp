/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:33:41 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/29 19:54:31 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap figura("Figura");
	figura.attack("Chris Rock");
	figura.takeDamage(6);
	figura.beRepaired(4);
	figura.takeDamage(3);
	figura.guardGate();
	figura.beRepaired(8);
	figura.takeDamage(17);

	std::cout << "----------------------------------------" << std::endl;

	ClapTrap dur("Máquina");
	dur.attack("Thor");
	dur.takeDamage(6);
	dur.beRepaired(4);
	dur.takeDamage(3);
	dur.beRepaired(8);
	dur.takeDamage(17);
	return (0);
}
