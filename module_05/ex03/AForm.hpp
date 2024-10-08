/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:23:52 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/21 14:43:11 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>

// Forward Declaration
class Bureaucrat;

class AForm
{
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

public:
	// Orthodox Canonical Form
	AForm(void);
	AForm(const AForm &other);
	AForm &operator=(const AForm &other);
	virtual ~AForm(void);

	// Project Requirements
	AForm(const std::string name, const int gradeToSign, const int gradeToExecute);
	const std::string getName(void) const;
	bool getIsSigned(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;
	void beSigned(const Bureaucrat &bureaucrat);

	// Abstract Method/Function
	virtual void execute(const Bureaucrat &executor) const = 0;

	// Custom Exceptions
	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};

	class NotSignedException : public std::exception
	{
	public:
		virtual const char *what() const throw();
	};
};

// output stream override
std::ostream &operator<<(std::ostream &output, const AForm &form);

#endif