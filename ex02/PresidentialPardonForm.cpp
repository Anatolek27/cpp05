#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm() : AForm("PresidentialPardonForm", 25, 3), _target("Default") {
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &other)  : AForm("PresidentialPardonForm", 25, 3), _target(other._target) {
}

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 3), _target(target) {
}

PresidentialPardonForm &PresidentialPardonForm::operator=(const PresidentialPardonForm &other) {
	this->_target = other._target;
	return *this;
}

PresidentialPardonForm::~PresidentialPardonForm() {
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) {
	if (executor.getGrade() > this->getGradeToExec())
		throw PresidentialPardonForm::GradeTooLow();
	else if (this->getSigned() == false)
		throw PresidentialPardonForm::FormNotSigned();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}