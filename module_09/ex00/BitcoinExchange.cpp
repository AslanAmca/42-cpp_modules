/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 23:08:25 by aaslan            #+#    #+#             */
/*   Updated: 2023/12/26 05:22:43 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "BitcoinExchange.hpp"

// Orthodox Canonical Form
BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &other) : database(other.database)
{
}

BitcoinExchange &BitcoinExchange::operator=(const BitcoinExchange &other)
{
	if (this != &other)
		this->database = other.database;

	return (*this);
}

BitcoinExchange::~BitcoinExchange() {}

// Helpers
void BitcoinExchange::trim(std::string &str)
{
	std::string::iterator it = str.begin();

	while (it != str.end() && std::isspace(*it))
	{
		++it;
	}

	str.erase(str.begin(), it);

	std::string::reverse_iterator rit = str.rbegin();

	while (rit != str.rend() && std::isspace(*rit))
	{
		++rit;
	}

	str.erase(rit.base(), str.end());
}

// Validators
bool BitcoinExchange::validateDate(std::string &date)
{
	if (date.find_first_not_of("0123456789-") != std::string::npos || std::count(date.begin(), date.end(), '-') != 2)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}

	if (date.length() != 10 || date[4] != '-' || date[7] != '-')
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}

	std::string year = date.substr(0, 4);
	std::string month = date.substr(5, 2);
	std::string day = date.substr(8, 2);

	int yearValue = std::atoi(year.c_str());
	if (yearValue < 2009 || yearValue > 2022)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}

	int monthValue = std::atoi(month.c_str());
	if (monthValue < 1 || monthValue > 12)
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}

	int dayValue = std::atoi(day.c_str());
	if (dayValue < 1 || dayValue > 31 ||
		(monthValue == 2 && dayValue > 28) || (monthValue == 4 && dayValue > 30) ||
		(monthValue == 6 && dayValue > 30) || (monthValue == 9 && dayValue > 30) || (monthValue == 11 && dayValue > 30))
	{
		std::cerr << "Error: bad input => " << date << std::endl;
		return false;
	}

	return true;
}

bool BitcoinExchange::validateRate(std::string &rate, bool inputControl)
{
	if (rate.find_first_not_of("0123456789-.") != std::string::npos)
	{
		std::cerr << "Error: bad input => " << rate << std::endl;
		return false;
	}

	size_t dotCount = std::count(rate.begin(), rate.end(), '.');

	if (dotCount > 1 || (dotCount == 1 && (rate[0] == '.' || rate[rate.length() - 1] == '.')))
	{
		std::cerr << "Error: bad input => " << rate << std::endl;
		return false;
	}

	size_t minusCount = std::count(rate.begin(), rate.end(), '-');
	if (minusCount > 1 || (minusCount == 1 && rate[0] != '-'))
	{
		std::cerr << "Error: bad input => " << rate << std::endl;
		return false;
	}

	double rateValue = atof(rate.c_str());

	if (rateValue < 0)
	{
		std::cerr << "Error: not a positive number." << std::endl;
		return false;
	}

	if (inputControl && rateValue > 1000)
	{
		std::cerr << "Error: too large a number." << std::endl;
		return false;
	}

	return true;
}

// Read and init data.csv
void BitcoinExchange::initializeDatabase(void)
{
	std::ifstream dataFile("data.csv");
	std::string line;

	if (!dataFile.is_open())
		throw std::runtime_error("Error: could not open database file.");

	if (dataFile.peek() == std::ifstream::traits_type::eof())
		throw std::runtime_error("Error: database file is empty.");

	if (std::getline(dataFile, line) && line != "date,exchange_rate")
		throw std::runtime_error("Error: invalid header in the database file.");

	while (std::getline(dataFile, line))
	{
		if (line.empty())
			throw std::runtime_error("Error: empty line in the database file.");

		if (line.find_first_not_of("0123456789-,. ") != std::string::npos)
			throw std::runtime_error("Error: invalid line in the database file => " + line);

		size_t delimiterPosition = line.find(',');

		if (delimiterPosition == std::string::npos || std::count(line.begin(), line.end(), ',') != 1 ||
			line[0] == ',' || line[0] == '-' || line[line.length() - 1] == ',' || line[line.length() - 1] == '-')
			throw std::runtime_error("Error: invalid line in the database file => " + line);

		std::string date = line.substr(0, delimiterPosition);
		std::string rate = line.substr(delimiterPosition + 1);

		database.insert(std::make_pair(date, atof(rate.c_str())));
	}
}

// Read and handle input file
void BitcoinExchange::handleInputFile(std::string &input)
{
	std::ifstream inputFile(input.c_str());
	std::string line;

	if (!inputFile.is_open())
		throw std::runtime_error("Error: could not open input file.");

	if (inputFile.peek() == std::ifstream::traits_type::eof())
		std::cerr << "Error: input file is empty." << std::endl;

	if (std::getline(inputFile, line) && line != "date | value")
		std::cerr << "Error: invalid header in the input file." << std::endl;

	while (std::getline(inputFile, line))
	{
		if (line.empty())
		{
			std::cerr << "Error: empty line in the input file." << std::endl;
			continue;
		}

		if (line.find_first_not_of("0123456789-.| ") != std::string::npos)
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		size_t pipePosition = line.find('|');

		if (pipePosition == std::string::npos || std::count(line.begin(), line.end(), '|') != 1 ||
			line[0] == '|' || line[0] == '-' || line[line.length() - 1] == '|' || line[line.length() - 1] == '-')
		{
			std::cerr << "Error: bad input => " << line << std::endl;
			continue;
		}

		std::string date = line.substr(0, pipePosition);
		std::string rate = line.substr(pipePosition + 1);

		trim(date);
		trim(rate);

		if (validateDate(date) == false)
			continue;

		if (validateRate(rate, true) == false)
			continue;

		// lower_bound fonksiyonu, belirtilen tarihi içeren veya belirtilen tarihten daha büyük ilk öğeyi döndürür.
		std::map<std::string, double>::iterator it = database.lower_bound(date);

		// Eğer it iterator'ünün tarihi aranan tarih ile eşleşmiyorsa, it'yi bir önceki tarihe kaydırır.
		// Bu, belirtilen tarihten küçük olan en son tarihi bulmaya çalışır.
		if (it->first != date)
			it--;

		// Rate değerini iteratorün bulunduğu öğenin (it->second) değeri ile çarpar.
		// Bu işlem, döviz kuru ile oranı çarpar ve sonucu exchange adlı değişkende saklar.
		double exchange = std::atof(rate.c_str()) * it->second;
		std::cout << date << " => " << rate << " = " << exchange << std::endl;
	}
}
