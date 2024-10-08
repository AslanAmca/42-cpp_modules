/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 06:38:53 by aaslan            #+#    #+#             */
/*   Updated: 2023/12/25 07:04:51 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP

#include <iostream>
#include <ctime>
#include <sstream>
#include <cstddef>
#include <algorithm>
#include <deque>
#include <vector>

class PmergeMe
{
public:
	// Orthodox Canonical Form
	PmergeMe();
	~PmergeMe();
	PmergeMe &operator=(const PmergeMe &other);
	PmergeMe(const PmergeMe &other);

	// Vector sort functions
	void mergeInsertSortVector(std::vector<int> &container, int start, int end);
	void mergeSortVector(std::vector<int> &container, int start, int mid, int end);
	void insertSortVector(std::vector<int> &container, int start, int end);

	// Deque sort functions
	void mergeInsertSortDeque(std::deque<int> &container, int start, int end);
	void mergeSortDeque(std::deque<int> &container, int start, int mid, int end);
	void insertSortDeque(std::deque<int> &container, int start, int end);

	// Calcualte time functions
	void runVector(std::vector<int> &container);
	void runDeque(std::deque<int> &container);

	// Utility functions
	void calculateTime(std::vector<int> &vector, std::deque<int> &deque, double &vecTime, double &deqTime);
	void print(std::vector<int> &vec, std::deque<int> &deq);
	int midPoint(int start, int end);
};

#endif