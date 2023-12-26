/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   MutantStack.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/22 11:05:41 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/22 11:44:09 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <deque>
# include <stack>

template <typename T, typename Container = std::deque<T> >

class MutantStack : public std::stack<T>
{
	public:
		MutantStack()
		{
			return ;
		}
		MutantStack(const MutantStack &src)
		{
			*this = src;
			return ;
		}
		~MutantStack()
		{
			return ;
		}
		MutantStack &operator=(const MutantStack &src)
		{
			if (*this != &src)
				this->c = src.c;
		}

		typedef typename std::stack<T, Container>::container_type::iterator iterator;

		iterator begin()
		{
			return (this->c.begin());
		}
		iterator end()
		{
			return (this->c.end());
		}
};
