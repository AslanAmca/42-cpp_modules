/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 20:50:53 by aaslan            #+#    #+#             */
/*   Updated: 2023/12/13 18:51:24 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALERCONVERTER_HPP
#define SCALERCONVERTER_HPP

#include <iostream>
#include <iomanip>
#include <climits>
#include <cfloat>
#include <stdlib.h>

class ScalarConverter
{
private:
	// Orthodox Canonical Form
	ScalarConverter(void);
	ScalarConverter(const ScalarConverter &other);
	ScalarConverter &operator=(const ScalarConverter &other);
	~ScalarConverter(void);

	// helpers
	static void validate_characters(std::string &str);
	static void print_char(std::string &str);
	static void print_int(std::string &str);
	static void print_float(std::string &str);
	static void print_double(std::string &str);

public:
	// Requirement
	static void convert(std::string &str);
};

#endif