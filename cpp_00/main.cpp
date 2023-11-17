/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:57:20 by kgezgin           #+#    #+#             */
/*   Updated: 2023/11/14 17:17:26 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main()
{
	Bureaucrat	goku("Goku", 0);
	Bureaucrat	vegeta("Vegeta", 1);
	Bureaucrat	piccolo("piccolo", 50);
	Bureaucrat	saibaman("saibaman", 150);
	Bureaucrat	mrSatan("Mr.Satan", 180);
	
	std::cout << goku << std::endl;
	std::cout << vegeta << std::endl;
	std::cout << piccolo << std::endl;
	std::cout << saibaman << std::endl;
	std::cout << mrSatan << std::endl;

// TODO: enlever try/catch des foonctions membres et faire un try dans le main a la place.

	return 0;
}

std::ostream	&operator<<(std::ostream& os, const Bureaucrat& bureaucrat)
{
    os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
    return os;
}