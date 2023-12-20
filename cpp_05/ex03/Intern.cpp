/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:20:32 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/16 13:07:15 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Intern.hpp"
# include "PresidentialPardonForm.hpp"
# include "RobotomyRequestForm.hpp"
# include "ShrubberyCreationForm.hpp"

Intern::Intern()
{
}

Intern::Intern(const Intern &src)
{
	*this = src;
}

Intern &Intern::operator=(const Intern &)
{
	return (*this);
}

Intern::~Intern()
{
}

AForm	*Intern::makeForm(std::string form, std::string target)
{
	std::string	form_names[3] = {"PresidentialPardonForm",
								"RobotomyRequestForm",
								"ShrubberyCreationForm"};
	AForm *forms[] = {
		new ShrubberyCreationForm(target),
		new RobotomyRequestForm(target),
		new PresidentialPardonForm(target)};
	AForm	*result = NULL;

	for (int i = 0; i < 3; i++)
	{
		if (form.compare(form_names[i]) == 0)
		{
			std::cout << "Intern creates " << form_names[i] << std::endl;
			result = forms[i];
		}
		else
			delete (forms[i]);
	}
	if (!result)
		std::cout << "Intern could not create " << form << " form ..." << std::endl;
	return (result);
}
