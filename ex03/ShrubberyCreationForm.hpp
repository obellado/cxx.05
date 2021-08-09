#pragma once
# ifndef __ShrubberyCreationForm__H__
# define __ShrubberyCreationForm__H__
# include <iostream>
# include <string>
# include <exception>
class ShrubberyCreationForm;
# include "Bureaucrat.hpp"
# include "Form.hpp"

class ShrubberyCreationForm : public Form {

	private:

		std::string		_target;

	public:

		class TargetFileOpenException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		ShrubberyCreationForm( std::string target );
		virtual ~ShrubberyCreationForm( void );
		ShrubberyCreationForm( const ShrubberyCreationForm &tocopy );
		ShrubberyCreationForm& operator = (const ShrubberyCreationForm &tocopy );

		std::string getTarget( void ) const ;

		void execute(Bureaucrat const & executor) const ;
};

std::ostream& operator << ( std::ostream & o, const ShrubberyCreationForm &ShrubberyCreationForm );

#endif
