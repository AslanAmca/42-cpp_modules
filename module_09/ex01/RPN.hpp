/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 03:54:02 by aaslan            #+#    #+#             */
/*   Updated: 2023/12/25 04:54:01 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RPN_HPP
#define RPN_HPP

#include <iostream>
#include <sstream>
#include <stack>
#include <cstdlib>

class RPN
{
private:
	std::stack<int> operandStack;
	int performOperation(int operand1, int operand2, const std::string &op);

public:
	RPN(void);
	RPN(const RPN &other);
	RPN &operator=(const RPN &other);
	~RPN(void);

	void EvaluateExpression(const std::string &expr);
	void PrintResult(std::ostream &out);
};

#endif // RPN_HPP
