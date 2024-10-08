/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.tpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 18:44:45 by aaslan            #+#    #+#             */
/*   Updated: 2023/12/22 19:00:57 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_TPP
#define ARRAY_TPP

#include "Array.hpp"

template <typename T>
Array<T>::Array() : array(new T[0]), length(0)
{
}

template <typename T>
Array<T>::Array(unsigned int n) : array(new T[n]), length(n)
{
}

template <typename T>
Array<T>::Array(const Array &other) : array(new T[other.size()]), length(other.size())
{
	for (unsigned int i = 0; i < length; ++i)
		array[i] = other.array[i];
}

template <typename T>
Array<T> &Array<T>::operator=(const Array &other)
{
	if (this != &other)
	{
		delete[] array;
		array = new T[other.size()];
		length = other.size();
		for (unsigned int i = 0; i < length; ++i)
			array[i] = other.array[i];
	}
	return *this;
}

template <typename T>
Array<T>::~Array()
{
	delete[] array;
}

template <typename T>
T &Array<T>::operator[](unsigned int index)
{
	if (index >= length)
		throw std::out_of_range("Index out of bounds");

	return array[index];
}

template <typename T>
unsigned int Array<T>::size() const
{
	return length;
}

#endif