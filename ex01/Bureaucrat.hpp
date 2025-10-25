/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:01:16 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/25 18:13:10 by radlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __BUREAUCRAT__
#define __BUREAUCRAT__

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include "Form.hpp"

class Form;

class Bureaucrat
{  
    private:
    std::string _name;
    int         _number;

    public:
        Bureaucrat(std::string _name, int _number);
        Bureaucrat(Bureaucrat const & src);
        Bureaucrat& operator=(const Bureaucrat& src);
        ~Bureaucrat();

    // --- Geteur ---
    std::string getName(void) const;
    int getGrade(void) const;

    // --- Fonction ---
    void    increment(void);
    void    decrement(void);
    void    signForm(Form& form);
    
    // --- Classe d'exceptions ---
    class GradeTooLowException : public std::exception
    {
        public:
        const char* what() const throw() {
            return ("the grade is too low");
        }
    };

    class GradeTooHighException : public std::exception
    {
        public:
        const char* what() const throw() {
            return ("the grade is too High");
        }
    };
};

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b);

#endif