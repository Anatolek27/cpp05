#pragma once

#include "Bureaucrat.hpp"
#include <fstream>

class AForm
{
	private:
		const std::string _name;
		bool _signed;
		const int _gradeToSign;
		const int _gradeToExec;
	public:
		AForm();
		AForm(const AForm &other);
		AForm(std::string name, int gradeToSign, int gradeToExec);
		virtual ~AForm() = 0;

		AForm &operator=(const AForm &other);
		
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

		virtual void beSigned(const Bureaucrat &b);
};