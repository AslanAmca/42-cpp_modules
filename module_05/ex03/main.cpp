/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:42:04 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/22 16:25:00 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat bureaucrat("Ali", 1);
		Intern intern;

		// Valid
		AForm *presidentialPardon = intern.makeForm("presidential pardon", "Aslan");
		bureaucrat.signForm(*presidentialPardon);
		bureaucrat.executeForm(*presidentialPardon);
		delete presidentialPardon;

		std::cout << "----------------" << std::endl;

		// Valid
		AForm *shrubberyCreation = intern.makeForm("shrubbery creation", "Aslan");
		bureaucrat.signForm(*shrubberyCreation);
		bureaucrat.executeForm(*shrubberyCreation);
		delete shrubberyCreation;

		std::cout << "----------------" << std::endl;

		// Invalid form name
		AForm *randomForm = intern.makeForm("random form", "veli");
		bureaucrat.signForm(*randomForm);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception Message: " << e.what() << std::endl;
	}

	return 0;
}
