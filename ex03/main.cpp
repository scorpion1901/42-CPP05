/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:00:56 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/27 16:29:59 by radlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Intern.hpp"

int main() {
    std::cout << "=== TEST DU STAGIAIRE ===" << std::endl;

    Intern someRandomIntern;
    AForm* form = NULL;

    std::cout << "\n--- Test 1 : Création d’un ShrubberyCreationForm ---" << std::endl;
    
    form = someRandomIntern.makeForm("ShrubberyCreation", "garden");
    if (form)
        std::cout << "Formulaire créé : " << form->getName()
                  << " pour cible : " << "garden" << std::endl;
    delete form;

    std::cout << "\n--- Test 2 : Création d’un RobotomyRequestForm ---" << std::endl;
    
    form = someRandomIntern.makeForm("RobotomyRequest", "Bender");
    if (form)
        std::cout << "Formulaire créé : " << form->getName()
                  << " pour cible : " << "Bender" << std::endl;
    delete form;

    std::cout << "\n--- Test 3 : Création d’un PresidentialPardonForm ---" << std::endl;
    
    form = someRandomIntern.makeForm("PresidentialPardon", "Arthur Dent");
    if (form)
        std::cout << "Formulaire créé : " << form->getName()
                  << " pour cible : " << "Arthur Dent" << std::endl;
    delete form;

    std::cout << "\n--- Test 4 : Formulaire inexistant ---" << std::endl;
    form = someRandomIntern.makeForm("coffee request", "Intern");
    if (!form)
        std::cout << "Aucun formulaire créé pour ce nom inconnu." << std::endl;

    std::cout << "\n=== FIN DES TESTS ===" << std::endl;

    return 0;
}


