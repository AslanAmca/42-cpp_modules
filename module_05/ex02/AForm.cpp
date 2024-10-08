/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 17:09:01 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/20 20:34:01 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"
#include "Bureaucrat.hpp"

// Orthodox Canonical Form
AForm::AForm(void) : name("Form"), isSigned(false), gradeToSign(150), gradeToExecute(150)
{
}

AForm::AForm(const AForm &other) : name(other.name), isSigned(other.isSigned), gradeToSign(other.gradeToSign), gradeToExecute(other.gradeToExecute)
{
}

AForm &AForm::operator=(const AForm &other)
{
	if (this != &other)
		this->isSigned = other.isSigned;
	return *this;
}

AForm::~AForm(void)
{
}

// Project Requirements
// AForm üyeleri const olduğu için Constructor Initializer List kısmında değerleri verilmelidir.
AForm::AForm(const std::string name, const int gradeToSign, const int gradeToExecute) : name(name), isSigned(false), gradeToSign(gradeToSign), gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
		throw GradeTooHighException();
	if (gradeToSign > 150 || gradeToExecute > 150)
		throw GradeTooLowException();
}

const std::string AForm::getName(void) const
{
	return name;
}

bool AForm::getIsSigned(void) const
{
	return isSigned;
}

int AForm::getGradeToSign(void) const
{
	return gradeToSign;
}

int AForm::getGradeToExecute(void) const
{
	return gradeToExecute;
}

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > gradeToSign)
		throw GradeTooLowException();
	isSigned = true;
}

// Custom Exceptions
const char *AForm::GradeTooHighException::what() const throw()
{
	return "Grade is too high.";
}

const char *AForm::GradeTooLowException::what() const throw()
{
	return "Grade is too low.";
}

const char *AForm::NotSignedException::what() const throw()
{
	return "Form is not signed.";
}

std::ostream &operator<<(std::ostream &output, const AForm &form)
{
	output << "AForm: " << form.getName()
		   << ", Grade to Sign: " << form.getGradeToSign()
		   << ", Grade to Execute: " << form.getGradeToExecute()
		   << ", Signed: " << (form.getIsSigned() ? "Yes." : "No.");
	return output;
}