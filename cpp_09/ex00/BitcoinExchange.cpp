/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   BitcoinExchange.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:23:35 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/28 12:11:11 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

BitcoinExchange::BitcoinExchange() {}

BitcoinExchange::~BitcoinExchange() {}

BitcoinExchange::BitcoinExchange(const BitcoinExchange &src)
{
	if (this != &src)
		*this = src;
}

BitcoinExchange	&BitcoinExchange::operator=(const BitcoinExchange &src)
{
	if (this != &src)
	{
		this->_map = src._map;
	}
	return (*this);
}

BitcoinExchange::BitcoinExchange(std::string filename) : _inputFilename(filename)
{
	try
	{
		fileParsing(0);
		fileParsing(1);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}

void	BitcoinExchange::fileParsing(int flag)
{
	
    std::string file = (flag == DATA_FILE) ? "data.csv" : _inputFilename;
	std::ifstream	data(file.c_str());
	std::string		line;

	// check if file exist
	if (!data.is_open())
		throw std::invalid_argument("Error: data.csv file not found");

	// check first line of file
	std::getline(data, line);
	if (flag == DATA_FILE && line != "date,exchange_rate")
		throw std::invalid_argument("Error: data.csv file not valid : first line must be \"date,exchange_rate\"");
	else if (flag == INPUT_FILE && line != "date | value")
		throw std::invalid_argument("Error: input file not valid : first line must be \"date | value\"");
	
	// check other lines of file
	while (getline(data, line))
	{
		if (flag == DATA_FILE)
			checkLine(line, flag);
		else
		{
			try
			{
				checkLine(line, flag);
			}
			catch(const std::exception& e)
			{
				std::cerr << e.what() << '\n';
			}
		}
	}
	data.close();
}

void	BitcoinExchange::checkLine(std::string line, int flag)
{
	checkDate(line, flag);
}

void	BitcoinExchange::checkDate(std::string line, int flag)
{
	//* stocker la date dans un tableau de string (year, month, day)
	std::string date[3];
	std::stringstream ss(line);
	std::getline(ss, date[0], '-');
	std::getline(ss, date[1], '-');
	if (flag == DATA_FILE)
		std::getline(ss, date[2], ',');
	else 
		std::getline(ss, date[2], ' ');

	//* verifier year.size == 4 , etc
	if (date[YEAR].size() != 4 || date[MONTH].size() != 2 || date[DAY].size() != 2)
		throw std::invalid_argument("Error: date should be : YYYY-MM-DD");


	//* stocker la date en int dans un tableau de int (year, month, day)
	int dateValue[3];
	for (int i = 0; i < 3; i++)
		dateValue[i] = std::atol(date[i].c_str());

	//* definir les dates max et min (year, month, day)
	int max[3] = {2023, 12, 31};
	int min[3] = {2009, 1, 1};


	//* recuperer le nombre de jours dans le mois pour avoir un max day precis
	if (dateValue[MONTH] < 8)
		max[3] = (dateValue[MONTH] % 2 == 0 ? 30 : 31);
	else if (dateValue[MONTH] > 8)
		max[3] = (dateValue[MONTH] % 2 ? 30 : 31);
	if (dateValue[MONTH] == 2)
		max[3] = (dateValue[YEAR] % 4) ? 28 : 29;


	//* verifier pour chaque date si elle est comprise entre les dates min et max
	for (int i = 0; i < 3; i++)
	{
		if (date[i].empty() || dateValue[i] < min[i] || dateValue[i] > max[i])
			throw std::invalid_argument("Error: date not valid");
		else if (date[i].find_first_not_of("0123456789") != std::string::npos)
			throw std::invalid_argument("Error: not only numbers in date");
	}
	for (int i = 0; i < 3; i++)
		_splitLine[i] = date[i];
	checkValue(line, ss, flag);
}

// fonction check date (meme pour data et input)
// fonction check ',' ou ' | '
// fonction check exchange rate ()

void	BitcoinExchange::checkValue(std::string line, std::stringstream &ss, int flag)
{
	if (flag == DATA_FILE)
	{
		ss >> _splitLine[PRICE];
		for (int i = 0; _splitLine[PRICE][i]; i++)
		{
			if (_splitLine[PRICE][i] == '.' && !std::isdigit(_splitLine[PRICE][i + 1]))
				throw std::invalid_argument("Error: exchange rate not valid");
		}
		size_t n = std::count(_splitLine[PRICE].begin(), _splitLine[PRICE].end(), '.');
		if (n > 1)
			throw std::invalid_argument("Error: one \'.\' only in exchange rate");
		if (ss.fail() || !ss.eof() || _splitLine[PRICE].empty() || _splitLine[PRICE].find_first_not_of("0123456789.") != std::string::npos || std::strtod(_splitLine[PRICE].c_str(), NULL) < 0)
			throw std::invalid_argument("Error: exchange rate not valid");
		_map.insert(std::pair<std::string, double>(line.substr(0, 10), std::strtod(_splitLine[PRICE].c_str(), NULL)));
	}
	else
	{
		ss >> _splitLine[PRICE];
		if (_splitLine[PRICE].empty() || _splitLine[PRICE].find_first_not_of("|") != std::string::npos)
			throw std::invalid_argument("Error: '|' missing");
		ss >> _splitLine[PRICE];
		for(int i = 0; _splitLine[PRICE][i]; i++)
		{
			if (_splitLine[PRICE][i] == '.' && !std::isdigit(_splitLine[PRICE][i + 1]))
				throw std::invalid_argument("Error: value not valid");
		}
		size_t n = std::count(_splitLine[PRICE].begin(), _splitLine[PRICE].end(), '.');
		if (n > 1)
			throw std::invalid_argument("Error: one \'.\' only in value");
		if (std::strtod(_splitLine[PRICE].c_str(), NULL) > INT_MAX || std::strtod(_splitLine[PRICE].c_str(), NULL) > 1000)
			throw std::invalid_argument("Error: value must be between 0 and 1000");
		if (std::strtod(_splitLine[PRICE].c_str(), NULL) < 0)
			throw std::invalid_argument("Error: value must be positive");
		if (ss.fail() || !ss.eof() || _splitLine[PRICE].empty() || _splitLine[PRICE].find_first_not_of("0123456789.") != std::string::npos)
			throw std::invalid_argument("Error: not only numbers in value");
		_value = std::strtod(_splitLine[PRICE].c_str(), NULL);
		printLine(line);
	}
}

void	BitcoinExchange::printLine(std::string line)
{
	int check = _map.count(line.substr(0, 10));

	//* si la date n'est pas dans le map, on cherche la date inferieure la plus proche
	if (!check)
	{
		std::map<std::string, double>::iterator it = _map.begin();
		std::string temp = it->first;
		for(; it != _map.end(); it++)
		{
			if (it->first > temp && it->first < line.substr(0, 10))
				temp = it->first;
		}
		std::cout << line.substr(0, 10) << " => " << _value << " = " << _map[temp] * _value << std::endl;
	}
	else //* si la date est dans le map, on affiche le resultat directement
		std::cout << line.substr(0, 10) << " => " << _value << " = " << _map[line.substr(0, 10)] * _value << std::endl;
}