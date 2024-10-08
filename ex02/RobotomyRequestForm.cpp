#include "RobotomyRequestForm.hpp"
#include <ctime>
#include <cstdlib>

RobotomyRequestForm::RobotomyRequestForm() : AForm("RobotomyRequestForm", 72, 45), _target("Default") {
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &other)  : AForm("RobotomyRequestForm", 72, 45), _target(other._target) {
}

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), _target(target) {
}

RobotomyRequestForm &RobotomyRequestForm::operator=(const RobotomyRequestForm &other) {
	this->_target = other._target;
	return *this;
}

RobotomyRequestForm::~RobotomyRequestForm() {
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) {
	if (executor.getGrade() > this->getGradeToExec())
		throw RobotomyRequestForm::GradeTooLow();
	else if (this->getSigned() == false)
		throw RobotomyRequestForm::FormNotSigned();
	std::cout << ">...some drilling noises...<" << std::endl;
	std::srand(std::time(NULL));
	if (std::rand() % 2 == 1) {
		std::cout << "Robotomy failed..." << std::endl;
	} else {
		std::cout << this->_target << " has been robotomized successfully" << std::endl;
	}
}