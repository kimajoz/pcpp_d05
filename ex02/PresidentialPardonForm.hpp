#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"
#include "Form.hpp"

class   PresidentialPardonForm;

class 										PresidentialPardonForm : public Form
{
	private:
		PresidentialPardonForm();
		
	public:
		PresidentialPardonForm( std::string target );
		virtual ~PresidentialPardonForm();
        PresidentialPardonForm(PresidentialPardonForm const & src);
		PresidentialPardonForm &    		operator=( PresidentialPardonForm const & rhs );
        void                                execute(Bureaucrat const & executor) const;

};


#endif