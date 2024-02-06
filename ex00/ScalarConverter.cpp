/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.cpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christine <christine@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:09:33 by cqin              #+#    #+#             */
/*   Updated: 2024/02/06 07:54:27 by christine        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter()
{
	std::cout << "ScalarConverter Constructor Called." << std::endl;
}

// ScalarConverter::ScalarConverter(std::string str)
// {
// 	std::cout << "ScalarConverter Constructor with param Called." << std::endl;
// }

ScalarConverter::ScalarConverter(const ScalarConverter &autre)
{
	(void)autre;
	std::cout << "ScalarConverter Constructor of copy Called." << std::endl;
	// _type = autre._type;
}

ScalarConverter &ScalarConverter::operator=(const ScalarConverter &autre)
{
	(void)autre;
	std::cout << "ScalarConverter Constructor of operator = Called." << std::endl;
	// if (this != &autre)
	// 	_type = autre._type;
	return (*this);
}


ScalarConverter::~ScalarConverter()
{
	std::cout << "ScalarConverter Destructor Called." << std::endl;
}

const char* ScalarConverter::nonDisplayableCharacters::what() const throw()
{
	return ("No displayable");
}

const char* ScalarConverter::invalidArgument::what() const throw()
{
	return ("Invalid Argument");
}

bool		ScalarConverter::isPseudoLiterals(std::string str)
{
	std::string list[8] = {"-inf", "inf", "+inf", "-inff", "inff", "+inff", "nan", "nanf"};
	std::string sign = "";
	for (int i = 0; i < 8; i++)
	{
		if (str == list[i])
		{
			std::cout << "char: impossible" << std::endl;
			std::cout << "int: impossible" << std::endl;
			if (i < 6)
			{
				if (list[i][0] == '-')
					sign = "-";
				std::cout << "float: " + sign << std::numeric_limits<float>::infinity() << "f" << std::endl;
				std::cout << "double: " + sign << std::numeric_limits<double>::infinity() << std::endl;
			}
			else
			{
				std::cout << "float: " << std::numeric_limits<float>::quiet_NaN() << "f" << std::endl;
				std::cout << "double: " << std::numeric_limits<double>::quiet_NaN() << std::endl;
			}
			return (true);
		}
	}
	return (false);
}

ScalarConverter::e_type		ScalarConverter::detectType(std::string str)
{
	if (str.length() == 1 && isprint(str[0]) && !isdigit(str[0]))
		return(CHAR);

	int	nbPoint = 0;

	for (size_t i = 0; i < str.length(); i++)
	{
		if (i == 0 && (str[0] == '+' || str[i] == '-'))
			;
		else if (str[i] == '.')
			nbPoint++;
		else if (!isdigit(str[i]) && i == str.length() - 1 && nbPoint < 2)
			return(FLOAT);
		else if (isdigit(str[i]) && nbPoint == 1 && i == str.length() - 1)
			return(DOUBLE);
		else if (!isdigit(str[i]))
			break;
		else if (!isprint(str[i]))
			throw nonDisplayableCharacters();
		else if (i == str.length() - 1 && isdigit(str[i]))
			return(INT);

		if (i == str.length() - 1 && str[i] == '.')
		{
			std::cout << "hehe" << std::endl;
			return (DOUBLE);
		}
	}
	return (NOTYPE);
}

void		ScalarConverter::convertToType(std::string str)
{
	// e_type	type = detectType(str);

	switch(detectType(str))
	{
		case CHAR:
			toChar(str);
			break;
		case INT:
			toInt(str);
			break;
		case FLOAT:
			toFloat(str);
			break;
		case DOUBLE:
			toDouble(str);
			break;
		case NOTYPE:
			throw invalidArgument();
	};

}

void		ScalarConverter::toChar(std::string str)
{
	char c = static_cast<char>(str[0]);
	std::cout << "char: " << c << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(c) << std::endl;
}

void		ScalarConverter::toInt(std::string str)
{
	char *endptr;
	long int value = strtol(str.c_str(), &endptr, 10);

	if (endptr == str || *endptr != '\0' || value > std::numeric_limits<int>::max() || value < std::numeric_limits<int>::min())
		throw invalidArgument();

	int i = static_cast<int>(value);
	if (!isprint(static_cast<char>(i)))
		std::cout << "char: no displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(i) << std::endl;
	std::cout << "int: " << i << std::endl;
	std::cout << "float: " << static_cast<float>(i) << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(i) << std::endl;
}

void		ScalarConverter::toFloat(std::string str)
{
	char *endptr;
	float value = strtof(str.c_str() + 1, &endptr);

	float f = static_cast<float>(value);
	if (str[0] == '-')
		f *= -1;

	if (endptr == str || *(endptr + 1) != '\0' || f > std::numeric_limits<float>::max() || f < -std::numeric_limits<float>::max())
		throw invalidArgument();


	if (!isprint(static_cast<char>(f)))
		std::cout << "char: no displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(f) << std::endl;
	std::cout << "int: " << static_cast<int>(f) << std::endl;
	std::cout << "float: " << f << "f" << std::endl;
	std::cout << "double: " << static_cast<double>(f) << std::endl;
}

void		ScalarConverter::toDouble(std::string str)
{
	char *endptr;
	double value = strtod(str.c_str(), &endptr);
	if (str[0] == '-')
		value = strtod(str.c_str() + 1, &endptr);

	double d = static_cast<double>(value);
	if (str[0] == '-')
		d *= -1;

	if (endptr == str || *(endptr + 1) != '\0'|| d > std::numeric_limits<double>::max() || d < -std::numeric_limits<double>::max())
		throw invalidArgument();

	if (!isprint(static_cast<char>(d)))
		std::cout << "char: no displayable" << std::endl;
	else
		std::cout << "char: " << static_cast<char>(d) << std::endl;
	std::cout << "int: " << static_cast<int>(d) << std::endl;
	std::cout << "float: " << static_cast<float>(d) << "f" << std::endl;
	std::cout << "double: " << d << std::endl;
}

void        ScalarConverter::convert(std::string strToConvert)
{
	if (isPseudoLiterals(strToConvert) == true)
		return ;
	convertToType(strToConvert);
}
