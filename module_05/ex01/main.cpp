/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 14:42:04 by aaslan            #+#    #+#             */
/*   Updated: 2023/11/20 20:31:42 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat bureaucrat("Ali", 3);
		Form formA("Form A", 2, 2);
		Form formB("Form B", 3, 3);
		
		bureaucrat.signForm(formA);
		bureaucrat.signForm(formB);
	}
	catch (std::exception &e)
	{
		std::cout << "Exception Message: " << e.what() << std::endl;
	}

	return 0;
}
