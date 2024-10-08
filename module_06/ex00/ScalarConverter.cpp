/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:50:50 by aaslan            #+#    #+#             */
/*   Updated: 2023/12/14 11:15:17 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
}

ScalarConverter::ScalarConverter(const ScalarConverter &other)
{
	(void)other;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &other)
{
	(void)other;
	return *this;
}

ScalarConverter::~ScalarConverter(void)
{
}

void ScalarConverter::validate_characters(std::string &str)
{
	if (str.length() == 1 || str == "-inff" || str == "+inff" || str == "nanf" || str == "-inf" || str == "+inf" || str == "nan")
		return;

	if (str.find_first_not_of(' ') == str.npos)
	{
		std::cout << "Error!\nThe argument value cannot consist of only spaces." << std::endl;
		exit(1);
	}

	if (str.find_first_not_of("+-.fF0123456789") != str.npos)
	{
		std::cout << "Error!\nThe argument value contains invalid character." << std::endl;
		exit(1);
	}

	int sign_count = 0;
	int dot_count = 0;
	int f_count = 0;
	for (size_t i = 0; i < str.length(); i++)
	{
		if (str[i] == '+' || str[i] == '-')
			sign_count++;

		if (str[i] == '.')
			dot_count++;

		if (str[i] == 'f' || str[i] == 'F')
			f_count++;

		if (sign_count > 1 || dot_count > 1 || f_count > 1)
		{
			std::cout << "Error!\nThe argument value can contain only 1 of each special character (+-.fF)." << std::endl;
			exit(1);
		}
	}

	if ((str.find('+') != str.npos && str[0] != '+') || (str.find('-') != str.npos && str[0] != '-'))
	{
		std::cout << "Error!\nThe signature sign (+ -) of the argument value must be at the beginning." << std::endl;
		exit(1);
	}

	if ((str.find('f') != str.npos && str[str.length() - 1] != 'f') || (str.find('F') != str.npos && str[str.length() - 1] != 'F'))
	{
		std::cout << "Error!\nIf the argument value is to be float, the f or F character must be at the end." << std::endl;
		exit(1);
	}

	if (str[0] == '0' || ((str[0] == '+' || str[0] == '-') && str[1] == '0'))
	{
		std::cout << "Error!\nThe argument value cannot start with 0." << std::endl;
		exit(1);
	}
}

void ScalarConverter::print_char(std::string &str)
{
	if (str.length() == 1)
	{
		char charValue = static_cast<char>(str[0]);

		if (std::isdigit(charValue) || !std::isprint(charValue))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << charValue << "'" << std::endl;
	}
	else
	{
		long long longValue = atoll(str.c_str());
		char charValue = static_cast<char>(longValue);

		if (str == "-inff" || str == "+inff" || str == "nanf" || str == "-inf" || str == "+inf" || str == "nan")
			std::cout << "char: impossible" << std::endl;
		else if (longValue < 0 || longValue > 255)
			std::cout << "char: impossible" << std::endl;
		else if (!std::isprint(longValue))
			std::cout << "char: Non displayable" << std::endl;
		else
			std::cout << "char: '" << charValue << "'" << std::endl;
	}
}

void ScalarConverter::print_int(std::string &str)
{
	long long longValue = atoll(str.c_str());
	int intValue = static_cast<int>(longValue);

	if (str == "-inff" || str == "+inff" || str == "nanf" || str == "-inf" || str == "+inf" || str == "nan")
		std::cout << "char: impossible" << std::endl;
	else if (longValue < INT_MIN || longValue > INT_MAX || (str.length() == 1 && !std::isdigit(str[0])))
		std::cout << "int: impossible" << std::endl;
	else
		std::cout << "int: " << intValue << std::endl;
}

void ScalarConverter::print_float(std::string &str)
{
	double doubleValue = atof(str.c_str());
	float floatValue = static_cast<float>(doubleValue);

	if (str == "-inff" || str == "-inf")
		std::cout << "float: " << "-inff" << std::endl;
	else if (str == "+inff" || str == "+inf")
		std::cout << "float: " << "+inff" << std::endl;
	else if (str == "nanf" || str == "nan")
		std::cout << "float: " << "nanf" << std::endl;
	else if (doubleValue < -FLT_MAX || doubleValue > FLT_MAX || (str.length() == 1 && !std::isdigit(str[0])))
		std::cout << "float: impossible" << std::endl;
	else if (str.find('.') == str.npos)
		std::cout << "float: " << floatValue << ".0f" << std::endl;
	else
	{
		int precisionLength = str.length() - (str.find('.') + 1);

		if (str[str.length() - 1] == 'f' || str[str.length() - 1] == 'F')
			precisionLength--;

		std::cout << "float: " << std::fixed << std::setprecision(precisionLength) << floatValue << "f" << std::endl;
	}
}

void ScalarConverter::print_double(std::string &str)
{
	double doubleValue = atof(str.c_str());

	if (str == "-inff" || str == "-inf")
		std::cout << "double: " << "-inf" << std::endl;
	else if (str == "+inff" || str == "+inf")
		std::cout << "double: " << "+inf" << std::endl;
	else if (str == "nanf" || str == "nan")
		std::cout << "double: " << "nan" << std::endl;
	else if (doubleValue < -DBL_MAX || doubleValue > DBL_MAX || (str.length() == 1 && !std::isdigit(str[0])))
		std::cout << "double: impossible" << std::endl;
	else if (str.find('.') == str.npos)
		std::cout << "double: " << doubleValue << ".0" << std::endl;
	else
	{
		int precisionLength = str.length() - (str.find('.') + 1);

		if (str[str.length() - 1] == 'f' || str[str.length() - 1] == 'F')
			precisionLength--;

		std::cout << "double: " << std::fixed << std::setprecision(precisionLength) << doubleValue << std::endl;
	}
}

void ScalarConverter::convert(std::string &str)
{
	validate_characters(str);
	print_char(str);
	print_int(str);
	print_float(str);
	print_double(str);
}
