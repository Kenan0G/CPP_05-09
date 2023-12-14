/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:57:20 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/14 15:42:01 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

int main()
{
	std::cout << "--------Random----------" << std::endl;
	try
	{
		Bureaucrat Random("Random", 50);
		Form Alt1("Alt1", 50, 10);
		Form Alt2("Alt2", 20, 20);
		std::cout << Random << Alt1 << Alt2;
		Random.signForm(Alt1);
		Random.signForm(Alt2);
		std::cout << Alt1 << Alt2;
		std::cout << "-------Operateur = ---------" << std::endl;
		Alt1 = Alt2;
		std::cout << Alt1 << Alt2;
	}
	catch (std::exception &e)
	{
		std::cout << e.what();
	}
		
	return 0;
}
