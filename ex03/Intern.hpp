#pragma once
# ifndef __Intern__H__
# define __Intern__H__
# include <iostream>
# include <string>
# include <exception>
class Intern;
# include "Form.hpp"
# include "PresidentialPardonForm.hpp"
# include "ShrubberyCreationForm.hpp"
# include "RobotomyRequestForm.hpp"

class Intern {
	public:

		virtual ~Intern( void );
		Intern( void );
		Intern( const Intern &tocopy );
		Intern& operator = (const Intern &tocopy );

		Form* makeForm( std::string form, std::string target );

		Form* createPresidentionPardon( std::string target );
		Form* createRobotomyRequest( std::string target );
		Form* createShrubberyCreation( std::string target );


		class NoMatchForm : public std::exception {
			public:
				virtual const char* what() const throw();
		};
};

std::ostream& operator << ( std::ostream & o, const Intern &b );

#endif
