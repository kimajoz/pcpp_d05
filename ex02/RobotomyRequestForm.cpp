#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::RobotomyRequestForm( ) : AForm("", 72, 45) {

}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm(target, 72, 45) {

}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &src) {
    *this = src;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &rhs) {
    if (this != &rhs)
    {
        //this->_target = rhs.target;
    }
    return *this;
}

int                         RobotomyRequestForm::randNumb(int r) const {
 
    int                     res;
   
    res = rand() % r; // res in the range 0 to 4 -> 5 (because 5 possibilities)
    //std::cout << "random numb:" << res << std::endl;
    return res;
}

void                        RobotomyRequestForm::execute(Bureaucrat const & executor) const {


        AForm::checkSigned(executor);
        std::cout << " Glung glung glung !!!" << std::endl;
        if (randNumb(2) == 0)
            std::cout << executor.getName() << "has been robotomized successfully" << std::endl;
        else
            std::cout << "it’s a failure." << std::endl;
}