/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:46:14 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/20 13:00:01 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serialize.hpp"

Serialize::Serialize()
{
}

Serialize::Serialize(const Serialize &src)
{
	*this = src;
}

Serialize::~Serialize()
{
}

Serialize &Serialize::operator=(const Serialize &)
{
	return *this;
}

uintptr_t Serialize::serialize(Data* ptr)
{
	uintptr_t uintptr = reinterpret_cast<uintptr_t>(ptr);
	return (uintptr);
}

Data* Serialize::deserialize(uintptr_t uintptr)
{
	Data *ptr = reinterpret_cast<Data *>(uintptr);
	return (ptr);
}