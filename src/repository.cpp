#include "repository.hpp"
#include "file_adder.hpp"

Repository::Repository( const fs::path& path, const std::string& name ) {
	path_to_repository = path;
	this->repo_name = name;

	// UUID of Version 3 or 5 needs a namespace uuid.
	uuid namespace_nil_uuid;
	repo_id.make( UUID_MAKE_V5, &namespace_nil_uuid, (path.string() + ":" + name).c_str() );
}

Repository::Repository( const std::string& repo_line ) {
	// Split repo_line at ';'
	// create the uuid Object with one of these substrings
	// assign the other variables
	// create an additional uuid Object to verify that the ID's
	// match and we really read a good repo_line and not some garbage
}

fs::path Repository::path() {
	return path_to_repository;
}

uuid Repository::id() {
	return repo_id;
}

std::string Repository::name() {
	return repo_name;
}

void Repository::name( const std::string& new_name ) {
	repo_name = new_name;
}

Repository& Repository::create() {
	// create directories 00 to ff
	for(int i = 0; i < 16; i++) {
		for(int j = 0; j < 16; j++) {
			std::stringstream str;
			str << std::hex << i << j;
			fs::create_directory( path_to_repository / str.str() );
		}
	}
	return *this;
}

Repository& Repository::inject( const fs::path& base_directory ) {
	FileAdder::process( base_directory );
	//FileAdder::sort_by_digest();
	FileAdder::sort_by_path();

	foreach( DigestFilePair pair, FileAdder::ref() ) {
		try {
			fs::copy_file( pair.file(), path_to_repository / pair.digest().substr(0,2) / (pair.digest() + fs::extension( pair.file() )) );
		} catch (fs::basic_filesystem_error< fs::path > error) {
			std::cerr << error.path1() << " is a duplicate of " << error.path2() << std::endl;
		}
	}
	return *this;
}
