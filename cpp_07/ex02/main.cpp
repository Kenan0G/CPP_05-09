/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:01:31 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/21 14:13:49 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Array.hpp"

int	main(void)
{
	try
	{
		Array<int> intArray;
		for (unsigned int i = 0; i < intArray.size(); ++i)
			intArray[i] = i * 10;

		std::cout << "Integer Array: ";
		for (unsigned int i = 0; i < intArray.size(); ++i)
			std::cout << intArray[i] << " ";
		std::cout << std::endl;

		Array<char> charArray(4);
		for (unsigned int i = 0; i < charArray.size(); ++i)
			charArray[i] = 'A' + i;

		std::cout << "Char Array: ";
		for (unsigned int i = 0; i < charArray.size(); ++i)
			std::cout << charArray[i] << " ";
		std::cout << std::endl;

		Array<double> doubleArray(3);
		for (unsigned int i = 0; i < doubleArray.size(); ++i)
			doubleArray[i] = i * 3.14;

		std::cout << "Double Array: ";
		for (unsigned int i = 0; i < doubleArray.size(); ++i)
			std::cout << doubleArray[i] << " ";
		std::cout << std::endl;

		Array<double> copyArray;
		doubleArray[0] = 8.5;
		copyArray = doubleArray;
		std::cout << "Copied Double Array: ";
		for (unsigned int i = 0; i < copyArray.size(); ++i)
			std::cout << copyArray[i] << " ";
		std::cout << std::endl;
	}
	catch (const std::exception &e)
	{
		std::cerr << "\nError: " << e.what() << std::endl;
	}
	return (0);
}