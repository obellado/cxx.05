#include <iostream>
#include <string>
#include "Bureaucrat.hpp"


Bureaucrat::Bureaucrat( void ) : _name("default"), _grade(150) {

}

Bureaucrat::~Bureaucrat( void ){
	std::cout << this->getName() << " destructed" << std::endl;
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name) {
	if ( grade > 150 )
		throw Bureaucrat::GradeTooLowException();
	else if ( grade < 1 )
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
	std::cout << this->getName() << " constructed" << std::endl;
}

Bureaucrat::Bureaucrat( const Bureaucrat &tocopy ) : _name(tocopy._name), _grade(tocopy._grade) {

}

Bureaucrat& Bureaucrat::operator = (const Bureaucrat & tocopy ) {
	if (this != &tocopy) {
		this->_grade = tocopy.getGrade();
	}
	return (*this);
}


std::string Bureaucrat::getName( void ) const {
	return this->_name;
}

int Bureaucrat::getGrade( void ) const {
	return this->_grade;
}


void Bureaucrat::incrementGrade( void ){
	if (this->_grade == 1)
		throw Bureaucrat::GradeTooHighException();
	this->_grade -= 1;
}

void Bureaucrat::decrementGrade( void ){
	if (this->_grade == 150)
		throw Bureaucrat::GradeTooLowException();
	this->_grade += 1;
}


const char* Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("Grade is too LOW");
}

const char* Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("Grade of is too HIGH");
}

std::ostream &	operator<< ( std::ostream & o, const Bureaucrat & b ) {
	o << b.getName() << ", bureaucrat grade " << b.getGrade();
	return o;
}
