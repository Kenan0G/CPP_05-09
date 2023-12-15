/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:57:31 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/15 10:38:23 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"

Bureaucrat::Bureaucrat(const std::string name, int grade) : _name(name), _grade(grade)
{
	if (grade < 1)
		throw GradeTooHighException();
	else if (grade > 150)
		throw GradeTooLowException();
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
	if (_grade - 1 > 0)
		_grade--;
	else
		throw GradeTooHighException();
}

void	Bureaucrat::levelDown(void)
{
	if (_grade + 1 <= 150)
		_grade++;
	else
		throw GradeTooLowException();
}

const std::string	&Bureaucrat::getName() const
{
	return (_name);
}
int	Bureaucrat::getGrade() const
{
	return (_grade);
}

void	Bureaucrat::signForm(AForm &form)
{
	try
	{
		form.beSigned(*this);
		std::cout << _name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " couldn't sign " << form.getName() << " because " << e.what() << std::endl;
	}
}

void	Bureaucrat::executeForm(AForm const & aform) const
{
	try
	{
		aform.execute(*this);
		std::cout << _name << " executed successfully " << aform.getName() << " form" << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cout << _name << " could not execute " << aform.getName() << " because " << e.what() << std::endl;
	}
}


std::ostream	&operator<<(std::ostream &os, const Bureaucrat &bureaucrat)
{
	os << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << std::endl;
	return os;
}