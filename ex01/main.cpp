#include <iostream>
#include "Form.hpp"
#include "Bureaucrat.hpp"

int main()
{
    Bureaucrat buro = Bureaucrat("buro", 51);
    Form form = Form("form", 52, 2);
    std::cout << buro <<std::endl;
    std::cout << form <<std::endl;
    buro.signForm(form);
    std::cout << form <<std::endl;

    Bureaucrat buro2 = Bureaucrat("buro2", 53);
    std::cout << buro <<std::endl;
    buro2.signForm(form);

    Bureaucrat    employee("Annoying employee", 150);
    std::cout << employee << std::endl;

    Bureaucrat    copy(employee);
    std::cout << copy << std::endl;
    Bureaucrat    assign = employee;
    std::cout << assign << std::endl;
    std::cout << "near end " <<std::endl;
    copy.signForm(form);

    //try
    //{
        Form form2 = Form("form", 152, 2);
    /*}
    catch(const Form::GradeTooHighException& e) {
        std::cout << e.what() << std::endl;
    }
    catch(const Form::GradeTooLowException& e) {
        std::cout << e.what() << std::endl;
    }*/
    /*catch (std::exception & e) {
        std::cout << grade << std::endl;
        std::cout << e.what() << std::endl;
    }*/

	return 0;
}
