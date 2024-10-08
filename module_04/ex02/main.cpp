/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/29 20:01:50 by aaslan            #+#    #+#             */
/*   Updated: 2023/07/30 19:32:57 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"
#include "Cat.hpp"

int main(void)
{
	// compile error because AAnimal is abstract class
	// AAnimal test1;
	// AAnimal *test2 = new AAnimal();

	const AAnimal *dog = new Dog();
	const AAnimal *cat = new Cat();

	std::cout << "\n*** Get Type ***" << std::endl;

	std::cout << "Dog Type : " << dog->getType() << std::endl;
	std::cout << "Cat Type : " << cat->getType() << std::endl;

	std::cout << "\n*** Make Sound ***" << std::endl;
	dog->makeSound();
	cat->makeSound();

	std::cout << std::endl;

	delete dog;
	delete cat;

	return 0;
}
