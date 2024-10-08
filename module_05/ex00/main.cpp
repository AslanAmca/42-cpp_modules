/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:42:04 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/19 14:42:55 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat highGradeBureaucrat("Ali", 2);
		std::cout << highGradeBureaucrat << std::endl;

		highGradeBureaucrat.incrementGrade();
		std::cout << highGradeBureaucrat << std::endl;

		Bureaucrat lowGradeBureaucrat("Veli", 150);
		std::cout << lowGradeBureaucrat << std::endl;

		lowGradeBureaucrat.decrementGrade();
		std::cout << lowGradeBureaucrat << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << "Exception Message: " << e.what() << std::endl;
	}

	return 0;
}
