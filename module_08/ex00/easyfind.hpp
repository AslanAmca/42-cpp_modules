/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 13:03:28 by aaslan            #+#    #+#             */
/*   Updated: 2023/12/24 19:03:23 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EASYFIND_HPP
#define EASYFIND_HPP

#include <vector>
#include <algorithm>
#include <stdexcept>

template <typename T>
typename T::iterator easyfind(T &container, int value)
{
	// T::iterator yerine typename ile başlamak gerekiyor.
	// Buna nedeni T::iterator ifadesinin bir değer(value) değil bir tür/tip döndürmesidir.
	typename T::iterator valuePosition = std::find(container.begin(), container.end(), value);
	if (valuePosition == container.end())
		throw std::runtime_error("Value Not Found!");

	return valuePosition;
}

#endif