#include "Form.hpp"
#include "PresidentialPardonForm.hpp"
#include "Bureaucrat.hpp"

PresidentialPardonForm::~PresidentialPardonForm( void ){
}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : Form("PresidentialPardonForm", 25, 5), _target(target) {
}

PresidentialPardonForm::PresidentialPardonForm( const PresidentialPardonForm &tocopy ) : Form(tocopy.getName(), tocopy.getGradeToSign(), tocopy.getGradeToExecute()), _target(tocopy.getTarget()) {

}

PresidentialPardonForm& PresidentialPardonForm::operator = (const PresidentialPardonForm & tocopy ) {
	if (this != &tocopy) {
		this->_target = tocopy.getTarget();
	}
	return (*this);
}

std::string PresidentialPardonForm::getTarget( void ) const {
	return this->_target;
}

std::ostream &	operator<< ( std::ostream & o, const PresidentialPardonForm & b ) {
	o << b.getName() << "\'s Target: " << b.getTarget() << ", grade to sign: " << b.getGradeToSign() << ", grade to execute: " << b.getGradeToExecute() << ", signed: " << b.getSign();
	return o;
}

void PresidentialPardonForm::execute(Bureaucrat const & executor) const {
	if (executor.getGrade() <= this->getGradeToExecute()) {
		if (this->getSign()){
			std::cout << this->getTarget() << " has been pardoned by Zafod Beeblebrox. " << std::endl;
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

