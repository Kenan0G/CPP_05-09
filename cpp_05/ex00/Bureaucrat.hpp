/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 14:57:22 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/13 15:40:45 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <stdexcept>

class Bureaucrat
{
	public:
		~Bureaucrat();
		Bureaucrat();
		Bureaucrat(const std::string name, int grade);
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat			&operator=(const Bureaucrat &other);

		const std::string	&getName(void) const;
		int					getGrade(void) const;
		void				levelUp(void);
		void				levelDown(void);

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
		int					_grade;
};

std::ostream		&operator<<(std::ostream &os, const Bureaucrat &bureaucrat);

