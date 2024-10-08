/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 14:50:21 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/21 16:02:21 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"
#include <fstream>

// Orthodox Canonical Form
ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("ShrubberyCreationForm", 145, 137), target("target")
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other) : AForm(other), target(other.target)
{

}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other)
{
	if (this != &other)
		this->target = other.target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
}

// Project Requirements
ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) : AForm("ShrubberyCreationForm", 145, 137), target(target)
{
}

void ShrubberyCreationForm::execute(const Bureaucrat &executor) const
{
	if (!getIsSigned())
		throw NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw GradeTooLowException();

	std::string fileName = target + "_shrubbery";
	std::ofstream outputFile(fileName.c_str());
	if (!outputFile.is_open())
	{
		std::cout << "Error : file named " << fileName << " cannot be opened." << std::endl;
		return;
	}
	outputFile << ""
				  "              ,@@@@@@@,\n"
				  "      ,,,.   ,@@@@@@@@@,  .oo8888o.\n"
				  "   ,&&&&&&&&,@@@@@@@@@@@@,888888888o\n"
				  "  ,&&&&&&&&&&,@@@@@@@@@@@88888888888'\n"
				  "  &&&&&&&&&&&&@@@@@@@@@@@88888888888'\n"
				  "  &&&&& &&&&&&@@@ @ @@@' `8888 `888'\n"
				  "  `&&  `  &&'    |.|         |'|8'\n"
				  "      |.|        |.|         |'|\n"
				  "      |.|        |.|         |'|\n";
	outputFile.close();
}