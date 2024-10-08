/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iter.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:24:36 by aaslan            #+#    #+#             */
/*   Updated: 2023/12/21 19:57:50 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ITER_HPP
#define ITER_HPP

#include <iostream>
#include <cstdlib>

template <typename T>
void iter(T *array, size_t length, void (*function)(T &element))
{
	if (array == NULL || function == NULL)
		return;

	for (size_t i = 0; i < length; i++)
		function(array[i]);
}

template <typename T>
void printElement(T element)
{
	std::cout << element << std::endl;
}

#endif