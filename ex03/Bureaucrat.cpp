#include <iostream>
#include <string>
#include "Bureaucrat.hpp"
#include "Form.hpp"

Bureaucrat::~Bureaucrat( void ){
}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name) {
	if ( grade > 150 )
		throw Bureaucrat::GradeTooLowException();
	else if ( grade < 1 )
		throw Bureaucrat::GradeTooHighException();
	else
		this->_grade = grade;
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

void Bureaucrat::signForm( Form & form ){

	if (form.getGradeToSign() >= this->getGrade()){
		std::cout << "Bureaucrat " << this->getName() << " signs Form " << form.getName() << std::endl;
		form.beSigned(*this);
	}
	else
		std::cout << "Bureaucrat " << this->getName() << " cannot sign Form " << form.getName() << ", because his/her grade (" << this->getGrade() << ") is lower, than required (" << form.getGradeToSign() << ")." << std::endl;
}

void Bureaucrat::executeForm(Form const & form){
	if (form.getGradeToExecute() >= this->getGrade()){
		if (form.getSign()){
			std::cout << "Bureaucrat " << this->getName() << " executes " << form.getName() << std::endl;
			form.execute(*this);
		}
		else {
			std::cout << "Bureaucrat " << this->getName() << " cannot execute " << form.getName() << ", because form is UNSIGNED." << std::endl;
		}
	}
	else
		std::cout << "Bureaucrat " << this->getName() << " cannot execute " << form.getName() << ", because his/her grade (" << this->getGrade() << ") is lower, than required (" << form.getGradeToExecute() << ")." << std::endl;
}

