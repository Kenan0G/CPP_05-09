/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kgezgin <kgezgin@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 13:00:19 by kgezgin           #+#    #+#             */
/*   Updated: 2023/12/20 13:02:07 by kgezgin          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "Serialize.hpp"

int	main(void)
{
	Data originalData;
	originalData.s1 = "Hello World!";
	
	uintptr_t serializedValue = Serialize::serialize(&originalData);
	Data *deserializedData = Serialize::deserialize(serializedValue);

	if (deserializedData == &originalData)
		std::cout << "La sérialisation et la désérialisation ont réussi. Voici s1 : " << deserializedData->s1 << std::endl;
	else
		std::cout << "Erreur : Les pointeurs ne sont pas égaux." << std::endl;
	return (0);
}
