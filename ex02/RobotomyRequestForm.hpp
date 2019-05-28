#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include <time.h>       /* time */
#include <random>
#include "Form.hpp"

class   Bureaucrat;

class 										RobotomyRequestForm : public Form
{
	private:
		RobotomyRequestForm();
		
	public:
		RobotomyRequestForm( std::string target );
		virtual ~RobotomyRequestForm();
        RobotomyRequestForm(RobotomyRequestForm const & src);
		RobotomyRequestForm &    		    operator=( RobotomyRequestForm const & rhs );
        void                                execute(Bureaucrat const & executor) const;
        int                                 randNumb(int r) const;

};


#endif