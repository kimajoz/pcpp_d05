#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

#include <string>
#include <iostream>
#include <ostream>
#include <fstream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

class   ShrubberyCreationForm;

class 										ShrubberyCreationForm : public Form
{
	private:
		ShrubberyCreationForm();
		
	public:
		ShrubberyCreationForm( std::string target );
		virtual ~ShrubberyCreationForm();
        ShrubberyCreationForm(ShrubberyCreationForm const & src);
		ShrubberyCreationForm &    		    operator=( ShrubberyCreationForm const & rhs );
        void                                execute(Bureaucrat const & executor) const;

};


#endif