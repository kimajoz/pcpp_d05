#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "AForm.hpp"

class   RobotomyRequestForm;

class 										RobotomyRequestForm : public AForm
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