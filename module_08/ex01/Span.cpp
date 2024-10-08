/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:48:59 by aaslan            #+#    #+#             */
/*   Updated: 2023/12/24 17:18:55 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Span.hpp"

// Orthodox Canonical Form
Span::Span(void) : N(0)
{
}

Span::Span(const Span &other) : N(other.N), numbers(other.numbers)
{
}

Span &Span::operator=(const Span &other)
{
	if (this != &other)
	{
		N = other.N;
		numbers = other.numbers;
	}

	return *this;
}

Span::~Span(void)
{
}

// Project Requirements
Span::Span(unsigned int N) : N(N)
{
}

void Span::addNumber(int number)
{
	if (numbers.size() >= N)
		throw std::overflow_error("Cannot add more numbers. Capacity exceeded.");

	numbers.push_back(number);
}

int Span::shortestSpan(void) const
{
	if (numbers.size() < 2)
		throw std::runtime_error("Cannot find span. Less than 2 numbers stored.");

	std::vector<int> sortedNumbers = numbers;
	std::sort(sortedNumbers.begin(), sortedNumbers.end());

	int minSpan = sortedNumbers[1] - sortedNumbers[0];
	for (size_t i = 2; i < sortedNumbers.size(); ++i)
	{
		int currentSpan = sortedNumbers[i] - sortedNumbers[i - 1];
		minSpan = std::min(minSpan, currentSpan);
	}

	return minSpan;
}

int Span::longestSpan(void) const
{
	if (numbers.size() < 2)
		throw std::runtime_error("Cannot find span. Less than 2 numbers stored.");

	int minNumber = *std::min_element(numbers.begin(), numbers.end());
	int maxNumber = *std::max_element(numbers.begin(), numbers.end());

	return maxNumber - minNumber;
}

void Span::fill(std::vector<int> &vector)
{
	if (numbers.size() + vector.size() > N)
		throw std::overflow_error("Cannot add more numbers. Capacity exceeded.");

	numbers.insert(numbers.end(), vector.begin(), vector.end());
}