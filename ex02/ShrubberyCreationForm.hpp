#pragma once

#include "AForm.hpp"

class ShrubberyCreationForm : public AForm {
	private:
		std::string _target;
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(const ShrubberyCreationForm &other);
		ShrubberyCreationForm(std::string target);
		~ShrubberyCreationForm();
		ShrubberyCreationForm &operator=(const ShrubberyCreationForm &other);

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