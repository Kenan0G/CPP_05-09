/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:21:37 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/21 18:05:09 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <string>
# include <iostream>
# include <vector>
# include <limits.h>
# include <algorithm>

class Span
{
	public:
		Span(unsigned int n);
		Span(Span const &copy);
		~Span();
		Span				&operator=(Span const &copy);
		void				addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end);
		void				addNumber(int n);
		int					shortestSpan();
		int					longestSpan();

	private:
		unsigned int		_size;
		std::vector<int>	_vec;
};