#ifndef RUNTIME_ERROR_HPP
#define RUNTIME_ERROR_HPP

#include <exception>

/**
 * RuntimeError is a classic Exception for unrecoverable errors during runtime.
 */
class RuntimeError : public std::exception {
	/**
	 * This string contains the reason, why this error was raised.
	 */
	std::string reason;

 public:
 	/**
	 * Constructor
	 * @param _reason The reason why the error is raised
	 */
 	RuntimeError( std::string _reason = "" ) : reason(_reason) {}
	/**
	 * Destructor
	 */
	virtual ~RuntimeError() throw() {}
	/**
	 * Returns a string containing the reason for the error.
	 * @return const char*
	 */
    virtual const char* what() const throw() {
		return reason.c_str();
	}

};

#endif
