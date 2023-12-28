/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RPN.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/28 14:40:28 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/28 14:41:20 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# pragma once

# include <iostream>
# include <sstream>
# include <stack>
# include <string>
# include <cstdlib>

class RPN
{
	public:
		RPN();
		RPN(RPN const &rhs);
		~RPN();

		RPN &operator=(RPN const &rhs);

		int evaluateRPN(const std::string& expression);
	
	private:
};