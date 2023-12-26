/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:23:32 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/26 20:10:32 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <string>
# include <map>

class BitcoinExchange
{
	public:
		BitcoinExchange();
		BitcoinExchange(const BitcoinExchange &src);
		~BitcoinExchange();
		BitcoinExchange						&operator=(const BitcoinExchange &src);
		void								parsingData();
		void								parsingInput(std::string filename);
		int									checkInputLine(std::string line);
		int									checkDataLine(std::string line);

	private:
		std::map<std::string, double>	_map;
};
