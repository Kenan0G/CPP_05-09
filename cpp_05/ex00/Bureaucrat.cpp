/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:57:31 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/13 15:41:03 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

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
