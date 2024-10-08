/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 03:57:25 by aaslan            #+#    #+#             */
/*   Updated: 2023/12/25 04:13:46 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cerr << "Usage: " << argv[0] << " \"RPN_expression\"" << std::endl;
		return 1;
	}

	RPN rpnCalculator;
	std::string rpnExpression = argv[1];

	rpnCalculator.EvaluateExpression(rpnExpression);
	rpnCalculator.PrintResult(std::cout);

	return 0;
}
