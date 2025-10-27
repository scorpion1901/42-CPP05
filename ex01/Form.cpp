/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:54:07 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/27 15:23:51 by radlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Form.hpp"

Form::Form() : _name("default"), _GradeToSign(50), _GradeToExec(25)
{
    std::cout << "constructor default of Form called" << std::endl;
    return ;
}

Form::Form(std::string n, int nb, int nb2) : _name(n), _GradeToSign(nb), _GradeToExec(nb2)
{
    std::cout << "constructor of " << getName() << " called" << std::endl;
    if (n.empty())
        _name = "default";
    if (getGradeToSign() < 1)
        throw GradeTooHighException();
    else if (getGradeToSign() > 150)
        throw GradeTooLowException();
    _check = false;
    return ;
}

Form::Form(Form const & src):_name(src._name), _GradeToSign(src._GradeToSign), _GradeToExec(src._GradeToExec)
{
    return ;
} 

Form& Form::operator=(const Form& src)
{
    if (this != &src)
    {
        this->_name = src._name;
        this->_GradeToSign = src._GradeToSign;
        this->_GradeToExec = src._GradeToExec;
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

int    Form::getGradeToSign(void) const
{
    return (this->_GradeToSign);
}

int    Form::getGradeToExec(void) const
{
    return (this->_GradeToExec);
}

std::string     Form::getCheck(void) const
{
    if (_check == false)
        return ("the Form is not signed");
    return ("the Form is signed");
}

void    Form::beSigned(Bureaucrat& toto)
{ 
    if (toto.getGrade() <= getGradeToSign())
    {
        _check = true;
        return ;
    }
    else
    {
        throw FormNotSigned();
        return ;
    }
}

std::ostream& operator<<(std::ostream& os, const Form& b)
{
    os << b.getName() << ", signé: " << b.getCheck() << ", grade requis: " << b.getGradeToSign() << ", grade exec: " << b.getGradeToExec() << std::endl;
    return os;
}