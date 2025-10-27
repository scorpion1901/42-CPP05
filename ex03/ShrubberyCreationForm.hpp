/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 13:00:21 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/27 19:14:09 by radlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __SHRUBBERYCREATIONFORM__
#define __SHRUBBERYCREATIONFORM__

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class Bureaucrat;

class ShruberyCreationForm : public AForm
{  
    private:
    ShruberyCreationForm();
    std::string _target;

    public:
        ShruberyCreationForm(std::string target);
        ShruberyCreationForm(ShruberyCreationForm const & src);
        ShruberyCreationForm& operator=(const ShruberyCreationForm& src);
        ~ShruberyCreationForm();

    // --- Fonction ---
    void    execute(Bureaucrat const& executor) const;

};

#endif