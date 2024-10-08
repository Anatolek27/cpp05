#include "AForm.hpp"

Bureaucrat::Bureaucrat() : _name("Bureaucrat"), _grade(150) {
	//std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
	//std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(std::string name, int grade) : _name(name), _grade(grade) {
	if (grade < 1)
		throw Bureaucrat::GradeTooHighException();
	else if (grade > 150)
		throw Bureaucrat::GradeTooLowException();
	//std::cout << "Bureaucrat set constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	//std::cout << "Bureaucrat destructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	this->_grade = other._grade;
	return (*this);
}

std::string Bureaucrat::getName() const {
	return (this->_name);
}

int Bureaucrat::getGrade() const {
	return (this->_grade);
}

void Bureaucrat::increment() {
	if (this->_grade - 1 < 1)
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade--;
}

void Bureaucrat::decrement() {
	if (this->_grade + 1 > 150)
		throw Bureaucrat::GradeTooLowException();
	else
		this->_grade++;
}

void Bureaucrat::signForm(AForm &f) {
	if (this->_grade <= f.getGradeToSign() && f.getSigned() == false)
	{
		std::cout << this->_name << " signed " << f.getName() << std::endl;
		f.setSigned();
	} else if (this->_grade >= f.getGradeToSign())
	{
		std::cout << this->_name << " couldn't sign " << f.getName() << " because his grade is too low." << std::endl;
	} else {
		std::cout << this->_name << " couldn't sign " << f.getName() << " because it was already signed." << std::endl;
	}
}

std::ostream &operator<<(std::ostream &os, const Bureaucrat *other) {
	os << other->getName() << ", bureaucrat grade " << other->getGrade() << "." << std::endl;
	return (os);
}