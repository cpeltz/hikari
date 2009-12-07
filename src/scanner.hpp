#ifndef SCANNER_HPP
#define SCANNER_HPP

#include "common.hpp"

class Scanner {
	std::list< fs::path > files;

 public:
	typedef std::list< fs::path >::iterator iterator;
	typedef std::list< fs::path >::const_iterator const_iterator;

	enum {
		NOT_RECURSIVE = 0,
		RECURSIVE = 1
	};

	Scanner(); 

	/**
	 * Gathers all Files in the given directory.
	 * @param directory The directory to be scanned.
	 * @param flags Flags, that should be applied.
	 */
	std::size_t scan( fs::path directory, int flags = RECURSIVE ) throw (RuntimeError);

	void sort();

	std::size_t size();
	
	/**
	 * Returns a iterator an the begin of the path holding container
	 * @return iterator A Iterator to the beginning
	 */
	virtual iterator begin();

	/**
	 * Returns a iterator an the end of the path holding container
	 * @return iterator A Iterator to the ending
	 */
	virtual iterator end();

	/**
	 * Returns a constant iterator an the begin of the path holding container
	 * @return const_iterator A constant Iterator to the beginning
	 */
	virtual const_iterator begin() const;

	/**
	 * Returns a constant iterator an the end of the path holding container
	 * @return const_iterator A constant Iterator to the ending
	 */
	virtual const_iterator end() const;
};

#endif
