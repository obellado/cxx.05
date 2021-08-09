#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void ) {
	Bureaucrat Anna("Anna", 150);
	Bureaucrat Maria("Maria", 50);
	Bureaucrat SuperBoss("SuperBoss", 1);

	std::cout << Anna << std::endl;
	std::cout << Maria << std::endl;
	std::cout << SuperBoss << std::endl << std::endl;

	// std::cout << std::endl << "Test of ShrubberyCreationForm: " << std::endl << std::endl;
	// try
	// {
	// 	ShrubberyCreationForm A("Doo");
	// 	std::cout << A << std::endl;
	// 	Anna.signForm(A);
	// 	//A.execute(Maria);
	// 	std::cout << A << std::endl;
	// 	Maria.signForm(A);
	// 	std::cout << A << std::endl;
	// 	//A.execute(Anna);
	// 	//A.execute(Maria);
	// 	//Anna.executeForm(A);
	// 	SuperBoss.executeForm(A);
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	std::cout << std::endl << "Test of RobotomyRequestForm: " << std::endl << std::endl;
	try
	{
		RobotomyRequestForm A("Openspace");
		std::cout << A << std::endl;
		//Anna.signForm(A);
		//A.execute(SuperBoss);
		// std::cout << A << std::endl;
		Maria.signForm(A);
		std::cout << A << std::endl;
		//Maria.executeForm(A);
		// SuperBoss.executeForm(A);
		// SuperBoss.executeForm(A);
		// SuperBoss.executeForm(A);
		// SuperBoss.executeForm(A);
		// SuperBoss.executeForm(A);
		// SuperBoss.executeForm(A);
		// SuperBoss.executeForm(A);
		// SuperBoss.executeForm(A);
		// SuperBoss.executeForm(A);
		// SuperBoss.executeForm(A);
		A.execute(SuperBoss);
		A.execute(SuperBoss);
		A.execute(SuperBoss);
		A.execute(SuperBoss);
		A.execute(SuperBoss);
		A.execute(SuperBoss);
		A.execute(SuperBoss);
		A.execute(SuperBoss);
		A.execute(SuperBoss);
		A.execute(SuperBoss);

		std::cout << A << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


	// std::cout << std::endl << "Test of PresidentialPardonForm: " << std::endl << std::endl;
	// try
	// {
	// 	PresidentialPardonForm A("Office");
	// 	std::cout << A << std::endl;
	// 	//SuperBoss.executeForm(A);
	// 	//A.execute(SuperBoss);
	// 	//Anna.signForm(A);
	// 	//A.execute(SuperBoss);
	// 	//std::cout << A << std::endl;
	// 	SuperBoss.signForm(A);
	// 	std::cout << A << std::endl;
	// 	//A.execute(Maria);
	// 	//A.execute(SuperBoss);
	// 	//A.execute(Maria);
	// 	A.execute(SuperBoss);
	// 	std::cout << A << std::endl;
	// }
	// catch(const std::exception& e)
	// {
	// 	std::cerr << e.what() << std::endl;
	// }

	return (0);
}
