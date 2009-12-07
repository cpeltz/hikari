#include "file_adder.hpp"
#include "scanner.hpp"

std::list< DigestFilePair > FileAdder::data;

FileAdder::FileAdder() { }

FileAdder::FileAdder( const FileAdder& ) { }

void FileAdder::process( std::vector< fs::path > directories ) {
	Scanner scanner;
	foreach( fs::path directory, directories ) {
		scanner.scan( directory );
	}
	foreach( fs::path file, scanner ) {
		data.push_back( DigestFilePair( file ) );
	}
}

void FileAdder::process( fs::path directory ) { 
	std::vector< fs::path > temp;
	temp.push_back( directory );
	process( temp );
}

bool PathPred( const DigestFilePair& left, const DigestFilePair& right ) {
	return left.file() < right.file();
}

bool DigestPred( const DigestFilePair& left, const DigestFilePair& right ) {
	return left.digest() < right.digest();
}

bool FilePred( const DigestFilePair& left, const DigestFilePair& right ) {
	return left.file().leaf() < right.file().leaf();
}

void FileAdder::sort_by_path() {
	data.sort( PathPred );
}

void FileAdder::sort_by_digest() {
	data.sort( DigestPred );
}

void FileAdder::sort_by_file() {
	data.sort( FilePred );
}

void FileAdder::clear() {
	data.clear();
}

std::list< DigestFilePair >& FileAdder::ref() {
	return data;
}
