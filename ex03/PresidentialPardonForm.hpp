/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 13:02:04 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/26 20:45:42 by radlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __PRESIDENTIALPARDONFORM__
#define __PRESIDENTIALPARDONFORM__

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;

class PresidentialPardonForm : public AForm
{  
    public:
        PresidentialPardonForm(std::string _name);
        PresidentialPardonForm(PresidentialPardonForm const & src);
        PresidentialPardonForm& operator=(const PresidentialPardonForm& src);
        ~PresidentialPardonForm();

    // --- Fonction ---
    void    execute(Bureaucrat const& executor) const;

};

#endif