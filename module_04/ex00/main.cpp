/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:01:50 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/29 22:34:10 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"
#include "WrongCat.hpp"

int main()
{
	const Animal *animal = new Animal();
	const Animal *dog = new Dog();
	const Animal *cat = new Cat();

	std::cout << std::endl;

	std::cout << "Animal Type : " << animal->getType() << std::endl;
	std::cout << "Dog Type : " << dog->getType() << std::endl;
	std::cout << "Cat Type : " << cat->getType() << std::endl;

	std::cout << std::endl;

	animal->makeSound();
	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl;

	delete animal;
	delete dog;
	delete cat;

	std::cout << "\n-----------------------\n" << std::endl;

	const WrongAnimal *wrongAnimal = new WrongAnimal();
	const WrongAnimal *wrongCat = new WrongCat();

	std::cout << std::endl;

	std::cout << "Wrong Animal Type : " << wrongAnimal->getType() << std::endl;
	std::cout << "Wrong Cat Type : " << wrongCat->getType() << std::endl;

	std::cout << std::endl;

	wrongAnimal->makeSound();
	wrongCat->makeSound();

	std::cout << std::endl;

	delete wrongAnimal;
	delete wrongCat;

	return 0;
}
