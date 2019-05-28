#ifndef BUREAUCRAT_CLASS_H
# define BUREAUCRAT_CLASS_H

#include <string>
#include <ostream>
#include <iostream>
#include "Form.hpp"

class 										Bureaucrat
{
	private:
		std::string const	 	    		_name;
		int 						        _grade;
		
		void                 				setGrade( int n );
		Bureaucrat();
		
	public:
		Bureaucrat( std::string const & name, int grade );
		virtual ~Bureaucrat();
        Bureaucrat(Bureaucrat const & src);
		Bureaucrat &    				    operator=( Bureaucrat const & rhs );
		
		class								GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what () const throw ();
		};
		class								GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what () const throw ();
		};
		std::string							getName( void ) const;
		int									getGrade( void ) const;
		void								incGrade();
		void								decGrade();

		void                 				signForm( Form & src );
		void                    			executeForm(Form const & form);
};

std::ostream & 	operator<<( std::ostream & o, Bureaucrat const & i );

#endif
