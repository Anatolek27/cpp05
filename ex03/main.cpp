#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include <unistd.h>

int main(void) 
{
	try {
		Bureaucrat A = Bureaucrat();
		Bureaucrat B = Bureaucrat(A);
		Bureaucrat C = Bureaucrat("Bob", 1);
		Bureaucrat D = Bureaucrat();

		D = C;

		ShrubberyCreationForm E = ShrubberyCreationForm();
		ShrubberyCreationForm F = ShrubberyCreationForm(E);
		ShrubberyCreationForm G = ShrubberyCreationForm("home");

		F = G;

		C.signForm(E);
		E.execute(C);
		E.execute(C);
		E.execute(C);
		//E.execute(A);

		RobotomyRequestForm H = RobotomyRequestForm();
		RobotomyRequestForm I = RobotomyRequestForm(H);
		RobotomyRequestForm J = RobotomyRequestForm("Test Robot");

		H = J;

		C.signForm(J);
		J.execute(C);
		//J.execute(A);

		PresidentialPardonForm K = PresidentialPardonForm();
		PresidentialPardonForm L = PresidentialPardonForm(K);
		PresidentialPardonForm M = PresidentialPardonForm("Bureaucrat");

		H = J;

		C.signForm(M);
		M.execute(C);
		M.execute(A);

	} catch(std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}
}