/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 12:59:41 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/27 19:16:14 by radlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137)
{
    std::cout << "constructor default of ShrubberyCreationForm called" << std::endl;
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target)
{
    std::cout << "constructor of ShrubberyCreationForm called" << std::endl;
    if (this->getGradeToSign() < 1)
        throw GradeTooHighException();
    else if (this->getGradeToSign() > 150)
        throw GradeTooLowException();
    return ;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const & src): AForm(src)
{
    return ;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm& src)
{
    if (this != &src)
    {
        AForm::operator=(src);
    }
    return (*this);
}

ShrubberyCreationForm::~ShrubberyCreationForm(void)
{
    std::cout << "Destructor of ShrubberyCreationForm (" << _target << ") called" << std::endl;
    return ;
}

void    ShrubberyCreationForm::execute(Bureaucrat const& executor) const
{  
    if (executor.getGrade() <= this->getGradeToExec())
    {
        std::string filename = _target + "_shrubbery";
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
    {
        throw FormNotExec();
    } 
}
