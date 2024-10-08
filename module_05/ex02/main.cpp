/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:42:04 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/21 17:54:09 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	try
	{
		Bureaucrat bureaucrat("Ali", 1);

		ShrubberyCreationForm shrubberyCreationForm("Home");
		bureaucrat.signForm(shrubberyCreationForm);
		bureaucrat.executeForm(shrubberyCreationForm);

		std::cout << "--------------" << std::endl;

		RobotomyRequestForm robotomyRequestForm("Aslan");
		bureaucrat.signForm(robotomyRequestForm);
		bureaucrat.executeForm(robotomyRequestForm);

		std::cout << "--------------" << std::endl;

		PresidentialPardonForm presidentialPardonForm("Emre");
		bureaucrat.signForm(presidentialPardonForm);
		bureaucrat.executeForm(presidentialPardonForm);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception Message: " << e.what() << std::endl;
	}

	return 0;
}
