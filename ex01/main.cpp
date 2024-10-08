#include "Form.hpp"

int main(void) 
{
	try {
		Bureaucrat A = Bureaucrat();
		Bureaucrat B = Bureaucrat(A);
		Bureaucrat C = Bureaucrat("Bob", 1);
		Bureaucrat D = Bureaucrat();

		D = C;
		//C.increment();
		std::cout << &A;
		std::cout << &C;
		//A.decrement();
		std::cout << &A;

		Form E = Form();
		Form F = Form(E);
		Form G = Form("Useless Form", 30, 50);

		E = G;

		C.signForm(E);
		D.signForm(E);
		/*E.beSigned(C);
		if (E.getSigned() == true)
			std::cout << "E was signed by C\n";
		F.beSigned(A);*/
	} catch(std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}
}