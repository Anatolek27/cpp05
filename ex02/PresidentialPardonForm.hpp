#pragma once

#include "AForm.hpp"

class PresidentialPardonForm : public AForm {
	private:
		std::string _target;
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(const PresidentialPardonForm &other);
		PresidentialPardonForm(std::string target);
		~PresidentialPardonForm();
		PresidentialPardonForm &operator=(const PresidentialPardonForm &other);

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