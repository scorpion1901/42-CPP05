/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 12:59:41 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/26 18:31:08 by radlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

// PresidentialPardonForm::PresidentialPardonForm() : _name("default", _number(50), _number2(25)
// {
//     std::cout << "constructor of Form called" << std::endl;
// }

ShruberyCreationForm::ShruberyCreationForm(std::string n) : AForm(n, 25, 5)
{
    std::cout << "constructor of PresidentialPardonForm called" << std::endl;
    if (this->getGradeToSign() < 1)
        throw GradeTooHighException();
    else if (this->getGradeToSign() > 150)
        throw GradeTooLowException();
    return ;
}

ShruberyCreationForm::ShruberyCreationForm(ShruberyCreationForm const & src): AForm(src)
{
    return ;
}

ShruberyCreationForm& ShruberyCreationForm::operator=(const ShruberyCreationForm& src)
{
    if (this != &src)
    {
        AForm::operator=(src);
    }
    return (*this);
}

ShruberyCreationForm::~ShruberyCreationForm(void)
{
    std::cout << "Destructor of PresidentialPardonForm (" << this->getName() << ") called" << std::endl;
    return ;
}

void    ShruberyCreationForm::execute(Bureaucrat const& executor) const
{  
    if (executor.getGrade() <= this->getGradeToExec())
    {
        std::string filename = this->getName() + "_shrubbery";
        std::ofstream ofs(filename.c_str(), std::ios::out);
        if (!ofs.is_open())
            throw std::runtime_error("Failed to create file: " + filename);
        const char* tree =
        "       ccee88oo\n"
        "    C8O8O8Q8PoOb o8oo\n"
        " dOB69QO8PdUOpugoO9bD\n"
        "CgggbU8OU qOp qOdoUOdcb\n"
        "    6OuU  /p u gcoUodpP\n"
        "      \\\\\\//  /douUP\n"
        "        \\\\\\\\\n"
        "         |||/\\\n"
        "         |||\\\\/\n"
        "         |||||\n"
        "   .....//||||\\\\....\n";
        ofs << tree << "\n\n";
        ofs << tree << "\n";
        ofs.close();
        if (ofs.fail())
            throw std::runtime_error("Write error while writing to: " + filename);
    }
    else
        std::cout << "the robotomy of " << this->getName() << "failed." << std::endl; 
}

// std::ostream& operator<<(std::ostream& os, const PresidentialPardonForm& b)
// {
//     os << b.getName() << ", signé: " << b.getCheckToSign() << ", grade requis: " << b.getGradeToSign() << ", grade exec: " << b.getGradeToExec() << std::endl;
//     return os;
// }