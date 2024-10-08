#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm() : AForm("ShrubberyCreationForm", 145, 137), _target("Default") {
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &other)  : AForm("ShrubberyCreationForm", 145, 137), _target(other._target) {
}

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(const ShrubberyCreationForm &other) {
	this->_target = other._target;
	return *this;
}

ShrubberyCreationForm::~ShrubberyCreationForm() {
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) {
	if (executor.getGrade() > this->getGradeToExec())
		throw ShrubberyCreationForm::GradeTooLow();
	else if (this->getSigned() == false)
		throw ShrubberyCreationForm::FormNotSigned();
	std::ofstream File((this->_target + "_shrubbery").c_str(), std::ios::out | std::ios::app);
	File << "         /\\         " << std::endl;
    File << "        /  \\        " << std::endl;
    File << "       /    \\       " << std::endl;
    File << "      /      \\      " << std::endl;
    File << "     /________\\     " << std::endl;
    File << "        ||||         " << std::endl;
    File << "        ||||         " << std::endl;
    File << "        ||||         " << std::endl;
	File.close();
}