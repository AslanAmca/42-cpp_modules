/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:16:10 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/29 18:54:15 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n"
			  << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. "
			  << "I really do!"
			  << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]\n"
			  << "I cannot believe adding extra bacon costs more money. "
			  << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!"
			  << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]\n"
			  << "I think I deserve to have some extra bacon for free. "
			  << "I’ve been coming for years whereas you started working here since last month."
			  << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\n"
			  << "This is unacceptable! I want to speak to the manager now."
			  << std::endl;
}

void Harl::complain(std::string level)
{
	void (Harl::*functions[4])(void) = {&Harl::debug, &Harl::info, &Harl::warning, &Harl::error};

	std::string levels[4] = {"DEBUG", "INFO", "WARNING", "ERROR"};

	for (int i = 0; i < 4; i++)
	{
		if (level == levels[i])
		{
			(this->*functions[i])();
			return;
		}
	}

	std::cout << "*** "
			  << level << " is not a valid level!"
			  << " ***"
			  << std::endl;
}
