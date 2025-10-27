/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 13:00:53 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/27 19:13:10 by radlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45)
{
    std::cout << "constructor default of RobotomyRequestForm called" << std::endl;
    return ;
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target)
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
    std::cout << "Destructor of RobotomyRequestForm (" << _target << ") called" << std::endl;
    return ;
}

void    RobotomyRequestForm::execute(Bureaucrat const& executor) const
{  
    if (executor.getGrade() > this->getGradeToExec())
        throw FormNotExec();
    for (int i = 0; i < 5; i++)
            std::cout << "drilling noises" << std::endl;
    if (std::rand() % 2 == 0)
        std::cout << _target << " has been robotomized" << std::endl;
    else
        std::cout << "the robotomy of " << _target << " failed." << std::endl;
}
