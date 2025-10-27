/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:00:56 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/27 15:15:26 by radlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"
#include "Form.hpp"

// void    check_grade(Bureaucrat toto)
// {
//     if (toto.getGrade() > 150)
//     {
//         throw std::overflow_error("safas");
//     }
//     else if (toto.getGrade() < 1)
//     {
//         throw std::underflow_error("hjlh");
//     }
//     else
//     {
//         std::cout << "the grade is good" << std::endl;
//     }
// }

// int main(void)
// {
//     try
//     {
//         Bureaucrat toto("elevator", 150);
//         toto.decrement();
//     }
//     catch(const std::exception& e)
//     {
//         std::cerr << e.what() << std::endl;
//     }
//     return (0);
// }

int main()
{
    try {
        std::cout << "=== Création des formulaires ===" << std::endl;
        Form f1("Formulaire A38", 50, 25);
        Form f2("Formulaire B21", 3, 2);
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        std::cout << "\n=== Création des bureaucrates ===" << std::endl;
        Bureaucrat bob("Bob", 75);
        Bureaucrat alice("Alice", 25);
        Bureaucrat charles("Charles", 2);
        std::cout << bob << std::endl;
        std::cout << alice << std::endl;
        std::cout << charles << std::endl;

        std::cout << "\n=== Tentatives de signature ===" << std::endl;
        bob.signForm(f1);      // Trop bas
        alice.signForm(f1);    // OK
        alice.signForm(f2);    // Trop bas
        charles.signForm(f2);  // OK

        std::cout << "\n=== État final des formulaires ===" << std::endl;
        std::cout << f1 << std::endl;
        std::cout << f2 << std::endl;

        std::cout << "\n=== Test de valeurs invalides ===" << std::endl;
        try {
            Form f3("Formulaire X", 0, 10); // Trop haut
        } catch (const std::exception &e) {
            std::cerr << "Erreur lors de la création de f3 : " << e.what() << std::endl;
        }
        try {
            Form f4("Formulaire Y", 160, 120); // Trop bas
        } catch (const std::exception &e) {
            std::cerr << "Erreur lors de la création de f4 : " << e.what() << std::endl;
        }
    }
    catch (const std::exception &e) {
        std::cerr << "Exception attrapée : " << e.what() << std::endl;
    }

    return 0;
}
