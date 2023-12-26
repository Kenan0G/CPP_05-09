/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 11:11:58 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/26 10:42:48 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include "AForm.hpp"
# include <cstdlib>
# include <ctime>

class RobotomyRequestForm : public AForm
{
	public:
		// exceptions
		class RobotomyRequestFormGradeTooHighException : public std::exception
		{
			public:
			virtual const char *what() const throw()
			{
				return ("RobotomyRequestForm grade is too High");
			}
		};
		class RobotomyRequestFormGradeTooLowException : public std::exception
		{
			public:
			virtual const char *what() const throw()
			{
				return ("RobotomyRequestForm grade is too Low");
			}
		};
		class NotSignedException : public std::exception
		{
			public:
			virtual const char *what() const throw()
			{
				return ("RobotomyRequestForm is not Signed");
			}
		};

		// member functions
		RobotomyRequestForm(const std::string &target);
		RobotomyRequestForm(const RobotomyRequestForm &src);
		RobotomyRequestForm &operator=(const RobotomyRequestForm &src);
		~RobotomyRequestForm();
		std::string getTarget()const ;
		virtual void execute(Bureaucrat const &executor) const;

	private:
		std::string _target;
};

#endif