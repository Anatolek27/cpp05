#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "AForm.hpp"
#include "Bureaucrat.hpp"
#include "Intern.hpp"
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
		//M.execute(A);


		Intern intern;
		AForm *form = intern.makeForm("ShrubberyCreationForm", "Target");
		AForm *form2 = intern.makeForm("RobotomyRequestForm", "Human");
		AForm *form3 = intern.makeForm("PresidentialPardonForm", "Target");		

		AForm *form4 = intern.makeForm("Non existant form", "Target");

		delete form;
		delete form2;
		delete form3;
		delete form4;
	} catch(std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}
}