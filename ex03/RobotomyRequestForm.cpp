#include "Form.hpp"
#include "RobotomyRequestForm.hpp"
#include "Bureaucrat.hpp"

RobotomyRequestForm::~RobotomyRequestForm( void ){
}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : Form("RobotomyRequestForm", 72, 45), _target(target) {
	srand(time(NULL));
}

RobotomyRequestForm::RobotomyRequestForm( const RobotomyRequestForm &tocopy ) : Form(tocopy.getName(), tocopy.getGradeToSign(), tocopy.getGradeToExecute()), _target(tocopy.getTarget()) {
	srand(time(NULL));
}

RobotomyRequestForm& RobotomyRequestForm::operator = (const RobotomyRequestForm & tocopy ) {
	if (this != &tocopy) {
		this->_target = tocopy.getTarget();
		srand(time(NULL));
	}
	return (*this);
}

std::string RobotomyRequestForm::getTarget( void ) const {
	return this->_target;
}

const char* RobotomyRequestForm::TargetFileOpenException::what() const throw()
{
	return ("Cannot open the Target File");
}

std::ostream &	operator<< ( std::ostream & o, const RobotomyRequestForm & b ) {
	o << b.getName() << "\'s Target: " << b.getTarget() << ", grade to sign: " << b.getGradeToSign() << ", grade to execute: " << b.getGradeToExecute() << ", signed: " << b.getSign();
	return o;
}

void RobotomyRequestForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() <= this->getGradeToExecute()) {
		if (this->getSign()){
			std::cout << " * DRILLING NOIZE * " << std::endl;
			if (rand() % 2)
				std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
			else
				std::cout << this->getTarget() << "\'s robotomization failed" << std::endl;
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
