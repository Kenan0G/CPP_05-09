/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:57:20 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/26 10:40:31 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "Intern.hpp"

int main()
{
	try
	{
		Bureaucrat Boss("Boss", 1);
		// Bureaucrat Recruit("Recruit", 150);
		Intern someRandomIntern;
		AForm *form;

		form = someRandomIntern.makeForm("ShrubberyCreationForm", "Bender");

		if (form != NULL)
		{
			Boss.signForm(*form);
			delete form;
		}
		else
			std::cout << "Cannot sign a NULL form." << std::endl;
		
		form = someRandomIntern.makeForm("Test", "Bender");
		if (form != NULL)
		{
			Boss.signForm(*form);
			delete form;
		}
		else
			std::cout << "Cannot sign a NULL form." << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
}
