/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:57:22 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/16 11:36:10 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP
# include <iostream>
# include <string>
# include <stdexcept>
# include "Form.hpp"

class Form;

class Bureaucrat
{
	public:
		~Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat			&operator=(const Bureaucrat &other);

		const std::string	&getName(void) const;
		int					getGrade(void) const;
		void				levelUp(void);
		void				levelDown(void);
		void				signForm(Form &form);

		class GradeTooHighException : public std::exception {
		public:
			const char* what() const throw() {
				return "Grade of Bureaucrat is too High";
			}
		};
		class GradeTooLowException : public std::exception {
		public:
			const char* what() const throw() {
				return "Grade of Bureaucrat is too Low";
			}
		};

	private:
		const std::string	_name;
		int					_grade;
};

std::ostream		&operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

#endif