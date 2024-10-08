/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 20:28:46 by aaslan            #+#    #+#             */
/*   Updated: 2023/12/22 18:47:37 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP

template <typename T>
class Array
{
private:
	T *array;
	unsigned int length;
public:
	Array(void);
	Array(unsigned int n);
	Array(const Array &other);
	Array &operator=(const Array &other);
	~Array(void);

	T &operator[](unsigned int index);
	unsigned int size(void) const;
};

#endif