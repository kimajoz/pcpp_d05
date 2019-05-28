#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

int main()
{
    Bureaucrat buro("buro", 51);
    ShrubberyCreationForm shru("shru");
    PresidentialPardonForm pre("pre");
    RobotomyRequestForm robot("robot");

    std::cout << buro <<std::endl;
    std::cout << shru <<std::endl;
    std::cout << pre <<std::endl;
    std::cout << robot <<std::endl;

    buro.executeForm(shru);
    buro.signForm(shru);
    buro.executeForm(shru);
   
    buro.signForm(pre);
    buro.executeForm(pre);

    buro.executeForm(robot);

    // -------------------------------------------------------------------------------------
    /*try
    {
        Bureaucrat buro = Bureaucrat("buro", -1);
        ShrubberyCreationForm shru = ShrubberyCreationForm("shru");
        buro.executeForm(shru);
    }
    catch(const Form::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch(const Form::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }*/

	return 0;
}
