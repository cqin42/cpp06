/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christine <christine@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 03:34:09 by christine         #+#    #+#             */
/*   Updated: 2024/02/06 05:06:36 by christine        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

int main(int argc, char **argv)
{
	if (argc != 2)
	{
		std::cout << "Error: need 2 parameters" << std::endl;
		return (-1);
	}
	std::string str = argv[1];

	try
	{
		ScalarConverter::convert(str);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
}
