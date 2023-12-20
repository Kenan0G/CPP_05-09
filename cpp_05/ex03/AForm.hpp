/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:25:23 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/15 09:23:47 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP
# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"
# include <fstream>

class Bureaucrat ;

class AForm
{
	public:
		// Exceptions
		class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw() {
				return "Grade is too High";
			}
		};
		class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw() {
				return "Grade is too Low";
			}
		};
		
		// member functions
		AForm();
		AForm(std::string name, const int gradeToSign, const int gradeToExecute);
		AForm(const AForm &other);
		virtual ~AForm();
		AForm				&operator=(const AForm &other);
		std::string			getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(Bureaucrat bureaucrat);
		virtual void		execute(Bureaucrat const &executor) const = 0;


	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream	&operator<<(std::ostream &os, const AForm &aform);

#endif