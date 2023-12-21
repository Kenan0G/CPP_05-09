/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   easyfind.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 15:04:50 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/21 15:18:58 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

#include <iostream>

template <typename T>
int	easyfind(T &container, int n)
{	
	for (typename T::iterator it = container.begin(); it != container.end(); it++)
	{
		if (*it == n)
			return (*it);
	}
	throw std::runtime_error("Value not found.");
}