#include <iostream>
#include "Bureaucrat.hpp"

int main()
{

    Bureaucrat joe = Bureaucrat("joe", 2);
    std::cout << joe;
    joe.incGrade();
    std::cout << joe;
    joe.incGrade();

    Bureaucrat zaz = Bureaucrat("zaz", 149);
    std::cout << zaz;
    zaz.decGrade();
    std::cout << zaz;
    zaz.decGrade();
    zaz.decGrade();
    zaz.incGrade();

    Bureaucrat tata = Bureaucrat("tata", 249);
    std::cout << tata;
	return 0;
}
