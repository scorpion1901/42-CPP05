/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:00:56 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/27 14:59:08 by radlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

int main(void)
{
    try
    {
        std::cout << "--- Creation d'un Bureaucrate + incrementation et decrementation ---" << std::endl;
        Bureaucrat toto("titi", 15);
        std::cout << toto << std::endl;
        toto.decrement();
        std::cout << toto << std::endl;
        toto.increment();
        toto.increment();
        std::cout << toto << std::endl;
        
        std::cout << "\n --- depassement de limite ---" << std::endl;
        Bureaucrat nono("nono", 175);
        std::cout << nono << std::endl;

    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() <<  std::endl;
    }
    return (0);
}