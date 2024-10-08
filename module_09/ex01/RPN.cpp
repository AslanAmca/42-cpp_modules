/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aaslan <aaslan@student.42kocaeli.com.tr    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/25 03:59:58 by aaslan            #+#    #+#             */
/*   Updated: 2023/12/25 05:01:24 by aaslan           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RPN.hpp"

RPN::RPN(void)
{
}

RPN::RPN(const RPN &other) : operandStack(other.operandStack)
{
}

RPN &RPN::operator=(const RPN &other)
{
	if (this != &other)
		operandStack = other.operandStack;

	return *this;
}

RPN::~RPN(void)
{
}

// iki operand ve bir operatör alarak ilgili matematiksel operasyonu gerçekleştirir.
int RPN::performOperation(int operand1, int operand2, const std::string &op)
{
	if (op == "+")
		return operand1 + operand2;
	else if (op == "-")
		return operand1 - operand2;
	else if (op == "*")
		return operand1 * operand2;
	else if (op == "/")
	{
		if (operand2 != 0)
			return operand1 / operand2;
		else
		{
			std::cerr << "Error: Division by zero." << std::endl;
			exit(1);
		}
	}
	return 0; // Error case
}

void RPN::EvaluateExpression(const std::string &expression)
{
	// expression string'ini kelime kelime işlemek için bir istringstream kullanıyoruz.
	std::istringstream iss(expression);
	std::string token;

	// gelen string içerisinde ki boşluktan ayırarak kelime kelime okuyoruz
	while (iss >> token)
	{
		// Eğer kelime bir operatörse
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			// Stack'ten iki operand çekip işlem yapmalıyız, eğer yoksa hata vermeliyiz.
			if (operandStack.size() < 2)
			{
				std::cerr << "Error: Insufficient operands for operator " << token << std::endl;
				exit(1);
			}

			// RPN mantığı gereği operatörden önce gelen 2 sayı ile işlem yapılır.
			// stack bu yapıya çok uygundur çünkü operand gördüğümüz anda stack.top() ile en yakın sayıyı çekebiliriz.
			// daha sonra stack.pop ile bu sayıyı atar ve diğer yakın sayıyı tekrar çekebiliriz.
			// Yaptığımız işlemin sonucunu tekrar en üste koyabiliriz, çünkü stack LIFO olarak çalışır.
			int operand2 = operandStack.top();
			operandStack.pop();
			int operand1 = operandStack.top();
			operandStack.pop();
			int result = performOperation(operand1, operand2, token);

			// işlemin sonucu stack'e tekrar gönderilir.
			operandStack.push(result);
		}
		else if (token.find_first_of("0123456789") != token.npos)
		{
			// Eğer kelime bir sayıysa, daha sonra işlem yapılacağı için int'e çevrilerek stack'e eklenir.
			int operand;
			std::istringstream(token) >> operand;
			operandStack.push(operand);
		}
		else
		{
			std::cerr << "Error: invalid token in argument" << std::endl;
			exit(1);
		}
	}
}

// stack'teki en üstteki sonucu yazdırır.
// Eğer stack boşsa veya birden fazla sonuç varsa uygun hata mesajını basar.
void RPN::PrintResult(std::ostream &out)
{
	if (operandStack.empty())
	{
		std::cerr << "Error: No result to print" << std::endl;
		exit(1);
	}

	// tüm işlemlerin sonucunda stack içerisinde sadece 1 tane sonuç olmalıdır.
	if (operandStack.size() > 1)
	{
		std::cerr << "Warning: More than one result in the stack, printing the last one" << std::endl;
	}

	// buraya kadar geldiyse sonucu aldı ve stackte sadece sonuç var, onu bastırıyoruz.
	out << operandStack.top() << std::endl;
}