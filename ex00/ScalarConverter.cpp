/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <cqin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:09:33 by cqin              #+#    #+#             */
/*   Updated: 2024/02/06 17:25:40 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Constructor Called." << std::endl;
}

ScalarConverter::ScalarConverter(const ScalarConverter &autre)
{
	std::cout << "ScalarConverter Constructor of copy Called." << std::endl;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &autre)
{
	(void)autre;
	std::cout << "ScalarConverter Constructor of operator = Called." << std::endl;
}


ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor Called." << std::endl;
}

const char* ScalarConverter::nonDisplayableCharacters::what() const throw()
{
	return ("No displayable");
}

void        ScalarConverter::convert(std::string strToConvert)
{
	/*char*/
	if (strToConvert.length() != 1 )
		throw
}
