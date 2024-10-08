/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 19:55:37 by aaslan            #+#    #+#             */
/*   Updated: 2023/12/20 20:07:57 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "A.hpp"
#include "B.hpp"
#include "C.hpp"

Base *generate(void)
{
	Base *base = NULL;
	std::srand(time(NULL));
	int number = std::rand() % 3;

	if (number == 0)
	{
		base = new A();
		std::cout << "generate() => A" << std::endl;
	}
	else if (number == 1)
	{
		base = new B();
		std::cout << "generate() => B" << std::endl;
	}
	else if (number == 2)
	{
		base = new C();
		std::cout << "generate() => C" << std::endl;
	}

	return base;
}

void identify(Base *p)
{
	if (dynamic_cast<A *>(p) != NULL)
		std::cout << "identify(*p) => A" << std::endl;
	else if (dynamic_cast<B *>(p) != NULL)
		std::cout << "identify(*p) => B" << std::endl;
	else if (dynamic_cast<C *>(p) != NULL)
		std::cout << "identify(*p) => C" << std::endl;
	else
		std::cout << "identify(*p) => NULL" << std::endl;
}

void identify(Base& p)
{
	try
	{
		(void)dynamic_cast<A &>(p);
		std::cout << "identify(&p) => A" << std::endl;
		return;
	}
	catch (const std::exception& e)
	{
	}

	try
	{
		(void)dynamic_cast<B &>(p);
		std::cout << "identify(&p) => B" << std::endl;
		return;
	}
	catch (const std::exception& e)
	{
	}

	try
	{
		(void)dynamic_cast<C &>(p);
		std::cout << "identify(&p) => C" << std::endl;
		return;
	}
	catch (const std::exception& e)
	{
	}

	std::cout << "identify(&p) => NULL" << std::endl;
}

int main(void)
{
	Base *basePointer = generate();
	identify(basePointer);
	identify(*basePointer);

	delete basePointer;
}
