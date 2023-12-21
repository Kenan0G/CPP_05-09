/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:21:35 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/21 18:21:58 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "span.hpp"

Span::Span(unsigned int n) : _size(n)
{
}

Span::Span(Span const &copy)	
{
	*this = copy;
}

Span::~Span()
{
}

Span	&Span::operator=(Span const &copy)
{
	this->_size = copy._size;
	this->_vec.assign(copy._vec.begin(), copy._vec.end());
	return (*this);
}

void	Span::addNumber(int n)
{
	if (this->_vec.size() < this->_size)
		this->_vec.push_back(n);
	else
		throw std::runtime_error("Error: Span is full");
}

void	Span::addNumber(std::vector<int>::iterator begin, std::vector<int>::iterator end)
{
	if (this->_vec.size() + std::distance(begin, end) <= this->_size)
		this->_vec.insert(this->_vec.end(), begin, end);
	else
		throw std::runtime_error("Error: Span is full");
}

int	Span::shortestSpan()
{
	if (_vec.size() < 2)
		throw std::runtime_error("Not enough elements");
	
	int shortest = INT_MAX;
	int span;

	for (size_t i = 0; i < _vec.size(); i++)
	{
		for (size_t j = i + 1; j < _vec.size(); j++)
		{
			span = std::abs(_vec[i] - _vec[j]);
			if (span < shortest) {
				shortest = span;
			}
		}
	}

	return (shortest);
}

int Span::longestSpan()
{
	if (_vec.size() < 2)
		throw std::runtime_error("Not enough elements");

	std::sort(_vec.begin(), _vec.end());

	return (_vec.back() - _vec.front());
}