/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/12 10:47:30 by chtan             #+#    #+#             */
/*   Updated: 2025/06/18 13:46:41 by jaxztan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Convert.hpp"

void Convert::print(const std::string c, const std::string num, const std::string f, const std::string d)
{
    std::cout << "char: " << c << std::endl;
    std::cout << "int: " << num << std::endl;
    std::cout << "float: " << f << std::endl;
    std::cout << "double: " << d << std::endl;
}

int main(int ac, char **av)
{
    // (void)av; // Ignore command line arguments for this example
    if (ac != 2)
    {
        std::cerr << "Error: Invalid number of arguments." << std::endl;
        return 1;
    }
    try
	{
		Convert::p_all(av[1]);
	}
	catch (const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
		return (1);
	}
    // std::string input[] = {av[1]};
    // std::cout << "Input: " << input[0] << std::endl;
    // print('~', 42, 42.0f, 42.0);
}
