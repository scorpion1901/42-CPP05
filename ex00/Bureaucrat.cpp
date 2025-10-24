/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:01:06 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/24 17:03:36 by radlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(std::string n, int nb) : _name(n), _number(nb)
{
    std::cout << "constructor called" << std::endl;
    if (n.empty())
        _name = "default";
    if (getGrade() < 1)
        throw GradeTooHighException();
    else if (getGrade() > 150)
        throw GradeTooLowException();
    return ;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src):_name(src._name), _number(src._number)
{
    return ;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
    if (this != &src)
    {
        this->_name = src._name;
        this->_number = src._number;
    }
    return (*this);
}

Bureaucrat::~Bureaucrat(void)
{
    std::cout << "Destructor of " << this->getName() << " called" << std::endl;
    return ;
}

std::string    Bureaucrat::getName(void) const
{
    return (this->_name);
}

int    Bureaucrat::getGrade(void) const
{
    return (this->_number);
}

void    Bureaucrat::decrement   (void)
{
    if (_number + 1 > 150)
        throw   GradeTooHighException();
    _number++;
}

void    Bureaucrat::increment   (void)
{
    if (_number - 1 < 1)
        throw GradeTooLowException();
    _number--;
        
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", note bureaucrate " << b.getGrade() << ".";
    return os;
}