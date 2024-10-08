/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whatever.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:25:45 by aaslan            #+#    #+#             */
/*   Updated: 2023/12/21 19:22:28 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WHATEVER_HPP
#define WHATEVER_HPP

template <typename T>
void swap(T &first, T &second)
{
	T temp = first;
	first = second;
	second = temp;
}

template <typename T>
T min(T first, T second)
{
	return first < second ? first : second;
}

template <typename T>
T max(T first, T second)
{
	return first > second ? first : second;
}

#endif