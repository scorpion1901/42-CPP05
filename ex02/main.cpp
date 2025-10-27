/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:00:56 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/27 20:56:21 by radlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"

int main() {
    try {
        std::srand(std::time(NULL));
        std::cout << "===== Création des bureaucrates =====" << std::endl;
        Bureaucrat bob("Bob", 1);
        Bureaucrat jim("Jim", 150);
        Bureaucrat joe("Joe", 150);

        std::cout << bob << std::endl;
        std::cout << jim << std::endl;
        std::cout << joe << std::endl;

        std::cout << "\n===== Test ShrubberyCreationForm =====" << std::endl;
        ShrubberyCreationForm shrub("ricardo");
        std::cout << shrub << std::endl;

        joe.signForm(shrub);      // il signe
        jim.signForm(shrub);      // devrait pas signer le formulaire
        jim.executeForm(shrub);   // devrait échouer (grade trop bas)
        bob.executeForm(shrub);   // devrait créer le fichier home_shrubbery

        std::cout << "\n===== Test RobotomyRequestForm =====" << std::endl;
        RobotomyRequestForm robot("hitachi");
        std::cout << robot << std::endl;

        joe.signForm(robot);
        joe.executeForm(robot);   // peut échouer si pas assez haut
        bob.executeForm(robot);   // doit réussir

        std::cout << "\n===== Test PresidentialPardonForm =====" << std::endl;
        PresidentialPardonForm pardon("Bush");
        std::cout << pardon << std::endl;

        joe.signForm(pardon);     // devrait échouer (grade trop bas)
        bob.signForm(pardon);
        bob.executeForm(pardon);
        std::cout << "\n\n";

    } catch (std::exception & e) {
        std::cerr << "Exception attrapée : " << e.what() << std::endl;
    }

    std::cout << "\n===== Fin des tests =====" << std::endl;
    return 0;
}

// int main() {
//     std::srand(std::time(NULL)); // Initialiser la graine du random

//     try {
//         std::cout << "===== Création des bureaucrates =====" << std::endl;
//         Bureaucrat bob("Bob", 1);      // Très haut grade
//         Bureaucrat jim("Jim", 140);    // Très bas grade
//         Bureaucrat joe("Joe", 50);     // Grade intermédiaire

//         std::cout << bob << std::endl;
//         std::cout << jim << std::endl;
//         std::cout << joe << std::endl;

//         std::cout << "\n===== Test ShrubberyCreationForm =====" << std::endl;
//         ShruberyCreationForm shrub("home");
//         std::cout << shrub << std::endl;

//         // Échec de signature (grade trop bas)
//         jim.signForm(shrub);

//         // Signature correcte
//         joe.signForm(shrub);
//         std::cout << shrub << std::endl;

//         // Échec d’exécution (grade trop bas)
//         jim.executeForm(shrub);

//         // Exécution réussie
//         bob.executeForm(shrub);
//         //std::cout << "Vérifie le fichier home_shrubbery !" << std::endl;

//         std::cout << "\n===== Test RobotomyRequestForm =====" << std::endl;
//         RobotomyRequestForm robot("Marvin");
//         std::cout << robot << std::endl;

//         // Signature par bureaucrate pas assez gradé
//         jim.signForm(robot);

//         // Signature correcte
//         joe.signForm(robot);

//         // Exécution refusée (grade trop bas)
//         jim.executeForm(robot);

//         // Exécution par Joe (peut échouer ou réussir selon le hasard)
//         joe.executeForm(robot);

//         // Exécution par Bob (réussira toujours à exécuter)
//         bob.executeForm(robot);

//         std::cout << "\n===== Test PresidentialPardonForm =====" << std::endl;
//         PresidentialPardonForm pardon("Arthur Dent");
//         std::cout << pardon << std::endl;

//         // Signature refusée (grade trop bas)
//         joe.signForm(pardon);

//         // Signature réussie
//         bob.signForm(pardon);

//         // Exécution refusée (grade trop bas)
//         joe.executeForm(pardon);

//         // Exécution réussie
//         bob.executeForm(pardon);

//         std::cout << "\n===== Tests d’erreurs explicites =====" << std::endl;
//         try {
//             Bureaucrat tooHigh("God", 0); // Trop haut
//         } catch (std::exception &e) {
//             std::cerr << "Erreur attendue : " << e.what() << std::endl;
//         }

//         try {
//             Bureaucrat tooLow("Peon", 200); // Trop bas
//         } catch (std::exception &e) {
//             std::cerr << "Erreur attendue : " << e.what() << std::endl;
//         }

//     } catch (std::exception &e) {
//         std::cerr << "Exception attrapée dans main : " << e.what() << std::endl;
//     }

//     std::cout << "\n===== Fin des tests =====" << std::endl;
//     return 0;
// }