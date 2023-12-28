/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 15:28:27 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/28 15:41:34 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <deque>
#include <vector>
#include <climits>

class PmergeMe
{
	public:
		PmergeMe();
		PmergeMe(int ac, char **av);
		PmergeMe(PmergeMe const &rhs);
		~PmergeMe();

		PmergeMe	&operator=(PmergeMe const &rhs);

		template <typename T>
		void		PmergeMe::sort(T &container);

		template <typename T>
		void		PmergeMe::merge(T &container);
		
		template <typename T>
		void		PmergeMe::print(T &container);
	
	private:
};