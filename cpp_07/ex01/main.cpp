/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 12:41:44 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/21 12:54:49 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "iter.hpp"

template <typename T>
void printElement(const T& element) {
	std::cout << element << " ";
}

int main()
{
	int intArray[] = {1, 2, 3, 4, 5};
	std::cout << "Iterating over intArray: ";
	iter(intArray, 5, printElement<int>);
	std::cout << std::endl;

	double doubleArray[] = {1.1, 2.2, 3.3, 4.4, 5.5};
	std::cout << "Iterating over doubleArray: ";
	iter(doubleArray, 5, printElement<double>);
	std::cout << std::endl;

	std::string stringArray[] = {"mot_1", "mot_2", "mot_3", "mot_4", "mot_5"};
	std::cout << "Iterating over stringArray: ";
	iter(stringArray, 5, printElement<std::string>);
	std::cout << std::endl;

	char charArray[] = {'a', 'b', 'c', 'd', 'e'};
	std::cout << "Iterating over charArray: ";
	iter(charArray, 5, printElement<char>);
	std::cout << std::endl;

	return 0;
}
