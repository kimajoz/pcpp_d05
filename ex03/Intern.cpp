#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() {

}

Intern::Intern(Intern const &src) {
    *this = src;
}

Intern::~Intern() {
}

Intern &Intern::operator=(Intern const &rhs) {
    if (this != &rhs)
    {
        //this->_target = rhs.target;
    }
    return *this;
}

Form                        *Intern::makeForm(std::string nameform, std::string target) const {

    Form                    *form = NULL;

    if (nameform.compare("robotomy request") == 0) {
        form = new RobotomyRequestForm(target);
        std::cout << "Intern creates " << nameform << std::endl;
    }
    else if (nameform.compare("presidential pardon") == 0) { // 's' and 't' are equal.
        form = new PresidentialPardonForm(target);
        std::cout << "Intern creates " << nameform << std::endl;
    }
    else if (nameform.compare("shrubbery creation") == 0) { // 's' and 't' are equal.
        form = new ShrubberyCreationForm(target);
        std::cout << "Intern creates " << nameform << std::endl;
    }
    else {
        std::cout << "ERROR: Input string wrong or unknown. Please set param1: robotomy request | presidential pardon | shrubbery creation" << std::endl;
    }
    return form;
}