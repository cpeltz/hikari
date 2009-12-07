#ifndef DIGEST_FILE_PAIR
#define DIGEST_FILE_PAIR

#include "common.hpp"

class DigestFilePair {
	fs::path _file;
	std::string _digest;

 public:
 	DigestFilePair( const DigestFilePair& rhs );

	DigestFilePair( const fs::path file );

	DigestFilePair();

	void calculate( const fs::path file );

	std::string digest() const;

	fs::path file() const;
};

#endif
