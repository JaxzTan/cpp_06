/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Generate.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/21 09:18:47 by jaxztan           #+#    #+#             */
/*   Updated: 2025/06/21 09:20:53 by jaxztan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Generate.hpp"
#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"

/*
	this generator produces how many numbers with given range.
	
	Example:
	if provided `range` is 2, then the number to be generated will be 0, 1 or 2.
*/
unsigned int randomNumGenerator(int range)
{
    static bool seeded = false;
    if (!seeded) {
        srand((unsigned) time(NULL));
        seeded = true;
    }
    return (rand() % (unsigned int)(range + 1));
}

Base *generate(void)
{
	unsigned int t = randomNumGenerator(2);
	Base *result = 0;

	switch (t)
	{
		case 0:
			result = new A();
			std::cout << "Generated A" << std::endl;
			break;
		case 1:
			result = new B();
			std::cout << "Generated B" << std::endl;
			break;
		default:
			result = new C();
			std::cout << "Generated C" << std::endl;
	}
	return (result);
}

void identify (Base *p)
{
	if (dynamic_cast<A *>(p))
		std::cout << "Object pointed to Class A." << std::endl;
	else if (dynamic_cast<B *>(p))
		std::cout << "Object pointed to Class B." << std::endl;
	else if (dynamic_cast<C *>(p))
		std::cout << "Object Pointed to Class C." << std::endl;
	else
		std::cout << "None of the object pointing to A/B/C Classes!" << std::endl;
}

void identify (Base &p)
{
	try
	{
		A &a = dynamic_cast<A &>(p);
		std::cout << "Identified class: Class A" << std::endl;
		(void)a;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Unknown class A error: " << e.what() << '\n';
	}

	try
	{
		B &b = dynamic_cast<B &>(p);
		std::cout << "Identified class: Class B" << std::endl;
		(void)b;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Unknown class B error: " << e.what() << '\n';
	}
	
	try
	{
		C &c = dynamic_cast<C &>(p);
		std::cout << "Identified class: Class C" << std::endl;
		(void)c;
	}
	catch(const std::exception& e)
	{
		std::cerr << "Unknown class C error: " << e.what() << '\n';
	}
}
