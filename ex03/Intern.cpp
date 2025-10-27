/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 22:04:21 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/27 10:37:59 by radlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

AForm*  Intern::makeForm(std::string forName, std::string target)
{
    std::string names[3] = {
        "ShrubberyCreation",
        "RobotomyRequest",
        "PresidentialPardon"
    };

    AForm* forms[3] = {
        new ShruberyCreationForm(target),
        new RobotomyRequestForm(target),
        new PresidentialPardonForm(target)
    };
    
    for (int i = 0; i < 3; i++)
    {
        if (forName == names[i])
        {
            std::cout << "Le stagiaire cree " << forName << std::endl;
            for (int j = 0; j < 3; j++)
            {
                if (i != j)
                    delete forms[j];
            }
            return (forms[i]);
        }
    }
    std::cout << "Erreur : le stagiaire ne connait pas ce type de formulaire" << std::endl;
    for (int i = 0; i < 3; i++)
        delete forms[i];
    return (NULL);
} 