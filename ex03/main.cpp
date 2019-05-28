#include <iostream>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
    Bureaucrat buro("buro", 51);
    Intern  someRandomIntern;
    Form*   rrf;
    rrf = someRandomIntern.makeForm("shrubbery creation", "target1");
    if (rrf)
        std::cout << *rrf << std::endl << std::endl;

    rrf = someRandomIntern.makeForm("robotomy request", "target2");
    if (rrf)
        std::cout << *rrf << std::endl << std::endl;

    rrf = someRandomIntern.makeForm("dsincjdsncihbndsoviu", "target4");
    if (rrf)
        std::cout << *rrf << std::endl;


    rrf = someRandomIntern.makeForm("presidential pardon", "target3");
    if (rrf)
        std::cout << *rrf << std::endl << std::endl;

    std::cout << "-----------------------------------------" << std::endl;
    std::cout << std::endl;
    buro.signForm(*rrf);
    std::cout << std::endl;
    buro.executeForm(*rrf);
    std::cout << std::endl;
    std::cout << "-----------------------------------------" << std::endl;
    
    return 0;
}