#include <iostream>
#include <fstream>
#include <string>
#include "Form.hpp"
#include "ShrubberyCreationForm.hpp"
#include "Bureaucrat.hpp"

ShrubberyCreationForm::~ShrubberyCreationForm( void ){
}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target ) : Form("ShrubberyCreationForm", 145, 137), _target(target) {
}

ShrubberyCreationForm::ShrubberyCreationForm( const ShrubberyCreationForm &tocopy ) : Form(tocopy.getName(), tocopy.getGradeToSign(), tocopy.getGradeToExecute()), _target(tocopy.getTarget()) {

}

ShrubberyCreationForm& ShrubberyCreationForm::operator = (const ShrubberyCreationForm & tocopy ) {
	if (this != &tocopy) {
		this->_target = tocopy.getTarget();
	}
	return (*this);
}

std::string ShrubberyCreationForm::getTarget( void ) const {
	return this->_target;
}

const char* ShrubberyCreationForm::TargetFileOpenException::what() const throw()
{
	return ("Problems with the Target File");
}

std::ostream &	operator<< ( std::ostream & o, const ShrubberyCreationForm & b ) {
	o << b.getName() << "\'s Target: " << b.getTarget() << ", grade to sign: " << b.getGradeToSign() << ", grade to execute: " << b.getGradeToExecute() << ", signed: " << b.getSign();
	return o;
}

void ShrubberyCreationForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() <= this->getGradeToExecute()) {
		if (this->getSign()){
			std::ofstream outfile (this->getTarget());
			if (!outfile.is_open() || outfile.bad())
				throw TargetFileOpenException();
			else {
				outfile <<
"        __ _.--..--._ _" << std::endl <<
"     .-' _/   _/\\_   \\_'-." << std::endl <<
"    |__ /   _/\\__/\\_   \\__|" << std::endl <<
"       |___/\\_\\__/  \\___|" << std::endl <<
"              \\__/" << std::endl <<
"              \\__/" << std::endl <<
"               \\__/" << std::endl <<
"                \\__/" << std::endl <<
"             ____\\__/___" << std::endl <<
"       . - '             ' -." << std::endl <<
"      /                      \\" << std::endl <<
"~~~~~~~  ~~~~~ ~~~~~  ~~~ ~~~  ~~~~~" << std::endl <<
"  ~~~   ~~~~~   ~!~~   ~~ ~  ~ ~ ~" << std::endl;

				outfile.close();
			}
		}
		else {
			throw Form::NoSignedForm();
			return ;
		}
	}
	else {
		throw Form::GradeTooLowException();
		return ;
	}
}
