#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

int main( void ) {
	Bureaucrat Anna("Anna", 150);
	Bureaucrat Maria("Maria", 50);

	std::cout << Anna << std::endl;
	std::cout << Maria << std::endl;

	std::cout << std::endl << "Creation of irrelevant Form: " << std::endl << std::endl;
	try
	{
		Form A("A", 180, 100);
		std::cout << A << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl << "Creation of relevant Form, but trying to sign with LOW grade: " << std::endl << std::endl;
	try
	{
		Form B("B", 100, 100);
		std::cout << B << std::endl;
		Anna.signForm(B);
		std::cout << B << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}


	std::cout << std::endl << "Creation of relevant Form and trying to sign with HIGH (OK) grade: " << std::endl << std::endl;

	try
	{
		Form B("B", 100, 100);
		std::cout << B << std::endl;
		Maria.signForm(B);
		std::cout << B << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "Relevant Form to be signed by Bureaucrat with LOW grade: " << std::endl << std::endl;

	try
	{
		Form C("C", 100, 100);
		std::cout << C << std::endl;
		C.beSigned(Anna);
		std::cout << C << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	std::cout << std::endl << "Relevant Form to be signed by Bureaucrat with HIGH (OK) grade: " << std::endl << std::endl;

	try
	{
		Form C("C", 100, 100);
		std::cout << C << std::endl;
		C.beSigned(Maria);
		std::cout << C << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << std::endl;
	}

	return (0);
}
