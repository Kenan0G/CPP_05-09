/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialize.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 12:46:36 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/20 12:48:48 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>
#include <string>
#include <cstring>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdint.h>

struct Data
{
	std::string s1;
};


class Serialize
{
	public:
		~Serialize();
		Serialize &operator=(const Serialize &);
		static uintptr_t serialize(Data* ptr);
		static Data* deserialize(uintptr_t uintptr);

	private:
		Serialize();
		Serialize(const Serialize &src);
};