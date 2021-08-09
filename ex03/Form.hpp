#pragma once
# ifndef __FORM__H__
# define __FORM__H__
# include <iostream>
# include <string>
# include <exception>
class Form;
# include "Bureaucrat.hpp"

class Form {

	private:

		std::string	const	_name;
		bool				_sign;
		int	const			_gradeToSign;
		int	const			_gradeToExecite;

	public:

		class GradeTooHighException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class GradeTooLowException : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		class NoSignedForm : public std::exception {
			public:
				virtual const char* what() const throw();
		};

		Form( std::string name, int gradeToSign, int gradeToExecute );
		virtual ~Form( void );
		Form( const Form &tocopy );
		Form& operator = (const Form &tocopy );

		std::string getName( void ) const ;
		int getGradeToSign( void ) const ;
		int getGradeToExecute( void ) const ;
		bool getSign( void ) const ;

		void beSigned(Bureaucrat & b);

		virtual void execute(Bureaucrat const & executor) const = 0;
};

std::ostream& operator << ( std::ostream & o, const Form &form );

#endif
