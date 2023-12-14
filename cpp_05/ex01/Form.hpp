/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:25:23 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/14 15:41:45 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP
# include <iostream>
# include <string>
# include <stdexcept>
# include "Bureaucrat.hpp"
class Bureaucrat ;

class Form
{
	public:
		Form();
		Form(std::string name, const int gradeToSign, const int gradeToExecute);
		Form(const Form &other);
		~Form();
		Form				&operator=(const Form &other);
		std::string			getName() const;
		bool				getIsSigned() const;
		int					getGradeToSign() const;
		int					getGradeToExecute() const;
		void				beSigned(Bureaucrat bureaucrat);

		class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw() {
				return "Grade trop élevé";
			}
		};
		class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw() {
				return "Grade trop bas";
			}
		};

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;
};

std::ostream	&operator<<(std::ostream &os, const Form &form);

#endif