#include "Form.hpp"
#include "Bureaucrat.hpp"


Form::Form( ) : _name("name"), _mybool(false), _gradereq(100), _gradeexec(150) {

    std::cout << "Form Constructor called created with default parameters !" << std::endl;
	return;
}

Form::Form( std::string const & name, int const gradereq, int const gradeexec ) : _name(name), _mybool(false), _gradereq(gradereq), _gradeexec(gradeexec){

    try
    {
        std::cout << "Form Constructor called" << " - " << name << " created !" << std::endl;
        if (gradereq > 150 || gradeexec > 150)
            throw GradeTooLowException();
        else if (gradereq < 1 || gradeexec < 1)
            throw GradeTooHighException();
    }
    catch(const Form::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch(const Form::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }
    /*catch (std::exception & e) {
        std::cout << grade << std::endl;
        std::cout << e.what() << std::endl;
    }*/
	return;
}

Form::Form(Form const & src) : _name(src.getName()), _gradereq(src.getGradeReq()), _gradeexec(src.getGradeExec()) {
	std::cout << "Form Copy constructor called" << std::endl;
	*this = src;
	return;
}

Form::~Form( void ) {

    std::cout << "Form Destructor called" << " - " << this->_name << " deleted !" << std::endl;
	return;
}

Form &    		Form::operator=( Form const & rhs ) {

	std::cout << "Assignation operator called" << std::endl;
	if ( this != &rhs )
    {
        this->_mybool = rhs.getBool();
        //this->_name = rhs.getName();
        //this->_grade = rhs.getGrade();
    }
    return *this;
}

std::ostream & 	operator<<( std::ostream & o, Form const & i ) {

	o << i.getName() << ", Form gradeReq " << i.getGradeReq() << ", Form gradeexec " << i.getGradeExec() << ", Form bool - form is signed: " << i.getBool() << std::endl;

	return o;
}

void                 	Form::beSigned( Bureaucrat const & src ) {

    if (src.getGrade() > this->getGradeReq())
        throw GradeTooLowException();
    std::cout << "grade: " << src.getGrade() << " grade req: " << this->getGradeReq() << " Will signed: " << !(src.getGrade() > this->getGradeReq()) << std::endl;
    this->_mybool = true;
}

std::string          	Form::getName( void ) const {return this->_name;}
int                 	Form::getGradeReq( void ) const {return this->_gradereq;}
bool                 	Form::getBool( void ) const {return this->_mybool;}
int                 	Form::getGradeExec( void ) const {return this->_gradeexec;}


const char * Form::GradeTooLowException::what ( ) const throw ()
{

    return "ERROR: Could no go higher than the grade required to execute it." ;
}

const char * Form::GradeTooHighException::what () const throw ()
{

    return "ERROR: Could no go lower than 1";
}

const char * Form::NotSignedException::what () const throw ()
{

    return "ERROR: Form not signed or/and too low grade compared to grade exec !";
}

/*En gros tu as require exécution grade et require signing grade
Je vois pas ce que tu comprends pas
Un formulaire a un grade requis pour être signé et un grade requis pour être exécuté
Un bureaucrate a un grade
Si un bureaucrate veut signer un document le grade du bureaucrate doit être <= au grade requis pour *signer* le document
Si un bureaucrate veut exécuter un document le grade du bureaucrate doit être <= au grade requis pour *exécuter* le document*/

void                     Form::checkSigned(Bureaucrat const & executor) const {

    std::cout << executor.getName() << " - is Grade:" << executor.getGrade() << " < Grade Exec: " << Form::getGradeExec() << " ? Currently signed: " << Form::getBool() << std::endl;
    if (Form::getBool() == 0 || executor.getGrade() > this->getGradeExec())
        throw NotSignedException();
    std::cout << " => Allowed for actions" << std::endl;
}