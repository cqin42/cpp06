/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScalarConverter.hpp                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cqin <cqin@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 17:09:36 by cqin              #+#    #+#             */
/*   Updated: 2024/02/06 17:10:33 by cqin             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCALARCONVERTER_HPP
#define SCALARCONVERTER_HPP

#include <iostream>

class ScalarConverter
{
    private :
        ScalarConverter();
        ScalarConverter(const ScalarConverter &autre);
        ScalarConverter &operator=(const ScalarConverter &autre);
        ~ScalarConverter();

    public :
        static void        convert(std::string strToConvert);

    class nonDisplayableCharacters : public std::exception
    {
        public:
            virtual const char *what() const throw();
    };
};

#endif
