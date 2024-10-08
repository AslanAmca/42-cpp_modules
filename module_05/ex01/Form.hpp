/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 15:23:52 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/20 17:08:27 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>

// Forward Declaration
class Bureaucrat;

class Form
{
private:
	const std::string name;
	bool isSigned;
	const int gradeToSign;
	const int gradeToExecute;

public:
	// Orthodox Canonical Form
	Form(void);
	Form(const Form &other);
	Form &operator=(const Form &other);
	~Form(void);

	// Project Requirements
	Form(const std::string name, const int gradeToSign, const int gradeToExecute);
	const std::string getName(void) const;
	bool getIsSigned(void) const;
	int getGradeToSign(void) const;
	int getGradeToExecute(void) const;
	void beSigned(const Bureaucrat &bureaucrat);

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
};

// output stream override
std::ostream &operator<<(std::ostream &output, const Form &form);

#endif