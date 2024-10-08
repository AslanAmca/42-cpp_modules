/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 16:02:29 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/21 18:45:27 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"
#include <cstdlib> // rand(), srand()
#include <ctime>   // time()

// Orthodox Canonical Form
RobotomyRequestForm::RobotomyRequestForm(void) : AForm("RobotomyRequestForm", 72, 45), target("target")
{
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other) : AForm(other), target(other.target)
{
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other)
{
	if (this != &other)
		this->target = other.target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
}

// Project Requirements
RobotomyRequestForm::RobotomyRequestForm(const std::string &target) : AForm("RobotomyRequestForm", 72, 45), target(target)
{
}

void RobotomyRequestForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::cout << "--> Drilling Noises <--" << std::endl;

	// Randomizer
	std::srand(std::time(NULL));
	// 0 - 1
	double randomRatio = (double)std::rand() / RAND_MAX;
	// check %50
	if (randomRatio <= 0.5)
		std::cout << target << " has been robotomized successfully." << std::endl;
	else
		std::cout << "Robotomization of " << target << " has failed." << std::endl;
}