/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 23:08:29 by aaslan            #+#    #+#             */
/*   Updated: 2023/12/25 02:26:52 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BITCOINEXCHANGE_HPP
#define BITCOINEXCHANGE_HPP

#include <iostream>
#include <fstream>
#include <algorithm>
#include <map>

class BitcoinExchange
{
private:
	std::map<std::string, double> database;

	// helpers
	void trim(std::string &str);

	// validators
	bool validateDate(std::string &date);
	bool validateRate(std::string &rate, bool inputControl);

public:
	// Orthodox Canonical Form
	BitcoinExchange(void);
	BitcoinExchange(const BitcoinExchange &other);
	BitcoinExchange &operator=(const BitcoinExchange &other);
	~BitcoinExchange(void);

	// Project Requirements
	void initializeDatabase(void);
	void handleInputFile(std::string &input);
};

#endif