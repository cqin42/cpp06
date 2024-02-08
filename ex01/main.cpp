/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <cqin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:28:07 by christine         #+#    #+#             */
/*   Updated: 2024/02/08 13:46:51 by cqin             ###   ########.fr       */
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

	std::cout << deserialize->c  << std::endl;
}
