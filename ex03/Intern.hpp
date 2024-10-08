#pragma once

#include "AForm.hpp"

class Intern {
	private:
	public:
		Intern();
		Intern(const Intern &other);
		~Intern();
		Intern &operator=(const Intern &other);

		AForm *makeForm(std::string name, std::string target);

		class FormNotFound : public std::exception {
			private:
				virtual const char *what() const throw() {
					return ("Form not found");
				}
		};
};