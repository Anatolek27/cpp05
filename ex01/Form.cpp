#include "Form.hpp"

Form::Form() : _name("Form"), _signed(false), _gradeToSign(50), _gradeToExec(100) {
}

Form::Form(const Form &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
}

Form::Form(std::string name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
}

Form::~Form() {
}

Form &Form::operator=(const Form &other) {
	this->_signed = other._signed;
	return (*this);
}

std::string Form::getName() const {
	return (this->_name);
}

bool Form::getSigned() const {
	return (this->_signed);
}

int Form::getGradeToExec() const {
	return (this->_gradeToExec);
}

int Form::getGradeToSign() const {
	return (this->_gradeToSign);
}

void Form::setSigned() {
	this->_signed = true;
}

void Form::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > this->_gradeToSign)
		throw Form::GradeTooLow();
	else
		this->setSigned();
}