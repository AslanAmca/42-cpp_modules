/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Harl.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/26 12:16:10 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/29 19:13:14 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

void Harl::debug(void)
{
	std::cout << "[ DEBUG ]\n"
			  << "I love having extra bacon for my 7XL-double-cheese-triple-pickle-special-ketchup burger. "
			  << "I really do!\n"
			  << std::endl;
}

void Harl::info(void)
{
	std::cout << "[ INFO ]\n"
			  << "I cannot believe adding extra bacon costs more money. "
			  << "You didn’t put enough bacon in my burger! If you did, I wouldn’t be asking for more!\n"
			  << std::endl;
}

void Harl::warning(void)
{
	std::cout << "[ WARNING ]\n"
			  << "I think I deserve to have some extra bacon for free. "
			  << "I’ve been coming for years whereas you started working here since last month.\n"
			  << std::endl;
}

void Harl::error(void)
{
	std::cout << "[ ERROR ]\n"
			  << "This is unacceptable! I want to speak to the manager now.\n"
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
			switch (i)
			{
			case 0:
				(this->*functions[0])();
				(this->*functions[1])();
				(this->*functions[2])();
				(this->*functions[3])();
				break;
			case 1:
				(this->*functions[1])();
				(this->*functions[2])();
				(this->*functions[3])();
				break;
			case 2:
				(this->*functions[2])();
				(this->*functions[3])();
				break;
			case 3:
				(this->*functions[3])();
				break;
			default:
				break;
			}
			return;
		}
	}

	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}
