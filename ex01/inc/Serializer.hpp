/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Serializer.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 14:19:42 by jaxztan           #+#    #+#             */
/*   Updated: 2025/06/18 14:53:43 by jaxztan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#pragma once

#include <iostream>

typedef unsigned long uintptr_t;

typedef struct Data
{
	int         index;
	double      db;
	std::string name;
}	Data;

class Serializer {
public:
    Serializer();
    Serializer(const Serializer &other);
    Serializer &operator=(const Serializer &other);
    ~Serializer();

    static uintptr_t    serialize(Data *ptr);
    static Data*        deserialize(uintptr_t raw);
};
