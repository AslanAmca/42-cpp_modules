/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 12:59:49 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/21 15:53:30 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

// Orthodox Canonical Form
Bureaucrat::Bureaucrat(void) : name("Bureaucrat"), grade(150)
{
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : name(other.name), grade(other.grade)
{
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		this->grade = other.grade;
	return *this;
}

Bureaucrat::~Bureaucrat(void)
{
}

// Project Requirements
Bureaucrat::Bureaucrat(const std::string &name, int grade) : name(name)
{
	if (grade < 1)
		throw GradeTooHighException();
	if (grade > 150)
		throw GradeTooLowException();
	// grade const olmadığı için burada verebiliyoruz.
	// const olsaydı Constructor Initializer List kısmında tanımlanmak gerekirdi.
	this->grade = grade;
}

const std::string Bureaucrat::getName(void) const
{
	return name;
}

int Bureaucrat::getGrade(void) const
{
	return grade;
}

void Bureaucrat::incrementGrade(void)
{
	if (grade - 1 < 1)
		throw GradeTooHighException();
	grade--;
}

void Bureaucrat::decrementGrade(void)
{
	if (grade + 1 > 150)
		throw GradeTooLowException();
	grade++;
}

void Bureaucrat::signForm(AForm &form) const
{
	if (form.getIsSigned())
	{
		std::cout << getName() << " couldn’t sign " << form.getName() << " because it's already signed." << std::endl;
		return;
	}
	try
	{
		form.beSigned(*this);
		std::cout << getName() << " signed " << form.getName() << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << getName() << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void Bureaucrat::executeForm(const AForm &form)
{
	try
	{
		form.execute(*this);
		std::cout << getName() << " executed " << form.getName() << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cout << getName() << " couldn’t execute " << form.getName()
				  << " because " << e.what() << std::endl;
	}
}

// Custom Exceptions
const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

// output stream override
std::ostream &operator<<(std::ostream &output, const Bureaucrat &bureaucrat)
{
	output << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade();
	return output;
}
