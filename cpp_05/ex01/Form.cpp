/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:25:11 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/14 15:41:40 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _isSigned(false), _gradeToSign(150), _gradeToExecute(150)
{
}

Form::Form(std::string name, const int gradeToSign, const int gradeToExecute) :
	_name(name), _isSigned(false), _gradeToSign(gradeToSign), _gradeToExecute(gradeToExecute)
{
	if (_gradeToSign > 150 || _gradeToExecute > 150)
		throw GradeTooHighException();
	else if (_gradeToSign < 1 || _gradeToExecute < 1)
		throw GradeTooLowException();
}

Form::~Form()
{
}

Form::Form(const Form &other) : _name(other._name),
								_isSigned(other._isSigned),
								_gradeToSign(other._gradeToSign),
								_gradeToExecute(other._gradeToExecute)
{
}

Form	&Form::operator=(const Form &other)
{
	if (this != &other)
	{
		_isSigned = other._isSigned;
	}
	return (*this);
}

std::string	Form::getName() const
{
	return(_name);
}

bool	Form::getIsSigned() const
{
	return (_isSigned);
}

int	Form::getGradeToSign() const
{
	return (_gradeToSign);
}

int	Form::getGradeToExecute() const
{
	return (_gradeToExecute);
}

void	Form::beSigned(Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() >= _gradeToSign)
		_isSigned = true;
	else
		throw GradeTooLowException();
}

std::ostream	&operator<<(std::ostream &os, const Form &form)
{
	os << "Form : " << form.getName() << ", grade to sign : " << form.getGradeToSign()
		<< ", grade to execute : " << form.getGradeToExecute() << ", Signed: " << (form.getIsSigned() ? "Yes" : "No") << std::endl;
	return (os);
}