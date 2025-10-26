/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:54:25 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/26 18:23:44 by radlouni         ###   ########.fr       */
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

class AForm
{  
    private:
    std::string _name;
    int         _GradeToSign;
    int         _GradeToExec;
    bool        _checkToSign;

    public:
        AForm(std::string _name, int _GradeToSign, int _GradeToExec);
        AForm(AForm const & src);
        AForm& operator=(const AForm& src);
        ~AForm();

    // --- Geteur ---
    std::string getName(void) const;
    int         getGradeToSign(void) const;
    int         getGradeToExec(void) const;
    std::string getCheckToSign(void) const;

    // --- Seteur ---
    void        setCheckToSign(bool check);

    // --- Fonction ---
    void            beSigned(Bureaucrat& toto);
    virtual void    execute(Bureaucrat const& toto) const = 0;
    
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

    class FormNotExec : public std::exception
    {
        public:
        const char* what() const throw() {
            return (" ne c'est pas executer ");
        }
    };

};

std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif

// std::rand()