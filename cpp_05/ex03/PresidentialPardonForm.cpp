/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:39:16 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/16 12:15:34 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 5),
													_target("default")
{
}
PresidentialPardonForm::PresidentialPardonForm(const std::string &target) :
											AForm("PresidentialPardonForm creation", 25, 5),
											_target(target)
{
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &src) : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute())
{
	*this = src;
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &src)
{
	if (this != &src)
	{
		this->_target = src._target;
	}
	return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm()
{
}

std::string PresidentialPardonForm::getTarget() const
{
	return (this->_target);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned() == false)
		throw NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw PresidentialPardonFormGradeTooHighException();

	std::cout << _target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
