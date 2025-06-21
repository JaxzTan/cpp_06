/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jaxztan <jaxztan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 12:14:47 by jaxztan           #+#    #+#             */
/*   Updated: 2025/06/21 09:31:15 by jaxztan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/A.hpp"
#include "../inc/B.hpp"
#include "../inc/C.hpp"
#include "../inc/Base.hpp"
#include "../inc/Generate.hpp"

int main() {
    for(int i = 0; i < 5; ++i) {
        Base *base = generate();
        
        if (dynamic_cast<A*>(base)) {
            std::cout << "A" << std::endl;
        } else if (dynamic_cast<B*>(base)) {
            std::cout << "B" << std::endl;
        } else if (dynamic_cast<C*>(base)) {
            std::cout << "C" << std::endl;
        } else {
            std::cout << "Unknown type" << std::endl;
        }
        identify(base);
        identify(*base);
        std::cout << "--------------------------------" << std::endl;
        delete base;
    }
    return 0;
}
