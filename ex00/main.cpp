#include <iostream>
#include <exception>
#include <string>
#include "Bureaucrat.hpp"

int main( void ) {
	Bureaucrat Anna("Anna", 150);
	Bureaucrat Maria("Maria", 50);
	Bureaucrat Liza("Liza", 1);

	try
	{
		Anna.decrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Maria.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	try
	{
		Liza.incrementGrade();
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}

	std::cout << Anna << std::endl;
	std::cout << Maria << std::endl;
	std::cout << Liza << std::endl;

	try
	{
		Bureaucrat Veniamin("Veniamin", 151);
	}
	catch(const std::exception& e)
	{
		std::cerr << e.what() << '\n';
	}
	return (0);
}
