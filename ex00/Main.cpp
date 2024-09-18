#include "Bureaucrat.hpp"

int main()
{
	try
	{
		Bureaucrat A;
		Bureaucrat B = Bureaucrat(1, "John");
		Bureaucrat C;
		Bureaucrat D = Bureaucrat(A);

		C = B;
		std::cout << A << std::endl;
		std::cout << B << std::endl;
		std::cout << C << std::endl;
		std::cout << D << std::endl;
		for (int i = 0; i < 149; i++)
			A.gradeUp();
		std::cout << A << std::endl;
		//test messages erreurs
		//A.gradeUp();
		//D.gradeDown();
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 0;
	}
	return 0;
}