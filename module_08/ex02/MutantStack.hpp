/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/24 17:31:35 by aaslan            #+#    #+#             */
/*   Updated: 2023/12/24 21:51:58 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MUTANTSTACK_HPP
#define MUTANTSTACK_HPP

#include <stack>

template <typename T>
class MutantStack : public std::stack<T>
{
public:
	// Orthodox Canonical Form
	MutantStack(void) : std::stack<T>() {}
	MutantStack(const MutantStack &other) : std::stack<T>(other) {}
	MutantStack &operator=(const MutantStack &other)
	{
		std::stack<T>::operator=(other);
		return *this;
	}
	~MutantStack(void) {}

	// Project Requirements
	/*
	-- std::stack<T>::container_type --
	std::stack sınıfı, bir adaptör sınıfıdır ve içerisinde belirli bir container türü ile çalışır.
	Varsayılan olarak std::stack sınıfı, elemanları saklamak için std::deque container'ını kullanır.
	Yani, std::stack<int> tanımlandığında, std::stack<int>::container_type türü std::deque<int>'dir.

	-- std::stack<T>::container_type::iterator --
	Bu, std::stack'in altındaki container'ın iterator türüne erişmek için kullanılır.

	Bu tip değerleri görmek için main içinde std::stack<int>:: ifadesi kullanılabilir, intellisense devamını getirecektir.
	Örneğin : std::stack<int>::container_type::iterator
	*/
	typedef typename std::stack<T>::container_type::iterator iterator;
	typedef typename std::stack<T>::container_type::reverse_iterator reverse_iterator;
	typedef typename std::stack<T>::container_type::const_iterator const_iterator;
	typedef typename std::stack<T>::container_type::const_reverse_iterator const_reverse_iterator;

	iterator begin(void)
	{
		return this->c.begin();
	}

	iterator end(void)
	{
		return this->c.end();
	}

	reverse_iterator rbegin(void)
	{
		return this->c.rbegin();
	}

	reverse_iterator rend(void)
	{
		return this->c.rend();
	}

	const_iterator cbegin(void)
	{
		return this->c.cbegin();
	}

	const_iterator cend(void)
	{
		return this->c.cend();
	}

	const_reverse_iterator crbegin(void)
	{
		return this->c.crbegin();
	}

	const_reverse_iterator crend(void)
	{
		return this->c.crend();
	}
};

#endif
