/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:11:52 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/26 10:43:02 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
	public:
		// exceptions
		class ShrubberyCreationFormGradeTooHighException : public std::exception
		{
			public:
			virtual const char *what() const throw()
			{
				return ("ShrubberyCreationForm grade is too High");
			}
		};
		class ShrubberyCreationFormGradeTooLowException : public std::exception
		{
			public:
			virtual const char *what() const throw()
			{
				return ("ShrubberyCreationForm grade is too Low");
			}
		};
		class NotSignedException : public std::exception
		{
			public:
			virtual const char *what() const throw()
			{
				return ("ShrubberyCreationForm is not Signed");
			}
		};

		// member functions
		ShrubberyCreationForm(const std::string &target);
		ShrubberyCreationForm(const ShrubberyCreationForm &src);
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &src);
		~ShrubberyCreationForm();
		std::string getTarget()const ;
		virtual void execute(Bureaucrat const &executor) const;

	private:
		std::string _target;
};

#endif