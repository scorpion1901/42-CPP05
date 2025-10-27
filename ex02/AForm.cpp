/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/24 15:54:07 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/27 16:13:21 by radlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "AForm.hpp"

AForm::AForm() : _name("default"), _GradeToSign(50), _GradeToExec(25)
{
    std::cout << "constructor default of AForm called" << std::endl;
    return ;
}

AForm::AForm(std::string n, int nb, int nb2) : _name(n), _GradeToSign(nb), _GradeToExec(nb2)
{
    std::cout << "constructor of AForm called" << std::endl;
    if (n.empty())
        _name = "default";
    if (getGradeToSign() < 1)
        throw GradeTooHighException();
    else if (getGradeToSign() > 150)
        throw GradeTooLowException();
    _checkToSign = false;
    return ;
}

AForm::AForm(AForm const & src):_name(src._name), _GradeToSign(src._GradeToSign), _GradeToExec(src._GradeToExec)
{
    return ;
}

AForm& AForm::operator=(const AForm& src)
{
    if (this != &src)
    {
        this->_name = src._name;
        this->_GradeToSign = src._GradeToSign;
        this->_GradeToExec = src._GradeToExec;
    }
    return (*this);
}

AForm::~AForm(void)
{
    std::cout << "Destructor of AForm (" << this->getName() << ") called" << std::endl;
    return ;
}

std::string    AForm::getName(void) const
{
    return (this->_name);
}

int    AForm::getGradeToSign(void) const
{
    return (this->_GradeToSign);
}

int    AForm::getGradeToExec(void) const
{
    return (this->_GradeToExec);
}

std::string     AForm::getCheckToSign(void) const
{
    if (_checkToSign == false)
        return ("the Form is not signed");
    return ("the Form is signed");
}

bool    AForm::getCheck(void) const
{
    return (_checkToSign);
}

void    AForm::setCheckToSign(bool check)
{
    this->_checkToSign = check;
}

void    AForm::beSigned(Bureaucrat& toto)
{ 
    if (toto.getGrade() <= getGradeToSign())
    {
        _checkToSign = true;
        return ;
    }
    else
    {
        throw FormNotSigned();
        return ;
    }
}

std::ostream& operator<<(std::ostream& os, const AForm& b)
{
    os << b.getName() << ", signé: " << b.getCheckToSign() << ", grade requis: " << b.getGradeToSign() << ", grade exec: " << b.getGradeToExec() << std::endl;
    return os;
}
