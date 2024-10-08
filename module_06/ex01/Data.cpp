/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 23:25:49 by aaslan            #+#    #+#             */
/*   Updated: 2023/12/19 23:31:15 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Data.hpp"

// Orthodox Canonical Form
Data::Data()
{
}

Data::Data(const Data &other)
{
	(void)other;
}

Data &Data::operator=(const Data &other)
{
	(void)other;
	return *this;
}

Data::~Data(void)
{
}

Data::Data(int value) : value(value)
{
}
