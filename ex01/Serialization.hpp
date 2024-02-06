/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.hpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christine <christine@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:07:45 by christine         #+#    #+#             */
/*   Updated: 2024/02/06 08:32:46 by christine        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERIALIZATION_HPP
#define SERIALIZATION_HPP

#include <stdint.h>
#include <iostream>

struct Data
{
	int i;
	char c;
};

class Serialization
{
	private:
		Serialization();
		Serialization(const Serialization &autre);
		Serialization &operator=(const Serialization &autre);
		~Serialization();

	public:
		static uintptr_t	serialize(Data* ptr);
		static Data*	deserialize(uintptr_t raw);
};

#endif
