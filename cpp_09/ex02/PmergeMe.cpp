/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:28:29 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/28 15:45:15 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "PmergeMe.hpp"

PmergeMe::PmergeMe() {}

PmergeMe::~PmergeMe() {}

PmergeMe::PmergeMe(PmergeMe const &rhs)
{
	*this = rhs;
	return ;
}

PmergeMe &PmergeMe::operator=(PmergeMe const &rhs)
{
	(void)rhs;
	return (*this);
}

PmergeMe::PmergeMe(int ac, char **av)
{
	clock_t			timeStart;
	clock_t			timeEnd;
	double			timeVecResult;
	double			timeDequeResult;

	std::vector<std::string>	vect;
	std::deque<std::string>		deque;

	for (int i; i < ac; i++)
	{
		vect.push_back(av[i]);
		deque.push_back(av[i]);
	}
	std::cout << "list to sort: ";
	print(vect);
	
	timeStart = clock();
	sort(vect);
	timeEnd = clock();
	timeVecResult = (timeEnd - timeStart) / static_cast<double>(CLOCKS_PER_SEC / 1000);
	
	timeStart = clock();
	sort(deque);
	timeEnd = clock();
	timeDequeResult = (timeEnd - timeStart) / static_cast<double>(CLOCKS_PER_SEC / 1000);

	std::cout << "sorted list: ";
	print(vect);
	std::cout << "to sort " << ac << " elements, vector took " << timeVecResult << " ms" << std::endl;
	std::cout << "to sort " << ac << " elements, deque took " << timeDequeResult << " ms" << std::endl;
}

