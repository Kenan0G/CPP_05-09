/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/15 10:39:16 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/15 10:41:15 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM
# define PRESIDENTIALPARDONFORM

# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
	public:
		// exceptions
		class PresidentialPardonFormGradeTooHighException : public std::exception
		{
			public:
			virtual const char *what() const throw()
			{
				return ("PresidentialPardonForm grade is too High");
			}
		};
		class PresidentialPardonFormGradeTooLowException : public std::exception
		{
			public:
			virtual const char *what() const throw()
			{
				return ("PresidentialPardonForm grade is too Low");
			}
		};
		class NotSignedException : public std::exception
		{
			public:
			virtual const char *what() const throw()
			{
				return ("PresidentialPardonForm is not Signed");
			}
		};

		// member functions
		PresidentialPardonForm();
		PresidentialPardonForm(const std::string &target);
		PresidentialPardonForm(const PresidentialPardonForm &src);
		PresidentialPardonForm &operator=(const PresidentialPardonForm &src);
		~PresidentialPardonForm();
		std::string getTarget()const ;
		virtual void execute(Bureaucrat const &executor) const;

	private:
		std::string target;
};

#endif