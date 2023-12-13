/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:57:20 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/12 08:22:10 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	// vegeta va se creer mais on ne pourra pas de faire de lvlup
	try
	{
		Bureaucrat	vegeta("Vegeta", 1);
		std::cout << vegeta;
		vegeta.levelUp();
		std::cout << vegeta;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// saibaman va se creer mais on ne pourra pas de faire de lvlDown
	try
	{
		std::cout << std::endl;
		Bureaucrat	saibaman("saibaman", 150);
		std::cout << saibaman;
		saibaman.levelDown();
		std::cout << saibaman;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// ici tout fonctionne sans throw
	try
	{
		std::cout << std::endl;
		Bureaucrat	piccolo("piccolo", 20);
		std::cout << piccolo;
		piccolo.levelUp();
		std::cout << piccolo;
		piccolo.levelDown();
		std::cout << piccolo;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// ici Goku a un grade trop eleve donc il y a un throw et Cell n'est pas cree
	try
	{
		std::cout << std::endl;
		Bureaucrat	goku("Goku", 0);
		std::cout << goku;
		
		Bureaucrat	Cell("Cell", 10);
		std::cout << Cell;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}

	// ici c'est pareil, mrSatan a un grade trop bas
	try
	{
		std::cout << std::endl;
		Bureaucrat	mrSatan("Mr.Satan", 180);
		std::cout << mrSatan;

		Bureaucrat	Cell("Cell", 10);
		std::cout << Cell;
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	return 0;
}

std::ostream	&operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return os;
}
