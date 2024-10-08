#pragma once

#include "Bureaucrat.hpp"

class Form
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExec;
	public:
		Form();
		Form(const Form &other);
		Form(std::string name, int gradeToSign, int gradeToExec);
		~Form();

		Form &operator=(const Form &other);
		
		std::string getName() const;
		bool getSigned() const;
		int getGradeToSign() const;
		int getGradeToExec() const;

		class GradeTooLow : public std::exception {
			virtual const char *what() const throw() {
				return ("Buraucrat grade too low to sign");
			}
		};

		void setSigned();

		void beSigned(const Bureaucrat &b);
};