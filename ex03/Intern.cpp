#include <iostream>
#include <string>
#include "Intern.hpp"
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"


Intern::~Intern( void ){
}

Intern::Intern( void ) {

}

Intern::Intern( const Intern &tocopy ) {

}

Intern& Intern::operator = (const Intern & tocopy ) {
	return (*this);
}


std::ostream &	operator<< ( std::ostream & o, const Intern & b ) {
	o << "I am an Intern";
	return o;
}

Form* Intern::createPresidentionPardon( std::string target ){
	return (new PresidentialPardonForm( target ));
}

Form* Intern::createRobotomyRequest( std::string target ){
	return (new RobotomyRequestForm( target ));
}

Form* Intern::createShrubberyCreation( std::string target ){
	return (new ShrubberyCreationForm( target ));
}

Form* Intern::makeForm( std::string form, std::string target ){
	std::string	forms[3] = { "presidential pardon", "robotomy request", "shrubbery creation" };
	Form*		(Intern::*func[3])(std::string target) = { &Intern::createPresidentionPardon,  &Intern::createRobotomyRequest, &Intern::createShrubberyCreation };
	int			flag;

	for (int i = 0; i < 3; i++){
		flag = form.compare(forms[i]);
		if (!flag){
			std::cout << "Intern is creating " << form << " form." << std::endl;
			return ((this->*func[i])( target ));}
	}
	throw Intern::NoMatchForm();
}

const char* Intern::NoMatchForm::what() const throw()
{
	return ("I dunno what is it and how to make it");
}
