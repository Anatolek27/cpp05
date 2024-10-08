#pragma once

#include <iostream>
#include <string>

class AForm;

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat(std::string name, int grade);
		~Bureaucrat();

		Bureaucrat &operator=(const Bureaucrat &other);

		std::string getName() const;
		int getGrade() const;

		void increment();
		void decrement();

		class GradeTooLowException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Grade too low");
				}
		};
		class GradeTooHighException : public std::exception {
			public:
				virtual const char *what() const throw() {
					return ("Grade too high");
				}
		};

		void signForm(AForm &f);
};

std::ostream &operator<<(std::ostream &os, const Bureaucrat *other);
