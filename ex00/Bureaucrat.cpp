#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Name"), _grade(150) {
	if (this->_grade > 150)
		throw (Bureaucrat::GradeTooHighException());
	if (this->_grade < 1)
		throw(Bureaucrat::GradeTooLowException());
	std::cout << "Bureaucrat constructor called" << std::endl;
}

Bureaucrat::Bureaucrat(const Bureaucrat &other) : _name(other._name), _grade(other._grade) {
	if (this->_grade > 150)
		throw (Bureaucrat::GradeTooHighException());
	if (this->_grade < 1)
		throw(Bureaucrat::GradeTooLowException());
	std::cout << "Bureaucrat copy constructor called" << std::endl;
}

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &other) {
	this->_grade = other._grade;
	if (this->_grade > 150)
		throw (Bureaucrat::GradeTooHighException());
	if (this->_grade < 1)
		throw(Bureaucrat::GradeTooLowException());
	std::cout << "Bureaucrat copy assignment operator called" << std::endl;
	return (*this);
}

Bureaucrat::Bureaucrat(int grade, std::string name) : _name(name), _grade(grade) {
	if (this->_grade > 150)
		throw (Bureaucrat::GradeTooHighException());
	if (this->_grade < 1)
		throw(Bureaucrat::GradeTooLowException());
	std::cout << "Bureaucrat set constructor called" << std::endl;
}

Bureaucrat::~Bureaucrat() {
	std::cout << "Bureaucrat destructor called" << std::endl;
}

std::string Bureaucrat::getName() {
	return (this->_name);
}

int Bureaucrat::getGrade() {
	return (this->_grade);
}

void Bureaucrat::gradeUp() {
	if (_grade <= 1) {
		throw Bureaucrat::GradeTooHighException();
	}
	_grade--;
}

void Bureaucrat::gradeDown() {
	if (_grade >= 150) {
		throw Bureaucrat::GradeTooLowException();
	}
	_grade++;
}

std::ostream &operator<<(std::ostream &out, Bureaucrat &b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".";
    return out;
}