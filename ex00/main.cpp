#include "Bureaucrat.hpp"

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
		A.decrement();
		std::cout << &A;
	} catch(std::exception const &e) {
		std::cerr << e.what() << std::endl;
	}
}