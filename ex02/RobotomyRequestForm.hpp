#pragma once

#include "AForm.hpp"

class RobotomyRequestForm : public AForm {
	private:
		std::string _target;
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(const RobotomyRequestForm &other);
		RobotomyRequestForm(std::string target);
		~RobotomyRequestForm();
		RobotomyRequestForm &operator=(const RobotomyRequestForm &other);

		void execute(Bureaucrat const &executor);

		class GradeTooLow : public std::exception {
			private:
				virtual const char *what() const throw() {
					return ("Grade too low to execute");
				}
		};
		class FormNotSigned : public std::exception {
			private:
				virtual const char *what() const throw() {
					return ("Form is not signed");
				}
		};
};