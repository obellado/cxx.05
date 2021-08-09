#pragma once
# ifndef __RobotomyRequestForm__H__
# define __RobotomyRequestForm__H__
# include <iostream>
# include <string>
# include <exception>
class RobotomyRequestForm;
# include "Bureaucrat.hpp"
# include "Form.hpp"

class RobotomyRequestForm : public Form {

	private:
		std::string		_target;

	public:

		class TargetFileOpenException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		RobotomyRequestForm( std::string target );
		virtual ~RobotomyRequestForm( void );
		RobotomyRequestForm( const RobotomyRequestForm &tocopy );
		RobotomyRequestForm& operator = (const RobotomyRequestForm &tocopy );

		std::string getTarget( void ) const ;

		void execute(Bureaucrat const & executor) const ;
};

std::ostream& operator << ( std::ostream & o, const RobotomyRequestForm &RobotomyRequestForm );

#endif
