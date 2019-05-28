#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    Bureaucrat buro = Bureaucrat("buro", 51);
    ShrubberyCreationForm shru = ShrubberyCreationForm("shru");
    PresidentialPardonForm pre = PresidentialPardonForm("pre");
    RobotomyRequestForm robot = RobotomyRequestForm("robot");

    //Form form("form", 52, 2);
    std::cout << buro <<std::endl;
    //std::cout << form <<std::endl;
    //buro.signForm(form);

    buro.executeForm(shru);
    buro.executeForm(pre);
    buro.executeForm(robot);

	return 0;
}
