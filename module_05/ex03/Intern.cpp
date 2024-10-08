#include "Intern.hpp"
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:48:03 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/21 18:48:04 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

// Orthodox Canonical Form
Intern::Intern(void)
{
}

Intern::Intern(const Intern &other)
{
	(void)other;
}

Intern &Intern::operator=(const Intern &other)
{
	(void)other;
	return *this;
}

Intern::~Intern(void)
{
}

// Project Requirements
AForm *Intern::makeForm(const std::string name, const std::string target)
{
	const std::string names[3] = {
		"presidential pardon",
		"robotomy request",
		"shrubbery creation"
	};

	AForm *(Intern::*makers[3])(const std::string) = {
		&Intern::makePresidentialPardonForm,
		&Intern::makeRobotomyRequestForm,
		&Intern::makeShrubberyCreationForm
	};

	for (int i = 0; i < 3; i++)
	{
		if (name == names[i])
		{
			std::cout << "Intern creates " << name << std::endl;
			return (this->*makers[i])(target);
		}
	}

	throw InvalidFormNameException();
}

// Helper Private Functions for Subject Requirements (if-elseif ugly)
AForm *Intern::makePresidentialPardonForm(const std::string target)
{
	return new PresidentialPardonForm(target);
}

AForm *Intern::makeRobotomyRequestForm(const std::string target)
{
	return new RobotomyRequestForm(target);
}

AForm *Intern::makeShrubberyCreationForm(const std::string target)
{
	return new ShrubberyCreationForm(target);
}

// Custom Exception
const char *Intern::InvalidFormNameException::what() const throw()
{
	return "Invalid Form Name.";
}
