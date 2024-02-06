/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: christine <christine@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:09:36 by cqin              #+#    #+#             */
/*   Updated: 2024/02/06 06:57:23 by christine        ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>
#include <limits>
#include <stdlib.h>

class ScalarConverter
{
	enum	e_type
	{
		CHAR,
		INT,
		FLOAT,
		DOUBLE,
		NOTYPE
	};

    private :
		// e_type		_type;
        ScalarConverter();
		// ScalarConverter(std::string str);
        ScalarConverter(const ScalarConverter &autre);
        ScalarConverter &operator=(const ScalarConverter &autre);
        ~ScalarConverter();

    public :
        static void		convert(std::string strToConvert);
		static bool		isPseudoLiterals(std::string str);
		static e_type	detectType(std::string str);
		static void		convertToType(std::string str);
		static void		toChar(std::string str);
		static void		toInt(std::string str);
		static void		toFloat(std::string str);
		static void		toDouble(std::string str);
		// static	void
		// void		setType(e_type type);

    class nonDisplayableCharacters : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };

	 class invalidArgument : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };



};

#endif
