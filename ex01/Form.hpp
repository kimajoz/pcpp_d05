#ifndef Form_CLASS_H
# define Form_CLASS_H

#include <string>
#include <ostream>
#include <iostream>

class   Bureaucrat;

class 										Form
{
	private:
		std::string const      	    		_name;
		bool	             	    		_mybool;
		int const					        _gradereq;
		int const					        _gradeexec;
		void                 				setGrade( int n );
		Form();
		
	public:
		Form( std::string const & name, int const grade, int const gradeexec );
		virtual ~Form();
        Form(Form const & src);
		Form &    				    operator=( Form const & rhs );
		
		class								GradeTooHighException : public std::exception
		{
			public:
				virtual const char * what ( ) const throw ();
		};
		class								GradeTooLowException : public std::exception
		{
			public:
				virtual const char * what ( ) const throw ();
		};

        void                 	            beSigned( Bureaucrat const & src );
		std::string							getName( void ) const;
		int									getGradeReq( void ) const;
		bool								getBool( void ) const;
		int									getGradeExec( void ) const;

};

std::ostream & 	operator<<( std::ostream & o, Form const & i );

#endif