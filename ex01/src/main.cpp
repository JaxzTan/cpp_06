/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:52:56 by jaxztan           #+#    #+#             */
/*   Updated: 2025/06/18 14:53:56 by jaxztan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Serializer.hpp"

int main()
{
	Data *dat = new Data;
	dat->index = 0;
	dat->name = "name";
	dat->db = 100.12;

	uintptr_t raw = Serializer::serialize(dat);
	Data *newdat = Serializer::deserialize(raw);

	
	std::cout << "Serialization: " << raw << std::endl << std::endl;

	std::cout
		<< "Data before Serialise.. " << dat << std::endl
		<< dat->index << std::endl
		<< dat->name << std::endl
		<< dat->db << std::endl << std::endl;

		std::cout
		<< "Data after Serialise.. " << newdat << std::endl
		<< newdat->index << std::endl
		<< newdat->name << std::endl
		<< newdat->db << std::endl << std::endl;

	delete dat;
	return 0;
}
