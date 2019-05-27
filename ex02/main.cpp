#include <iostream>
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    Bureaucrat buro = Bureaucrat("buro", 51);
    ShrubberyCreationForm shru = ShrubberyCreationForm("shru");
    PresidentialPardonForm pre = PresidentialPardonForm("pre");
    //RobotomyRequestForm robot = RobotomyRequestForm("robot");
    buro.executeForm(shru);
    buro.executeForm(pre);
    //pre.execute(pre);
    //robot.execute(robot);

	return 0;
}
