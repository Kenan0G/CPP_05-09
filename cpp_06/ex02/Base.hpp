/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:04:36 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/20 15:38:53 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once
# include <iostream>
# include <cstdlib>
# include <ctime>

class Base
{
	public:
		virtual ~Base() {};
};

class A : public Base {};

class B : public Base {};

class C : public Base {};


// mandatory
Base	*generate();
void	identify(Base* p);
void	identify(Base &p);
