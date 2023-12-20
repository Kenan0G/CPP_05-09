/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:25:11 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/15 09:19:52 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
}

AForm::AForm(std::string name, const int gradeToSign, const int gradeToExecute) :
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooHighException();
	else if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooLowException();
}

AForm::~AForm()
{
}

AForm::AForm(const AForm &other) : _name(other._name),
								_isSigned(other._isSigned),
								_gradeToSign(other._gradeToSign),
								_gradeToExecute(other._gradeToExecute)
{
}

AForm	&AForm::operator=(const AForm &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

std::string	AForm::getName() const
{
	return(_name);
}

bool	AForm::getIsSigned() const
{
	return (_isSigned);
}

int	AForm::getGradeToSign() const
{
	return (_gradeToSign);
}

int	AForm::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void	AForm::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() <= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

void	AForm::execute(Bureaucrat const &executor) const
{
	if (_isSigned == false)
	{
		std::cout << executor.getName() << " could not execute " << _name << " because it is not signed" << std::endl;
		return ;
	}
	else if (executor.getGrade() > _gradeToExecute)
	{
		std::cout << executor.getName() << " could not execute " << _name << " because his grade is too low" << std::endl;
		return ;
	}
}


std::ostream	&operator<<(std::ostream &os, const AForm &aform)
{
	os << "AForm: " << aform.getName() << ", grade to sign: " << aform.getGradeToSign()
		<< ", grade to execute: " << aform.getGradeToExecute() << ", Signed: " << (aform.getIsSigned() ? "Yes" : "No") << std::endl;
	return (os);
}
