/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 13:34:55 by aaslan            #+#    #+#             */
/*   Updated: 2023/06/27 22:41:01 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
#define PHONEBOOK_HPP

#include "Contact.hpp"

class PhoneBook
{
private:
	Contact contacts[8];
	int contactCount;

public:
	PhoneBook(void);
	~PhoneBook(void);

	void addContact(void);
	void searchContact(void);
	void printContact(int index);
	int getContactCount(void);
	std::string getFormattedField(std::string field);
};
#endif
