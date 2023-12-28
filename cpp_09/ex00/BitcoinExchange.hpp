/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:23:32 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/28 10:50:16 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <fstream>
# include <sstream>
# include <map>
# include <cstdlib>
# include <cmath>
# include <algorithm>
# include <climits>
# define DATA_FILE 0
# define INPUT_FILE 1
# define YEAR 0 
# define MONTH 1
# define DAY 2
# define PRICE 3


class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(std::string filename);
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();
		BitcoinExchange					&operator=(const BitcoinExchange &src);
		void							fileParsing(int flag);
		void							checkLine(std::string line, int flag);
		void							checkDate(std::string line, int flag);
		void							checkValue(std::string line, std::stringstream &ss, int flag);
		int								InputLine(std::string line);
		void							printLine(std::string line);

	private:
		std::string						_inputFilename;
		std::string						_splitLine[4];
		double							_value;
		std::map<std::string, double>	_map;
};
