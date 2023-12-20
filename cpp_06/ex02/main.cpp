/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 15:37:56 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/20 15:43:03 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Base.hpp"

int main()
{
	srand(time(0));
	Base *base1 = generate();
	Base *base2 = generate();
	Base *base3 = generate();
	
	std::cout << "base1 = " << std::endl;
	identify(base1);
	identify(*base1);

	std::cout << "base2 = " << std::endl;
	identify(base2);
	identify(*base2);
	
	std::cout << "base3 = " << std::endl;
	identify(base3);
	identify(*base3);

	delete base1;
	delete base2;
	delete base3;
	return (0);
}