/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:27:55 by aaslan            #+#    #+#             */
/*   Updated: 2023/12/12 18:16:27 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error!\nThe program must take 1 argument." << std::endl;
		return 1;
	}

	if (argv[1][0] == '\0')
	{
		std::cout << "Error!\nThe argument value cannot be empty." << std::endl;
		return 1;
	}

	std::string str(argv[1]);
	ScalarConverter::convert(str);

	return 0;
}
