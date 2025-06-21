/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:48:38 by chtan             #+#    #+#             */
/*   Updated: 2025/06/21 15:43:20 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

# include <iostream>
# include <iomanip>
# include <cstdlib>
# include <exception>
# include <vector>
# include <string>
# include <limits>

// Integer limits
#define INT_MIN_VALUE       (-2147483648)       // -2147483648
#define INT_MAX_VALUE       2147483647          // 2147483647
// Float limits
#define FLOAT_MIN_VALUE     1.17549e-38f         // smallest positive normalized float
#define FLOAT_MAX_VALUE     3.40282e+38f         // largest positive float
#define FLOAT_LOWEST_VALUE  (-3.40282e+38f)      // most negative float
// Double limits
#define DOUBLE_MIN_VALUE     2.22507e-308        // smallest positive normalized double
#define DOUBLE_MAX_VALUE     1.79769e+308        // largest positive double
#define DOUBLE_LOWEST_VALUE  (-1.79769e+308)     // most negative double

enum type {
    CHAR,     // Represents a character type (e.g., 'a', 'Z')
    INT,      // Represents an integer type (e.g., 42, -10)
    DOUBLE,   // Represents a double-precision floating-point number (e.g., 3.14)
    FLOAT,    // Represents a single-precision floating-point number (e.g., 2.5f)
    POSINF,   // Represents positive infinity (+∞, e.g., `1.0 / 0.0`)
    NEGINF,   // Represents negative infinity (-∞, e.g., `-1.0 / 0.0`)
    NANF      // Represents "Not a Number" (NaN, e.g., `0.0 / 0.0`)
};

class Convert{
    public:
        Convert();
        Convert(const Convert &other);
        Convert &operator=(const Convert &other);
        ~Convert();

        static  bool    p_printable(std::string input);
        static  void    p_all(std::string input);
        static  type    classify(std::string str);
        static  void    print(const std::string c, const std::string num, const std::string f, const std::string d);

        class InvalidInputException : public std::exception {
            public:
                virtual const char* what() const throw();
        };
};
