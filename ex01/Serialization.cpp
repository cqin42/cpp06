/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serialization.cpp                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christine <christine@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 08:07:41 by christine         #+#    #+#             */
/*   Updated: 2024/02/06 08:33:20 by christine        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Serialization.hpp"

Serialization::Serialization()
{}
Serialization::Serialization(const Serialization &autre)
{
	(void)autre;
}
Serialization &Serialization::operator=(const Serialization &autre)
{
	(void)autre;
	return (*this);
}

Serialization::~Serialization()
{}
uintptr_t	Serialization::serialize(Data* ptr)
{
	return (reinterpret_cast<uintptr_t>(ptr));
}
Data*	Serialization::deserialize(uintptr_t raw)
{
	return (reinterpret_cast<Data*>(raw));
}
