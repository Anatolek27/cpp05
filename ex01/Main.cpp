#include "Form.hpp"

int main()
{
	try
	{
		/*Bureaucrat A;
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

		A.gradeUp();
		D.gradeDown();*/

		Form E;
		Form F = Form("FormB", false, 10, 100);
		Form G = Form(F);
		Form H;
		
		H = E;
		std::cout << E << std::endl;
		std::cout << F << std::endl;
		std::cout << G << std::endl;
		std::cout << H << std::endl;

	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
		return 0;
	}
	return 0;
}