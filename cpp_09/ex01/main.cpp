/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 12:33:19 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/28 14:53:36 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

int evaluateRPN(const std::string& expression)
{
	std::stack<int> stack;
	std::istringstream iss(expression);
	std::string token;

	int num1, num2;
	while (iss >> token)
	{
		if (token == "+" || token == "-" || token == "*" || token == "/")
		{
			if (stack.size() < 2)
				throw std::runtime_error("Error: need more digits for operation");

			//* recuperer et supprimer les 2 derniers elements de la pile
			num2 = stack.top();
			stack.pop();
			num1 = stack.top();
			stack.pop();

			//* effectuer l'operation et la mettre dans la pile
			if (token == "+") stack.push(num1 + num2);
			else if (token == "-") stack.push(num1 - num2);
			else if (token == "*") stack.push(num1 * num2);
			else if (token == "/")
			{
				if (num2 == 0)
					throw std::runtime_error("Error: Division by zero");
				stack.push(num1 / num2);
			}
		}
		else if (token.size() == 1 && std::isdigit(token[0]))
			stack.push(std::atoi(token.c_str()));
		else
			throw std::runtime_error("Error: Invalid input");
	}

	if (stack.size() != 1) {
		throw std::runtime_error("Error: in expression");
	}

	return stack.top();
}

int main(int argc, char* argv[])
{
	try
	{
		if (argc != 2)
			throw std::runtime_error("usage: ./RPN \"expression\"");
		std::cout << evaluateRPN(argv[1]) << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}