/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 13:44:59 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/20 12:02:05 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once
# include <cmath>
# include <cstdlib>
# include <iomanip>
# include <iostream>
# include <limits.h>
# include <limits>
# include <sstream>
# include <string>

class ScalarConverter
{
	public:
		static bool isChar(const std::string &input);
		static bool isInt(const std::string &input);
		static bool isFloat(const std::string &input);
		static bool isDouble(const std::string &input);

		static void convert(const std::string &input);
		static void printChar(char c);
		static void printInt(double n);
		static void printDouble(double d);
		static void printFloat(float f);

	private:
		ScalarConverter();
		ScalarConverter(const ScalarConverter &);
		ScalarConverter &operator=(const ScalarConverter &src);
		std::string		_value;
};

