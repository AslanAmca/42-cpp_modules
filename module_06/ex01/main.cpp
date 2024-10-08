/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 19:27:55 by aaslan            #+#    #+#             */
/*   Updated: 2023/12/19 23:47:41 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serializer.hpp"

int main()
{
	Data myData(42);
	std::cout << "Data Adress: " << &myData << "\n"
			  << "Data Value : " << myData.value
			  << std::endl;

	std::cout << "------------------------" << std::endl;

	// Get the address using serialize()
	uintptr_t serializedPtr = Serializer::serialize(&myData);
	std::cout << "Data serialized to uintptr_t." << std::endl;

	// Get original address using deserialize()
	Data *deserializedPtr = Serializer::deserialize(serializedPtr);
	std::cout << "uintptr_t deserialized to Data." << std::endl;

	std::cout << "------------------------" << std::endl;

	// Print Deserialized Data
	std::cout << "Deserialized Data Adress: " << deserializedPtr << "\n"
			  << "Deserialized Data Value : " << deserializedPtr->value
			  << std::endl;

	std::cout << "------------------------" << std::endl;

	// Compare two pointers for address
	if (&myData == deserializedPtr)
		std::cout << "Serialization and deserialization successful!" << std::endl;
	else
		std::cout << "Serialization and deserialization failed!" << std::endl;

	return 0;
}
