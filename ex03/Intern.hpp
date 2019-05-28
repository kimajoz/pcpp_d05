#ifndef INTERN_HPP
# define INTERN_HPP

#include <string>
#include <iostream>
#include "Form.hpp"

class   Intern;

class 										Intern
{
	private:
		

	public:
		Intern();
		virtual ~Intern();
		Intern(Intern const & src);
		Intern &    		    operator=( Intern const & rhs );
		Form                    *makeForm(std::string nameform, std::string target) const;

};


#endif
