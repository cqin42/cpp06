/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christine <christine@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:28:07 by christine         #+#    #+#             */
/*   Updated: 2024/02/06 08:32:29 by christine        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

int main()
{
	Data data;
	data.c = 'C';
	data.i = 42;

	uintptr_t serialize = Serialization::serialize(&data);
	Data *deserialize = Serialization::deserialize(serialize);

	if (deserialize == &data)
		std::cout << "Successful" << std::endl;
	else
		std::cout << "Failed" << std::endl;
}
