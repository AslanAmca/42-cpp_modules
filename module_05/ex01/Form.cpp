/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:09:01 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/22 16:30:15 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"
#include "Bureaucrat.hpp"

// Orthodox Canonical Form
Form::Form(void) : name("Form"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

Form::Form(const Form &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

Form &Form::operator=(const Form &other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

Form::~Form(void)
{
}

// Project Requirements
// Form üyeleri const olduğu için Constructor Initializer List kısmında değerleri verilmelidir.
Form::Form(const std::string name, const int gradeToSign, const int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

const std::string Form::getName(void) const
{
	return name;
}

bool Form::getIsSigned(void) const
{
	return isSigned;
}

int Form::getGradeToSign(void) const
{
	return gradeToSign;
}

int Form::getGradeToExecute(void) const
{
	return gradeToExecute;
}

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

// Custom Exceptions
const char *Form::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

const char *Form::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

std::ostream &operator<<(std::ostream &output, const Form &form)
{
	output << "Form: " << form.getName()
		   << ", Grade to Sign: " << form.getGradeToSign()
		   << ", Grade to Execute: " << form.getGradeToExecute()
		   << ", Signed: " << (form.getIsSigned() ? "Yes." : "No.");
	return output;
}
