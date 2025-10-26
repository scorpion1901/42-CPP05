/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:00:56 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/26 17:40:03 by radlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    try {
        std::cout << "===== Création des bureaucrates =====" << std::endl;
        Bureaucrat bob("Bob", 1);
        Bureaucrat jim("Jim", 140);
        Bureaucrat joe("Joe", 50);

        std::cout << bob << std::endl;
        std::cout << jim << std::endl;
        std::cout << joe << std::endl;

        std::cout << "\n===== Test ShrubberyCreationForm =====" << std::endl;
        ShruberyCreationForm shrub("home");
        std::cout << shrub << std::endl;

        jim.signForm(shrub);
        jim.executeForm(shrub);   // devrait échouer (grade trop bas)
        bob.executeForm(shrub);   // devrait créer le fichier home_shrubbery

        std::cout << "\n===== Test RobotomyRequestForm =====" << std::endl;
        RobotomyRequestForm robot("Marvin");
        std::cout << robot << std::endl;

        joe.signForm(robot);
        joe.executeForm(robot);   // peut échouer si pas assez haut
        bob.executeForm(robot);   // doit réussir

        std::cout << "\n===== Test PresidentialPardonForm =====" << std::endl;
        PresidentialPardonForm pardon("Arthur Dent");
        std::cout << pardon << std::endl;

        joe.signForm(pardon);     // devrait échouer (grade trop bas)
        bob.signForm(pardon);
        bob.executeForm(pardon);

    } catch (std::exception & e) {
        std::cerr << "Exception attrapée : " << e.what() << std::endl;
    }

    std::cout << "\n===== Fin des tests =====" << std::endl;
    return 0;
}