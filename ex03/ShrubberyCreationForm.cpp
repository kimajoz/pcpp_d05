#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::ShrubberyCreationForm( ) : Form("", 145, 137) {

}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : Form(target, 145, 137) {

}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &src) {
    *this = src;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &rhs) {
    if (this != &rhs)
    {
        //this->_target = rhs.target;
    }
    return *this;
}

void                    writeASCIITreeFile(std::string name) {
    
    std::string         str;

    std::ofstream       out(name + "_shrubbery");
    if (!out)
    {
        std::cout << "filename not readable, please specify a filename with the good rights." << std::endl;
    }
    else
    {
        std::cout << "File \"" << name << "_shrubbery\" as been created in the current directory with ASCII trees inside." << std::endl;

        out << "               ,@@@@@@@," << std::endl;
        out << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
        out << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
        out << "   ,%&\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
        out << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
        out << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
        out << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
        out << "       |o|        | |         | |" << std::endl;
        out << "       |.|        | |         | |" << std::endl;
        out << "    \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;

            //out << str;
        out.close();
    }
}

void                    ShrubberyCreationForm::execute(Bureaucrat const & executor) const {

    Form::checkSigned(executor);
    writeASCIITreeFile(getName());
}