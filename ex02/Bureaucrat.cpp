/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/02 19:01:06 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/26 18:01:31 by radlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Bureaucrat.hpp"

// Bureaucrat::Bureaucrat() : _name("default"), _number(15)
// {
//     std::cout << "constructor called" << std::endl;
//     return ;
// }

Bureaucrat::Bureaucrat(std::string n, int nb) : _name(n), _grade(nb)
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

Bureaucrat::Bureaucrat(Bureaucrat const & src):_name(src._name), _grade(src._grade)
{
    return ;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat& src)
{
    if (this != &src)
    {
        this->_name = src._name;
        this->_grade = src._grade;
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
    return (this->_grade);
}

void    Bureaucrat::decrement   (void)
{
    if (_grade + 1 > 150)
        throw   GradeTooHighException();
    _grade++;
}

void    Bureaucrat::increment   (void)
{
    if (_grade - 1 < 1)
        throw GradeTooLowException();
    _grade--;
        
}

void    Bureaucrat::signForm    (AForm& form)
{
    try
    {
        form.beSigned(*this);
        std::cout << getName() << " a signe " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << getName() << e.what() << form.getName() << " car " << e.what() << std::endl;
    }
}

void    Bureaucrat::executeForm     (AForm const& form)
{
    try
    {
      form.execute(*this);
      std::cout << getName() << " a executer " << form.getName() << std::endl;
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
    }
    
}

std::ostream& operator<<(std::ostream& os, const Bureaucrat& b)
{
    os << b.getName() << ", note bureaucrate " << b.getGrade() << ".";
    return os;
}