#pragma once
# ifndef __PresidentialPardonForm__H__
# define __PresidentialPardonForm__H__
# include <iostream>
# include <string>
# include <exception>
class PresidentialPardonForm;
# include "Bureaucrat.hpp"
# include "Form.hpp"

class PresidentialPardonForm : public Form {

	private:

		std::string		_target;

	public:

		PresidentialPardonForm( std::string target );
		virtual ~PresidentialPardonForm( void );
		PresidentialPardonForm( const PresidentialPardonForm &tocopy );
		PresidentialPardonForm& operator = (const PresidentialPardonForm &tocopy );

		std::string getTarget( void ) const ;

		void execute(Bureaucrat const & executor) const ;
};

std::ostream& operator << ( std::ostream & o, const PresidentialPardonForm &PresidentialPardonForm );

#endif
