/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:54:25 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/27 12:41:49 by radlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FORM__
#define __FORM__

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include "Bureaucrat.hpp"

class Bureaucrat;

class Form
{  
    private:
    std::string _name;
    int         _GradeToSign;
    int         _GradeToExec;
    bool        _check;

    public:
        Form();
        Form(std::string _name, int _GradeToSign, int _GradeToExec);
        Form(Form const & src);
        Form& operator=(const Form& src);
        ~Form();

    // --- Geteur ---
    std::string getName(void) const;
    int         getGradeToSign(void) const;
    int         getGradeToExec(void) const;
    std::string getCheck(void) const;

    // --- Fonction ---
    void    beSigned(Bureaucrat& toto);
    
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

    class FormNotSigned : public std::exception
    {
        public:
        const char* what() const throw() {
            return (" n'a pas pu signer ");
        }
    };
};

std::ostream& operator<<(std::ostream& os, const Form& b);

#endif