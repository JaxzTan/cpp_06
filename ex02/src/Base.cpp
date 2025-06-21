/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Base.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/18 15:03:42 by jaxztan           #+#    #+#             */
/*   Updated: 2025/06/20 12:14:34 by jaxztan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/Base.hpp"

Base::Base()
{}

Base::Base(const Base &other)
{
    *this = other;
}

Base &Base::operator=(const Base &other) {
    if (this != &other) {
        *this = other;
    }
    return *this;
}

Base::~Base()
{}
