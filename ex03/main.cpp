#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"
#include "Intern.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main( void ) {
	Bureaucrat Anna("Anna", 150);
	Bureaucrat Maria("Maria", 50);
	Bureaucrat SuperBoss("SuperBoss", 1);

	Intern		lol;

	Form*      A;

	std::cout << std::endl << "Test of Intern: " << std::endl << std::endl;
	try
	{
		A = lol.makeForm("presidential pardon", "Mr. Darcy");
		std::cout << *A << std::endl;
		delete A;

		A = lol.makeForm("shrubbery creation", "Mr. Darcy");
		A->beSigned(SuperBoss);
		A->execute(SuperBoss);
		std::cout << *A << std::endl;
		delete A;

		A = lol.makeForm("robotomy request", "Mr. Darcy");
		std::cout << *A << std::endl;
		A->beSigned(SuperBoss);
		A->execute(SuperBoss);
		delete A;

		A = lol.makeForm("sgdf", "Mr. Darcy");
		std::cout << *A << std::endl;
		delete A;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
