/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:40:31 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/28 14:42:37 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "RPN.hpp"

RPN::RPN() {}

RPN::~RPN() {}

RPN::RPN(RPN const &rhs)
{
	*this = rhs;
	return ;
}

RPN &RPN::operator=(RPN const &rhs)
{
	(void)rhs;
	return (*this);
}
