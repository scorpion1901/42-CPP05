/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 13:00:53 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/26 21:10:53 by radlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

// PresidentialPardonForm::PresidentialPardonForm() : _name("default", _number(50), _number2(25)
// {
//     std::cout << "constructor of Form called" << std::endl;
// }

RobotomyRequestForm::RobotomyRequestForm(std::string n) : AForm(n, 72, 45)
{
    std::cout << "constructor of RobotomyRequestForm called" << std::endl;
    if (this->getGradeToSign() < 1)
        throw GradeTooHighException();
    else if (this->getGradeToSign() > 150)
        throw GradeTooLowException();
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const & src): AForm(src)
{
    return ;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm& src)
{
    if (this != &src)
    {
        AForm::operator=(src);
    }
    return (*this);
}

RobotomyRequestForm::~RobotomyRequestForm(void)
{
    std::cout << "Destructor of PresidentialPardonForm (" << this->getName() << ") called" << std::endl;
    return ;
}

void    RobotomyRequestForm::execute(Bureaucrat const& executor) const
{  
    if (executor.getGrade() > this->getGradeToExec())
        throw FormNotExec();
    for (int i = 0; i < 5; i++)
            std::cout << "drilling noises" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << this->getName() << " has been robotomized" << std::endl;
    else
        std::cout << "the robotomy of " << this->getName() << " failed." << std::endl;
}
