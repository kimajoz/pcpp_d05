#include "AForm.hpp"
#include "Bureaucrat.hpp"


AForm::AForm( ) : _name("name"), _mybool(false), _gradereq(100), _gradeexec(150) {

    std::cout << "AForm Constructor called created with default parameters !" << std::endl;
	return;
}

AForm::AForm( std::string const & name, int const gradereq, int const gradeexec ) : _name(name), _mybool(false), _gradereq(gradereq), _gradeexec(gradeexec){

    try
    {
        std::cout << "AForm Constructor called" << " - " << name << " created !" << std::endl;
        if (gradereq > 150 || gradeexec > 150)
            throw GradeTooLowException();
        else if (gradereq < 1 || gradeexec < 1)
            throw GradeTooHighException();
    }
    catch(const AForm::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch(const AForm::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    /*catch (std::exception & e) {
        std::cout << grade << std::endl;
        std::cout << e.what() << std::endl;
    }*/
	return;
}

AForm::AForm(AForm const & src) : _name(src.getName()), _gradereq(src.getGradeReq()), _gradeexec(src.getGradeExec()) {
	std::cout << "AForm Copy constructor called" << std::endl;
	*this = src;
	return;
}

AForm::~AForm( void ) {

    std::cout << "AForm Destructor called" << " - " << this->_name << " deleted !" << std::endl;
	return;
}

AForm &    		AForm::operator=( AForm const & rhs ) {

	std::cout << "Assignation operator called" << std::endl;
	if ( this != &rhs )
    {
        this->_mybool = rhs.getBool();
        //this->_name = rhs.getName();
        //this->_grade = rhs.getGrade();
    }
    return *this;
}

std::ostream & 	operator<<( std::ostream & o, AForm const & i ) {

	o << i.getName() << ", AForm gradeReq " << i.getGradeReq() << ", AForm gradeexec " << i.getGradeExec() << ", AForm bool - form is signed: " << i.getBool() << std::endl;

	return o;
}

void                 	AForm::beSigned( Bureaucrat const & src ) {

    if (src.getGrade() > this->getGradeReq())
        throw GradeTooLowException();
    std::cout << "grade: " << src.getGrade() << " grade req: " << this->getGradeReq() << " Will signed: " << !(src.getGrade() > this->getGradeReq()) << std::endl;
    this->_mybool = true;
}

std::string          	AForm::getName( void ) const {return this->_name;}
int                 	AForm::getGradeReq( void ) const {return this->_gradereq;}
bool                 	AForm::getBool( void ) const {return this->_mybool;}
int                 	AForm::getGradeExec( void ) const {return this->_gradeexec;}


const char * AForm::GradeTooLowException::what ( ) const throw ()
{

    return "ERROR: Could no go higher than the grade required to execute it." ;
}

const char * AForm::GradeTooHighException::what () const throw ()
{

    return "ERROR: Could no go lower than 1";
}

const char * AForm::NotSignedException::what () const throw ()
{

    return "ERROR: AForm not signed !";
}

void                     AForm::checkSigned(Bureaucrat const & executor) const {
    if (AForm::getBool() == 1 && executor.getGrade() > this->getGradeReq())
        throw NotSignedException();
}