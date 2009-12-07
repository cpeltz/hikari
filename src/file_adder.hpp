#ifndef FILE_ADDER_HPP
#define FILE_ADDER_HPP

#include "digest_file_pair.hpp"

class FileAdder {
	static std::list< DigestFilePair > data;

	FileAdder();

	FileAdder( const FileAdder& );

 public:
 	static void process( std::vector< fs::path > directories );

	static void process( fs::path directory );

	static void sort_by_path();

	static void sort_by_digest();

	static void sort_by_file();

	static void clear();

	static std::list< DigestFilePair >& ref();
};

#endif
