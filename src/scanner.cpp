#include "scanner.hpp"

Scanner::Scanner() { }

std::size_t Scanner::scan( fs::path directory, int flags ) throw (RuntimeError) {
	if( !fs::exists( directory ) ) {
		throw new RuntimeError("Directory " + directory.string() + " does not exist!" );
	}
	std::size_t number_of_files = 0;
	for( fs::directory_iterator dir_iter( directory ), end_iter; dir_iter != end_iter; dir_iter++ ) {
		if( fs::is_directory( dir_iter->path() ) ) {
			if( flags & RECURSIVE ) {
				scan( dir_iter->path(), flags );
			}
		} else if( fs::is_regular( dir_iter->path() ) ) {
			number_of_files++;
			files.push_back( dir_iter->path() );
		}
	}
}

void Scanner::sort() {
	files.sort();
}

std::size_t Scanner::size() {
	return files.size();
}

Scanner::iterator Scanner::begin() {
	return files.begin();
}

Scanner::iterator Scanner::end() {
	return files.end();
}

Scanner::const_iterator Scanner::begin() const {
	return files.begin();
}

Scanner::const_iterator Scanner::end() const {
	return files.end();
}
