/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:00:56 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/24 15:04:52 by radlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

void    check_grade(Bureaucrat toto)
{
    if (toto.getGrade() > 150)
    {
        throw std::overflow_error("safas");
    }
    else if (toto.getGrade() < 1)
    {
        throw std::underflow_error("hjlh");
    }
    else
    {
        std::cout << "the grade is good" << std::endl;
    }
}

int main(void)
{
    try
    {
        Bureaucrat toto("elevator", 150);
        toto.decrement();
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << std::endl;
    }
    return (0);
}