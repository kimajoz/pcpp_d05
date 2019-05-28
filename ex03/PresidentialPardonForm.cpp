#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm( ) : Form("", 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : Form(target, 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &src) {
    *this = src;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &rhs) {
    if (this != &rhs)
    {
        //this->_gradereq = Form::getGradeReq();
        //this->_gradeexec = Form::getGradeExec(); // -> set by copy constructor ;)
    }
    return *this;
}

void                    PresidentialPardonForm::execute(Bureaucrat const & executor) const {

    Form::checkSigned(executor);
    std::cout << Form::getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
