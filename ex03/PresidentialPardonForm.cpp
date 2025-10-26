/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 13:01:37 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/26 20:45:45 by radlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PresidentialPardonForm.hpp"

// PresidentialPardonForm::PresidentialPardonForm() : _name("default", _number(50), _number2(25)
// {
//     std::cout << "constructor of Form called" << std::endl;
// }

PresidentialPardonForm::PresidentialPardonForm(std::string n) : AForm(n, 25, 5)
{
    std::cout << "constructor of PresidentialPardonForm called" << std::endl;
    if (this->getGradeToSign() < 1)
        throw GradeTooHighException();
    else if (this->getGradeToSign() > 150)
        throw GradeTooLowException();
    return ;
}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const & src): AForm(src)
{
    return ;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm& src)
{
    if (this != &src)
    {
        AForm::operator=(src);
    }
    return (*this);
}

PresidentialPardonForm::~PresidentialPardonForm(void)
{
    std::cout << "Destructor of PresidentialPardonForm (" << this->getName() << ") called" << std::endl;
    return ;
}

void    PresidentialPardonForm::execute(Bureaucrat const& executor) const
{
//    std::cout << "grade: " << toto.getGrade() << "gradesign: " << this->getGradeToSign() << std::endl;   
    if (executor.getGrade() <= this->getGradeToExec())
    {
        std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
    }
    else
        throw FormNotExec();
}
