/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/25 21:33:41 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/25 22:09:11 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap	ct("Nwakaeme");
	ClapTrap	ct2("Yattara");

	for (int i = 0; i < 5; i++)
		ct2.attack("Nwakaeme");
	ct2.beRepaired(5);
	ct.beRepaired(5);
	ct.attack("Yattara");
	ct.takeDamage(20);
	ct.beRepaired(100);
	ct.attack("Yattara");

	return (0);
}
