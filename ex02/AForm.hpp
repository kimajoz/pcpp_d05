#ifndef AForm_CLASS_H
# define AForm_CLASS_H

#include <string>
#include <ostream>
#include <iostream>

class   Bureaucrat;

class 										AForm
{
	private:
		std::string const      	    		_name;
		bool	             	    		_mybool;
		int const					        _gradereq;
		int const					        _gradeexec;
		void                 				setGrade( int n );
		
		
	public:
		AForm();
		AForm( std::string const & name, int const grade, int const gradeexec );
		virtual ~AForm();
        AForm(AForm const & src);
		AForm &    				    operator=( AForm const & rhs );
		
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
		class								NotSignedException : public std::exception
		{
			public:
				virtual const char * what ( ) const throw ();
		};

        void                 	            beSigned( Bureaucrat const & src );
		std::string							getName( void ) const;
		int									getGradeReq( void ) const;
		bool								getBool( void ) const;
		int									getGradeExec( void ) const;

		virtual void               			execute(Bureaucrat const & executor) const = 0;
		void                     			checkSigned(Bureaucrat const & executor) const;

};

std::ostream & 	operator<<( std::ostream & o, AForm const & i );

#endif