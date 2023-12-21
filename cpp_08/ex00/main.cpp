/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:04:17 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/21 15:19:51 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "easyfind.hpp"
#include <vector>
#include <list>

int main()
{
	std::vector<int> vec;
	std::list<int> lst;

	for (int i = 0; i < 10; i++)
	{
		vec.push_back(i);
		lst.push_back(i);
	}

	try
	{
		std::cout << easyfind(vec, 5) << std::endl;
		std::cout << easyfind(lst, 5) << std::endl;
		std::cout << easyfind(vec, 9) << std::endl;
		std::cout << easyfind(lst, 120) << std::endl;
	}
	catch (std::runtime_error &e)
	{
		std::cout << e.what() << std::endl;
	}
	return (0);
}