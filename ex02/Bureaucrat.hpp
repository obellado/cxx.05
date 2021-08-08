#pragma once
# ifndef __BUREAUCRAT__H__
# define __BUREAUCRAT__H__
# include <iostream>
# include <string>
# include <exception>
class Bureaucrat;
# include "Form.hpp"

class Bureaucrat {
	private:

		std::string const	_name;
		int					_grade;


	public:

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		virtual ~Bureaucrat( void );
		Bureaucrat( std::string name, int grade );
		Bureaucrat( const Bureaucrat &tocopy );
		Bureaucrat& operator = (const Bureaucrat &tocopy );


		std::string getName( void ) const ;
		int getGrade( void ) const ;


		void incrementGrade( void );
		void decrementGrade( void );

		void signForm( Form & form );
};

std::ostream& operator << ( std::ostream & o, const Bureaucrat &b );

#endif
