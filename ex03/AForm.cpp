#include "AForm.hpp"

AForm::AForm() : _name("Form"), _signed(false), _gradeToSign(50), _gradeToExec(100) {
}

AForm::AForm(const AForm &other) : _name(other._name), _signed(other._signed), _gradeToSign(other._gradeToSign), _gradeToExec(other._gradeToExec) {
}

AForm::AForm(std::string name, int gradeToSign, int gradeToExec) : _name(name), _signed(false), _gradeToSign(gradeToSign), _gradeToExec(gradeToExec) {
}

AForm::~AForm() {
}

AForm &AForm::operator=(const AForm &other) {
	this->_signed = other._signed;
	return (*this);
}

std::string AForm::getName() const {
	return (this->_name);
}

bool AForm::getSigned() const {
	return (this->_signed);
}

int AForm::getGradeToExec() const {
	return (this->_gradeToExec);
}

int AForm::getGradeToSign() const {
	return (this->_gradeToSign);
}

void AForm::setSigned() {
	this->_signed = true;
}

void AForm::beSigned(const Bureaucrat &b) {
	if (b.getGrade() > this->_gradeToSign)
		throw AForm::GradeTooLow();
	else
		this->setSigned();
}