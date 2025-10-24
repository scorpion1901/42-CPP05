/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:54:25 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/24 18:01:55 by radlouni         ###   ########.fr       */
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

class Form
{  
    private:
    std::string _name;
    int         _number;
    int         _number2;
    bool        _check;

    public:
        Form(std::string _name, int _number);
        Form(Form const & src);
        Form& operator=(const Form& src);
        ~Form();

    // --- Geteur ---
    std::string getName(void) const;
    int getGradeSign(void) const;
    int getGradeExec(void) const;
    std::string     getCheck(void);

    // --- Fonction ---
    void    increment(void);
    void    decrement(void);
    void    beSigned(Bureaucrat toto);
    
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

#endif