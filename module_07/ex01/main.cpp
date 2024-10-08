/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:40:27 by aaslan            #+#    #+#             */
/*   Updated: 2023/12/21 19:57:16 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

int main(void)
{
	int intArray[5] = {10, 5, 9, 12, 7};
	float floatArray[3] = {2.42, 5.69, 42.61};
	std::string stringArray[4] = {"ecole", "42", "cpp_07", "teplate"};

	std::cout << "--- Result of iter the int array ---" << std::endl;
	iter<int>(intArray, 5, printElement);

	std::cout << "--- Result of iter the float array ---" << std::endl;
	iter<float>(floatArray, 3, printElement);

	std::cout << "--- Result of iter the string array ---" << std::endl;
	iter<std::string>(stringArray, 4, printElement);

	return 0;
}