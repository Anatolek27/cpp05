#ifndef FORM_CPP
#define FORM_CPP

#include <string>
#include <iostream>
#include "Bureaucrat.hpp"

class Form
{
private:
	const std::string _name;
	bool _isSigned;
	const int _signGrade;
	const int _exeGrade;

public:
	Form();
	Form(const Form &other);
	Form(const std::string name, bool isSigned, const int signGrade, const int exeGrade);
	Form &operator=(const Form &other);
	~Form();
	std::string getName() const;
	bool getIsSigned() const;
	int getSignGrade() const;
	int getExeGrade() const;
	void beSigned(Bureaucrat &b);

	class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw() {
					return "Grade is too high to sign this form!";
				}
		};

	class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw() {
					return "Grade is too low to sign this form!";
				}
		};
	class FormAlreadySignedException : public std::exception {
			public:
				const char* what() const throw() {
					return "Form already singed!";
				}
		};
};

std::ostream&	operator<<(std::ostream &o, const Form& form);

#endif