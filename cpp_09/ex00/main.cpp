/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/26 13:02:14 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/27 14:08:42 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "BitcoinExchange.hpp"

// TODO input file parsing
/*
	- check if the file is open
	- check if the file is empty
	- check if the file has only one line
	- check values line per line
*/
// TODO data file parsing
/*
	- check if the file is open
	- check if the file is empty
	- check if the file has only one line
	- check values line per line

*/
// TODO get line from input file
// TODO get the correct date from data file
// TODO print the bitcoin value for that date

int main(int ac, char **av)
{
	if (ac != 2)
	{
		std::cout << "Usage: ./bitcoin [input_file]" << std::endl;
		return (1);
	}
	BitcoinExchange bitcoin(av[1]);
	return (0);
}