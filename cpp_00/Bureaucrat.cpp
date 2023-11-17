/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:57:31 by kgezgin           #+#    #+#             */
/*   Updated: 2023/11/14 17:14:39 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	try
	{
		if (grade < 1)
			throw GradeTooHighException();
		else if (grade > 150)
			throw GradeTooLowException();
	}
	catch(const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
	
}

Bureaucrat::~Bureaucrat()
{
}

Bureaucrat	&Bureaucrat::operator=(const Bureaucrat &other)
{
	if (this != &other)
		_grade = other._grade;
	return (*this);
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name)
{
	if (this != &other)
		*this = other;
}


void	Bureaucrat::levelUp(void)
{
	try
	{
		if (_grade - 1 > 0)
			_grade--;
		else
			throw GradeTooHighException();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

void	Bureaucrat::levelDown(void)
{
	try
	{
		if (_grade + 1 <= 150)
			_grade++;
		else
			throw GradeTooLowException();
	}
	catch (const std::exception& e)
	{
		std::cerr << "Error: " << e.what() << std::endl;
	}
}

const std::string	&Bureaucrat::getName() const
{
	return (_name);
}
int	Bureaucrat::getGrade() const
{
	return (_grade);
}
