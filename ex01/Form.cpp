#include <iostream>
#include <string>
#include "Form.hpp"
#include "Bureaucrat.hpp"

Form::~Form( void ){
}

Form::Form( std::string name, int gradeToSign, int gradeToExecute ) : _name(name), _gradeToSign(gradeToSign), _gradeToExecite(gradeToExecute), _sign(0) {
	if ( gradeToSign > 150 || gradeToExecute > 150 )
		throw Form::GradeTooLowException();
	else if ( gradeToExecute < 1 || gradeToSign < 1)
		throw Form::GradeTooHighException();
}

Form::Form( const Form &tocopy ) : _name(tocopy._name), _gradeToSign(tocopy._gradeToSign), _gradeToExecite(tocopy._gradeToExecite), _sign(tocopy._sign) {

}

Form& Form::operator = (const Form & tocopy ) {
	if (this != &tocopy) {
		this->_sign = tocopy.getSign();
	}
	return (*this);
}

std::string Form::getName( void ) const {
	return this->_name;
}

int Form::getGradeToExecute( void ) const {
	return this->_gradeToExecite;
}

int Form::getGradeToSign( void ) const {
	return this->_gradeToSign;
}

bool Form::getSign( void ) const {
	return this->_sign;
}

void Form::beSigned(Bureaucrat & b){
	if (b.getGrade() <= this->getGradeToSign())
		this->_sign = 1;
	else
		throw Form::GradeTooLowException();
}

const char* Form::GradeTooLowException::what() const throw()
{
	return ("Grade is too LOW");
}

const char* Form::GradeTooHighException::what() const throw()
{
	return ("Grade of is too HIGH");
}

std::ostream &	operator<< ( std::ostream & o, const Form & b ) {
	o << "Form: " << b.getName() << ", grade to sign: " << b.getGradeToSign() << ", grade to execute: " << b.getGradeToExecute() << ", signed: " << b.getSign();
	return o;
}
