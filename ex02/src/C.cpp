/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   C.cpp                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:03:15 by jaxztan           #+#    #+#             */
/*   Updated: 2025/06/20 12:14:41 by jaxztan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/C.hpp"

C::C()
{}

C::C(const C &other)
{
    *this = other;
}

C &C::operator=(const C &other) {
    if (this != &other) {
        *this = other;
    }
    return *this;
}

C::~C()
{}
