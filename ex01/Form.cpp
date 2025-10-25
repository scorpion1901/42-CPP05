/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:54:07 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/25 19:16:44 by radlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form(std::string n, int nb, int nb2) : _name(n), _number(nb), _number2(nb2)
{
    std::cout << "constructor called" << std::endl;
    if (n.empty())
        _name = "default";
    if (getGradeSign() < 1)
        throw GradeTooHighException();
    else if (getGradeSign() > 150)
        throw GradeTooLowException();
    _check = false;
    return ;
}

Form::Form(Form const & src):_name(src._name), _number(src._number), _number2(src._number2)
{
    return ;
}

Form& Form::operator=(const Form& src)
{
    if (this != &src)
    {
        this->_name = src._name;
        this->_number = src._number;
        this->_number2 = src._number2;
    }
    return (*this);
}

Form::~Form(void)
{
    std::cout << "Destructor of " << this->getName() << " called" << std::endl;
    return ;
}

std::string    Form::getName(void) const
{
    return (this->_name);
}

int    Form::getGradeSign(void) const
{
    return (this->_number);
}

int    Form::getGradeExec(void) const
{
    return (this->_number2);
}

std::string     Form::getCheck(void) const
{
    if (_check == false)
        return ("the Form is not signed");
    return ("the Form is signed");
}

void    Form::decrement   (void)
{
    if (_number + 1 > 150)
        throw   GradeTooHighException();
    _number++;
}

int    Form::beSigned(Bureaucrat& toto)
{
    std::cout << "grade: " << toto.getGrade() << "gradesign: " << getGradeSign() << std::endl;   
    if (toto.getGrade() <= getGradeSign())
    {
        _check = true;
        return (1);
    }
    else
        return (0);
}

void    Form::increment   (void)
{
    if (_number - 1 < 1)
        throw GradeTooLowException();
    _number--;
        
}

std::ostream& operator<<(std::ostream& os, const Form& b)
{
    os << b.getName() << ", signé: " << b.getCheck() << ", grade requis: " << b.getGradeSign() << ", grade exec: " << b.getGradeExec() << std::endl;
    return os;
}