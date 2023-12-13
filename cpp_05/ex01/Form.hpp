/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/11 13:25:23 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/13 15:41:44 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <string>
# include <stdexcept>

class Form
{
	public:
		Form(std::string name, const int gradeToSign, const int gradeToExecute);
		Form(const Form &other);
		~Form();
		Form				&operator=(const Form &other);

	private:
		const std::string	_name;
		bool				_isSigned;
		const int			_gradeToSign;
		const int			_gradeToExecute;

};

std::ostream	&operator<<(std::ostream &os, const Form &form);
