#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat {
	private:
		const std::string _name;
		int _grade;
		
	public:
		class GradeTooHighException : public std::exception {
			public:
				const char* what() const throw() {
					return "Grade is too high!";
				}
		};

		class GradeTooLowException : public std::exception {
			public:
				const char* what() const throw() {
					return "Grade is too low!";
				}
		};

		Bureaucrat();
		Bureaucrat(const Bureaucrat &other);
		Bureaucrat(int grade, std::string name);
		Bureaucrat &operator=(const Bureaucrat &other);
		~Bureaucrat();
		std::string getName();
		int getGrade();
		void gradeUp();
		void gradeDown();
};

std::ostream &operator<<(std::ostream &out, Bureaucrat &bureaucrat);

#endif