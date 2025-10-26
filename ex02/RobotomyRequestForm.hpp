/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: radlouni <radlouni@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/26 13:01:18 by radlouni          #+#    #+#             */
/*   Updated: 2025/10/26 18:20:17 by radlouni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __ROBOTOMYREQUESTFORM__
#define __ROBOTOMYREQUESTFORM__

#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdlib>
#include <fstream>
#include <cmath>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class Bureaucrat;

class RobotomyRequestForm : public AForm
{  
    public:
        RobotomyRequestForm(std::string _name);
        RobotomyRequestForm(RobotomyRequestForm const & src);
        RobotomyRequestForm& operator=(const RobotomyRequestForm& src);
        ~RobotomyRequestForm();

    // --- Fonction ---
    void    execute(Bureaucrat const& executor) const;

};

#endif