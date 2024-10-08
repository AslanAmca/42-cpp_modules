/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:48:35 by aaslan            #+#    #+#             */
/*   Updated: 2023/12/24 17:21:11 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

class Span
{
private:
	unsigned int N;
	std::vector<int> numbers;

public:
	// Orthodox Canonical Form
	Span(void);
	Span(const Span &other);
	Span &operator=(const Span &other);
	~Span(void);

	// Project Requirements
	Span(unsigned int N);
	void addNumber(int number);
	int shortestSpan(void) const;
	int longestSpan(void) const;

	// Helper
	void fill(std::vector<int> &vector);
};

#endif