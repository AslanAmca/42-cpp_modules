/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Data.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 23:22:15 by aaslan            #+#    #+#             */
/*   Updated: 2023/12/19 23:32:52 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DATA_HPP
#define DATA_HPP

class Data
{
private:
	// Orthodox Canonical Form
	Data(void);
	Data(const Data &other);
	Data &operator=(const Data &other);

public:
	int value;
	Data(int value);
	~Data(void);
};


#endif