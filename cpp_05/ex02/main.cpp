/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:57:20 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/16 15:36:42 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main()
{
	try
	{
		srand(time(0));
		std::cout << "--------ShrubberyCreationForm----------" << std::endl;
		Bureaucrat Boss("Boss", 1);
		Bureaucrat Recruit("Recruit", 150);
		ShrubberyCreationForm f1("tree");
		std::cout << Boss << Recruit << f1 << std::endl;

		Boss.executeForm(f1);
		Recruit.executeForm(f1);
		Recruit.signForm(f1);
		Boss.signForm(f1);
		Recruit.executeForm(f1);
		Boss.executeForm(f1);
		std::cout << f1 << std::endl;

		std::cout << "--------RobotomyRequestForm---------" << std::endl;
		RobotomyRequestForm f2("frank");
		Boss.executeForm(f2);
		Recruit.executeForm(f2);
		Recruit.signForm(f2);
		Boss.signForm(f2);
		Recruit.executeForm(f2);
		Boss.executeForm(f2);
		Boss.executeForm(f2);
		Boss.executeForm(f2);
		Boss.executeForm(f2);

		std::cout << std::endl << "--------PresidentialPardonForm--------" << std::endl;
		PresidentialPardonForm f3("eden");
		Boss.executeForm(f3);
		Recruit.executeForm(f3);
		Recruit.signForm(f3);
		Boss.signForm(f3);
		Recruit.executeForm(f3);
		Boss.executeForm(f3);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	return 0;
}
