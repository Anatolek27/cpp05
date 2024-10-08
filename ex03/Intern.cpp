#include "Intern.hpp"
#include "PresidentialPardonForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"

Intern::Intern() {
}

Intern::Intern(const Intern &other) {
	(void)other;
}

Intern::~Intern() {
}

Intern &Intern::operator=(const Intern &other) {
	(void)other;
	return *this;
}

AForm *Intern::makeForm(std::string name, std::string target) {
	if (name == "ShrubberyRequestForm") {
		AForm *form = new ShrubberyCreationForm(target);
		std::cout << "Intern creates " << target << std::endl;
		return (form);
	} else if (name == "RobotomyRequestForm") {
		AForm *form = new RobotomyRequestForm(target);
		std::cout << "Intern creates " << target << std::endl;
		return (form);
	} else if (name == "PresidentialPardonForm") {
		AForm *form = new PresidentialPardonForm(target);
		std::cout << "Intern creates " << target << std::endl;
		return (form);
	} else {
		std::cout << name << " form was not found" << std::endl;
		throw(Intern::FormNotFound());
		return 0;
	}
}