#include "Form.hpp"

Form::Form() : _name("Form"), _isSigned(false), _signGrade(50), _exeGrade(150) {
    std::cout << "Form constructor called" << std::endl;
}

Form::Form(const Form &other) : _name(other._name), _isSigned(other._isSigned), _signGrade(other._signGrade), _exeGrade(other._exeGrade) {
    std::cout << "Form copy constructor called" << std::endl;
}

Form::Form(const std::string name, bool isSigned, const int signGrade, const int exeGrade) : _name(name), _isSigned(isSigned), _signGrade(signGrade), _exeGrade(exeGrade) {
    std::cout << "Form parametrized constructor called" << std::endl;
}

Form &Form::operator=(const Form &other) {
	this->_isSigned = other._isSigned;
	return *this;
}

Form::~Form() {
	std::cout << "Form destructor called" << std::endl;
}

std::string Form::getName() const {
	return (this->_name);
}

bool Form::getIsSigned() const {
	return (this->_isSigned);
}

int Form::getSignGrade() const {
	return (this->_signGrade);
}

int Form::getExeGrade() const {
	return (this->_exeGrade);
}

void Form::beSigned(Bureaucrat &b) {
	if (b.getGrade() > this->_signGrade)
		throw GradeTooLowException();
	if (this->getIsSigned() != false)
		throw FormAlreadySignedException();
	this->_isSigned = true;
}

std::ostream&	operator<<(std::ostream &o, const Form &form) {
	o << std::boolalpha << form.getName() << ": signed: " << form.getIsSigned() << ", grade needed to sign: " << form.getSignGrade() << ", grade needed to execute: " << form.getExeGrade() << std::endl;
	return o;
}