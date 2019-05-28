#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::Bureaucrat( ) : _name("name"), _grade(150) {

    std::cout << "Bureaucrat Constructor called created with default parameters !" << std::endl;
	return;
}

Bureaucrat::Bureaucrat( std::string const & name, int grade ) : _name(name) {

    try
    {
        std::cout << "Bureaucrat Constructor called" << " - " << name << " created !" << std::endl;
        Bureaucrat::setGrade(grade);
    }
    catch(const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    /*catch (std::exception & e) {
        std::cout << grade << std::endl;
        std::cout << e.what() << std::endl;
    }*/
	return;
}

Bureaucrat::Bureaucrat(Bureaucrat const & src) : _name(src.getName()) {
	std::cout << "Bureaucrat Copy constructor called" << std::endl;
	*this = src;
	return;
}

Bureaucrat::~Bureaucrat( void ) {

    std::cout << "Bureaucrat Destructor called" << " - " << this->_name << " deleted !" << std::endl;
	return;
}

Bureaucrat &    		Bureaucrat::operator=( Bureaucrat const & rhs ) {

	std::cout << "Assignation operator called" << std::endl;
	if ( this != &rhs )
    {
        this->_grade = rhs.getGrade();
    }
    return *this;
}

std::ostream & 	operator<<( std::ostream & o, Bureaucrat const & i ) {

	o << i.getName() << ", bureaucrat grade " << i.getGrade() << std::endl;

	return o;
}

void                 	Bureaucrat::setGrade( int n ) {

    if (n > 150)
        throw GradeTooLowException();
    else if (n < 1)
        throw GradeTooHighException();
    this->_grade = n;
}

void                 	Bureaucrat::incGrade( ) {

    try
    {
        setGrade(this->_grade - 1);
        std::cerr << this->_name << ", increment grade " << this->_grade << std::endl;
    }
    catch(const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    /*catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }*/
}
void                 	Bureaucrat::decGrade( ) {

    try
    {
        setGrade(this->_grade + 1);
        std::cerr << this->_name << ", decrement grade " << this->_grade << std::endl;
    }
    catch(const Bureaucrat::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch(const Bureaucrat::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    /*catch (std::exception & e) {
        std::cout << e.what() << std::endl;
    }*/
}

std::string          	Bureaucrat::getName( void ) const {return this->_name;}
int                 	Bureaucrat::getGrade( void ) const {return this->_grade;}


const char *            Bureaucrat::GradeTooLowException::what () const throw ()
{

    return "ERROR: Could no go lower than 150. Could not decremente.";
}

const char *            Bureaucrat::GradeTooHighException::what () const throw ()
{

    return "ERROR: Could no go higher than 1st Grade. Could not incremente.";
}

void                 	Bureaucrat::signForm( Form & src) {

    try {
        src.beSigned(*this);
        std::cerr << this->_name << " signs " << src.getName() << std::endl;
    }
    catch(const Form::GradeTooLowException& e) {
        std::cerr << this->_name << " cannot sign " << src.getName() << " because " << e.what() << std::endl;
    }
}

void                    Bureaucrat::executeForm(Form const & form) {
    try
    {
        form.execute(*this);
    }
    catch(const Form::NotSignedException& e) {
        std::cout << e.what() << std::endl;
    }
}