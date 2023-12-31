/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 12:20:29 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/26 10:36:19 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP
# include "AForm.hpp"

class Intern
{
	public:
		Intern();
		Intern(const Intern &src);
		~Intern();
		Intern			&operator=(const Intern &src);
		AForm			*makeForm(std::string form, std::string name);
};

#endif