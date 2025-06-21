/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Convert.cpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: chtan <chtan@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:48:36 by chtan             #+#    #+#             */
/*   Updated: 2025/06/21 15:32:31 by chtan            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Convert.hpp"

// constructor
Convert::Convert() 
{}

Convert::Convert(const Convert &other) {
    *this = other;
}

Convert &Convert::operator=(const Convert &other) {
    if (this != &other)
    *this = other; // Handle self-assignment
    return *this;
}

// exception
const char *Convert::InvalidInputException::what() const throw()
{
    return ("Invalid input for conversion.");
}

//destructor
Convert::~Convert()
{}

// check is the char is printable
bool Convert::p_printable(std::string input) {
    int i = 0;
    while (input[i])
    {
        if (input[i] < 32 || input[i] > 126) 
        {
            return false;
        }
    }
    return true;
}

type Convert::classify(std::string str)
{
	int n = 0;
	unsigned int count_dot= 0;
	unsigned int after_dot = 0;
	unsigned char ischar = 0;

	if (str == "+inf" || str == "+inff")
		return (POSINF);
	else if (str == "-inf" || str == "-inff")
		return(NEGINF);
	else if (str == "nan" || str == "nanf")
		return (NANF);
	
	if (!str.empty() && *str.begin() == '-')
		n++;

	while (str[n] && (n != static_cast<int>(str.length() - 1)))
	{
		if (str[n] == '.')
			count_dot++;
		else if (!(str[n] >= '0' && str[n] <= '9'))
			ischar = 1;
		if (count_dot == 1 && !ischar)
			after_dot++;
		if (count_dot > 1)
			ischar = 1;
		n++;
	}
	if (str.length() <= 2 && !(str[n] >= '0' && str[n] <= '9'))
		ischar = 1;

	if (after_dot && count_dot <= 1 && !ischar && str[str.size() - 1] != 'f')
		return(DOUBLE);
	else if (after_dot && count_dot <= 1 && !ischar && str[str.size() - 1] == 'f')
		return (FLOAT);
	if (ischar)
		return (CHAR);
	else
		return (INT);
}

static bool is_ascii(char c) {
    return (c >= 0 && c <= 127);
}

void Convert::p_all(std::string str) {
	double input = 0.0;
    if (str.empty())
    {
        throw InvalidInputException();
    }
    // if (!p_printable(str))
    //     std::cerr << "Error: arguments must be printable characters." << std::endl;
    type t = classify(str);
    if (t == INT || t == DOUBLE || t == FLOAT)
		input = std::atof(str.c_str());
	else if (t == CHAR)
		input = static_cast<double>(str[0]);
	if (t == POSINF)
	{
		Convert::print(
			"impossible",
			"impossible",
			"+inff",
			"+inf"
		);
	}
	else if (t == NEGINF)
	{
		Convert::print(
			"impossible",
			"impossible",
			"-inff",
			"-inf"
		);
	}
	else if (t == NANF)
	{
		Convert::print(
			"impossible",
			"impossible",
			"nanf",
			"nan"
		);
	}
	else
	{
		if (input >= ' ' && input <= '~')
			std::cout << "char: \'" << static_cast<char>(input) << "\'" << std::endl;
		else if (!is_ascii(static_cast<char>(input)))
			std::cout << "char: " << "Impossible" << std::endl;
		else
			std::cout << "char: " << "Non displayable" << std::endl;
		
		if (input >= std::numeric_limits<int>::min() && input <= std::numeric_limits<int>::max())
		{
			std::cout << "int: " << static_cast<int>(input) << std::endl;
			// std::cout << std::fixed << std::setprecision(1);
			if (input >= -std::numeric_limits<float>::max() && input <= std::numeric_limits<float>::max())
				std::cout << std::fixed << std::setprecision(1)  << "float: " << static_cast<float>(input) << "f" << std::endl;
			else
				std::cout << "float: " << static_cast<float>(input) << "f" << std::endl;
			std::cout  << std::fixed << std::setprecision(1) << "double: " << static_cast<double>(input) << std::endl;
		}
		else
		{
			std::cout << "char: " << "Impossible" << std::endl;
			// std::cout << std::fixed << std::setprecision(1) << std::endl;
			std::cout   << "float: " << static_cast<float>(input) << "f" << std::endl;
			std::cout  << "double: " << static_cast<double>(input) << std::endl;
		}
	}
}
