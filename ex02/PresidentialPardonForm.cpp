#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::PresidentialPardonForm( ) : AForm("", 25, 5)
{

}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm(target, 25, 5)
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
        //this->_gradereq = AForm::getGradeReq();
        //this->_gradeexec = AForm::getGradeExec(); // -> set by copy constructor ;)
    }
    return *this;
}

void                    PresidentialPardonForm::execute(Bureaucrat const & executor) const {

    AForm::checkSigned(executor);
    std::cout << AForm::getName() << " has been pardoned by Zaphod Beeblebrox." << std::endl;
}
