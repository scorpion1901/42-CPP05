/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:54:25 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/27 16:15:03 by radlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __AFORM__
#define __AFORM__

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
        AForm();
        AForm(std::string _name, int _GradeToSign, int _GradeToExec);
        AForm(AForm const & src);
        AForm& operator=(const AForm& src);
        virtual ~AForm();

    // --- Geteur ---
    std::string getName(void) const;
    int         getGradeToSign(void) const;
    int         getGradeToExec(void) const;
    std::string getCheckToSign(void) const;
    bool        getCheck(void) const;

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
            return (" n'a pas executer ");
        }
    };

};

std::ostream& operator<<(std::ostream& os, const AForm& b);

#endif

// std::rand()