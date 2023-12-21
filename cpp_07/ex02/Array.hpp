/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 14:00:27 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/21 14:13:46 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <iostream>

template <typename T>
class Array
{
	public :
		// constructeur sans parametre
		Array(): array(NULL), arraySize(0) {};

		// constructeur avec parametre
		Array(unsigned int n): arraySize(n)
		{
			this->array = new T[this->arraySize];
		}

		// constructeur par copie
		Array(const Array &src): arraySize(src.arraySize)
		{
			array = new T[arraySize];
		}

		// destructeur
		~Array()
		{
			delete[] array;
		}

		// operator =
		Array &operator=(const Array &src)
		{
			if (this != &src)
			{
				if (this->array)
					delete[] this->array;
				arraySize = src.arraySize;
				array = new T[arraySize];
				for (unsigned int i = 0; i < arraySize; i++)
					array[i] = src.array[i];
			}
			return (*this);
		};

		// operator []
		T& operator[](unsigned int index)
		{
			if (index >= arraySize || index < 0)
				throw std::out_of_range("Index hors limites");
			return (array[index]);
		};

		unsigned int size()
		{
			return (arraySize);
		};

	private :
		T*				array;
		unsigned int	arraySize;
};