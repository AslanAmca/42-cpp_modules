/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:01:50 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/30 18:01:03 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

void subject_test(void)
{
	std::cout << "*** Subject Test ***" << std::endl;

	const Animal *j = new Dog();
	const Animal *i = new Cat();

	std::cout << std::endl;

	delete j;
	delete i;

	std::cout << "------------------------------------------"
			  << std::endl;
}

void array_test(void)
{
	std::cout << "*** Creating an array[4] of animals, half dog and half cat ***" << std::endl;
	Animal *animals[4];
	for (int i = 0; i < 4; i++)
	{
		if (i < 2)
			animals[i] = new Dog();
		else
			animals[i] = new Cat();
	}

	std::cout << std::endl;

	std::cout << "*** We delete the created animals ***" << std::endl;
	for (int i = 0; i < 4; i++)
		delete animals[i];

	std::cout << "------------------------------------------"
			  << std::endl;
}

void copy_test(void)
{
	std::cout << "*** Test Shallow Copy or Deep Copy ***"
			  << std::endl;

	Dog dog1;
	Dog dog2(dog1);
	std::cout << "\nDog 1 Brain Address : " << dog1.getBrain() << std::endl;
	std::cout << "Dog 2 Brain Address : " << dog2.getBrain() << std::endl;

	std::cout << std::endl;

	Cat cat1;
	Cat cat2;
	cat1 = cat2;
	std::cout << "\nCat 1 Brain Address : " << cat1.getBrain() << std::endl;
	std::cout << "Cat 2 Brain Address : " << cat2.getBrain() << "\n"
			  << std::endl;
}

int main(void)
{
	subject_test();
	array_test();
	copy_test();

	return 0;
}
