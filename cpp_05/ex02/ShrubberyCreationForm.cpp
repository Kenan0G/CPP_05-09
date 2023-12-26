/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:11:55 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/26 10:43:26 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(const std::string &target) :
											AForm("ShrubberyCreationForm", 145, 137),
											_target(target)
{
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src) : AForm(src.getName(), src.getGradeToSign(), src.getGradeToExecute())
{
	*this = src;
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &src)
{
	if (this != &src)
	{
		this->_target = src._target;
	}
	return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm()
{
}

std::string ShrubberyCreationForm::getTarget() const
{
	return (this->_target);
}

void	ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (getIsSigned() == false)
		throw NotSignedException();
	if (executor.getGrade() > getGradeToExecute())
		throw ShrubberyCreationFormGradeTooLowException();

	std::ofstream treeFile((_target + "_shrubbery").c_str());
	if (!treeFile.is_open())
	{
		std::cerr << "Error while opening treeFile" << std::endl;
		return ;
	}
	if (treeFile.is_open())
	{
		treeFile << "    *\n";
		treeFile << "   ***\n";
		treeFile << "  *****\n";
		treeFile << " *******\n";
		treeFile << "*********\n";
		treeFile << "   |||\n";
		treeFile.close();
	}
}