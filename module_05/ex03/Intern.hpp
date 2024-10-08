/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/21 18:47:55 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/22 16:19:14 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP

#include "AForm.hpp"

class Intern
{
private:
	AForm *makePresidentialPardonForm(const std::string target);
	AForm *makeRobotomyRequestForm(const std::string target);
	AForm *makeShrubberyCreationForm(const std::string target);

public:
	// Orthodox Canonical Form
	Intern(void);
	Intern(const Intern &other);
	Intern &operator=(const Intern &other);
	~Intern(void);

	// Project Requirements
	AForm *makeForm(const std::string name, const std::string target);

	// Custom Exception
	class InvalidFormNameException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

#endif